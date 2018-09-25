/********************************************************************************
** Form generated from reading UI file 'mouserect.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOUSERECT_H
#define UI_MOUSERECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_mouserect
{
public:

    void setupUi(QDialog *mouserect)
    {
        if (mouserect->objectName().isEmpty())
            mouserect->setObjectName(QStringLiteral("mouserect"));
        mouserect->resize(400, 300);

        retranslateUi(mouserect);

        QMetaObject::connectSlotsByName(mouserect);
    } // setupUi

    void retranslateUi(QDialog *mouserect)
    {
        mouserect->setWindowTitle(QApplication::translate("mouserect", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mouserect: public Ui_mouserect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOUSERECT_H
