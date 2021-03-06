#ifndef ADDRESSBARBUTTON_H
#define ADDRESSBARBUTTON_H

#include <QPushButton>

class AddressBarButton : public QPushButton
{
	Q_OBJECT
private:
	QString _path;

	int idx;

	QRect _textRect;
	QRect _arrowRect;
	bool _atLeastOneSubDir;

public:
	explicit AddressBarButton(const QString &newPath, int index = -1, QWidget *parent = 0);

	QString currentPath() const;

	inline int index() const { return idx; }

	inline void setIndex(const int &index) { idx = index; }

	inline const QString & path() const { return _path; }

protected:
	/** Redefined. */
	virtual void mouseMoveEvent(QMouseEvent *);

	/** Redefined. */
	virtual void mousePressEvent(QMouseEvent *);

	/** Redefined. */
	virtual void paintEvent(QPaintEvent *);

signals:
	void aboutToShowMenu();
};

#endif // ADDRESSBARBUTTON_H
