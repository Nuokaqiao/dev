/********************************************************************************
** Form generated from reading UI file 'filetoolarge.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILETOOLARGE_H
#define UI_FILETOOLARGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileTooLarge
{
public:

    void setupUi(QWidget *FileTooLarge)
    {
        if (FileTooLarge->objectName().isEmpty())
            FileTooLarge->setObjectName(QStringLiteral("FileTooLarge"));
        FileTooLarge->resize(400, 300);

        retranslateUi(FileTooLarge);

        QMetaObject::connectSlotsByName(FileTooLarge);
    } // setupUi

    void retranslateUi(QWidget *FileTooLarge)
    {
        FileTooLarge->setWindowTitle(QApplication::translate("FileTooLarge", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileTooLarge: public Ui_FileTooLarge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILETOOLARGE_H
