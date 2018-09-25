#include "mymainwindow.h"
#include "ui_mymainwindow.h"

MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    InitUI();
    adjustSize();
    ncountoutput=1;

    pBaseFileDataset=NULL;

    connect(pushButtonLoadImage,SIGNAL(clicked()),this,SLOT(slotAddImage()));
    connect(treeWidget,SIGNAL(itemClicked(QTreeWidgetItem *, int )),this,SLOT(slotTreeClicked(QTreeWidgetItem *, int)));
    connect(radioButtonGray,SIGNAL(clicked()),this,SLOT(slotRadioGrayClicked()));
    connect(radioButtonRgb,SIGNAL(clicked()),this,SLOT(slotRadioColorClicked()));
    connect(treeWidget,SIGNAL(itemDoubleClicked(QTreeWidgetItem *, int)),this,SLOT(slotTreeDoubleClicked(QTreeWidgetItem*,int)));
    connect(pushButtonCancel,SIGNAL(clicked()),this,SLOT(close()));
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

void MyMainWindow::slotActionOpenBaseFile()
{
  //open file dialog to choose base file
  if (pBaseFileDataset)
    return;
  mBaseFileName= QFileDialog::getOpenFileName(this, tr("Open File"),
                          "/home");

  GDALAllRegister();

  pBaseFileDataset=(GDALDataset *)GDALOpen(mBaseFileName.toStdString().data(),GA_ReadOnly);

  if (pBaseFileDataset==NULL)
    return;

  if(!CheckOverView(pBaseFileDataset))
    return;

  GetBaseFileMapinfo(mBaseFileName);

  pShowimagebaseUI1=new ShowImageBase1(0,pBaseFileDataset);
  pShowSubsetUI=new SubsetImage(0,pBaseFileDataset);

  connect(this,SIGNAL(ReportCloseWindows()),pShowimagebaseUI1,SLOT(close()));
  connect(this,SIGNAL(ReportCloseWindows()),pShowSubsetUI,SLOT(close()));
  connect(pShowimagebaseUI1,SIGNAL(ReportPosition(QPoint,int,int)),pShowSubsetUI,SLOT(MoveImage(QPoint,int,int)));
  connect(pShowSubsetUI,SIGNAL(ReportPosition(QPoint,QPoint)),this,SLOT(GetPosition(QPoint,QPoint)));
  connect(pShowSubsetUI,SIGNAL(ReportPosition2(QPoint,int,int)),this,SLOT(GetPosition2(QPoint,int,int)));
}

bool MyMainWindow::GetBaseFileMapinfo(QString filename)
{
  //to get image infomation. flag 1 is base image and 2 warp image
  treeBaseItem->setText(0,filename);
  int n=pBaseFileDataset->GetRasterCount();
  //to construct n treewidgetiterm
  QList<QTreeWidgetItem *> items;
  QTreeWidgetItem *p;
  GDALRasterBand *poBand;
  for (int i = 0; i < n; ++i)
    {
      p=new QTreeWidgetItem();
      //get raster band information；
      poBand=pBaseFileDataset->GetRasterBand(i+1);
      char *poBandDescription=new char[100];
      const char* ptemp=poBand->GetDescription();
      strcpy(poBandDescription,ptemp);
      QString poDes=QString(QLatin1String(poBandDescription));
      p->setText(0,poDes);
      if (sizeof(*ptemp)<2)
    p->setText(0,QString("layer %0").arg(i+1));
      items.append(p);
      treeBaseLayerItem.append(p);
      delete[] poBandDescription;
    }

  //get the width and height of the image;
nWidth=poBand->GetXSize();
nHeight=poBand->GetYSize();

  p=new QTreeWidgetItem();
  QString str="Map Info";
  p->setText(0,str);
  items.append(p);
  treeBaseItem->insertChildren(0,items);

  items.clear();
  //to get projection
  const char* strchr=pBaseFileDataset->GetProjectionRef();
  char* strchr1=new char[100];
  memcpy(strchr1,strchr,100);
  QTreeWidgetItem *q=new QTreeWidgetItem();
  QString poDes2=QString(QLatin1String(strchr1));
  q->setText(0,poDes2);
  items.append(q);
  treeBaseMapinfoItem=q;
  delete[] strchr1;

  double adfGeoTransform[6];
  pBaseFileDataset->GetGeoTransform( adfGeoTransform );
  strchr1=new char[100];
  sprintf(strchr1,"Pixel: %f",adfGeoTransform[1]);
  QString poDes3=QString(QLatin1String(strchr1));
  q=new QTreeWidgetItem();
  q->setText(0,poDes3);
  items.append(q);
  delete[] strchr1;

  strchr1=new char[100];
  sprintf(strchr1,"UL X: %.2f",adfGeoTransform[0]);
  QString poDes4=QString(QLatin1String(strchr1));
  q=new QTreeWidgetItem();
  q->setText(0,poDes4);
  items.append(q);
  delete[] strchr1;

  strchr1=new char[100];
  sprintf(strchr1,"UL Y: %.2f",adfGeoTransform[3]);
  QString poDes5=QString(QLatin1String(strchr1));
  q=new QTreeWidgetItem();
  q->setText(0,poDes5);
  items.append(q);
  delete[] strchr1;

  p->insertChildren(0,items);
  return true;
}

