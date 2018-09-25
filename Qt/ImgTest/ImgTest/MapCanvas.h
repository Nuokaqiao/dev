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
// <summary>ͼ����ʾ�����࣬����ͼ��Ķ�ȡ����ʾ�ȹ��ܡ�</summary>
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
    /// ����ͼ��Ԫ������Ϣģ��.
    /// </summary>
    /// <returns>ͼ��Ԫ������Ϣģ��.</returns>
    QStandardItemModel* ImgMetaModel()
    {
        return imgMetaModel;
    };
    /// <summary>
    /// ����ͼ��Ԫ������Ϣģ��
    /// </summary>
    /// <param name="model">ͼ��Ԫ������Ϣģ��.</param>
    void SetMetaModel( QStandardItemModel* model )
    {
        this->imgMetaModel = model;
    };
    /// <summary>
    /// �����ļ��б�����ģ��
    /// </summary>
    /// <returns>�ļ��б�����ģ��.</returns>
    QStandardItemModel* FileListModel()
    {
        return fileListModel;
    };
    /// <summary>
    /// ����fileListModelͼ���ļ��б�����ģ��
    /// </summary>
    /// <param name="model">�ļ��б�����ģ��.</param>
    void SetFileListModel( QStandardItemModel* model )
    {
        this->fileListModel = model;
    };
    
    QSize sizeHint() const;
    
public slots:
    /// <summary>
    /// �Ŵ�ͼ��
    /// </summary>
    void ZoomIn()
    {
        ScaleImg( 1.2 );
    };
    /// <summary>
    /// ��Сͼ��
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
    /// ͼ������
    /// </summary>
    /// <param name="factor">��������</param>
    void ScaleImg( double factor )
    {
        m_scaleFactor *= factor;
        QMatrix matrix;
        matrix.scale( m_scaleFactor, m_scaleFactor );
        this->setMatrix( matrix );
    };
    
    /// <summary>
    /// ͼ��Ԫ����ģ��
    /// </summary>
    QStandardItemModel *imgMetaModel;
    /// <summary>
    /// ͼ�����ݼ�
    /// </summary>
    GDALDataset *poDataset;
    
    /// <summary>
    /// �ļ��б�����ģ��
    /// </summary>
    QStandardItemModel *fileListModel;
    
    /// <summary>
    /// ����ϵ��
    /// </summary>
    float m_scaleFactor;
    
    /// <summary>
    /// �ж��Ƿ���ʾRGB��ɫͼ��
    /// </summary>
    bool m_showColor;
    
    /// <summary>
    /// ��һ������¼�����ʱ����λ��
    /// </summary>
    QPoint lastEventCursorPos;
};

#endif // MAPCANVAS_H
