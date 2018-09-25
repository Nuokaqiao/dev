/********************************************************************************
** Form generated from reading UI file 'resampleinput.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESAMPLEINPUT_H
#define UI_RESAMPLEINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_resampleinput
{
public:

    void setupUi(QDialog *resampleinput)
    {
        if (resampleinput->objectName().isEmpty())
            resampleinput->setObjectName(QStringLiteral("resampleinput"));
        resampleinput->resize(400, 300);

        retranslateUi(resampleinput);

        QMetaObject::connectSlotsByName(resampleinput);
    } // setupUi

    void retranslateUi(QDialog *resampleinput)
    {
        resampleinput->setWindowTitle(QApplication::translate("resampleinput", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class resampleinput: public Ui_resampleinput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESAMPLEINPUT_H
