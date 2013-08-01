#ifndef LIBRARYITEMARTIST_H
#define LIBRARYITEMARTIST_H

#include "libraryitem.h"

class LibraryItemArtist : public LibraryItem
{
public:
	explicit LibraryItemArtist() : LibraryItem() {}

	explicit LibraryItemArtist(const QString &artist);

	/** Redefined. */
	inline int type() const { return LibraryItem::Artist; }
};

#endif // LIBRARYITEMARTIST_H
