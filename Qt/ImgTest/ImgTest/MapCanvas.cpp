#include "MapCanvas.h"
#include <QtGui/QMessageBox>
#include <QtCore/QFileInfo>
#include <QtGui/QImage>
#include <QtGui/QPixmap>
#include <QtGui/QGraphicsPixmapItem>
#include <QtGui/QMatrix>
#include <QtGui/QWheelEvent>
#include <QtGui/QScrollBar>

MapCanvas::MapCanvas( QWidget *parent /*= 0 */ )
    : QGraphicsView( parent )
{
    poDataset = NULL;
    m_scaleFactor = 1.0;
    m_showColor = true;
    imgMetaModel = new QStandardItemModel;
    imgMetaModel->setColumnCount( 2 );
    fileListModel = new QStandardItemModel;
    QSizePolicy policy( QSizePolicy::Preferred, QSizePolicy::Preferred );
    this->setSizePolicy( policy );
}

/// <summary>
/// Finalizes an instance of the <see cref="MapCanvas" /> class.
/// </summary>
MapCanvas::~MapCanvas()
{

}

/// <summary>
/// 读取图像文件
/// </summary>
/// <param name="imgPath">图像文件</param>
void MapCanvas::ReadImg( const QString imgPath )
{
    GDALAllRegister();
    CPLSetConfigOption( "GDAL_FILENAME_IS_UTF8", "NO" );
    poDataset = ( GDALDataset* )GDALOpen( imgPath.toStdString().c_str(), GA_ReadOnly );
    if ( poDataset == NULL )
    {
        QMessageBox::critical( this, tr( "Error!" ), tr( "Can not open file %1" ).arg( imgPath ) );
        return;
    }
    ShowFileList( imgPath );
    ShowImgInfor( imgPath );
    // 如果图像文件并非三个波段，则默认只显示第一波段灰度图像
    if ( poDataset->GetRasterCount() != 3 )
    {
        m_showColor = false;
        ShowBand( poDataset->GetRasterBand( 1 ) );
    }
    // 如果图像正好三个波段，则默认以RGB的顺序显示彩色图
    else
    {
        m_showColor = true;
        QList<GDALRasterBand*> bandList;
        bandList.append( poDataset->GetRasterBand( 1 ) );
        bandList.append( poDataset->GetRasterBand( 2 ) );
        bandList.append( poDataset->GetRasterBand( 3 ) );
        ShowImg( &bandList );
    }
    GDALClose( poDataset );
}

/// <summary>
/// 关闭当前图像文件
/// </summary>
void MapCanvas::CloseCurrentImg()
{
    poDataset = NULL;
    imgMetaModel->clear();
    fileListModel->clear();
}

/// <summary>
/// 显示单波段图像
/// </summary>
/// <param name="band">图像波段</param>
void MapCanvas::ShowBand( GDALRasterBand* band )
{
    if ( band == NULL )
    {
        return;
    }
    
    QList<GDALRasterBand*> myBand;
    myBand.append( band );
    myBand.append( band );
    myBand.append( band );
    
    ShowImg( &myBand );
    
}