bool MyMainWindow::ShowGrayImage()
{
  //firstly show a gray image: base image ;
  //check if the file has been selected;
  if (treeBaseItem==treeWidget->currentItem())
    {
      //to show base image in gray;
      //firstly, show overview, creat a qimage;
//      pShowimagebaseUI1->ShowOverviewGray();
      ncountoutput=1;
    }
  return true;
}

bool MyMainWindow::ShowColorImage()
{
  if (treeBaseItem==treeWidget->currentItem())
    {
      //to show base image in gray;
      //firstly, show overview, creat a qimage;
      pShowimagebaseUI1->ShowOverviewColor(nRGBofBase);
      pShowSubsetUI->GetRasterband(nRGBofBase);
      ncountoutput=1;
    }
  return true;
}

void MyMainWindow::slotAddImage()
{
  if (radioButtonGray->isChecked())
    ShowGrayImage();
  if (radioButtonRgb->isChecked())
    ShowColorImage();
}

bool MyMainWindow::InitUI()
{
  QWidget *centwig=new QWidget;
  setCentralWidget(centwig);
  //	centwig->resize(50,100);
  treeWidget=new QTreeWidget();
  treeWidget->setHeaderLabel(tr("Image Info"));
  treeWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
  treeBaseItem=new QTreeWidgetItem(treeWidget);

  groupBox=new QGroupBox;
  groupBox->setTitle("Style");
  radioButtonGray=new QRadioButton("Gray");
  radioButtonRgb=new QRadioButton("Color");
  QHBoxLayout *layout3=new QHBoxLayout;
  layout3->addWidget(radioButtonGray);
  layout3->addWidget(radioButtonRgb);
  groupBox->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::MinimumExpanding);
  groupBox->setLayout(layout3);

  groupBox_2=new QGroupBox;
  radioButtonRed=new QRadioButton("Red");
  radioButtonGreen=new QRadioButton("Green");
  radioButtonBlue=new QRadioButton("Blue");
  lineEditRed=new QLineEdit;
  lineEditGreen=new QLineEdit;
  lineEditBlue=new QLineEdit;
  groupBox_2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::MinimumExpanding);
  QGridLayout *layout1=new QGridLayout(groupBox_2);
  layout1->addWidget(radioButtonRed,0,0);
  layout1->addWidget(radioButtonGreen,1,0);
  layout1->addWidget(radioButtonBlue,2,0);
  layout1->addWidget(lineEditRed,0,1);
  layout1->addWidget(lineEditGreen,1,1);
  layout1->addWidget(lineEditBlue,2,1);

  QHBoxLayout *layout2=new QHBoxLayout;
  pushButtonCancel=new QPushButton;
  pushButtonCancel->setText(tr("Cancel"));
  pushButtonLoadImage=new QPushButton;
  pushButtonLoadImage->setText("LoadImage");
  layout2->addWidget(pushButtonLoadImage);
  layout2->addWidget(pushButtonCancel);

  layoutMain=new QVBoxLayout;
  layoutMain->addWidget(treeWidget);
  layoutMain->addWidget(groupBox);
  layoutMain->addWidget(groupBox_2);
  layoutMain->addLayout(layout2);

  centwig->setLayout(layoutMain);

  QDesktopWidget desktopwidg;
  const QRect screen=desktopwidg.screenGeometry(-1);
  move(screen.width()/2-200,screen.y());
  return true;
}

