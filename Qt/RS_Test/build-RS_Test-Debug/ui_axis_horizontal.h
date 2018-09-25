/********************************************************************************
** Form generated from reading UI file 'axis_horizontal.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AXIS_HORIZONTAL_H
#define UI_AXIS_HORIZONTAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Axis_Horizontal
{
public:

    void setupUi(QWidget *Axis_Horizontal)
    {
        if (Axis_Horizontal->objectName().isEmpty())
            Axis_Horizontal->setObjectName(QStringLiteral("Axis_Horizontal"));
        Axis_Horizontal->resize(400, 300);

        retranslateUi(Axis_Horizontal);

        QMetaObject::connectSlotsByName(Axis_Horizontal);
    } // setupUi

    void retranslateUi(QWidget *Axis_Horizontal)
    {
        Axis_Horizontal->setWindowTitle(QApplication::translate("Axis_Horizontal", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Axis_Horizontal: public Ui_Axis_Horizontal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AXIS_HORIZONTAL_H
