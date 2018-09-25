#include "showimagebase2.h"

ShowImageBase2::ShowImageBase2(QWidget *parent)
  : QGraphicsView(parent)
{
  ui.setupUi(this);
}

ShowImageBase2::~ShowImageBase2()
{

}

ShowImageBase2::ShowImageBase2(QWidget *parent,GDALDataset *p)
  : QGraphicsView(parent)
{
  ui.setupUi(this);
  pDataset=p;
  InitPara();
  CalBoundary();
  scene=new QGraphicsScene;
  setScene(scene);
  setWindowTitle("ImageBase2");
  resize(nShowImageWidth,nShowImageWidth);
}

void ShowImageBase2::CalBoundary()
{
  /* //confirm the starting and ending position of the image
  nPointEndShown.rx()=nPointStartShown.x()+nShowImageWidth;
  nPointEndShown.ry()=nPointStartShown.y()+nShowImageWidth;
  if(pRasterBand->GetXSize()<nPointEndShown.x())
    nPointEndShown.rx()=pRasterBand->GetXSize();
  if(pRasterBand->GetYSize()<nPointEndShown.y())
    nPointEndShown.ry()=pRasterBand->GetYSize();
  */
}

bool ShowImageBase2::CreatQimage(QImage* pimage)
{
  QRgb nPixelValue;
  int n_val1;
  // int n_Width,n_Height;
  //n_Width=nPointEndShown.x()-nPointStartShown.x();
  //n_Height=nPointEndShown.y()-nPointStartShown.y();

  //translate the void type to a int type data
  void *p_Banddata1=malloc(sizeof(nBandType)*nWidth*nHeight);
  pRasterBand->RasterIO(GF_Read,nPointStartShown.x(),nPointStartShown.y(),nWidth,nHeight,p_Banddata1,nWidth,nHeight,nBandType,0,0);
  TransVoidToInt Trans(pRasterBand,p_Banddata1,nBandType);

  for (int i=0;i<nHeight;i++)
    for(int j=0;j<nWidth;j++)
      {
   n_val1=Trans.GetValue(i*nWidth+j);
    nPixelValue=qRgb(n_val1,n_val1,n_val1);
    pimage->setPixel(j,i,nPixelValue);
      }
  delete[] p_Banddata1;
  return true;
}

bool ShowImageBase2::CreatQimageColor(QImage* pimage,void* p_Banddata1,void* p_Banddata2,void* p_Banddata3)
{
  QRgb nPixelValue;
  int nValue1,nValue2,nValue3;
  //translate the void type to a int type data
  TransVoidToInt TransRed(pRasterBandRed,p_Banddata1,nBandType);
  TransVoidToInt TransGreen(pRasterBandGreen,p_Banddata2,nBandType);
  TransVoidToInt TransBlue(pRasterBandBlue,p_Banddata3,nBandType);

   for (int i=0;i<nHeight;i++)
    for(int j=0;j<nWidth;j++)
      {
    nValue1=TransRed.GetValue(i*nWidth+j);
    nValue2=TransGreen.GetValue(i*nWidth+j);
    nValue3=TransBlue.GetValue(i*nWidth+j);
    nPixelValue=qRgb(nValue1,nValue2,nValue3);
    pimage->setPixel(j,i,nPixelValue);
      }
  delete[] p_Banddata1;
  delete[] p_Banddata2;
  delete[] p_Banddata3;
  return true;
}

