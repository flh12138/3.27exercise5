#include <iostream>
#include <opencv.hpp>
using namespace cv;
using namespace std;

int main() {

	VideoCapture cap(0);
	double scale = 0.5;

	//0-180
	//·ôÉ«
	double i_minH = 0;
	double i_maxH = 20;

	//0-255 
	double i_mins = 43;
	double i_maxs = 255;

	//8-255
	double i_minV = 55;
	double i_maxV = 255;
	while (1)
	{
		Mat frame;
		Mat hsvMat;
		Mat detectMat;
		Mat SobelMat;

		cap >> frame;
		Size ResImgSiz = Size(frame.cols*scale, frame.rows*scale);
		Mat rFrame = Mat(ResImgSiz, frame.type());
		resize(frame, rFrame, ResImgSiz, INTER_LINEAR);

		cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);
		rFrame.copyTo(detectMat);
		cv::inRange(hsvMat, Scalar(i_minH, i_mins, i_minV), Scalar(i_maxH, i_maxs, i_maxV), detectMat);

		GaussianBlur(rFrame, SobelMat, Size(5, 5), 5, 5);
		imshow("SobelMat", SobelMat);
		imshow("whie: in the range", detectMat);
		imshow("frame", rFrame);
		waitKey(38);
	}
}

		//cv::Mat frame;
		//cv::Mat SobelMat;
		//cap.read(frame);
		//Sobel(frame, SobelMat, 6, 1, 1, 3, 1, 0);
		//imshow("SobelMat", SobelMat);
		//imshow("frame", frame);
		//waitKey(30);






