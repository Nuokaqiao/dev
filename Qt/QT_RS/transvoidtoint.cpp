#include "transvoidtoint.h"

TransVoidToInt::TransVoidToInt(GDALRasterBand *p_RasterBand,void *p_Banddatatemp,GDALDataType eBandType)
{
    /*++++++++++++++++++++++++++++++++++
    /void*:the start pointer of band data
    /gdaldatatype.
    +++++++++++++++++++++++++++++++++++*/
    pBandData=p_Banddatatemp;
    nBandType=eBandType;
    pRasterBand=p_RasterBand;
    ComputeRasterScale();
}

int TransVoidToInt::GetValue(int index)
{
    double n_Value;
    if(nBandType==GDT_Byte)
      {
        char n_val1=((char*)pBandData)[index];
        n_Value=n_val1;
      }
    else if(nBandType==GDT_UInt16||nBandType==GDT_Int16)
      {
        int16_t n_val1=((int16_t*)pBandData)[index];
        n_Value =n_val1;
      }
    else if(nBandType==GDT_UInt32||nBandType==GDT_Int32)
      {
        int32_t n_val1=((int32_t*)pBandData)[index];
        n_Value =n_val1;
      }
    else if(nBandType==GDT_Float32)
      {
        float n_val1=((float*)pBandData)[index];
        n_Value =n_val1;
      }
    else if(nBandType==GDT_Float64)
      {
        double n_val1=((double*)pBandData)[index];
        n_Value =n_val1;
      }
    return n_Value*nScale+nOffSet;
}

bool TransVoidToInt::ComputeRasterScale()
{
    double n_MinMax[2];
    GDALComputeRasterMinMax(pRasterBand,TRUE,n_MinMax);
    if(n_MinMax[1]==n_MinMax[0])
        n_MinMax[1]++;
    nScale=255/(n_MinMax[1]-n_MinMax[0]);
    nOffSet=-1*n_MinMax[0]*nScale;
}
