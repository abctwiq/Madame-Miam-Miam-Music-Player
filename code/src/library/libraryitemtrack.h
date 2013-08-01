#ifndef LIBRARYITEMTRACK_H
#define LIBRARYITEMTRACK_H

#include "libraryitem.h"

class LibraryItemTrack : public LibraryItem
{
public:
	explicit LibraryItemTrack() : LibraryItem() {}

	explicit LibraryItemTrack(const QString &track, int suffix);

	int childCount() const { return 0; }

	void setTrackNumber(int track) { setData(track, TRACK_NUMBER); }
	inline int trackNumber() const { return data(TRACK_NUMBER).toInt(); }

	/** Redefined. */
	inline int type() const { return LibraryItem::Track; }

	QString filePath() const;
	void setFilePath(const QString &absFilePath);
};

#endif // LIBRARYITEMTRACK_H
