/********************************************************************************
** Form generated from reading UI file 'rs_demo_gdal.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RS_DEMO_GDAL_H
#define UI_RS_DEMO_GDAL_H

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

class Ui_RS_DEMO_GDAL
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RS_DEMO_GDAL)
    {
        if (RS_DEMO_GDAL->objectName().isEmpty())
            RS_DEMO_GDAL->setObjectName(QStringLiteral("RS_DEMO_GDAL"));
        RS_DEMO_GDAL->resize(400, 300);
        menuBar = new QMenuBar(RS_DEMO_GDAL);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        RS_DEMO_GDAL->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RS_DEMO_GDAL);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RS_DEMO_GDAL->addToolBar(mainToolBar);
        centralWidget = new QWidget(RS_DEMO_GDAL);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        RS_DEMO_GDAL->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(RS_DEMO_GDAL);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RS_DEMO_GDAL->setStatusBar(statusBar);

        retranslateUi(RS_DEMO_GDAL);

        QMetaObject::connectSlotsByName(RS_DEMO_GDAL);
    } // setupUi

    void retranslateUi(QMainWindow *RS_DEMO_GDAL)
    {
        RS_DEMO_GDAL->setWindowTitle(QApplication::translate("RS_DEMO_GDAL", "RS_DEMO_GDAL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RS_DEMO_GDAL: public Ui_RS_DEMO_GDAL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RS_DEMO_GDAL_H
