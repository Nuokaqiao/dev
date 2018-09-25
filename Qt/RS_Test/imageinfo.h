#ifndef IMAGEINFO_H
#define IMAGEINFO_H

#include <QWidget>
#include "ui_imageinfo.h"
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>

namespace Ui {
class ImageInfo;
}

class ImageInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ImageInfo(QWidget *parent = 0);
    ~ImageInfo();
    QLabel *imagetype;
    QLabel *xsize;
    QLabel *ysize;
    QLabel *bands;
    QLabel *datatype;

private:
    Ui::ImageInfo *ui;
    QScrollArea *area;
    QVBoxLayout *layout;
    QFormLayout *form;
};

#endif // IMAGEINFO_H
