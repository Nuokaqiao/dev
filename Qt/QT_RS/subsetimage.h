#ifndef SUBSETIMAGE_H
#define SUBSETIMAGE_H

#include <QWidget>
#include <QPoint>
#include <QGraphicsRectItem>
#include <gdal.h>
#include <gdal_priv.h>
#include <fstream>
#include "showimagebase2.h"

namespace Ui {
  class SubsetImage;
}

class SubsetImage: public ShowImageBase2
{
  Q_OBJECT

  public:
  //explicit SubsetImage(QWidget *parent = 0);
  SubsetImage(QWidget *parent,GDALDataset*);
  ~SubsetImage();

private:
  Ui::SubsetImage *ui;
  QPoint nMouseClick,nMouseMoveStart,nMouseMoveEnd;
  bool nIfMouseClick;
  bool nifmouseright;
  bool nifmouseleft;
  bool nWidthStrict;//子图像是否限制大小。
  int nWidthStrictInt,nWidth,nHeight;//如果限制图像，则其大小。
  QGraphicsRectItem *nRectItem;

public:
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
  void ReadParam();
signals:
  void ReportPosition(QPoint,QPoint);//第一个点为子图像的在原图像上的起始点。第二个点存储了其终止点。
  void ReportPosition2(QPoint,int,int);//子图像在原图像上的起始点
};

#endif
