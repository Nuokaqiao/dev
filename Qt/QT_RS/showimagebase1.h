#ifndef SHOWIMAGEBASE1_H
#define SHOWIMAGEBASE1_H


#include <QGraphicsView>
#include <QImage>
#include <QMouseEvent>
#include <QPoint>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QWheelEvent>
#include <QPainter>
#include <QPen>
#include <QDesktopWidget>
#include <QRect>
#include <gdal.h>
#include <gdal_priv.h>
#include <math.h>
//#include "ui_showimagebase1.h"
#include "showimagebase2.h"
#include "transvoidtoint.h"

#define nShowImageWidth 700

class ShowImageBase1 : public QGraphicsView
{
  Q_OBJECT

    public:
  ShowImageBase1(QWidget *parent = 0);
  ShowImageBase1(QWidget *,GDALDataset*);
  ~ShowImageBase1();

 private:
  Ui::ShowImageBase1 ui;

 public:
  QImage *pImageBase1;
  QPoint nPointMouseClick,nPointMouseRelease,nPointDoubleClick,nPointLeftClickDown,nPointLeftClickRelease,nPointMouseMove1,nPointMouseMove2,nPointStartRect; //mouse position;
  QGraphicsRectItem *nRectItem; //红十字丝，表示要放大显示的范围。应该支持拉伸和缩小。
  QGraphicsScene *scene;

  GDALDataset* pDataset;
  GDALRasterBand *pRasterBand,*pRasterBandRed,*pRasterBandGreen,*pRasterBandBlue;
  GDALDataType nBandType;

  int nWidth,nHeight;
  int  nRectHeight,nRectWidth;
  bool nMousePressed,nMouseRealsed;
  bool bImageColor;//flags for the gray and color image;
  double adfCMinMax[2],adfCMinMaxRed[2],adfCMinMaxGreen[2],adfCMinMaxBlue[2];
  double dfscale,dfRedScale,dfGreenScale,dfBlueScale;
  double nScaleFactorWidth,nScaleFactorHeight;//the rect width and the shown image width;
  int nRGBofBase[3];

 public:
  bool ShowOverviewGray();//show gray image;
  bool ShowOverviewColor(int *);//show color image;
  bool CreatQimage(QImage*);
  bool CreatQimageColor(QImage*);
  bool CalRectWidth();
  QPoint TransOvToSrcPos(QPoint);

  public slots:
  void mousePressEvent(QMouseEvent *);
  void mouseMoveEvent(QMouseEvent *);
  void mouseReleaseEvent(QMouseEvent *);
  void wheelEvent(QWheelEvent *event);

 signals:
  void ReportPosition(QPoint,int,int);//第一个点表示要显示区域的左上角。第二个点存储的是显示长和宽。
};
#endif // SHOWIMAGEBASE1
