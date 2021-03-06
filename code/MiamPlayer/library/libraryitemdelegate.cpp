#include "libraryitemdelegate.h"

#include <cover.h>
#include <settings.h>
#include "librarytreeview.h"
#include "../playlists/starrating.h"

#include <memory>

#include <QtDebug>
#include <QImageReader>

LibraryItemDelegate::LibraryItemDelegate(LibraryFilterProxyModel *proxy) :
	QStyledItemDelegate(proxy), _animateIcons(false), _iconSizeChanged(false), _iconOpacity(1.0)
{
	_proxy = proxy;
	_libraryModel = qobject_cast<QStandardItemModel*>(_proxy->sourceModel());
	_showCovers = Settings::getInstance()->isCoversEnabled();
}

void LibraryItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	painter->save();
	painter->setFont(Settings::getInstance()->font(Settings::LIBRARY));
	QStandardItem *item = _libraryModel.data()->itemFromIndex(_proxy.data()->mapToSource(index));
	QStyleOptionViewItem o = option;
	initStyleOption(&o, index);
	o.palette = QGuiApplication::palette();
	if (QGuiApplication::isLeftToRight()) {
		o.rect.adjust(0, 0, -19, 0);
	} else {
		o.rect.adjust(19, 0, 0, 0);
	}

	// Removes the dotted rectangle to the focused item
	o.state &= ~QStyle::State_HasFocus;
	int type = item->data(LibraryTreeView::Type).toInt();
	switch (type) {
	case LibraryTreeView::Album:
		this->drawAlbum(painter, o, item);
		break;
	case LibraryTreeView::Artist:
		this->drawArtist(painter, o);
		break;
	case LibraryTreeView::Disc:
		this->drawDisc(painter, o, index);
		break;
	case LibraryTreeView::Letter:
		this->drawLetter(painter, o, index);
		break;
	case LibraryTreeView::Track:
		this->drawTrack(painter, o, item);
		break;
	default:
		QStyledItemDelegate::paint(painter, o, index);
		break;
	}
	painter->restore();
}

/** Redefined to always display the same height for albums, even for those without one. */
QSize LibraryItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	Settings *settings = Settings::getInstance();
	QStandardItem *item = _libraryModel->itemFromIndex(_proxy->mapToSource(index));
	int type = item->data(LibraryTreeView::Type).toInt();
	if (settings->isCoversEnabled() && type == LibraryTreeView::Album) {
		QFontMetrics fmf(settings->font(Settings::LIBRARY));
		return QSize(option.rect.width(), qMax(fmf.height(), settings->coverSize() + 2));
	} else {
		return QStyledItemDelegate::sizeHint(option, index);
	}
}

