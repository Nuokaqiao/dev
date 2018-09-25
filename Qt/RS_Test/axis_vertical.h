#ifndef AXIS_VERTICAL_H
#define AXIS_VERTICAL_H

#include <QWidget>
#include <QPainter>
#include <iostream>
#include "ui_axis_vertical.h"

#include <gdal.h>
#include <gdal_priv.h>
#include <ogr_spatialref.h>
#include "ogrsf_frmts.h"
#include "ogr_srs_api.h"
#include "ogr_api.h"
#include "proj_api.h"

#include <iostream>

namespace Ui {
class Axis_Vertical;
}

class Axis_Vertical : public QWidget
{
    Q_OBJECT

public:
    explicit Axis_Vertical(QWidget *parent = 0);
    ~Axis_Vertical();
    int startposition[2] = { 0,0 };
    int settings[2] = { 100,10 };//[pixceldiff,distance per pixceldiff]
    int size[2] = { 30,100 };//height,width
    GDALDataset *src;
    double ratio = 1;

private:
    Ui::Axis_Vertical *ui;
    int getGISinfo(double * dst);

protected:
    void paintEvent(QPaintEvent *);
};

#endif // AXIS_VERTICAL_H
