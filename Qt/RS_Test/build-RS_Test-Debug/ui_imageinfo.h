/********************************************************************************
** Form generated from reading UI file 'imageinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEINFO_H
#define UI_IMAGEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageInfo
{
public:

    void setupUi(QWidget *ImageInfo)
    {
        if (ImageInfo->objectName().isEmpty())
            ImageInfo->setObjectName(QStringLiteral("ImageInfo"));
        ImageInfo->resize(400, 300);

        retranslateUi(ImageInfo);

        QMetaObject::connectSlotsByName(ImageInfo);
    } // setupUi

    void retranslateUi(QWidget *ImageInfo)
    {
        ImageInfo->setWindowTitle(QApplication::translate("ImageInfo", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageInfo: public Ui_ImageInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEINFO_H
