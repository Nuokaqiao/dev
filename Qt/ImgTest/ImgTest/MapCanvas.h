// ***********************************************************************
// Assembly         : ImgTest
// Author           : Jacory
// Created          : 07-10-2014
//
// Last Modified By : Jacory
// Last Modified On : 07-10-2014
// ***********************************************************************
// <copyright file="MapCanvas.h" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary>图像显示窗口类，负责图像的读取和显示等功能。</summary>
// ***********************************************************************
#ifndef MAPCANVAS_H
#define MAPCANVAS_H

#include <QtGui/QGraphicsView>
#include <QStandardItemModel>
#include <gdal_priv.h>


/// <summary>
/// Class MapCanvas.
/// </summary>
class MapCanvas : public QGraphicsView
{
    Q_OBJECT
    
public:
    MapCanvas( QWidget *parent = 0 );
    ~MapCanvas();
    void ReadImg( const QString imgPath );
    void CloseCurrentImg();
    /// <summary>
    /// 返回图像元数据信息模型.
    /// </summary>
    /// <returns>图像元数据信息模型.</returns>
    QStandardItemModel* ImgMetaModel()
    {
        return imgMetaModel;
    };
    /// <summary>
    /// 设置图像元数据信息模型
    /// </summary>
    /// <param name="model">图像元数据信息模型.</param>
    void SetMetaModel( QStandardItemModel* model )
    {
        this->imgMetaModel = model;
    };
    /// <summary>
    /// 返回文件列表数据模型
    /// </summary>
    /// <returns>文件列表数据模型.</returns>
    QStandardItemModel* FileListModel()
    {
        return fileListModel;
    };
    /// <summary>
    /// 设置fileListModel图像文件列表数据模型
    /// </summary>
    /// <param name="model">文件列表数据模型.</param>
    void SetFileListModel( QStandardItemModel* model )
    {
        this->fileListModel = model;
    };
    
    QSize sizeHint() const;
    
public slots:
    /// <summary>
    /// 放大图像
    /// </summary>
    void ZoomIn()
    {
        ScaleImg( 1.2 );
    };
    /// <summary>
    /// 缩小图像
    /// </summary>
    void ZoomOut()
    {
        ScaleImg( 0.8 );
    };
    
protected:
    void wheelEvent( QWheelEvent *event );
    void mousePressEvent( QMouseEvent *event );
    void mouseMoveEvent( QMouseEvent *event );
    void mouseReleaseEvent( QMouseEvent *event );
    
private:
    void ShowBand( GDALRasterBand* band );
    void ShowImg( QList<GDALRasterBand*> *imgBand );
    void ShowImgInfor( const QString filename );
    void ShowFileList( const QString filename );
    unsigned char* ImgSketch( float* buffer , GDALRasterBand* currentBand, int size, double noValue );
    /// <summary>
    /// 图像缩放
    /// </summary>
    /// <param name="factor">缩放因子</param>
    void ScaleImg( double factor )
    {
        m_scaleFactor *= factor;
        QMatrix matrix;
        matrix.scale( m_scaleFactor, m_scaleFactor );
        this->setMatrix( matrix );
    };
    
    /// <summary>
    /// 图像元数据模型
    /// </summary>
    QStandardItemModel *imgMetaModel;
    /// <summary>
    /// 图像数据集
    /// </summary>
    GDALDataset *poDataset;
    
    /// <summary>
    /// 文件列表数据模型
    /// </summary>
    QStandardItemModel *fileListModel;
    
    /// <summary>
    /// 缩放系数
    /// </summary>
    float m_scaleFactor;
    
    /// <summary>
    /// 判断是否显示RGB彩色图像
    /// </summary>
    bool m_showColor;
    
    /// <summary>
    /// 上一个鼠标事件触发时鼠标的位置
    /// </summary>
    QPoint lastEventCursorPos;
};

#endif // MAPCANVAS_H
