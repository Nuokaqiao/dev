#ifndef DISPLAY_CHANGE_H
#define DISPLAY_CHANGE_H

#include <QWidget>

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QErrorMessage>
#include <QMessageBox>
#include <QImage>
#include <QtGui/QPixmap>
#include <gdal.h>
#include <gdal_priv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;

#include <cstring>

using namespace std;

#include "ui_display_change.h"

namespace Ui {
class display_change;
}

class display_change : public QWidget
{
    Q_OBJECT

public:
    explicit display_change(QWidget *parent = 0);
    ~display_change();
    /*Mat change;
    void display_image();*/
    void init_set();
    void lrr(Mat X, double lambda, Mat *Z, Mat *E);
    void solve_l1l2(Mat W, double lambda, Mat *E);
    void solve_l2(Mat w, double lambda, Mat *x);
    void F_lrr_2_origin(Mat Inimg1, Mat Inimg2, double lambda, Mat *Y1, Mat *Y2, Mat *Y3, Mat *Y4);
    void F_lrr_4_origin(Mat Inimg1, Mat Inimg2, Mat Inimg3, Mat Inimg4, double lambda, Mat *Y1, Mat *Y2, Mat *Y3, Mat *Y4, Mat *Y5, Mat *Y6, Mat *Y7, Mat *Y8);
    void F_GY(Mat IN, Mat *OUT);
    void F_kmeans(Mat IN, Mat *OUT);
    GDALDataset *src1;
    GDALDataset *src2;
    Mat OUT;
    int XSize, YSize;

private:
    Ui::display_change *ui;
    QLabel *dischange;
    QImage img;
    QComboBox *box;
    QPushButton *Apply;
    QFormLayout *formlayout;
    QVBoxLayout *mainlayout;
    QErrorMessage *error;

private slots:
    void update_view();
};


#endif // DISPLAY_CHANGE_H
