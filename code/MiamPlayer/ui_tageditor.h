/********************************************************************************
** Form generated from reading UI file 'tageditor.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAGEDITOR_H
#define UI_TAGEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "tageditor/albumcover.h"
#include "tageditor/tageditortablewidget.h"

QT_BEGIN_NAMESPACE

class Ui_TagEditor
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *closeTagEditorButton;
    QSpacerItem *spacer_tagEditor;
    QPushButton *convertPushButton;
    QPushButton *saveChangesButton;
    QPushButton *cancelButton;
    TagEditorTableWidget *tagEditorWidget;
    QHBoxLayout *horizontalLayout_2;
    AlbumCover *albumCover;
    QGridLayout *gridLayout;
    QLabel *labelDisc;
    QComboBox *commentComboBox;
    QComboBox *artistComboBox;
    QLabel *labelArtist;
    QLabel *labelTrack;
    QLabel *labelComment;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *trackComboBox;
    QLabel *labelYear;
    QComboBox *yearComboBox;
    QLabel *labelTitle;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelArtistAlbum;
    QLabel *labelAlbum;
    QVBoxLayout *verticalLayout_3;
    QComboBox *artistAlbumComboBox;
    QComboBox *albumComboBox;
    QComboBox *titleComboBox;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *discComboBox;
    QLabel *labelGenre;
    QComboBox *genreComboBox;

    void setupUi(QWidget *TagEditor)
    {
        if (TagEditor->objectName().isEmpty())
            TagEditor->setObjectName(QStringLiteral("TagEditor"));
        TagEditor->resize(600, 600);
        verticalLayout = new QVBoxLayout(TagEditor);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        closeTagEditorButton = new QPushButton(TagEditor);
        closeTagEditorButton->setObjectName(QStringLiteral("closeTagEditorButton"));

        horizontalLayout->addWidget(closeTagEditorButton);

        spacer_tagEditor = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer_tagEditor);

        convertPushButton = new QPushButton(TagEditor);
        convertPushButton->setObjectName(QStringLiteral("convertPushButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/rename"), QSize(), QIcon::Normal, QIcon::Off);
        convertPushButton->setIcon(icon);
        convertPushButton->setCheckable(true);

        horizontalLayout->addWidget(convertPushButton);

        saveChangesButton = new QPushButton(TagEditor);
        saveChangesButton->setObjectName(QStringLiteral("saveChangesButton"));
        saveChangesButton->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/save"), QSize(), QIcon::Normal, QIcon::Off);
        saveChangesButton->setIcon(icon1);

        horizontalLayout->addWidget(saveChangesButton);

        cancelButton = new QPushButton(TagEditor);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setEnabled(false);

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);

        tagEditorWidget = new TagEditorTableWidget(TagEditor);
        if (tagEditorWidget->columnCount() < 11)
            tagEditorWidget->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tagEditorWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tagEditorWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tagEditorWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tagEditorWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tagEditorWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tagEditorWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tagEditorWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tagEditorWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tagEditorWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tagEditorWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tagEditorWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        tagEditorWidget->setObjectName(QStringLiteral("tagEditorWidget"));
        tagEditorWidget->setAlternatingRowColors(true);
        tagEditorWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tagEditorWidget->setShowGrid(false);
        tagEditorWidget->setSortingEnabled(true);
        tagEditorWidget->horizontalHeader()->setHighlightSections(false);
        tagEditorWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tagEditorWidget->horizontalHeader()->setStretchLastSection(true);
        tagEditorWidget->verticalHeader()->setVisible(false);
        tagEditorWidget->verticalHeader()->setHighlightSections(false);

        verticalLayout->addWidget(tagEditorWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        albumCover = new AlbumCover(TagEditor);
        albumCover->setObjectName(QStringLiteral("albumCover"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(albumCover->sizePolicy().hasHeightForWidth());
        albumCover->setSizePolicy(sizePolicy);
        albumCover->setMinimumSize(QSize(100, 100));
        albumCover->setMaximumSize(QSize(100, 100));
        albumCover->setProperty("text", QVariant(QStringLiteral("")));
        albumCover->setProperty("pixmap", QVariant(QPixmap(QString::fromUtf8(":/icons/disc"))));
        albumCover->setProperty("scaledContents", QVariant(true));

        horizontalLayout_2->addWidget(albumCover);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, 6, -1);
        labelDisc = new QLabel(TagEditor);
        labelDisc->setObjectName(QStringLiteral("labelDisc"));

        gridLayout->addWidget(labelDisc, 1, 2, 1, 1, Qt::AlignRight);

        commentComboBox = new QComboBox(TagEditor);
        commentComboBox->setObjectName(QStringLiteral("commentComboBox"));
        commentComboBox->setEditable(true);
        commentComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);

        gridLayout->addWidget(commentComboBox, 2, 3, 1, 1, Qt::AlignTop);

        artistComboBox = new QComboBox(TagEditor);
        artistComboBox->setObjectName(QStringLiteral("artistComboBox"));
        artistComboBox->setEditable(true);
        artistComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);

        gridLayout->addWidget(artistComboBox, 1, 1, 1, 1);

        labelArtist = new QLabel(TagEditor);
        labelArtist->setObjectName(QStringLiteral("labelArtist"));

        gridLayout->addWidget(labelArtist, 1, 0, 1, 1, Qt::AlignRight);

        labelTrack = new QLabel(TagEditor);
        labelTrack->setObjectName(QStringLiteral("labelTrack"));

        gridLayout->addWidget(labelTrack, 0, 2, 1, 1, Qt::AlignRight);

        labelComment = new QLabel(TagEditor);
        labelComment->setObjectName(QStringLiteral("labelComment"));

        gridLayout->addWidget(labelComment, 2, 2, 1, 1, Qt::AlignRight|Qt::AlignTop);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        trackComboBox = new QComboBox(TagEditor);
        trackComboBox->setObjectName(QStringLiteral("trackComboBox"));
        trackComboBox->setEditable(true);
        trackComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);

        horizontalLayout_5->addWidget(trackComboBox);

        labelYear = new QLabel(TagEditor);
        labelYear->setObjectName(QStringLiteral("labelYear"));

        horizontalLayout_5->addWidget(labelYear, 0, Qt::AlignRight);

        yearComboBox = new QComboBox(TagEditor);
        yearComboBox->setObjectName(QStringLiteral("yearComboBox"));
        yearComboBox->setEditable(true);
        yearComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);

        horizontalLayout_5->addWidget(yearComboBox);


        gridLayout->addLayout(horizontalLayout_5, 0, 3, 1, 1);

        labelTitle = new QLabel(TagEditor);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));

        gridLayout->addWidget(labelTitle, 0, 0, 1, 1, Qt::AlignRight);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelArtistAlbum = new QLabel(TagEditor);
        labelArtistAlbum->setObjectName(QStringLiteral("labelArtistAlbum"));

        verticalLayout_2->addWidget(labelArtistAlbum, 0, Qt::AlignRight);

        labelAlbum = new QLabel(TagEditor);
        labelAlbum->setObjectName(QStringLiteral("labelAlbum"));

        verticalLayout_2->addWidget(labelAlbum, 0, Qt::AlignRight);


        gridLayout->addLayout(verticalLayout_2, 2, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        artistAlbumComboBox = new QComboBox(TagEditor);
        artistAlbumComboBox->setObjectName(QStringLiteral("artistAlbumComboBox"));
        artistAlbumComboBox->setEditable(true);
        artistAlbumComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);

        verticalLayout_3->addWidget(artistAlbumComboBox);

        albumComboBox = new QComboBox(TagEditor);
        albumComboBox->setObjectName(QStringLiteral("albumComboBox"));
        albumComboBox->setEditable(true);
        albumComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);

        verticalLayout_3->addWidget(albumComboBox);


        gridLayout->addLayout(verticalLayout_3, 2, 1, 1, 1);

        titleComboBox = new QComboBox(TagEditor);
        titleComboBox->setObjectName(QStringLiteral("titleComboBox"));
        titleComboBox->setEditable(true);
        titleComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);

        gridLayout->addWidget(titleComboBox, 0, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        discComboBox = new QComboBox(TagEditor);
        discComboBox->setObjectName(QStringLiteral("discComboBox"));
        discComboBox->setEditable(true);
        discComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);

        horizontalLayout_4->addWidget(discComboBox);

        labelGenre = new QLabel(TagEditor);
        labelGenre->setObjectName(QStringLiteral("labelGenre"));

        horizontalLayout_4->addWidget(labelGenre, 0, Qt::AlignRight);

        genreComboBox = new QComboBox(TagEditor);
        genreComboBox->setObjectName(QStringLiteral("genreComboBox"));
        genreComboBox->setEditable(true);
        genreComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);

        horizontalLayout_4->addWidget(genreComboBox);


        gridLayout->addLayout(horizontalLayout_4, 1, 3, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 1);
        gridLayout->setColumnStretch(3, 6);

        horizontalLayout_2->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout_2);

        QWidget::setTabOrder(closeTagEditorButton, saveChangesButton);
        QWidget::setTabOrder(saveChangesButton, cancelButton);
        QWidget::setTabOrder(cancelButton, tagEditorWidget);
        QWidget::setTabOrder(tagEditorWidget, titleComboBox);
        QWidget::setTabOrder(titleComboBox, artistComboBox);
        QWidget::setTabOrder(artistComboBox, artistAlbumComboBox);
        QWidget::setTabOrder(artistAlbumComboBox, albumComboBox);
        QWidget::setTabOrder(albumComboBox, trackComboBox);
        QWidget::setTabOrder(trackComboBox, discComboBox);
        QWidget::setTabOrder(discComboBox, yearComboBox);
        QWidget::setTabOrder(yearComboBox, genreComboBox);
        QWidget::setTabOrder(genreComboBox, commentComboBox);

        retranslateUi(TagEditor);

        QMetaObject::connectSlotsByName(TagEditor);
    } // setupUi

    void retranslateUi(QWidget *TagEditor)
    {
        TagEditor->setWindowTitle(QApplication::translate("TagEditor", "Form", 0));
        closeTagEditorButton->setText(QApplication::translate("TagEditor", "Close Editor", 0));
        convertPushButton->setText(QApplication::translate("TagEditor", "Converter", 0));
        saveChangesButton->setText(QApplication::translate("TagEditor", "Save changes", 0));
        cancelButton->setText(QApplication::translate("TagEditor", "Cancel", 0));
        QTableWidgetItem *___qtablewidgetitem = tagEditorWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TagEditor", "Filename", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tagEditorWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TagEditor", "Path", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tagEditorWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("TagEditor", "Title", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tagEditorWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("TagEditor", "Artist", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tagEditorWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("TagEditor", "Artist Album", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tagEditorWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("TagEditor", "Album", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tagEditorWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("TagEditor", "Track", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tagEditorWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("TagEditor", "Disc", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tagEditorWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("TagEditor", "Year", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tagEditorWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("TagEditor", "Genre", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tagEditorWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("TagEditor", "Comment", 0));
        labelDisc->setText(QApplication::translate("TagEditor", "Disc: ", 0));
        labelArtist->setText(QApplication::translate("TagEditor", "Artist: ", 0));
        labelTrack->setText(QApplication::translate("TagEditor", "Track: ", 0));
        labelComment->setText(QApplication::translate("TagEditor", "Comment: ", 0));
        labelYear->setText(QApplication::translate("TagEditor", "Year: ", 0));
        labelTitle->setText(QApplication::translate("TagEditor", "Title: ", 0));
        labelArtistAlbum->setText(QApplication::translate("TagEditor", "Artist Album: ", 0));
        labelAlbum->setText(QApplication::translate("TagEditor", "Album: ", 0));
        labelGenre->setText(QApplication::translate("TagEditor", "Genre: ", 0));
    } // retranslateUi

};

namespace Ui {
    class TagEditor: public Ui_TagEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAGEDITOR_H
