#ifndef TABPLAYLIST_H
#define TABPLAYLIST_H

#include <QDir>
#include <QTabWidget>
#include <QMouseEvent>

#include "dialogs/closeplaylistpopup.h"
#include "playlist.h"
#include "../tracksnotfoundmessagebox.h"

#include "mediabutton.h"

//#include <QFileSystemWatcher>
#include <mediaplayer.h>

class TabPlaylist : public QTabWidget
{
	Q_OBJECT

private:
	/** A custom message box for handling errors. */
	TracksNotFoundMessageBox *messageBox;

	QString _nextAction;

	//QFileSystemWatcher *_watcher;

	/** Test: used to simulate a callback.*/
	int _tabIndex;

	QWeakPointer<MediaPlayer> _mediaPlayer;

	ClosePlaylistPopup *_closePlaylistPopup;

public:
	/** Default constructor. */
	TabPlaylist(QWidget *parent = 0);

	/** Get the current playlist. */
	inline Playlist *currentPlayList() const { return qobject_cast<Playlist *>(this->currentWidget()); }

	inline QWeakPointer<MediaPlayer> mediaPlayer() const { return _mediaPlayer; }

	/** Get the playlist at index. */
	inline Playlist *playlist(int index) { return qobject_cast<Playlist *>(this->widget(index)); }

	inline QList<Playlist *> playlists() {
		QList<Playlist*> _playlists;
		for (int i = 0; i < count() - 1; i++) {
			_playlists.append(this->playlist(i));
		}
		return _playlists;
	}

	void setMediaPlayer(QWeakPointer<MediaPlayer> mediaPlayer);

protected:
	/** Retranslate tabs' name and all playlists in this widget. */
	void changeEvent(QEvent *event);

public slots:
	/** Add a new playlist tab. */
	Playlist* addPlaylist();

	/** Add external folders (from a drag and drop) to the current playlist. */
	void addExtFolders(const QList<QDir> &folders);

	/** Append a single track chosen by one from the library or the filesystem into the active playlist. */
	void appendItemToPlaylist(const QString &track);

	/** Insert multiple tracks chosen by one from the library or the filesystem into a playlist. */
	void insertItemsToPlaylist(int rowIndex, const QStringList &tracks);

	void moveTracksDown();

	void moveTracksUp();

	/** Action sent from the menu. */
	void removeCurrentPlaylist();

	void removeSelectedTracks();

	/** Remove a playlist when clicking on a close button in the corner. */
	void removeTabFromCloseButton(int index);

	void updateRowHeight();

private slots:
	/** When the user is clicking on the (+) button to add a new playlist. */
	void checkAddPlaylistButton(int i);

	void execActionFromClosePopup(QAbstractButton *action);

signals:
	/** Forward the signal. */
	void aboutToChangeMenuLabels(int);

	void created();

	void destroyed(int);

	void aboutToSavePlaylist(int);

	void sendToTagEditor(const QList<QPersistentModelIndex> &);

	void updatePlaybackModeButton();
};

#endif // TABPLAYLIST_H
