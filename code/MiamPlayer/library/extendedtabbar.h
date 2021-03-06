#ifndef EXTENDEDTABBAR_H
#define EXTENDEDTABBAR_H

#include <QTabBar>

class ExtendedTabBar : public QTabBar
{
	Q_OBJECT
public:
	explicit ExtendedTabBar(QWidget *parent = 0) : QTabBar(parent) {}

protected:
	QSize tabSizeHint(int) const { return QSize(rect().width() / 2, rect().height()); }
};

#endif // EXTENDEDTABBAR_H
