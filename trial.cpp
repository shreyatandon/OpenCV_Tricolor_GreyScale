#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdlib.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	// To create an image
	// CV_8UC3 depicts : (3 channels,8 bit image depth
	// Height  = 500 pixels, Width = 1000 pixels
	// (0, 0, 100) assigned for Blue, Green and Red 
	//             plane respectively. 
	// So the image will appear red as the red 
	// component is set to 100.

	int rows = 200;
	int columns = 200;
	Mat img(rows,columns, CV_8U);
	//Mat img(rows, columns,CV_8UC3);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			if (i<rows/3)
			{
				img.at<uchar>(i, j) = 0;
				
			}
			else if (i< 2*rows/3)
			{
				img.at<uchar>(i, j) = 255;
			}
			else
			{
				img.at<uchar>(i, j) = 48;
			}

			
		}

	}



	// check whether the image is loaded or not
	if (img.empty())
	{
		cout << "\n Image not created. You"
			" have done something wrong. \n";
		return -1;	// Unsuccessful.
	}

	// first argument: name of the window
	// second argument: flag- types: 
	// WINDOW_NORMAL If this is set, the user can 
	//               resize the window.
	// WINDOW_AUTOSIZE If this is set, the window size
	//                is automatically adjusted to fit 
	//                the displayed image, and you cannot
	//                change the window size manually.
	// WINDOW_OPENGL  If this is set, the window will be
	//                created with OpenGL support.
	namedWindow("A_good_name", CV_WINDOW_NORMAL);

	// first argument: name of the window
	// second argument: image to be shown(Mat object)
	imshow("A_good_name", img);

	waitKey(0); //wait infinite time for a keypress

				// destroy the window with the name, "MyWindow"
	destroyWindow("A_good_name");

	return 0;
}