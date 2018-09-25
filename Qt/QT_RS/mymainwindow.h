#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTreeWidget>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QString>
#include <QMessageBox>
#include <QLatin1String>
#include <QImage>
#include <gdal.h>
#include <gdal_priv.h>
#include <ogr_core.h>
#include <math.h>
#include <stdio.h>
#include "showimagebase1.h"
#include "showimagebase2.h"
#include "subsetimage.h"
namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();

private:
    Ui::MyMainWindow *ui;

public:
   QString mBaseFileName;
   QTreeWidget *treeWidget;//ui items
   QTreeWidgetItem *treeBaseItem;
   QList<QTreeWidgetItem *> treeBaseLayerItem;
   QTreeWidgetItem *treeBaseMapinfoItem;
   QGroupBox   *groupBox,*groupBox_2;
   QRadioButton *radioButtonGray,*radioButtonRgb,*radioButtonBlue,*radioButtonGreen,*radioButtonRed;
   QLineEdit   *lineEditBlue,*lineEditGreen,*lineEditRed;
   QPushButton *pushButtonCancel,*pushButtonLoadImage;
   QVBoxLayout *layoutMain;
   int ncountoutput;

   int nRGBofBase[3];
   int nWidth,nHeight;

   GDALDataset *pBaseFileDataset;//the dataset
   ShowImageBase1 *pShowimagebaseUI1;
   SubsetImage *pShowSubsetUI;

public slots:
   void slotActionOpenBaseFile();
   void slotAddImage();
   void slotTreeClicked( QTreeWidgetItem * , int );
   void slotRadioGrayClicked();
   void slotRadioColorClicked();
   void closeEvent(QCloseEvent *);


public:
   bool InitUI();
   bool GetBaseFileMapinfo(QString);
   bool ShowGrayImage();
   bool ShowColorImage();
   bool CreatQimage(QImage*,GByte*);
   bool CheckOverView(GDALDataset*);
   bool BuildOverView(GDALDataset*);
   bool CheckBoundary(QPoint);

public slots:
   void GetPosition(QPoint,QPoint);
   void GetPosition2(QPoint,int,int);

signals:
   //void ReportBasePosition(QPoint);
   void ReportCloseWindows();
};

#endif // MYMAINWINDOW_H
