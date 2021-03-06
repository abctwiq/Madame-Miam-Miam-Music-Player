#include "quickstartsearchengine.h"

#include <QDir>
#include <QDirIterator>
#include <QStandardPaths>
#include <QThread>

#include "filehelper.h"

QuickStartSearchEngine::QuickStartSearchEngine(QObject *parent) :
	QObject(parent)
{
}

void QuickStartSearchEngine::doSearch()
{
	QString userMusicPath = QStandardPaths::standardLocations(QStandardPaths::MusicLocation).first();
	QDir musicDir(userMusicPath);

	// For every subfolder in the user's music path, a quick test on multimedia files is done
	foreach (QFileInfo fileInfo, musicDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name)) {

		// Files are excluded if the player can't read them!
		QStringList filters;
		foreach (QString filter, FileHelper::suffixes()) {
			filters.append("*." + filter);
		}
		QDirIterator it(fileInfo.absoluteFilePath(), filters, QDir::Files, QDirIterator::Subdirectories);
		int musicFiles = 0;
		while (it.hasNext()) {
			it.next();
			musicFiles++;
		}
		emit folderScanned(fileInfo, musicFiles);
	}
	this->thread()->quit();
}
