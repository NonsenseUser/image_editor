/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *mOpen;
    QAction *mSave;
    QAction *mClose;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QMdiArea *mdiArea;
    QTabWidget *tabWidget;
    QWidget *tabRadon;
    QPushButton *radon;
    QCheckBox *radonNewImage;
    QWidget *tabRotation;
    QLabel *rotationDegreeLabel;
    QLabel *rotationPointLabel;
    QLabel *pointCoordsLabel;
    QPlainTextEdit *rotationDegreeInput;
    QPushButton *rotateButton;
    QCheckBox *rotateNewImage;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1108, 665);
        mOpen = new QAction(MainWindow);
        mOpen->setObjectName("mOpen");
        mSave = new QAction(MainWindow);
        mSave->setObjectName("mSave");
        mClose = new QAction(MainWindow);
        mClose->setObjectName("mClose");
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName("mdiArea");
        mdiArea->setMaximumSize(QSize(784, 16777215));

        horizontalLayout->addWidget(mdiArea);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setMinimumSize(QSize(300, 0));
        tabWidget->setMaximumSize(QSize(300, 16777215));
        tabRadon = new QWidget();
        tabRadon->setObjectName("tabRadon");
        radon = new QPushButton(tabRadon);
        radon->setObjectName("radon");
        radon->setGeometry(QRect(10, 10, 101, 31));
        radonNewImage = new QCheckBox(tabRadon);
        radonNewImage->setObjectName("radonNewImage");
        radonNewImage->setGeometry(QRect(10, 50, 271, 23));
        radonNewImage->setChecked(true);
        tabWidget->addTab(tabRadon, QString());
        tabRotation = new QWidget();
        tabRotation->setObjectName("tabRotation");
        rotationDegreeLabel = new QLabel(tabRotation);
        rotationDegreeLabel->setObjectName("rotationDegreeLabel");
        rotationDegreeLabel->setGeometry(QRect(20, 30, 91, 16));
        rotationPointLabel = new QLabel(tabRotation);
        rotationPointLabel->setObjectName("rotationPointLabel");
        rotationPointLabel->setGeometry(QRect(20, 10, 101, 16));
        pointCoordsLabel = new QLabel(tabRotation);
        pointCoordsLabel->setObjectName("pointCoordsLabel");
        pointCoordsLabel->setGeometry(QRect(130, 10, 61, 16));
        rotationDegreeInput = new QPlainTextEdit(tabRotation);
        rotationDegreeInput->setObjectName("rotationDegreeInput");
        rotationDegreeInput->setGeometry(QRect(130, 30, 91, 21));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rotationDegreeInput->sizePolicy().hasHeightForWidth());
        rotationDegreeInput->setSizePolicy(sizePolicy);
        rotationDegreeInput->setCenterOnScroll(true);
        rotateButton = new QPushButton(tabRotation);
        rotateButton->setObjectName("rotateButton");
        rotateButton->setGeometry(QRect(130, 60, 75, 24));
        rotateNewImage = new QCheckBox(tabRotation);
        rotateNewImage->setObjectName("rotateNewImage");
        rotateNewImage->setGeometry(QRect(20, 90, 271, 23));
        rotateNewImage->setChecked(true);
        tabWidget->addTab(tabRotation, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1108, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(mOpen);
        menu->addAction(mSave);
        menu->addSeparator();
        menu->addAction(mClose);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        mOpen->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        mSave->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        mClose->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
#if QT_CONFIG(whatsthis)
        tabRadon->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\320\265 \320\240\320\260\320\264\320\276\320\275\320\260</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        radon->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\321\202\321\214", nullptr));
        radonNewImage->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\275\320\276\320\262\320\276\320\265 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabRadon), QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\320\265 \320\240\320\260\320\264\320\276\320\275\320\260", nullptr));
        rotationDegreeLabel->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260:", nullptr));
        rotationPointLabel->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\321\207\320\272\320\260 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260:", nullptr));
        pointCoordsLabel->setText(QCoreApplication::translate("MainWindow", "(null, null)", nullptr));
        rotateButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        rotateNewImage->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\275\320\276\320\262\320\276\320\265 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabRotation), QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