/// <summary>
/// 显示图像
/// </summary>
/// <param name="imgBand">图像波段</param>
void MapCanvas::ShowImg( QList<GDALRasterBand*> *imgBand )
{
    if ( imgBand->size() != 3 )
    {
        return;
    }
    
    int imgWidth = imgBand->at( 0 )->GetXSize();
    int imgHeight = imgBand->at( 0 )->GetYSize();
    
    m_scaleFactor = this->height() * 1.0 / imgHeight;
    
    int iScaleWidth = ( int )( imgWidth * m_scaleFactor - 1 );
    int iScaleHeight = ( int )( imgHeight * m_scaleFactor - 1 );
    
    GDALDataType dataType = imgBand->at( 0 )->GetRasterDataType();
    
    // 首先分别读取RGB三个波段
    float* rBand = new float[iScaleWidth * iScaleHeight];
    float* gBand = new float[iScaleWidth * iScaleHeight];
    float* bBand = new float[iScaleWidth * iScaleHeight];
    
    unsigned char *rBandUC, *gBandUC, *bBandUC;
    
    // 根据是否显示彩色图像，判断RGB三个波段的组成方式，并分别读取
    if ( m_showColor == true )
    {
        imgBand->at( 0 )->RasterIO( GF_Read, 0, 0, imgWidth, imgHeight, rBand , iScaleWidth, iScaleHeight, GDT_Float32, 0, 0 );
        imgBand->at( 1 )->RasterIO( GF_Read, 0, 0, imgWidth, imgHeight, gBand, iScaleWidth, iScaleHeight, GDT_Float32, 0, 0 );
        imgBand->at( 2 )->RasterIO( GF_Read, 0, 0, imgWidth, imgHeight, bBand, iScaleWidth, iScaleHeight, GDT_Float32, 0, 0 );
        
        // 分别拉伸每个波段并将Float转换为unsigned char
        rBandUC = ImgSketch( rBand, imgBand->at( 0 ), iScaleWidth * iScaleHeight, imgBand->at( 0 )->GetNoDataValue() );
        gBandUC = ImgSketch( gBand, imgBand->at( 1 ), iScaleWidth * iScaleHeight, imgBand->at( 1 )->GetNoDataValue() );
        bBandUC = ImgSketch( bBand, imgBand->at( 2 ), iScaleWidth * iScaleHeight, imgBand->at( 2 )->GetNoDataValue() );
    }
    else
    {
        imgBand->at( 0 )->RasterIO( GF_Read, 0, 0, imgWidth, imgHeight, rBand , iScaleWidth, iScaleHeight, GDT_Float32, 0, 0 );
        
        rBandUC = ImgSketch( rBand, imgBand->at( 0 ), iScaleWidth * iScaleHeight, imgBand->at( 0 )->GetNoDataValue() );
        gBandUC = rBandUC;
        bBandUC = rBandUC;
    }
    
    // 将三个波段组合起来
    int bytePerLine = ( iScaleWidth * 24 + 31 ) / 8;
    unsigned char* allBandUC = new unsigned char[bytePerLine * iScaleHeight * 3];
    for( int h = 0; h < iScaleHeight; h++ )
    {
        for( int w = 0; w < iScaleWidth; w++ )
        {
            allBandUC[h * bytePerLine + w * 3 + 0] = rBandUC[h * iScaleWidth + w];
            allBandUC[h * bytePerLine + w * 3 + 1] = gBandUC[h * iScaleWidth + w];
            allBandUC[h * bytePerLine + w * 3 + 2] = bBandUC[h * iScaleWidth + w];
        }
    }
    
    // 构造图像并显示
    QGraphicsPixmapItem *imgItem = new QGraphicsPixmapItem(  QPixmap::fromImage( QImage( allBandUC, iScaleWidth, iScaleHeight, bytePerLine, QImage::Format_RGB888  ) ) );
    QGraphicsScene *myScene = new QGraphicsScene();
    myScene->addItem( imgItem );
    this->setScene( myScene );
}

/// <summary>
/// 显示图像基本信息
/// </summary>
/// <param name="filename">文件名</param>
void MapCanvas::ShowImgInfor( const QString filename )
{
    if ( filename == "" || poDataset == NULL )
    {
        return;
    }
    int row = 0; // 用来记录数据模型的行号
    
    // 图像的格式信息
    imgMetaModel->setItem( row, 0, new QStandardItem( tr( "Description" ) ) );
    imgMetaModel->setItem( row++, 1, new QStandardItem( poDataset->GetDriver()->GetDescription() ) );
    imgMetaModel->setItem( row, 0, new QStandardItem( tr( "Meta Infor" ) ) );
    imgMetaModel->setItem( row++, 1, new QStandardItem( poDataset->GetDriver()->GetMetadataItem( GDAL_DMD_LONGNAME ) ) ) ;
    imgMetaModel->setItem( row, 0, new QStandardItem( tr( "Data Type" ) ) );
    imgMetaModel->setItem( row++, 1, new QStandardItem( GDALGetDataTypeName( ( poDataset->GetRasterBand( 1 )->GetRasterDataType() ) ) ) );
    
    // 图像的大小和波段个数
    imgMetaModel->setItem( row, 0, new QStandardItem( tr( "X Size" ) ) );
    imgMetaModel->setItem( row++, 1, new QStandardItem( QString::number( poDataset->GetRasterXSize() ) ) );
    imgMetaModel->setItem( row, 0, new QStandardItem( tr( "Y Size" ) ) );
    imgMetaModel->setItem( row++, 1, new QStandardItem( QString::number( poDataset->GetRasterYSize() ) ) );
    imgMetaModel->setItem( row, 0, new QStandardItem( tr( "Band Count" ) ) );
    imgMetaModel->setItem( row++, 1, new QStandardItem( QString::number( poDataset->GetRasterCount() ) ) );
    
    // 图像的投影信息
    imgMetaModel->setItem( row, 0, new QStandardItem( tr( "Projection" ) ) );
    imgMetaModel->setItem( row++, 1, new QStandardItem( poDataset->GetProjectionRef() ) );
    
    // 图像的坐标和分辨率信息
    double adfGeoTransform[6];
    QString origin = "";
    QString pixelSize = "";
    if( poDataset->GetGeoTransform( adfGeoTransform ) == CE_None )
    {
        origin = QString::number( adfGeoTransform[0] ) + ", " + QString::number( adfGeoTransform[3] );
        pixelSize = QString::number( adfGeoTransform[1] ) + ", " + QString::number( adfGeoTransform[5] );
    }
    imgMetaModel->setItem( row, 0, new QStandardItem( tr( "Origin" ) ) );
    imgMetaModel->setItem( row++, 1, new QStandardItem( origin ) );
    imgMetaModel->setItem( row, 0, new QStandardItem( tr( "Pixel Size" ) ) );
    imgMetaModel->setItem( row++, 1, new QStandardItem( pixelSize ) );
}

