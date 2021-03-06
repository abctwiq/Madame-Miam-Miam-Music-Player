#ifndef TIMELABEL_H
#define TIMELABEL_H

#include <QLabel>

/**
* @brief Display up to three modes for the length of a track.
*/
class TimeLabel : public QLabel
{
	Q_OBJECT
private:
	/** The mode from "mm:ss", "-mm:ss" or "mm:ss / mm:ss" */
	int _mode;

	/** Current time of selected track. */
	qint64 _time;

	/** Total time of selected track. */
	qint64 _total;

public:
	/** Default constructor. */
	explicit TimeLabel(QWidget *parent = 0);

	/** Setter. */
	void setTime(qint64 time, qint64 total);

	/** Redefined to filter mouse press event. */
	bool eventFilter(QObject *obj, QEvent *event);

private slots:
	/** Display track length using the selected mode. */
	void display();

signals:
	/** Sent when time has changed to update the label.*/
	void timeChanged();
};

#endif // TIMELABEL_H
