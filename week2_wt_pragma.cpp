// OpenCV GrayScale Image  Tutorial
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <omp.h>
#include <iostream>

using namespace cv;
using namespace std;

string INPUT_IMAGE = "maianh.jpg";
string OUTPUT_IMAGE = "maianh_gray.jpg";

int main()
{
    double itime, ftime, exec_time;

    const float pi = 3.14;
    Mat src1, src2;
    src1 = imread(INPUT_IMAGE);
    src2 = Mat::zeros(src1.rows, src1.cols, CV_8UC1);

    if (!src1.data)
    {
        printf("Error loading src1 \n");
        return -1;
    }

    itime = omp_get_wtime();

    for (int i = 0; i < src1.cols; i++)
    {
        for (int j = 0; j < src1.rows; j++)
        {
            Vec3b color1 = src1.at<Vec3b>(Point(i, j));
            Scalar color2 = src2.at<uchar>(Point(i, j));
            color2 = (0.11 * color1.val[0] + 0.59 * color1.val[1] + 0.3 * color1.val[2]);

            src2.at<uchar>(Point(i, j)) = color2.val[0];
        }
    }

    ftime = omp_get_wtime();
    exec_time = ftime - itime;
    printf("\nTime taken (without #pragma) is %f seconds\n\n", exec_time);

    imwrite("maianh_gray.png", src2);

    namedWindow(INPUT_IMAGE, WINDOW_NORMAL);
    resizeWindow(INPUT_IMAGE, 960, 540);
    imshow(INPUT_IMAGE, src1);

    namedWindow(OUTPUT_IMAGE, WINDOW_NORMAL);
    resizeWindow(OUTPUT_IMAGE, 960, 540);
    imshow(OUTPUT_IMAGE, src2);

    waitKey(0);
    return 0;
}