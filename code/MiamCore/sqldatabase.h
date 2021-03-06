#ifndef SQLDATABASE_H
#define SQLDATABASE_H

#include <QObject>
#include <QSqlDatabase>

#include "miamcore_global.h"

/**
 * \brief The SqlDatabase class uses SQLite to store few but useful tables for tracks, playlists, etc.
 */
class MIAMCORE_LIBRARY SqlDatabase : public QSqlDatabase
{
public:
	explicit SqlDatabase();

	virtual ~SqlDatabase() {}

	/** Resynchronize table Playlists in case one has deleted some files. */
	void cleanBeforeQuit();
};

#endif // SQLDATABASE_H
