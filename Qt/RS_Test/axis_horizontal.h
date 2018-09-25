#ifndef AXIS_HORIZONTAL_H
#define AXIS_HORIZONTAL_H

#include <QWidget>
#include <QPainter>
#include <iostream>
#include "ui_axis_horizontal.h"

#include <gdal.h>
#include <gdal_priv.h>
#include <ogr_spatialref.h>
#include "ogrsf_frmts.h"
#include "ogr_srs_api.h"
#include "ogr_api.h"
#include "proj_api.h"

namespace Ui {
class Axis_Horizontal;
}

class Axis_Horizontal : public QWidget
{
    Q_OBJECT

public:
    explicit Axis_Horizontal(QWidget *parent = 0);
    ~Axis_Horizontal();
    int startposition[2] = { 0,0 };
    int settings[2] = {100,10};//[pixceldiff,distance per pixceldiff]
    int size[2] = {25,100};//height,width
    GDALDataset *src;
    double ratio = 1;

private:
    Ui::Axis_Horizontal *ui;
    int getGISinfo(double * dst);

protected:
    void paintEvent(QPaintEvent *);
    // void resizeEvent(QResizeEvent *);
};

#endif // AXIS_HORIZONTAL_H
