#ifndef TAGEDITOR_H
#define TAGEDITOR_H

#include <QWidget>

#include "cover.h"
#include "tagconverter.h"

#include "ui_tageditor.h"

class TagEditor : public QWidget, public Ui::TagEditor
{
	Q_OBJECT

private:
	QMap<int, QComboBox*> combos;

	/// An automatic helper for writing tags following regExp
	TagConverter *tagConverter;

	static QStringList genres;

	QMap<int, Cover*> covers;
	QMap<int, Cover*> unsavedCovers;

public:
	TagEditor(QWidget *parent = 0);

protected:
	/** Redefined to filter context menu event for the cover album object. */
	bool eventFilter(QObject *obj, QEvent *event);

private:
	void clearCovers(QMap<int, Cover *> &coversToRemove);

public slots:
	/** Splits tracks into columns to be able to edit metadatas. */
	void addItemsToEditor(const QStringList &tracks);

	/** Clears all rows and comboboxes. */
	void clear();

private slots:
	void applyCoverToAll(bool isForAll, Cover *cover);

	/** Closes this Widget and tells its parent to switch views. */
	void close();

	/** Saves all fields in the media. */
	void commitChanges();

	/** Displays tags in separate QComboBoxes. */
	void displayTags();

	/** Displays a cover only if all the selected items have exactly the same cover. */
	void displayCover();

	void recordSingleItemChange(QTableWidgetItem *item);

	void replaceCover(Cover *newCover);

	/** Cancels all changes made by the user. */
	void rollbackChanges();

	void toggleTagConverter(bool);

	void updateCells(QString text);

signals:
	void closeTagEditor(bool);

	void rebuildTreeView(QList<QPersistentModelIndex>);
};

#endif // TAGEDITOR_H
