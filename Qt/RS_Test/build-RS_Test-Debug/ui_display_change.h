/********************************************************************************
** Form generated from reading UI file 'display_change.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAY_CHANGE_H
#define UI_DISPLAY_CHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_display_change
{
public:

    void setupUi(QWidget *display_change)
    {
        if (display_change->objectName().isEmpty())
            display_change->setObjectName(QStringLiteral("display_change"));
        display_change->resize(400, 300);

        retranslateUi(display_change);

        QMetaObject::connectSlotsByName(display_change);
    } // setupUi

    void retranslateUi(QWidget *display_change)
    {
        display_change->setWindowTitle(QApplication::translate("display_change", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class display_change: public Ui_display_change {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_CHANGE_H