bool ShowImageBase2::MoveImage(QPoint point,int n_Width,int n_Height)
{
  scene->clear();
  nPointStartShown=point;
  //CalBoundary();
  //  n_Width=nPointEndShown.x()-nPointStartShown.x();
  //n_Height=nPointEndShown.y()-nPointStartShown.y();
  nWidth=n_Width;
  nHeight=n_Height;
  if(showGrayImage)
    {
      //  CheckScalePix(pRasterBand,&dfscale,adfCMinMax);
      QImage *p_image=new QImage(nWidth,nHeight,QImage::Format_RGB888);
      CreatQimage(p_image);

      QGraphicsItem *items=scene->addPixmap(QPixmap::fromImage(*p_image));
      items->setZValue(0);
      items->setPos(0,0);
      delete p_image;
}
 else
   {
     QImage *p_Image=new QImage(n_Width,n_Height,QImage::Format_RGB888);
     void *p_Banddata1=malloc(sizeof(nBandType)*nWidth*nHeight);
     void *p_Banddata2=malloc(sizeof(nBandType)*nWidth*nHeight);
     void *p_Banddata3=malloc(sizeof(nBandType)*nWidth*nHeight);

     pRasterBandRed->RasterIO(GF_Read,nPointStartShown.x(),nPointStartShown.y(),nWidth,nHeight,p_Banddata1,nWidth,nHeight,nBandType,0,0);
     pRasterBandGreen->RasterIO(GF_Read,nPointStartShown.x(),nPointStartShown.y(),nWidth,nHeight,p_Banddata2,nWidth,nHeight,nBandType,0,0);
     pRasterBandBlue->RasterIO(GF_Read,nPointStartShown.x(),nPointStartShown.y(),nWidth,nHeight,p_Banddata3,nWidth,nHeight,nBandType,0,0);

     CreatQimageColor(p_Image,p_Banddata1,p_Banddata2,p_Banddata3);

     QGraphicsItem *items=scene->addPixmap(QPixmap::fromImage(*p_Image));
     items->setZValue(0);
     items->setPos(0,0);
     delete p_Image;
   }
  scene->setSceneRect(0,0,nWidth,nHeight);
  show();
  return true;
}

bool ShowImageBase2::InitPara()
{
  //init the nPointStartOv;
  nPointStartShown.rx()=0;
  nPointStartShown.ry()=0;

  pRasterBand=pDataset->GetRasterBand(1);
  nBandType=pRasterBand->GetRasterDataType();
  showGrayImage=true;

  //adjust position of widget;
  QDesktopWidget desktopwidg;
  const QRect screen=desktopwidg.screenGeometry(-1);
  move(screen.x()+10,screen.y()+10);

  bool nifmouseright=false;
  bool nifmouseleft=false;
  return true;
}


void ShowImageBase2::wheelEvent(QWheelEvent *event)
{
  if (event->delta()<0)
    scale(0.8,0.8);
  else
    scale(1.2,1.2);
}

void ShowImageBase2::mousePressEvent(QMouseEvent *event)
{
  QPointF p;
  p=mapToScene(event->x(),event->y());
  p1.rx()=p.x();
  p1.ry()=p.y();

  if (event->button() == Qt::RightButton)
    {
      nPan= true;
      nPanStartX = event->x();
      nPanStartY = event->y();
      setCursor(Qt::ClosedHandCursor);
      event->accept();
      return;
    }
  event->ignore();

}

void ShowImageBase2::mouseMoveEvent(QMouseEvent *event)
{
  QPointF p;
  p=mapToScene(event->x(),event->y());
  p2.rx()=p.x();
  p2.ry()=p.y();
  int dx,dy;
  dx=p2.x()-p1.x();
  dy=p2.y()-p1.y();
  p1=p2;

  if (nPan)
    {
     horizontalScrollBar()->setValue(horizontalScrollBar()->value() - (event->x() - nPanStartX));
      verticalScrollBar()->setValue(verticalScrollBar()->value() - (event->y() - nPanStartY));
      nPanStartX = event->x();
      nPanStartY = event->y();
      event->accept();
      return;
    }
  event->ignore();
}

void ShowImageBase2::mouseReleaseEvent(QMouseEvent *event)
{
if (event->button() == Qt::RightButton)
    {
        nPan = false;
        setCursor(Qt::ArrowCursor);
        event->accept();
        return;
    }
    event->ignore();
}

void ShowImageBase2::GetRasterband(int *nRGBofBasetemp)
{
  showGrayImage=false;

  nRGBofBase[0]=nRGBofBasetemp[0];
  nRGBofBase[1]=nRGBofBasetemp[1];
  nRGBofBase[2]=nRGBofBasetemp[2];

  pRasterBandRed=pDataset->GetRasterBand(nRGBofBase[0]);
  pRasterBandGreen=pDataset->GetRasterBand(nRGBofBase[1]);
  pRasterBandBlue=pDataset->GetRasterBand(nRGBofBase[2]);
}

QPoint ShowImageBase2::GetImageSize()
{
  return QPoint(nWidth,nHeight);
}

QGraphicsScene* ShowImageBase2::GetScene()
{
  return scene;
}

QPoint ShowImageBase2::GetStartPosition()
{
    return nPointStartShown;
}
