#include "shortcutwidget.h"
#include "settings.h"

#include "QHBoxLayout"

#include <QtDebug>

ShortcutWidget::ShortcutWidget(QWidget *parent) :
	QWidget(parent)
{
	QHBoxLayout *layout = new QHBoxLayout(this);
	comboBox = new QComboBox(this);
	plusLabel = new QLabel(this);
	lineEdit = new ShortcutLineEdit(this);
	reset = new QPushButton(this);

	comboBox->addItem(QString(), 0);
	comboBox->addItem(tr("Ctrl"), Qt::CTRL);
	comboBox->addItem(tr("Shift"), Qt::SHIFT);
	comboBox->addItem(tr("Alt"), Qt::ALT);

	plusLabel->setMinimumWidth(10);

	reset->setFlat(true);
	closeButton = new QIcon(":/config/closeButton");
	reset->setIcon(*closeButton);
	reset->setMaximumSize(20, 20);
	reset->hide();

	layout->addWidget(comboBox);
	layout->addWidget(plusLabel);
	layout->addWidget(lineEdit);
	layout->addWidget(reset);
	layout->setSizeConstraint(QLayout::SetMinAndMaxSize);
	setLayout(layout);

	connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(showPlusLabel(int)));
	connect(lineEdit, SIGNAL(editingFinished()), this, SLOT(createKeySequence()));
	connect(reset, SIGNAL(clicked()), this, SLOT(deleteKeySequence()));
}

void ShortcutWidget::setObjectName(const QString &name)
{
	int shortcut = Settings::getInstance()->shortcut(name);
	if (shortcut > 0) {
		QKeySequence keySequence(shortcut);
		QStringList keys = keySequence.toString().split('+');
		// If we have a modifier like 'Ctrl'
		if (keys.size() > 1) {
			int index = comboBox->findText(keys.first());
			comboBox->setCurrentIndex(index);

			// Removes the modifier
			shortcut -= comboBox->itemData(index).toInt();
			keySequence = QKeySequence(shortcut);
		}
		lineEdit->setKey(shortcut);
		reset->setIcon(*closeButton);
		reset->show();
	}
	QObject::setObjectName(name);
}

/** Create a QKeySequence from a combobox and a label. */
void ShortcutWidget::createKeySequence()
{
	if (!lineEdit->text().isEmpty()) {
		int modifier = comboBox->itemData(comboBox->currentIndex()).toInt();
		reset->setIcon(*closeButton);
		reset->show();
		emit shortcutChanged(this, modifier + lineEdit->key());
	}
}

/** Delete a QKeySequence. */
void ShortcutWidget::deleteKeySequence()
{
	comboBox->setCurrentIndex(0);
	lineEdit->setKey(0);
	lineEdit->setStyleSheet(QString());
	reset->setIcon(QIcon());
	emit shortcutChanged(this);
}

/** Add the '+' symbol when a modifier key is selected. */
void ShortcutWidget::showPlusLabel(int i)
{
	if (i == 0) {
		plusLabel->clear();
	} else {
		plusLabel->setText("+");
	}
	lineEdit->setFocus();
	if (!lineEdit->text().isEmpty()) {
		emit createKeySequence();
	}
}
