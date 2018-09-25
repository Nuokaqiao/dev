/********************************************************************************
** Form generated from reading UI file 'uiimgtest.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIIMGTEST_H
#define UI_UIIMGTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UIImgTest
{
public:
    QAction *actionImage;
    QAction *actionClose;
    QAction *actionExit;
    QAction *actionZoom_Out;
    QAction *actionZoom_Int;
    QAction *actionFit_Window;
    QAction *actionNormal_Size;
    QAction *actionFile_List;
    QAction *actionInformation;
    QAction *actionAbout;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuOpen;
    QMenu *menuView_Operation;
    QMenu *menuWindow;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *FileListDockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QTreeView *fileTreeView;
    QDockWidget *infoDockWidget;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QTreeView *tableView;

    void setupUi(QMainWindow *UIImgTest)
    {
        if (UIImgTest->objectName().isEmpty())
            UIImgTest->setObjectName(QStringLiteral("UIImgTest"));
        UIImgTest->resize(1024, 768);
        actionImage = new QAction(UIImgTest);
        actionImage->setObjectName(QStringLiteral("actionImage"));
        actionClose = new QAction(UIImgTest);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionExit = new QAction(UIImgTest);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionZoom_Out = new QAction(UIImgTest);
        actionZoom_Out->setObjectName(QStringLiteral("actionZoom_Out"));
        actionZoom_Int = new QAction(UIImgTest);
        actionZoom_Int->setObjectName(QStringLiteral("actionZoom_Int"));
        actionFit_Window = new QAction(UIImgTest);
        actionFit_Window->setObjectName(QStringLiteral("actionFit_Window"));
        actionNormal_Size = new QAction(UIImgTest);
        actionNormal_Size->setObjectName(QStringLiteral("actionNormal_Size"));
        actionFile_List = new QAction(UIImgTest);
        actionFile_List->setObjectName(QStringLiteral("actionFile_List"));
        actionInformation = new QAction(UIImgTest);
        actionInformation->setObjectName(QStringLiteral("actionInformation"));
        actionAbout = new QAction(UIImgTest);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(UIImgTest);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        UIImgTest->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UIImgTest);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 28));
        menuOpen = new QMenu(menuBar);
        menuOpen->setObjectName(QStringLiteral("menuOpen"));
        menuView_Operation = new QMenu(menuBar);
        menuView_Operation->setObjectName(QStringLiteral("menuView_Operation"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        UIImgTest->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UIImgTest);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        UIImgTest->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(UIImgTest);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        UIImgTest->setStatusBar(statusBar);
        FileListDockWidget = new QDockWidget(UIImgTest);
        FileListDockWidget->setObjectName(QStringLiteral("FileListDockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        fileTreeView = new QTreeView(dockWidgetContents);
        fileTreeView->setObjectName(QStringLiteral("fileTreeView"));

        verticalLayout->addWidget(fileTreeView);

        FileListDockWidget->setWidget(dockWidgetContents);
        UIImgTest->addDockWidget(static_cast<Qt::DockWidgetArea>(1), FileListDockWidget);
        infoDockWidget = new QDockWidget(UIImgTest);
        infoDockWidget->setObjectName(QStringLiteral("infoDockWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableView = new QTreeView(dockWidgetContents_2);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_2->addWidget(tableView);

        infoDockWidget->setWidget(dockWidgetContents_2);
        UIImgTest->addDockWidget(static_cast<Qt::DockWidgetArea>(2), infoDockWidget);

        menuBar->addAction(menuOpen->menuAction());
        menuBar->addAction(menuView_Operation->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuOpen->addAction(actionImage);
        menuOpen->addAction(actionClose);
        menuOpen->addAction(actionExit);
        menuView_Operation->addAction(actionZoom_Out);
        menuView_Operation->addAction(actionZoom_Int);
        menuView_Operation->addAction(actionFit_Window);
        menuView_Operation->addAction(actionNormal_Size);
        menuWindow->addAction(actionFile_List);
        menuWindow->addAction(actionInformation);
        menuHelp->addAction(actionAbout);

        retranslateUi(UIImgTest);

        QMetaObject::connectSlotsByName(UIImgTest);
    } // setupUi

    void retranslateUi(QMainWindow *UIImgTest)
    {
        UIImgTest->setWindowTitle(QApplication::translate("UIImgTest", "UIImgTest", nullptr));
        actionImage->setText(QApplication::translate("UIImgTest", "Image", nullptr));
        actionClose->setText(QApplication::translate("UIImgTest", "Close", nullptr));
        actionExit->setText(QApplication::translate("UIImgTest", "Exit", nullptr));
        actionZoom_Out->setText(QApplication::translate("UIImgTest", "Zoom Out", nullptr));
        actionZoom_Int->setText(QApplication::translate("UIImgTest", "Zoom Int", nullptr));
        actionFit_Window->setText(QApplication::translate("UIImgTest", "Fit Window", nullptr));
        actionNormal_Size->setText(QApplication::translate("UIImgTest", "Normal Size", nullptr));
        actionFile_List->setText(QApplication::translate("UIImgTest", "File List", nullptr));
        actionInformation->setText(QApplication::translate("UIImgTest", "Information", nullptr));
        actionAbout->setText(QApplication::translate("UIImgTest", "About", nullptr));
        menuOpen->setTitle(QApplication::translate("UIImgTest", "Open", nullptr));
        menuView_Operation->setTitle(QApplication::translate("UIImgTest", "View Operation", nullptr));
        menuWindow->setTitle(QApplication::translate("UIImgTest", "Window", nullptr));
        menuHelp->setTitle(QApplication::translate("UIImgTest", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UIImgTest: public Ui_UIImgTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIIMGTEST_H
