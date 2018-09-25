/********************************************************************************
** Form generated from reading UI file 'rsinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RSINFO_H
#define UI_RSINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RSInfo
{
public:

    void setupUi(QWidget *RSInfo)
    {
        if (RSInfo->objectName().isEmpty())
            RSInfo->setObjectName(QStringLiteral("RSInfo"));
        RSInfo->resize(400, 300);

        retranslateUi(RSInfo);

        QMetaObject::connectSlotsByName(RSInfo);
    } // setupUi

    void retranslateUi(QWidget *RSInfo)
    {
        RSInfo->setWindowTitle(QApplication::translate("RSInfo", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RSInfo: public Ui_RSInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RSINFO_H
