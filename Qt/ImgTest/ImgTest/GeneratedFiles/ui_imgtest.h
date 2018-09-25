/********************************************************************************
** Form generated from reading UI file 'imgtest.ui'
**
** Created: Tue Jul 15 20:13:10 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGTEST_H
#define UI_IMGTEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImgTestClass
{
public:
    QAction *actionImage;
    QAction *actionExit;
    QAction *actionInformation;
    QAction *actionFile_List;
    QAction *actionAbout;
    QAction *actionClose;
    QAction *actionZoom_Out;
    QAction *actionZoom_In;
    QAction *actionFit_Window;
    QAction *actionNormal_Size;
    QWidget *centralWidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *FileListDockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QTreeView *fileTreeView;
    QDockWidget *inforDockWidget;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menuOpen;
    QMenu *menuWindow;
    QMenu *menuAbout;
    QMenu *menuView_Operation;

    void setupUi(QMainWindow *ImgTestClass)
    {
        if (ImgTestClass->objectName().isEmpty())
            ImgTestClass->setObjectName(QString::fromUtf8("ImgTestClass"));
        ImgTestClass->resize(1024, 768);
        ImgTestClass->setStyleSheet(QString::fromUtf8(""));
        actionImage = new QAction(ImgTestClass);
        actionImage->setObjectName(QString::fromUtf8("actionImage"));
        actionExit = new QAction(ImgTestClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionInformation = new QAction(ImgTestClass);
        actionInformation->setObjectName(QString::fromUtf8("actionInformation"));
        actionFile_List = new QAction(ImgTestClass);
        actionFile_List->setObjectName(QString::fromUtf8("actionFile_List"));
        actionAbout = new QAction(ImgTestClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionClose = new QAction(ImgTestClass);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionZoom_Out = new QAction(ImgTestClass);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        actionZoom_In = new QAction(ImgTestClass);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        actionFit_Window = new QAction(ImgTestClass);
        actionFit_Window->setObjectName(QString::fromUtf8("actionFit_Window"));
        actionNormal_Size = new QAction(ImgTestClass);
        actionNormal_Size->setObjectName(QString::fromUtf8("actionNormal_Size"));
        centralWidget = new QWidget(ImgTestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ImgTestClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(ImgTestClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ImgTestClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ImgTestClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ImgTestClass->setStatusBar(statusBar);
        FileListDockWidget = new QDockWidget(ImgTestClass);
        FileListDockWidget->setObjectName(QString::fromUtf8("FileListDockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        fileTreeView = new QTreeView(dockWidgetContents);
        fileTreeView->setObjectName(QString::fromUtf8("fileTreeView"));
        fileTreeView->header()->setVisible(false);

        verticalLayout_2->addWidget(fileTreeView);

        FileListDockWidget->setWidget(dockWidgetContents);
        ImgTestClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), FileListDockWidget);
        inforDockWidget = new QDockWidget(ImgTestClass);
        inforDockWidget->setObjectName(QString::fromUtf8("inforDockWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        verticalLayout = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(dockWidgetContents_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->horizontalHeader()->setVisible(true);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableView);

        inforDockWidget->setWidget(dockWidgetContents_2);
        ImgTestClass->addDockWidget(static_cast<Qt::DockWidgetArea>(2), inforDockWidget);
        menuBar = new QMenuBar(ImgTestClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 23));
        menuOpen = new QMenu(menuBar);
        menuOpen->setObjectName(QString::fromUtf8("menuOpen"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuView_Operation = new QMenu(menuBar);
        menuView_Operation->setObjectName(QString::fromUtf8("menuView_Operation"));
        ImgTestClass->setMenuBar(menuBar);

        mainToolBar->addAction(actionImage);
        mainToolBar->addAction(actionClose);
        mainToolBar->addAction(actionZoom_Out);
        mainToolBar->addAction(actionZoom_In);
        mainToolBar->addAction(actionFit_Window);
        mainToolBar->addAction(actionNormal_Size);
        mainToolBar->addAction(actionAbout);
        menuBar->addAction(menuOpen->menuAction());
        menuBar->addAction(menuView_Operation->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuOpen->addAction(actionImage);
        menuOpen->addAction(actionClose);
        menuOpen->addSeparator();
        menuOpen->addAction(actionExit);
        menuWindow->addAction(actionFile_List);
        menuWindow->addAction(actionInformation);
        menuAbout->addAction(actionAbout);
        menuView_Operation->addAction(actionZoom_Out);
        menuView_Operation->addAction(actionZoom_In);
        menuView_Operation->addAction(actionFit_Window);
        menuView_Operation->addAction(actionNormal_Size);

        retranslateUi(ImgTestClass);

        QMetaObject::connectSlotsByName(ImgTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImgTestClass)
    {
        ImgTestClass->setWindowTitle(QApplication::translate("ImgTestClass", "ImgTest", 0, QApplication::UnicodeUTF8));
        actionImage->setText(QApplication::translate("ImgTestClass", "image", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionImage->setToolTip(QApplication::translate("ImgTestClass", "Open image files", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionImage->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        actionImage->setShortcut(QApplication::translate("ImgTestClass", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("ImgTestClass", "Exit", 0, QApplication::UnicodeUTF8));
        actionInformation->setText(QApplication::translate("ImgTestClass", "Information", 0, QApplication::UnicodeUTF8));
        actionFile_List->setText(QApplication::translate("ImgTestClass", "File List", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("ImgTestClass", "About", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("ImgTestClass", "Close", 0, QApplication::UnicodeUTF8));
        actionZoom_Out->setText(QApplication::translate("ImgTestClass", "Zoom Out", 0, QApplication::UnicodeUTF8));
        actionZoom_In->setText(QApplication::translate("ImgTestClass", "Zoom In", 0, QApplication::UnicodeUTF8));
        actionFit_Window->setText(QApplication::translate("ImgTestClass", "Fit Window", 0, QApplication::UnicodeUTF8));
        actionNormal_Size->setText(QApplication::translate("ImgTestClass", "Normal Size", 0, QApplication::UnicodeUTF8));
        menuOpen->setTitle(QApplication::translate("ImgTestClass", "Open", 0, QApplication::UnicodeUTF8));
        menuWindow->setTitle(QApplication::translate("ImgTestClass", "Window", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("ImgTestClass", "Help", 0, QApplication::UnicodeUTF8));
        menuView_Operation->setTitle(QApplication::translate("ImgTestClass", "View Operation", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImgTestClass: public Ui_ImgTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGTEST_H
