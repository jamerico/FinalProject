#pragma once

#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>
#include <thread> 
#include "C:\opencv_git\modules\features2d\include\opencv2\features2d\features2d.hpp"
#include "Cor.h"
#include "dbStorage.h"
#include "Logger.h"
#include <omp.h>
//#include "opencv2/cudafilters.hpp"
//#include "opencv2/cudaimgproc.hpp"
//#include "opencv2/cudaarithm.hpp"
//#include "opencv2/cudacodec.hpp"
//#include "opencv2/cudafilters.hpp"

 

//using namespace cv;


class Vision
{
public:	
	Vision(int camNumber);
	~Vision();

	static void ReleaseCam();
	static void ProcessFrames();
	static cv::Mat ProcessFramesRtn();
	static void CvtCor();
	static cv::Mat originalMatHSV;
	static cv::Mat originalMat;
	static Vision *instance();
	static cv::Mat filtredMat;
	static Vision *instance(int);

	//static cv::cuda::GpuMat inRangeGpu(cv::cuda::GpuMat pMatrizEntrada[], Cor);

	//static cv::cuda::GpuMat originalGpuMat;

	void getBlobs();			//funcao para "adquirir" os blobs ----- DEVE MORRER mas ainda n sei
	vector<cv::Point> getBlobs(Cor, bool);		//funcao para "adquirir" os blobs por cor
	vector<vector<cv::Point>> getPosicaoCores(vector<Cor> , bool);
	vector<vector<cv::Point>> getAllBlobs(vector<Cor>, bool);

	cv::Mat filtroDeBlobPorArea(cv::Mat, float, float);

private:
	static cv::VideoCapture capWebCam;
	static Vision* inst;	
};

