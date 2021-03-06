#include "uniquelibrary.h"

#include "ui_uniquelibrary.h"

#include "flowlayout.h"

#include <QPushButton>
#include <QSqlRecord>
#include <QSqlQuery>

#include <QtDebug>

#include "albumform.h"

UniqueLibrary::UniqueLibrary(QWidget *parent) :
	QWidget(parent), ui(new Ui::UniqueLibrary), _sqlModel(NULL)
{
	ui->setupUi(this);
	_flowLayout = new FlowLayout();
	ui->scrollArea->setWidgetResizable(true);
	ui->scrollArea->widget()->setLayout(_flowLayout);
}

void UniqueLibrary::init(LibrarySqlModel *sql)
{
	_sqlModel = sql;

	connect(_sqlModel, &LibrarySqlModel::modelAboutToBeReset, this, &UniqueLibrary::reset);
	connect(_sqlModel, &LibrarySqlModel::trackExtractedFromFS, this, &UniqueLibrary::insertTrackFromFile);
	connect(_sqlModel, &LibrarySqlModel::trackExtractedFromDB, this, &UniqueLibrary::insertTrackFromRecord);
	connect(_sqlModel, &LibrarySqlModel::coverWasUpdated, this, &UniqueLibrary::updateCover);
}

void UniqueLibrary::insertTrackFromRecord(const QSqlRecord &record)
{
	int i = -1;
	//coverAbsPath varchar(255), internalCover INTEGER DEFAULT 0, externalCover INTEGER DEFAULT 0)
	const QString artist = record.value(++i).toString();
	const QString artistAlbum = record.value(++i).toString();
	const QString album = record.value(++i).toString();
	const QString title = record.value(++i).toString();
	int trackNumber = record.value(++i).toInt();
	int discNumber = record.value(++i).toInt();
	int year = record.value(++i).toInt();
	const QString absPath = record.value(++i).toString();
	const QString path = record.value(++i).toString();
	const QString coverAbsPath = record.value(++i).toString();
	//qDebug() << coverAbsPath;
	//bool internalCover = record.value(++i).toBool();
	record.value(++i).toBool();
	//bool externalCover = record.value(++i).toBool();
	record.value(++i).toBool();
	QString trackTitle = QString::number(trackNumber).append(". ").append(title);
	this->insertTrack(absPath, artistAlbum, artist, album, discNumber, trackTitle, year);
}

void UniqueLibrary::insertTrackFromFile(const FileHelper &fh)
{
	this->insertTrack(fh.fileInfo().absoluteFilePath(), fh.artistAlbum(), fh.artist(), fh.album(), fh.discNumber(),
					  fh.title(), fh.year().toInt());
}

void UniqueLibrary::insertTrack(const QString &, const QString &/*artistAlbum*/, const QString &/*artist*/, const QString &/*album*/,
				 int /*discNumber*/, const QString &/*title*/, int /*year*/)
{
	/*QString theArtist = artistAlbum.isEmpty() ? artist : artistAlbum;
	AlbumForm *wAlbum = NULL;
	if (_albums.contains(album)) {
		wAlbum = _albums.value(album);
	} else {
		wAlbum = new AlbumForm();
		wAlbum->setArtist(theArtist);
		wAlbum->setAlbum(album, year);
		wAlbum->setDiscNumber(discNumber);
		_albums.insert(album, wAlbum);
		ui->scrollArea->widget()->layout()->addWidget(wAlbum);
	}
	wAlbum->appendTrack(title);*/
}

void UniqueLibrary::reset()
{
	_albums.clear();
	while (QLayoutItem* item = _flowLayout->takeAt(0)) {
		delete item->widget();
		delete item;
	}
}

void UniqueLibrary::updateCover(const QFileInfo &coverFileInfo)
{
	QSqlQuery externalCover("SELECT DISTINCT album FROM tracks WHERE path = ?", _sqlModel->database());
	externalCover.addBindValue(QDir::toNativeSeparators(coverFileInfo.absolutePath()));
	if (!_sqlModel->database().isOpen()) {
		_sqlModel->database().open();
	}
	externalCover.exec();
	if (externalCover.next()) {
		QString album = externalCover.record().value(0).toString();
		AlbumForm *albumForm = _albums.value(album);
		albumForm->setCover(coverFileInfo.absoluteFilePath());
	}
}