/** Albums have covers usually. */
void LibraryItemDelegate::drawAlbum(QPainter *painter, QStyleOptionViewItem &option, QStandardItem *item) const
{
	static QImageReader imageReader;
	static int coverSize = Settings::getInstance()->coverSize();
	QString file = item->data(LibraryTreeView::DataCoverPath).toString();
	//Settings *settings = Settings::getInstance();
	// Display a light selection rectangle when one is moving the cursor
	if (option.state.testFlag(QStyle::State_MouseOver) && !option.state.testFlag(QStyle::State_Selected)) {
		painter->save();
		/*if (settings->isCustomColors()) {
			QColor highlight = settings->customColors(Settings::ColorHighlight);
			painter->setPen(highlight);
			painter->setBrush(highlight.lighter());
		} else {*/
			painter->setPen(option.palette.highlight().color());
			painter->setBrush(option.palette.highlight().color().lighter(175));
		//}
		painter->drawRect(option.rect.adjusted(0, 0, -1, -1));
		painter->restore();
	} else if (option.state & QStyle::State_Selected) {
		// Display a not so light rectangle when one has chosen an item. It's darker than the mouse over
		painter->save();
		/*if (settings->isCustomColors()) {
			QColor highlight = settings->customColors(Settings::ColorHighlight);
			painter->setPen(highlight);
			painter->setBrush(highlight.lighter(125));
		} else {*/
			painter->setPen(option.palette.highlight().color());
			painter->setBrush(option.palette.highlight().color().lighter(160));
		//}
		painter->drawRect(option.rect.adjusted(0, 0, -1, -1));
		painter->restore();
	}
	if (_showCovers) {
		// Qt::UserRole + 20 == false => pixmap not loaded ; == true => pixmap loaded
		/// XXX: extract this elsewhere
		if (item->data(Qt::UserRole + 20).toBool() == false && !file.isEmpty()) {
			FileHelper fh(file);
			QFileInfo f(file);
			qDebug() << "loading cover from harddrive";
			// If it's an inner cover, load it
			if (FileHelper::suffixes().contains(f.suffix())) {
				std::unique_ptr<Cover> cover(fh.extractCover());
				if (cover) {
					QPixmap p;
					p.loadFromData(cover->byteArray(), cover->format());
					p = p.scaled(coverSize, coverSize);
					item->setIcon(p);
					item->setData(true, Qt::UserRole + 20);
				}
			} else {
				imageReader.setFileName(QDir::fromNativeSeparators(file));
				imageReader.setScaledSize(QSize(coverSize, coverSize));
				item->setIcon(QPixmap::fromImage(imageReader.read()));
				item->setData(true, Qt::UserRole + 20);
			}
		}
	}
	bool b = item->data(Qt::UserRole + 20).toBool();
	if (_showCovers && b) {
		QPixmap p = option.icon.pixmap(QSize(coverSize, coverSize));
		QRect cover;
		if (QGuiApplication::isLeftToRight()) {
			cover = QRect(option.rect.x() + 1, option.rect.y() + 1, coverSize, coverSize);
		} else {
			cover = QRect(option.rect.width() + 19 - coverSize - 1, option.rect.y() + 1, coverSize, coverSize);
		}
		if (_animateIcons) {
			painter->save();
			painter->setOpacity(_iconOpacity);
			painter->drawPixmap(cover, p);
			painter->restore();
		} else {
			painter->drawPixmap(cover, p);
		}
	}
	// It's possible to have missing covers in your library, so we need to keep alignment.
	QFontMetrics fmf(Settings::getInstance()->font(Settings::LIBRARY));
	option.textElideMode = Qt::ElideRight;
	if (QGuiApplication::isLeftToRight()) {
		QPoint topLeft(option.rect.x() + coverSize + 5, option.rect.y());
		QRect rectText(topLeft, option.rect.bottomRight());
		QString s = fmf.elidedText(option.text, Qt::ElideRight, rectText.width());
		painter->drawText(rectText, Qt::AlignVCenter, s);
	} else {
		QRect rectText(option.rect.x(), option.rect.y(), option.rect.width() - coverSize - 5, option.rect.height());
		QString s = fmf.elidedText(option.text, Qt::ElideRight, rectText.width());
		painter->drawText(rectText, Qt::AlignVCenter, s);
	}
}

