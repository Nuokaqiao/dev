/********************************************************************************
** Form generated from reading UI file 'mymainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMAINWINDOW_H
#define UI_MYMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMainWindow
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyMainWindow)
    {
        if (MyMainWindow->objectName().isEmpty())
            MyMainWindow->setObjectName(QStringLiteral("MyMainWindow"));
        MyMainWindow->resize(400, 300);
        menuBar = new QMenuBar(MyMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MyMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyMainWindow->addToolBar(mainToolBar);
        centralWidget = new QWidget(MyMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MyMainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MyMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyMainWindow->setStatusBar(statusBar);

        retranslateUi(MyMainWindow);

        QMetaObject::connectSlotsByName(MyMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MyMainWindow)
    {
        MyMainWindow->setWindowTitle(QApplication::translate("MyMainWindow", "MyMainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyMainWindow: public Ui_MyMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMAINWINDOW_H
