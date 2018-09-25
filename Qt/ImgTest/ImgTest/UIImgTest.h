// ***********************************************************************
// Assembly         : ImgTest
// Author           : Jacory
// Created          : 07-08-2014
//
// Last Modified By : Jacory
// Last Modified On : 07-10-2014
// ***********************************************************************
// <copyright file="UIImgTest.h" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary>��UI�ࡣ</summary>
// ***********************************************************************
#ifndef IMGTEST_H
#define IMGTEST_H

#include <QtGui/QMainWindow>
#include "ui_imgtest.h"

class MapCanvas;

/// <summary>
/// Class ImgTest.
/// </summary>
class UIImgTest : public QMainWindow
{
    Q_OBJECT
    
public:
    UIImgTest( QWidget *parent = 0, Qt::WFlags flags = 0 );
    ~UIImgTest();
public slots:
    void PickOpenFile();
    void Exit();
    void ShowFileListWindow();
    void ShowInforWindow();
private:
    /// <summary>
    /// ������UI
    /// </summary>
    Ui::ImgTestClass ui;
    /// <summary>
    /// ͼ����ʾ���ڿؼ�
    /// </summary>
    MapCanvas *myMap;
};

#endif // IMGTEST_H