void LibraryItemDelegate::drawArtist(QPainter *painter, QStyleOptionViewItem &option) const
{
	//Settings *settings = Settings::getInstance();
	// Display a light selection rectangle when one is moving the cursor
	if (option.state.testFlag(QStyle::State_MouseOver) && !option.state.testFlag(QStyle::State_Selected)) {
		painter->save();
		/*if (settings->isCustomColors()) {
			QColor highlight = settings->customColors(Settings::ColorHighlight);
			painter->setPen(highlight);
			painter->setBrush(highlight.lighter());
		} else {*/
			painter->setPen(option.palette.highlight().color());
			painter->setBrush(option.palette.highlight().color().lighter(175));
		//}
		painter->drawRect(option.rect.adjusted(0, 0, -1, -1));
		painter->restore();
	} else if (option.state & QStyle::State_Selected) {
		// Display a not so light rectangle when one has chosen an item. It's darker than the mouse over
		painter->save();
		/*if (settings->isCustomColors()) {
			QColor highlight = settings->customColors(Settings::ColorHighlight);
			painter->setPen(highlight);
			painter->setBrush(highlight.lighter(125));
		} else {*/
			painter->setPen(option.palette.highlight().color());
			painter->setBrush(option.palette.highlight().color().lighter(160));
		//}
		painter->drawRect(option.rect.adjusted(0, 0, -1, -1));
		painter->restore();
	}

	// It's possible to have missing covers in your library, so we need to keep alignment.
	QFontMetrics fmf(Settings::getInstance()->font(Settings::LIBRARY));
	option.textElideMode = Qt::ElideRight;
	if (QGuiApplication::isLeftToRight()) {
		QPoint topLeft(option.rect.x() + 5, option.rect.y());
		QRect rectText(topLeft, option.rect.bottomRight());
		QString s = fmf.elidedText(option.text, Qt::ElideRight, rectText.width());
		painter->drawText(rectText, Qt::AlignVCenter, s);
	} else {
		QRect rectText(option.rect.x(), option.rect.y(), option.rect.width() - 5, option.rect.height());
		QString s = fmf.elidedText(option.text, Qt::ElideRight, rectText.width());
		painter->drawText(rectText, Qt::AlignVCenter, s);
	}
}

void LibraryItemDelegate::drawDisc(QPainter *painter, QStyleOptionViewItem &option, const QModelIndex &index) const
{
	option.state = QStyle::State_None;
	QPointF p1 = option.rect.bottomLeft(), p2 = option.rect.bottomRight();
	p1.setX(p1.x() + 2);
	p2.setX(p2.x() - 2);
	painter->setPen(Qt::gray);
	painter->drawLine(p1, p2);
	QStyledItemDelegate::paint(painter, option, index);
}

void LibraryItemDelegate::drawLetter(QPainter *painter, QStyleOptionViewItem &option, const QModelIndex &index) const
{
	// One cannot interact with an alphabetical separator
	option.state = QStyle::State_None;
	option.font.setBold(true);
	QPointF p1 = option.rect.bottomLeft(), p2 = option.rect.bottomRight();
	p1.setX(p1.x() + 2);
	p2.setX(p2.x() - 2);
	painter->setPen(Qt::gray);
	painter->drawLine(p1, p2);
	QStyledItemDelegate::paint(painter, option, index);
}

void LibraryItemDelegate::drawTrack(QPainter *painter, QStyleOptionViewItem &option, const QStandardItem *track) const
{
	/// XXX: it will be a piece of cake to add an option that one can customize how track number will be displayed
	/// QString title = settings->libraryItemTitle();
	/// for example: zero padding
	if (Settings::getInstance()->isStarDelegates()) {
		QString absFilePath = track->data(LibraryTreeView::DataAbsFilePath).toString();
		/// XXX: query the sqlmodel instead?
		FileHelper fh(absFilePath);
		//qDebug() << "rating" << fh.rating();
		if (fh.rating() > 0) {
			//StarRating starRating(fh.rating());
			//starRating.paint(painter, option, StarRating::ReadOnly);
		}
	}
	int trackNumber = track->data(LibraryTreeView::DataTrackNumber).toInt();
	QString title = QString("%1").arg(trackNumber, 2, 10, QChar('0')).append(". ").append(track->text());
	option.text = title;
	option.widget->style()->drawControl(QStyle::CE_ItemViewItem, &option, painter, option.widget);
}

void LibraryItemDelegate::displayIcon(bool b)
{
	qDebug() << Q_FUNC_INFO;
	_showCovers = b;
	if (_showCovers) {
		_animateIcons = true;
	} else {
		this->setIconOpacity(0);
	}
}
