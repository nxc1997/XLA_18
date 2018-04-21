#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
using namespace cv;
using namespace std;


int Mtype = 0;
int Msize = 0;
int const max_elem = 2;
int const max_size = 22;

Mat src, eor_dst;
void Ero(int, void*);

int main() {

	src = imread("Fig0905(a)(wirebond-mask).tif", IMREAD_GRAYSCALE);

	cvNamedWindow("ero", WINDOW_AUTOSIZE);
	createTrackbar("elemant : \n 0: Rect \n 1: Cross \n 2: ellipe", "ero", &Mtype, max_elem,Ero);
	createTrackbar("size : \n 0: Rect \n 1: Cross \n 2: ellipe", "ero", &Msize, max_size, Ero);
	Ero(0, 0);
	waitKey(0);
	destroyAllWindows();
}

void Ero(int, void*) {
	Mat elemen = getStructuringElement(Mtype, Size(2 * Msize + 1, 2 * Msize + 1));
	erode(src, eor_dst, elemen);
	imshow("ero", eor_dst);
}
