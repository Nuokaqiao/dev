#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QImage>
#include <QtGui/QPixmap>
#include <gdal.h>
#include <gdal_priv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;

#include <cstring>

using namespace std;
#include "ui_histogram.h"

namespace Ui {
class Histogram;
}

class Histogram : public QWidget
{
    Q_OBJECT

public:
    explicit Histogram(QWidget *parent = 0);
    ~Histogram();
    GDALDataset *src;
    void init_combo();

private:
    Ui::Histogram *ui;
    QLabel *hist;
    QLabel *range;
    QImage image;
    QComboBox *box;
    QPushButton *Apply;
    QVBoxLayout *mainlayout;
    QFormLayout *formlayout;

private slots:
    void update_view();
};

#endif // HISTOGRAM_H
