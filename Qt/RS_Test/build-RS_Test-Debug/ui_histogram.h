/********************************************************************************
** Form generated from reading UI file 'histogram.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAM_H
#define UI_HISTOGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Histogram
{
public:

    void setupUi(QWidget *Histogram)
    {
        if (Histogram->objectName().isEmpty())
            Histogram->setObjectName(QStringLiteral("Histogram"));
        Histogram->resize(400, 300);

        retranslateUi(Histogram);

        QMetaObject::connectSlotsByName(Histogram);
    } // setupUi

    void retranslateUi(QWidget *Histogram)
    {
        Histogram->setWindowTitle(QApplication::translate("Histogram", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Histogram: public Ui_Histogram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAM_H
