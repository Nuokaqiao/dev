/********************************************************************************
** Form generated from reading UI file 'displaycontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYCONTROLLER_H
#define UI_DISPLAYCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DisplayController
{
public:

    void setupUi(QWidget *DisplayController)
    {
        if (DisplayController->objectName().isEmpty())
            DisplayController->setObjectName(QStringLiteral("DisplayController"));
        DisplayController->resize(400, 300);

        retranslateUi(DisplayController);

        QMetaObject::connectSlotsByName(DisplayController);
    } // setupUi

    void retranslateUi(QWidget *DisplayController)
    {
        DisplayController->setWindowTitle(QApplication::translate("DisplayController", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DisplayController: public Ui_DisplayController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYCONTROLLER_H