/// <summary>
/// 显示文件结构树
/// </summary>
/// <param name="filename">文件名</param>
void MapCanvas::ShowFileList( const QString filename )
{
    if ( filename == "" || poDataset == NULL )
    {
        return;
    }
    QFileInfo fileInfo( filename );
    QStandardItem *rootItem = new QStandardItem( fileInfo.fileName() );
    for ( int i = 0; i < poDataset->GetRasterCount(); i++ )
    {
        QStandardItem *childItem = new QStandardItem( tr( "Band %1" ).arg( i + 1 ) );
        rootItem->setChild( i, childItem );
    }
    fileListModel->setItem( 0, rootItem );
}

/// <summary>
/// 图像线性拉伸
/// </summary>
/// <param name="buffer">图像缓存</param>
/// <param name="currentBand">当前波段</param>
/// <param name="size">The size.</param>
/// <param name="noValue">图像中的异常值</param>
/// <returns>经过拉伸的8位图像缓存</returns>
unsigned char* MapCanvas::ImgSketch( float* buffer , GDALRasterBand* currentBand, int bandSize, double noValue )
{
    unsigned char* resBuffer = new unsigned char[bandSize];
    double max, min;
    double minmax[2];
    
    
    currentBand->ComputeRasterMinMax( 1, minmax );
    min = minmax[0];
    max = minmax[1];
    if( min <= noValue && noValue <= max )
    {
        min = 0;
    }
    for ( int i = 0; i < bandSize; i++ )
    {
        if ( buffer[i] > max )
        {
            resBuffer[i] = 255;
        }
        else if ( buffer[i] <= max && buffer[i] >= min )
        {
            resBuffer[i] = static_cast<uchar>( 255 - 255 * ( max - buffer[i] ) / ( max - min ) );
        }
        else
        {
            resBuffer[i] = 0;
        }
    }
    
    return resBuffer;
}

/// <summary>
/// 控件大小
/// </summary>
/// <returns>QSize.</returns>
QSize MapCanvas::sizeHint() const
{
    return QSize( 1024, 768 );
}

/// <summary>
/// 鼠标滚轮事件，实现图像缩放
/// </summary>
/// <param name="event">滚轮事件</param>
void MapCanvas::wheelEvent( QWheelEvent *event )
{
    // 滚轮向上滑动，放大图像
    if ( event->delta() > 0 )
    {
        ZoomIn();
    }
    // 滚轮向下滑动，缩小图像
    if ( event->delta() < 0 )
    {
        ZoomOut();
    }
}

/// <summary>
/// 鼠标按键按下事件
/// </summary>
/// <param name="event">鼠标事件.</param>
void MapCanvas::mousePressEvent( QMouseEvent *event )
{
    // 滚轮键按下，平移图像
    if ( event->button() == Qt::MidButton )
    {
        this->setDragMode( QGraphicsView::ScrollHandDrag );
        this->setInteractive( false );
        lastEventCursorPos = event->pos();
    }
}

/// <summary>
/// 鼠标移动事件
/// </summary>
/// <param name="event">鼠标事件</param>
void MapCanvas::mouseMoveEvent( QMouseEvent *event )
{
    if ( this->dragMode() == QGraphicsView::ScrollHandDrag )
    {
        QPoint delta = ( event->pos() - lastEventCursorPos ) / 10;
        this->horizontalScrollBar()->setValue( this->horizontalScrollBar()->value() + ( isRightToLeft() ? delta.x() : -delta.x() ) );
        this->verticalScrollBar()->setValue( this->verticalScrollBar()->value() - delta.y() );
        this->viewport()->setCursor( Qt::ClosedHandCursor );
    }
    
}

/// <summary>
/// 鼠标按键释放事件
/// </summary>
/// <param name="event">鼠标事件</param>
void MapCanvas::mouseReleaseEvent( QMouseEvent *event )
{
    if ( event->button() == Qt::MidButton )
    {
        this->setDragMode( QGraphicsView::NoDrag );
    }
}

