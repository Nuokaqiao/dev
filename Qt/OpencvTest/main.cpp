
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>

using namespace std;
using namespace cv;


int main(int argc, char *argv[])
{
    Mat a = imread("./nd_dem.tif",1);
    namedWindow("gray");
    imshow("gray",a);
    waitKey(0);
    cout << "Hello Opencv" << endl;


    return 0;
}
