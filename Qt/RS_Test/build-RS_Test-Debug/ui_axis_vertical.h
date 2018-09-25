/********************************************************************************
** Form generated from reading UI file 'axis_vertical.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AXIS_VERTICAL_H
#define UI_AXIS_VERTICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Axis_Vertical
{
public:

    void setupUi(QWidget *Axis_Vertical)
    {
        if (Axis_Vertical->objectName().isEmpty())
            Axis_Vertical->setObjectName(QStringLiteral("Axis_Vertical"));
        Axis_Vertical->resize(400, 300);

        retranslateUi(Axis_Vertical);

        QMetaObject::connectSlotsByName(Axis_Vertical);
    } // setupUi

    void retranslateUi(QWidget *Axis_Vertical)
    {
        Axis_Vertical->setWindowTitle(QApplication::translate("Axis_Vertical", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Axis_Vertical: public Ui_Axis_Vertical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AXIS_VERTICAL_H
