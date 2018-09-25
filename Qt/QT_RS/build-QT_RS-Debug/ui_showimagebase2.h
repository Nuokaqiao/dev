/********************************************************************************
** Form generated from reading UI file 'showimagebase2.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWIMAGEBASE2_H
#define UI_SHOWIMAGEBASE2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowImageBase2
{
public:

    void setupUi(QWidget *ShowImageBase2)
    {
        if (ShowImageBase2->objectName().isEmpty())
            ShowImageBase2->setObjectName(QStringLiteral("ShowImageBase2"));
        ShowImageBase2->resize(400, 300);

        retranslateUi(ShowImageBase2);

        QMetaObject::connectSlotsByName(ShowImageBase2);
    } // setupUi

    void retranslateUi(QWidget *ShowImageBase2)
    {
        ShowImageBase2->setWindowTitle(QApplication::translate("ShowImageBase2", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowImageBase2: public Ui_ShowImageBase2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWIMAGEBASE2_H
