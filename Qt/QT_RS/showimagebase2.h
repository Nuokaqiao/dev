#ifndef SHOWIMAGEBASE2_H
#define SHOWIMAGEBASE2_H

#include <QImage>
#include <QMouseEvent>
#include <QPoint>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QWheelEvent>
#include <QGraphicsLineItem>
#include <QDesktopWidget>
#include <QRect>
#include <QScrollBar>
#include <gdal.h>
#include <gdal_priv.h>
#include <math.h>
#include <stdint.h>
#include "ui_showimagebase2.h"
#include "transvoidtoint.h"

#define nShowImageWidth 700

class ShowImageBase2 : public QGraphicsView
{
    Q_OBJECT

public:
    ShowImageBase2(QWidget *parent = 0);
    ShowImageBase2(QWidget *parent,GDALDataset*);//Add three parameters to specific dataset,overview and sizeof overview rubber;
    ~ShowImageBase2();

private:
    Ui::ShowImageBase2 ui;

private:
    GDALDataset* pDataset;
    GDALRasterBand *pRasterBand,*pRasterBandRed,*pRasterBandGreen,*pRasterBandBlue;
    GDALDataType nBandType;

    QPoint nPointStartShown,nPointEndShown,nPointBase;
    QPoint p1,p2;
    QGraphicsScene *scene;
    QGraphicsView *view;

    double adfCMinMax[2],adfCMinMaxRed[2],adfCMinMaxGreen[2],adfCMinMaxBlue[2];
    double dfscale,dfRedScale,dfGreenScale,dfBlueScale;
    int nRGBofBase[3];
    bool showGrayImage;

    int nHeight,nWidth;//显示图像的长宽。

    bool nPan;
    int nPanStartX,nPanStartY;

public:
    void CalBoundary();
    bool CreatQimage(QImage*);
    bool CreatQimageColor(QImage*,void*,void*,void*);
    bool MoveImageColor(QPoint);
    bool InitPara();// Create enough labels to contain qimages.
    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void GetRasterband(int *);
    QPoint GetImageSize();
    QGraphicsScene* GetScene();
    QPoint GetStartPosition();

 public slots:
    bool MoveImage(QPoint,int,int);
};

#endif // SHOWIMAGEBASE2_H
