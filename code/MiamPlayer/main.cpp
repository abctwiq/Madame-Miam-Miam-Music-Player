#include <QApplication>

#include "mainwindow.h"

#define COMPANY "MmeMiamMiam"
#define SOFT "MmeMiamMiamMusicPlayer"
#define VERSION "0.5.5"

#include "plugininfo.h"

int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(mmmmp);

	qRegisterMetaType<QFileInfo>();
	qRegisterMetaType<PluginInfo>();
	qRegisterMetaTypeStreamOperators<PluginInfo>("PluginInfo");

	QApplication app(argc, argv);
	app.setOrganizationName(COMPANY);
	app.setApplicationName(SOFT);
	app.setApplicationVersion(VERSION);

	MainWindow window;
	window.init();
	window.show();
	window.loadPlugins();

	return app.exec();
}