void MyMainWindow::slotTreeClicked( QTreeWidgetItem * item, int column )
{
  //the number of selected raster band;
  for (int i=0;i<treeBaseLayerItem.count();i++)
    {
      if (treeBaseLayerItem.at(i)==treeWidget->currentItem())
    {
      //get the number of raster band;
      if(radioButtonRed->isChecked())
        {
          nRGBofBase[0]=i+1;
          radioButtonGreen->setChecked(true);
          lineEditRed->setText(QString("Layer %0").arg(i+1));
          break;
        }
      if (radioButtonGreen->isChecked())
        {
          nRGBofBase[1]=i+1;
          radioButtonBlue->setChecked(true);
          lineEditGreen->setText(QString("Layer %0").arg(i+1));
          break;
        }
      if (radioButtonBlue->isChecked())
        {
          nRGBofBase[2]=i+1;
          radioButtonRed->setChecked(true);
          lineEditBlue->setText(QString("Layer %0").arg(i+1));
          break;
        }
    }
    }

}

void MyMainWindow::slotRadioGrayClicked()
{
  groupBox_2->setDisabled(true);
}

void MyMainWindow::slotRadioColorClicked()
{
  groupBox_2->setEnabled(true);
  radioButtonRed->setChecked(true);
}

bool MyMainWindow::CheckOverView(GDALDataset*pDataset)
{
  GDALRasterBand *pband=pDataset->GetRasterBand(1);
  int n=pband->GetOverviewCount();
  if (n==0)
    {
      BuildOverView(pDataset);
      QMessageBox w;
      w.setText("build over view for the image,please reopen it!");
      return false;
    }
  return true;
}

bool MyMainWindow::BuildOverView(GDALDataset* poDataset)
{
  //abc.tif 2 4 8 16
  const char * pszResampling = "nearest";
  int          anLevels[1024];
  int          nLevelCount = 0;
  anLevels[nLevelCount++]=2;
  anLevels[nLevelCount++]=4;
  anLevels[nLevelCount++]=8;
  anLevels[nLevelCount++]=16;

  poDataset->BuildOverviews( pszResampling,
                 nLevelCount, anLevels, 0, NULL,
                 GDALTermProgress, NULL );

  return true;
}

void MyMainWindow::closeEvent(QCloseEvent *event)
{
  qApp->exit();
}

void MyMainWindow::GetPosition(QPoint n_pt1, QPoint n_pt2)
{
   QPoint n_PointOff=n_pt1;
   QPoint n_PointSize=n_pt2-n_pt1;
   if(!CheckBoundary(n_pt1))
       return;
   if(!CheckBoundary(n_pt2))
       return;
   char* argv=new char[1024];
   char* n_strfileout=new char[1024];
   sprintf(n_strfileout,"output/%d.tif",ncountoutput++);
   sprintf(argv,"gdal_translate -srcwin %d %d %d %d %s %s",
           n_PointOff.x(),n_PointOff.y(),n_PointSize.x(),n_PointSize.y(),mBaseFileName.toStdString().data(),n_strfileout);
 /*  for(int i=0;i<8;i++)
       argv[i]=new char[500];
   sprintf(argv[0],"gdal_translate");
   sprintf(argv[1],"-srcwin");

   sprintf(argv[2],"%d",n_PointOff.x());
   sprintf(argv[3],"%d",n_PointOff.y());
   sprintf(argv[4],"%d",n_PointSize.x());
   sprintf(argv[5],"%d",n_PointSize.y());

   sprintf(argv[6],"%s",mBaseFileName.toStdString().data());
   sprintf(argv[7],"output.tif");
   system("")
   ProxyMain(8,argv);*/

   const char* mycommand=(const char*)argv;
   system(mycommand);
//   QMessageBox w;
//   w.setText("subset image stored in the program file directory! please check!");
 //  w.exec();
}

void MyMainWindow::GetPosition2(QPoint n_pt1,int n_width, int n_height)
{
QPoint n_PointOff=n_pt1-QPoint(n_width/2,n_height/2);
QPoint n_pt2=QPoint(n_width,n_height)+n_PointOff;
if(!CheckBoundary(n_PointOff))
return;
if(!CheckBoundary(n_pt2))
return;
QPoint n_PointSize(n_width,n_height);
char* argv=new char[1024];
char* n_strfileout=new char[1024];
sprintf(n_strfileout,"output/%d.tif",ncountoutput++);
sprintf(argv,"gdal_translate -srcwin %d %d %d %d %s %s",
        n_PointOff.x(),n_PointOff.y(),n_PointSize.x(),n_PointSize.y(),mBaseFileName.toStdString().data(),n_strfileout);

const char* mycommand=(const char*)argv;
system(mycommand);
}

bool MyMainWindow::CheckBoundary(QPoint n_pt)
{
    if(n_pt.x()<0)
        return false;
    if(n_pt.y()<0)
        return false;
    if(n_pt.x()>nWidth)
        return false;
    if(n_pt.y()>nHeight)
        return false;
    return true;
}
