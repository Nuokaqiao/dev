#include "subsetimage.h"
#include "ui_subsetimage.h"

/*SubsetImage::SubsetImage(QWidget *parent=0):
  ShowImageBase2(parent),
  ui(new Ui::SubsetImage)
{
  ui->setupUi(this);
}
*/
SubsetImage::SubsetImage(QWidget *parent,GDALDataset *p_Dataset):
  ShowImageBase2(parent,p_Dataset),
  ui(new Ui::SubsetImage)
{
  ui->setupUi(this);
  setWindowTitle("SubsetImage");
  nifmouseright=false;
  nifmouseleft=false;
  ReadParam();
  if(nWidthStrictInt==1)
      nWidthStrict=true;
  else
      nWidthStrict=false;
}

SubsetImage::~SubsetImage()
{
  delete ui;
}

void SubsetImage::mousePressEvent(QMouseEvent *event)
{
  QPointF n_Point1;
  n_Point1=mapToScene(event->x(),event->y());
  nMouseClick=QPoint(n_Point1.x(),n_Point1.y());
  //为标记点赋初始值
  nIfMouseClick=true;
  nMouseMoveStart=nMouseClick;
  nMouseMoveEnd=nMouseMoveStart;
  //调用基类的方法。
  ShowImageBase2::mousePressEvent(event);
  //在这个继承类中，我们只处理subsetimg的操作，基本操作在前面的类中完成。
if(event->button() == Qt::RightButton)
    return;

  if(event->modifiers()==Qt::ControlModifier)
  {
      QGraphicsScene *scene=ShowImageBase2::GetScene();
      nRectItem=scene->addRect(nMouseClick.x(),nMouseClick.y(),1,1,QPen(Qt::red));
  }
}

void SubsetImage::mouseMoveEvent(QMouseEvent *event)
{
  if(!nIfMouseClick)
    return;

  ShowImageBase2::mouseMoveEvent(event);

  if(event->button() == Qt::RightButton)
      return;
  if(event->modifiers()!=Qt::ControlModifier)
      return;
  QPointF n_Point1;
  n_Point1=mapToScene(event->x(),event->y());
  nMouseMoveEnd=QPoint(n_Point1.x(),n_Point1.y());

  int n_dx=nMouseMoveEnd.x()-nMouseMoveStart.x();
  int n_dy=nMouseMoveEnd.y()-nMouseMoveStart.y();

  if(n_dx<0||n_dy<0)
    return;
  if(nMouseMoveStart.x()+n_dx>GetImageSize().x())
    return;
  if(nMouseMoveStart.y()+n_dy>GetImageSize().y())
    return;

  int n_Width=nMouseMoveEnd.x()-nMouseClick.x();
  int n_Height=nMouseMoveEnd.y()-nMouseClick.y();
  QGraphicsScene *scene=ShowImageBase2::GetScene();
  scene->removeItem(nRectItem);
  nRectItem=scene->addRect(nMouseClick.x(),nMouseClick.y(),n_Width,n_Height,QPen(Qt::red));
  nMouseMoveStart=nMouseMoveEnd;
}

void SubsetImage::mouseReleaseEvent(QMouseEvent *event)
{
 ShowImageBase2::mouseReleaseEvent(event);
 if(event->button() == Qt::RightButton)
     return;
 if(event->modifiers()!=Qt::ControlModifier)
     return;

 if(!nWidthStrict)
     emit ReportPosition(nMouseClick+ShowImageBase2::GetStartPosition(),nMouseMoveEnd+ShowImageBase2::GetStartPosition());
 else
 {
     emit ReportPosition2(nMouseClick+ShowImageBase2::GetStartPosition(),nWidth,nHeight);
     //在图上画出来
     QGraphicsScene *n_scene=ShowImageBase2::GetScene();
     n_scene->addRect(nMouseClick.x()-nWidth/2,nMouseClick.y()-nHeight/2,nWidth,nHeight,QPen(Qt::red));
 }
 nIfMouseClick=false;
}

void SubsetImage::ReadParam()
{
    std::ifstream n_readfile("Param.ini");
    if(!n_readfile)
        return;

    char ParamDescription[100];
    n_readfile >> ParamDescription;
    n_readfile >> nWidthStrictInt;
    n_readfile >> ParamDescription;
    n_readfile >> nWidth;
    n_readfile >> ParamDescription;
    n_readfile >> nHeight;
}
