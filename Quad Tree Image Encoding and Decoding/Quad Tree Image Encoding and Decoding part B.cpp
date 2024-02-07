#include<opencv2/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include <cstdlib>
#include <ctime>
#include<iostream>
using namespace std;
using namespace cv;


int main()
{
    /*
    cv::Mat img = cv::imread("C:/Users/DELL/Desktop/Test_Images (1)/Student Test Images");
     */
     /* namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
      cv::imshow("First OpenCV Application", img);
      cv::moveWindow("First OpenCV Application", 0, 45);
      cv::waitKey(0);\
      cv::destroyAllWindows();*/


      // Load an image from file    😂😂

    Mat img = imread("C:/Users/DELL/Desktop/t1.bmp");

    // Check if the image was loaded successfully


    //namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
    //imshow("First OpenCV Application", img);
    //moveWindow("First OpenCV Application", 0, 45);
    //waitKey(0);
    //destroyAllWindows();


    int row1 = img.rows;
    int col1 = img.cols;
    /*int row = 30;
    int col = 30;*/
    srand(time(NULL));

    // Generate a random number between 1 and 2
    int random = 0;

    int** array = new int* [row1];
    for (int i = 0; i < row1; i++)
    {
        array[i] = new int[col1];
    }
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {

            random = rand() % 2 + 1;
            /*if (random == 1)
            {
                array[i][j] = 0;
            }
            else array[i][j] = 225;*/
            array[i][j] = img.at<uchar>(i, j * 3);
            //  cout << array[i][j]<<" ";
        }
        // cout << endl;
    }


    Mat img2 = imread("C:/Users/DELL/Desktop/t2.bmp");

    // Check if the image was loaded successfully


   /* namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
    imshow("First OpenCV Application", img2);
    moveWindow("First OpenCV Application", 200, 45);
    waitKey(0);
    destroyAllWindows();*/


    int row = img2.rows;
    int col = img2.cols;
    /*int row = 30;
    int col = 30;*/
    srand(time(NULL));

    // Generate a random number between 1 and 2
   

    int** array2 = new int* [row];
    for (int i = 0; i < row; i++)
    {
        array2[i] = new int[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            random = rand() % 2 + 1;
            /*if (random == 1)
            {
                array[i][j] = 0;
            }
            else array[i][j] = 225;*/
            array2[i][j] = img2.at<uchar>(i, j * 3);
            //  cout << array[i][j]<<" ";
        }
        // cout << endl;
    }
    cout << endl;
    cout << "number of rows " << row << "\nnumber of coloms " << col << endl;
    float sum = 0;

    for (int i = 0; i < row1;i++)
    {
        for (int j = 0; j < col1;j++)
        {
            
            sum += ((array[i][j] - array2[i][j]) * (array[i][j] - array2[i][j]));
        }
    }
    float x = (sum / (row * col));
    float y = 0;
    y =(100 * (1 - (x / (255 * 255))));
    cout << y;
    return 0;
}
