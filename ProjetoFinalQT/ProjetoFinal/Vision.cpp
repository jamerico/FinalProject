#include "Vision.h"

//#define imagem		// so deixar isso para caso de teste com imagem fixa
using namespace cv;

VideoCapture Vision::capWebCam;
Mat Vision::originalMat;
Mat Vision::originalMatHSV;
Mat Vision::filtredMat;
Vision *Vision::inst = 0;
//cuda::GpuMat Vision::originalGpuMat;


Vision::Vision(int camNumber = 0)
{	
	
#ifndef imagem
	//for (int i = 0; i < 5; i++)
	//{
	//	capWebCam.open(i);
	//	bool a = capWebCam.isOpened();

	//	capWebCam.release();
	//}


	//CvCapture* capture = cvCaptureFromCAM(CV_CAP_DSHOW);
	//capture->VI.listDevices();

	//capWebCam.open(camNumber);
	capWebCam.open(CV_CAP_DSHOW + camNumber);
	//capWebCam.set(CAP_PROP_FRAME_HEIGHT, 480);
	//capWebCam.set(CAP_PROP_FRAME_WIDTH, 640);

	capWebCam.set(CAP_PROP_FRAME_HEIGHT, 240);
	capWebCam.set(CAP_PROP_FRAME_WIDTH, 320);
	

	/*capWebCam.set(CV_CAP_PROP_AUTO_EXPOSURE, 0);
	capWebCam.set(CV_CAP_PROP_EXPOSURE, -8);
	capWebCam.set(CV_CAP_PROP_SETTINGS, 1);
	*/

	if (capWebCam.isOpened() == false)
	{
		//ui.XYText->appendPlainText("Erro ao tentar abrir a webCam");		
		return;
	}
	else
	{
		//ui.XYText->appendPlainText("Camera aberta com sucesso!!!");
	}
#else
	//originalMat = imread("C:/Users/gabri/Desktop/imgTeste.jpg", CV_LOAD_IMAGE_COLOR);
	originalMat = imread("D:/imgTeste.jpg", CV_LOAD_IMAGE_COLOR);
#endif
	

	
}

Vision::~Vision()
{
	ReleaseCam();
		
}

void Vision::ReleaseCam()
{
	if (capWebCam.isOpened())
	{
		capWebCam.release();
	}
	capWebCam.~VideoCapture();
}



cv::Mat Vision::ProcessFramesRtn()
{
	int count = 0;
	while (count < 3)
	{
#ifndef imagem
		capWebCam.read(originalMat);
		//double exposure = capWebCam.get(CV_CAP_PROP_EXPOSURE);
#endif
		if (originalMat.empty() == true)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			count++;
			continue;
		}
		else
		{
			//std::this_thread::sleep_for(std::chrono::milliseconds(33));
			CvtCor();
			return originalMat;
		}
	}
	throw new exception("Erro na captura de vídeo");

}



void Vision::ProcessFrames()
{
	while (true)
	{
	#ifndef imagem
		capWebCam.read(originalMat);
		//double exposure = capWebCam.get(CV_CAP_PROP_EXPOSURE);
	#endif
		if (originalMat.empty() == true)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			continue;
		}
		else
		{
			//std::this_thread::sleep_for(std::chrono::milliseconds(33));
			CvtCor();
			return;
		}
	}
}

void Vision::CvtCor()
{
	if (originalMatHSV.cols == 0)
	{
		originalMatHSV = cv::Mat(originalMat.cols, originalMat.rows, CV_8UC3);
	}

	cv::cvtColor(originalMat, originalMatHSV, cv::COLOR_BGR2HSV);
	
}

Vision *Vision::instance(int intcamnumber)
{
	if (!inst){
		inst = new Vision(intcamnumber);
	}

	return inst;
}

Vision *Vision::instance()
{
	if (!inst){
		inst = new Vision();
	}
		
	return inst;
}

void Vision::getBlobs(){
	// Codigo temporario para fazer a detecção dos blobs
	Cor vermelho1, vermelho2; // A cor vermelha é a Troll da brincadeira pq ela é o inicio de fim do range de cores (Ao menos parece)
	vermelho1.maxH = 7;
	vermelho1.maxS = 255;
	vermelho1.maxV = 196;
	vermelho1.minH = 0;
	vermelho1.minS = 100;
	vermelho1.minV = 50;
	
	vermelho2.maxH = 180;
	vermelho2.maxS = 255;
	vermelho2.maxV = 255;
	vermelho2.minH = 170;
	vermelho2.minS = 100;
	vermelho2.minV = 204;


	
	// 1 Maneira, achei meio lento mas temos de verificar
	//Tentativa de minimar problemas de deteccao com ruidos, isso pode ser resolvido tbm com filtro de area
	Mat temporaryMat;
	//medianBlur(originalMat, temporaryMat, 3);

	// Convert input image to HSV	
	cvtColor(originalMat, filtredMat, COLOR_BGR2HSV);
	
	// Threshold the HSV image, keep only the red pixels
	Mat lower_red_hue_range;
	Mat upper_red_hue_range;

	inRange(filtredMat, Scalar(vermelho1.minH, vermelho1.minS, vermelho1.minV), Scalar(vermelho1.maxH, vermelho1.maxS, vermelho1.maxV), lower_red_hue_range);
	inRange(filtredMat, Scalar(vermelho2.minH, vermelho2.minS, vermelho2.minV), Scalar(vermelho2.maxH, vermelho2.maxS, vermelho2.maxV), upper_red_hue_range);	

	// Combine the above two ranges for color
	Mat red_hue_image;
	addWeighted(lower_red_hue_range, 1.0, upper_red_hue_range, 1.0, 0.0, red_hue_image);	

	// Fazer operações morfologicas para reduzir a quantidade de ruido do pixel
	// Essa redução tbm pode ser feita ajustando melhor os parametros do filtro de cor

	//morphological opening (remove small objects from the foreground)
	int morphsize = 5;
	erode(red_hue_image, red_hue_image, getStructuringElement(MORPH_ELLIPSE, Size(morphsize, morphsize)));
	dilate(red_hue_image, red_hue_image, getStructuringElement(MORPH_ELLIPSE, Size(morphsize, morphsize)));

	//morphological closing (fill small holes in the foreground)
	dilate(red_hue_image, red_hue_image, getStructuringElement(MORPH_ELLIPSE, Size(morphsize * 2, morphsize * 2)));
	erode(red_hue_image, red_hue_image, getStructuringElement(MORPH_ELLIPSE, Size(morphsize * 2, morphsize * 2)));

	//isso deixa a imagem meio q borrada (blur) -- fica mais bonito de ver o filtro mas achei meio pesado
	//GaussianBlur(red_hue_image, red_hue_image, Size(9, 9), 2, 2);

	// mostrar a imagem do filtro por enquanto (Imagem preto e branco)
	filtredMat = red_hue_image;

	// Use the Hough transform to detect circles in the combined threshold image
	std::vector<Vec3f> circles;
	HoughCircles(red_hue_image, circles, CV_HOUGH_GRADIENT, 1, red_hue_image.rows / 8, 100, 20, 0, 0);

	//// Loop over all detected circles and outline them on the original image
	////if (circles.size() == 0) std::exit(-1);
	for (size_t current_circle = 0; current_circle < circles.size(); ++current_circle) 
	{		
		Point center(std::round(circles[current_circle][0]), std::round(circles[current_circle][1])); // X e Y do carrinho
		int radius = std::round(circles[current_circle][2]);	// raio do blob
	
		circle(originalMat, center, radius, Scalar(0, 255, 0), 5); // desenha um circulo entorno do blob
	}

	SimpleBlobDetector::Params params;
	// filtrar por Area.
	params.filterByArea = true;
	params.minArea = 150;
	params.maxArea = 10000000;
	// Change thresholds
	params.minThreshold = 10;
	params.maxThreshold = 200;
	// Set up detector with params
	Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
	// Detect blobs.
	std::vector<KeyPoint> keypoints;
	// Draw detected blobs as red circles.
	// DrawMatchesFlags::DRAW_RICH_KEYPOINTS flag ensures the size of the circle corresponds to the size of blob
	Mat im_with_keypoints;
	drawKeypoints(filtredMat, keypoints, im_with_keypoints, Scalar(0, 0, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	detector->detect(filtredMat, keypoints);
	//ESSA FUNCAO JA PODE VIR DO CODIGO DA HEFESTOS, SE N ME ENGANO DO FILTER.CPP LA NO FIM
}

//cuda::GpuMat Vision::inRangeGpu(cuda::GpuMat pMatrizEntrada[], Cor pCor){
//	/*
//		Funcao inRange implementada para funcionar com CUDA
//		* pMatrizEntrada -> array do tipo GpuMat que sera filtrado (HSV)
//		* pCor -> Cor que sera capturada
//		
//		Retorna um GpuMat (Binario, preto e branco) apos filtrada para cor passada como parametros
//
//	*/
//	clock_t beginNovo = clock();
//
//	cuda::GpuMat channels_device_dest[6] = { cuda::GpuMat(originalMat.rows, originalMat.cols, CV_8UC1) };
//	
//	/*
//	cuda::GpuMat hMinMat(originalMat.rows, originalMat.cols, CV_8UC1);
//	cuda::GpuMat sMinMat(originalMat.rows, originalMat.cols, CV_8UC1);
//	cuda::GpuMat vMinMat(originalMat.rows, originalMat.cols, CV_8UC1);
//	cuda::GpuMat hMaxMat(originalMat.rows, originalMat.cols, CV_8UC1);
//	cuda::GpuMat sMaxMat(originalMat.rows, originalMat.cols, CV_8UC1);
//	cuda::GpuMat vMaxMat(originalMat.rows, originalMat.cols, CV_8UC1);*/
//
//	cuda::GpuMat output(originalMat.rows, originalMat.cols, CV_8UC1, Scalar(255, 255, 255));
//
//	float tempoGpuNovo = float(clock() - beginNovo) / CLOCKS_PER_SEC;
//	beginNovo = clock();
//
//	//std::thread hMin([pMatrizEntrada, hMinMat, pCor](){
//	cuda::threshold(pMatrizEntrada[0], channels_device_dest[0], pCor.minH, 255, THRESH_BINARY);
//	//});
//	//hMin.detach();
//	
//	//std::thread sMin([pMatrizEntrada, sMinMat, pCor](){
//	cuda::threshold(pMatrizEntrada[1], channels_device_dest[1], pCor.minS, 255, THRESH_BINARY);
//	//});
//	//sMin.detach();
//
//	//std::thread vMin([pMatrizEntrada, vMinMat, pCor](){
//	cuda::threshold(pMatrizEntrada[2], channels_device_dest[2], pCor.minV, 255, THRESH_BINARY);
//	//});
//	//vMin.detach();
//
//	//std::thread hMax([pMatrizEntrada, hMaxMat, pCor](){
//	cuda::threshold(pMatrizEntrada[0], channels_device_dest[3], pCor.maxH, 255, THRESH_BINARY_INV);
//	//});
//	//hMax.detach();
//
//	//std::thread sMax([pMatrizEntrada, sMaxMat, pCor](){
//	cuda::threshold(pMatrizEntrada[1], channels_device_dest[4], pCor.maxS, 255, THRESH_BINARY_INV);
//	//});
//	//sMax.detach();
//
//	//std::thread vMax([pMatrizEntrada, vMaxMat, pCor](){
//	cuda::threshold(pMatrizEntrada[2], channels_device_dest[5], pCor.maxV, 255, THRESH_BINARY_INV);
//	//});
//	//vMax.detach();
//	
//
//	float tempoGpuThread1 = float(clock() - beginNovo) / CLOCKS_PER_SEC;
//	beginNovo = clock();
//
//	/*hMin.join();
//	sMin.join();
//	vMin.join();
//	hMax.join();
//	sMax.join();
//	vMax.join();*/
//
//	float tempoGpuThread2 = float(clock() - beginNovo) / CLOCKS_PER_SEC;
//	beginNovo = clock();
//
//
//	cuda::bitwise_and(output, channels_device_dest[0], output);
//	cuda::bitwise_and(output, channels_device_dest[1], output);
//	cuda::bitwise_and(output, channels_device_dest[2], output);
//	cuda::bitwise_and(output, channels_device_dest[3], output);
//	cuda::bitwise_and(output, channels_device_dest[4], output);
//	cuda::bitwise_and(output, channels_device_dest[5], output);
//
//	float tempoGpuAnd = float(clock() - beginNovo) / CLOCKS_PER_SEC;
//
//
//	return output;
//}

//void Vision::getBlobs(Cor cor){
//	
//
//	cuda::GpuMat filtredMat = cuda::GpuMat(originalMat.rows, originalMat.cols, CV_8UC3);
//	cuda::GpuMat originalGpu = cuda::GpuMat(originalMat);
//	
//	cuda::cvtColor(originalGpu, filtredMat, COLOR_BGR2HSV);
//	cuda::GpuMat channels_device[3];
//	cuda::GpuMat channels_device_dest[6];
//
//	cuda::GpuMat output(originalMat.rows, originalMat.cols, CV_8UC1, Scalar(255, 255, 255));
//
//	cv::Mat result_host;
//
//	cuda::split(filtredMat, channels_device);
//	
//	
//	
//	////Começa aqui a parte que deveria ser separada em threads
//
//	////threshold HSV
//	//cuda::threshold(channels_device[0], channels_device_dest[0], cor.minH, 255, THRESH_BINARY);
//	//cuda::threshold(channels_device[1], channels_device_dest[1], cor.minS, 255, THRESH_BINARY);
//	//cuda::threshold(channels_device[2], channels_device_dest[2], cor.minV, 255, THRESH_BINARY);
//
//	//cuda::threshold(channels_device[0], channels_device_dest[3], cor.maxH, 255, THRESH_BINARY_INV);
//	//cuda::threshold(channels_device[1], channels_device_dest[4], cor.maxS, 255, THRESH_BINARY_INV);
//	//cuda::threshold(channels_device[2], channels_device_dest[5], cor.maxV, 255, THRESH_BINARY_INV);
//
//	//
//	////Termina aqui a parte que deveria ser separada em threads
//
//	//for (size_t i = 0; i < 6; i++)
//	//{
//	//	cuda::bitwise_and(output, channels_device_dest[i], output);
//	//}
//
//	cuda::GpuMat originalNewGpu;
//
//	//originalGpuMat = output;
//
//	Mat originalNew;
//	Mat processedMat = cv::Mat(originalMat.cols, originalMat.rows, CV_8UC3);
//	cv::cvtColor(originalMat, processedMat, cv::COLOR_BGR2HSV);
//	
//	clock_t begin1 = clock();
//
//	cv::inRange(processedMat, cv::Scalar(cor.minH, cor.minS, cor.minV), cv::Scalar(cor.maxH, cor.maxS, cor.maxV), originalNew);
//
//
//	float tempoCpu = float(clock() - begin1) / CLOCKS_PER_SEC;
//
//	originalMat = cv::Mat(originalNewGpu);
//
//
//		
//	/*
//
//	// Define os parametros do detector de blobs
//	SimpleBlobDetector::Params params;
//	// filtrar por Area.
//	params.filterByArea = true;
//	params.minArea = 100;
//	params.maxArea = 154000;
//
//	// Change thresholds
//	params.minThreshold = 0;
//	params.thresholdStep = 1;
//	params.maxThreshold = 10;
//
//	// filtro de cor
//	params.filterByColor = false;
//
//	// Filter by Circularity
//	params.filterByCircularity = false;
//	params.minCircularity = 0.1;
//
//	// Filter by Convexity
//	params.filterByConvexity = false;
//	params.minConvexity = 0.87;
//
//	// Filter by Inertia
//	params.filterByInertia = true;
//	params.minInertiaRatio = 0.01;
//
//	// Cria o detector com os parametros definidos
//	Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
//	
//	// Cria um vetor para receber os blobs
//	std::vector<KeyPoint> keypoints;
//	
//	// Draw detected blobs as red circles.
//	// DrawMatchesFlags::DRAW_RICH_KEYPOINTS flag ensures the size of the circle corresponds to the size of blob
//	//Mat im_with_keypoints;
//	detector->detect(filtredMat, keypoints);
//	drawKeypoints(originalMat, keypoints, originalMat, Scalar(0, 0, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
//
//
//	// Passa a imagem na tela
//
//	//circle(originalMat, center, radius, Scalar(0, 255, 0), 5); // desenha um circulo entorno do blob
//
//	//QImage qimgProcessed((uchar*)originalMat.data, originalMat.cols, originalMat.rows, originalMat.step, QImage::Format_RGB);
//	//uiCalib.label->setPixmap(QPixmap::fromImage(qimgProcessed)); */
//}


vector<vector<cv::Point>> Vision::getPosicaoCores(vector<Cor> pVCor, bool pDesenha){
	//Logger::Output("Inicio getPosicaoCores");

	Mat processedMat = cv::Mat(originalMatHSV.cols, originalMatHSV.rows, CV_8UC3);
	vector<vector<cv::Point>> rtnVct(pVCor.size());

#pragma omp parallel for firstprivate(originalMatHSV,processedMat) 
	for (int idxCor = 0; idxCor < pVCor.size(); idxCor++)
	{
		Cor cor = pVCor.at(idxCor);
		/*char msgbuf[1024];
		sprintf(msgbuf, "thread %d i %d cor = %s\n", omp_get_thread_num(), idxCor, cor.nome);
		Logger::Output(msgbuf);*/

		cv::inRange(originalMatHSV, cv::Scalar(cor.minH, cor.minS, cor.minV), cv::Scalar(cor.maxH, cor.maxS, cor.maxV), processedMat);

		std::vector< std::vector<Point> > contours;	// Vector para armazenar os contornos
		std::vector<Vec4i> hierarchy;
		std::vector<int> IndicesValidosContorno;	// Vector para armazenar os indices dos contornos validos

		findContours(processedMat, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_TC89_KCOS);

		// Encontra os  contornos
		if (!contours.empty()) {
			for (size_t i = 0; i < contours.size(); ++i) {
				double contour_area = contourArea(contours[i]);
				if (contour_area >= cor.minArea && contour_area <= cor.maxArea) // Se o contorno estiver dentro do limite de area
					IndicesValidosContorno.push_back(i);
			}
		}

		// Desenha os contornos e seus centros
		for (size_t i = 0; i < IndicesValidosContorno.size(); ++i) {

			float centroX, centroY;
			// Calculando o centro dos contornoes
			cv::Moments momentos = cv::moments(contours[IndicesValidosContorno[i]]);

			centroX = momentos.m10 / momentos.m00;
			centroY = momentos.m01 / momentos.m00;

			cv::Point centroObjeto = cv::Point(centroX, centroY);
			// Vetor de pontos dos contornos
			rtnVct.at(idxCor).push_back(centroObjeto);
		}
	}

	return rtnVct;

}


vector<cv::Point> Vision::getBlobs(Cor cor, bool desenha){

	vector<cv::Point> posicaoObjetos;

	//Mat originalNew;
	Mat processedMat = cv::Mat(originalMatHSV.cols, originalMatHSV.rows, CV_8UC3);
	//cv::cvtColor(originalMat, processedMat, cv::COLOR_BGR2HSV);

	cv::inRange(originalMatHSV, cv::Scalar(cor.minH, cor.minS, cor.minV), cv::Scalar(cor.maxH, cor.maxS, cor.maxV), processedMat);
	

	/*
	//originalMat = cv::Mat(originalNewGpu);

	// Define os parametros do detector de blobs
	SimpleBlobDetector::Params params;
	// filtrar por Area.
	params.filterByArea = true;
	params.minArea = 100;
	params.maxArea = 154000;

	// Change thresholds
	params.minThreshold = 0;
	params.thresholdStep = 1;
	params.maxThreshold = 10;

	// filtro de cor
	params.filterByColor = false;

	// Filter by Circularity
	params.filterByCircularity = false;
	params.minCircularity = 0.1;

	// Filter by Convexity
	params.filterByConvexity = false;
	params.minConvexity = 0.87;

	// Filter by Inertia
	params.filterByInertia = true;
	params.minInertiaRatio = 0.01;

	// Cria o detector com os parametros definidos
	Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);

	// Cria um vetor para receber os blobs
	std::vector<KeyPoint> keypoints;

	// Draw detected blobs as red circles.
	// DrawMatchesFlags::DRAW_RICH_KEYPOINTS flag ensures the size of the circle corresponds to the size of blob
	//Mat im_with_keypoints;

	

	clock_t begin1 = clock();
	
	//detector->detect(processedMat, keypoints);
	float tempo1 = float(clock() - begin1) / CLOCKS_PER_SEC;

	Mat temp_image;
	originalMat.copyTo(temp_image);
	//drawKeypoints(originalMat, keypoints, originalMat, Scalar(0, 0, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	*/
	
	////morphological opening (remove small objects from the foreground)
	//int morphsize = 5;
	//erode(processedMat, processedMat, getStructuringElement(MORPH_ELLIPSE, Size(morphsize, morphsize)));
	//dilate(processedMat, processedMat, getStructuringElement(MORPH_ELLIPSE, Size(morphsize, morphsize)));

	////morphological closing (fill small holes in the foreground)
	//dilate(processedMat, processedMat, getStructuringElement(MORPH_ELLIPSE, Size(morphsize * 2, morphsize * 2)));
	//erode(processedMat, processedMat, getStructuringElement(MORPH_ELLIPSE, Size(morphsize * 2, morphsize * 2)));

	std::vector< std::vector<Point> > contours;	// Vector para armazenar os contornos
	std::vector<Vec4i> hierarchy;				
	std::vector<int> IndicesValidosContorno;	// Vector para armazenar os indices dos contornos validos
	
	// Aqui faz-se uma copia pra n cagar a imagem original (PODE SER UTIL PRA VER O FILTRO)
	//Mat temp_image;
	//processedMat.copyTo(temp_image);
	
	// Encontra os contornos, o 4 parametros eh interessante pra considerar o level de hierarquia
	// o 5 parametro n usar o NONE, de resto acho q ta OK
	findContours(processedMat, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_TC89_KCOS);

	// Encontra os  contornos
	if (!contours.empty()) {
		for (size_t i = 0; i < contours.size(); ++i) {
			double contour_area = contourArea(contours[i]);
			if (contour_area >= cor.minArea && contour_area <= cor.maxArea) // Se o contorno estiver dentro do limite de area
				IndicesValidosContorno.push_back(i);
		}
	}

	/*cuda::GpuMat originalGpu = cuda::GpuMat(temp_image);

	//clock_t begin3 = clock();
	//std::vector<Vec3f> circles;
	//HoughCircles(temp_image, circles, CV_HOUGH_GRADIENT, 1, temp_image.rows / 8, 100, 20, 0, 0);

	//float tempo3 = float(clock() - begin3) / CLOCKS_PER_SEC;


	//clock_t begin4 = clock();
	//std::vector<Vec3f> circles1;
	//cuda::GpuMat d_lines;

	//cuda::Stream stream;
	//Ptr<cuda::HoughCirclesDetector> detetor = cuda::createHoughCirclesDetector(1, originalGpu.rows / 8, 100, 20, 25, 154000);
	//detetor->detect(originalGpu, circles1, stream);
	//stream.waitForCompletion();

	//float tempo4 = float(clock() - begin4) / CLOCKS_PER_SEC;
	*/

	// Desenha os contornos e seus centros
	for (size_t i = 0; i < IndicesValidosContorno.size(); ++i) {

		float centroX, centroY;		
		// Calculando o centro dos contornoes
		cv::Moments momentos = cv::moments(contours[IndicesValidosContorno[i]]);		
		
		centroX = momentos.m10 / momentos.m00;
		centroY = momentos.m01 / momentos.m00;
		
		cv::Point centroObjeto = cv::Point(centroX, centroY);
		// Vetor de pontos dos contornos
		posicaoObjetos.push_back(centroObjeto);
		
		if (desenha)
		{
			// Desenha os contornos
			cv::drawContours(originalMat, contours, IndicesValidosContorno[i], cv::Scalar(255, 255, 255), 1, 8);
			// Desnha um circulo de raio 0 (um ponto) no centro do contorno 
			cv::circle(originalMat, centroObjeto, 1, cv::Scalar(255, 255, 255), 3);
		}
	}
	return posicaoObjetos;
}

vector<vector<cv::Point>> Vision::getAllBlobs(vector<Cor> cores, bool desenha){

	// IMPORTANTE AQUI PROVAVELMENTE ESSES CARAS DEVEM SER CONVERTIDOS PARA PONTEIROS

	// Vetor contendo as coordenadas de todos os contornos de todas as cores
	vector<vector<cv::Point>> posicaoObjetos;
	//vector<int> teste;
	//teste.push_back(10);

	const int tamanho = cores.size();


	vector<cv::Point> *posicaoObjetos1 = new vector<cv::Point>(cores.size());
	vector<cv::Point> teste[3];



	// Vetor para armazenar todos os contornos dos threads
	//vector< vector< vector<Point> >> todosContornos;
	vector< vector<Point> > *todosContornos1 = new vector<vector<Point>>(cores.size());
	vector<vector<cv::Point>> teste2[3];
	
	// Vetor para armazenar todos os indices de todos os contornos validos dos threads
	//vector< vector<int> > todosIndicesValidosContornos;
	vector<int> *todosIndicesValidosContornos1 = new vector<int>(cores.size());
	vector<int> teste3[3];

	// Converte a imagem para HSV
	Mat processedMat = cv::Mat(originalMat.cols, originalMat.rows, CV_8UC3);
	cv::cvtColor(originalMat, processedMat, cv::COLOR_BGR2HSV);

	// Vetor para armazenar os threads
	vector<std::thread> grupoThread;

	for (int i = 0; i < cores.size(); i++)
	{
		//Abre os threads
		//grupoThread.push_back(std::thread([](vector<cv::Point> *posicaoCor, Cor cor, cv::Mat processedMat, vector< vector<Point> > *contours, vector<int> *validIndices){
		//	
		//	cv::inRange(processedMat, cv::Scalar(cor.minH, cor.minS, cor.minV), cv::Scalar(cor.maxH, cor.maxS, cor.maxV), processedMat);

		//	////morphological opening (remove small objects from the foreground)
		//	//int morphsize = 5;
		//	//erode(processedMat, processedMat, getStructuringElement(MORPH_ELLIPSE, Size(morphsize, morphsize)));
		//	//dilate(processedMat, processedMat, getStructuringElement(MORPH_ELLIPSE, Size(morphsize, morphsize)));

		//	////morphological closing (fill small holes in the foreground)
		//	//dilate(processedMat, processedMat, getStructuringElement(MORPH_ELLIPSE, Size(morphsize * 2, morphsize * 2)));
		//	//erode(processedMat, processedMat, getStructuringElement(MORPH_ELLIPSE, Size(morphsize * 2, morphsize * 2)));

		//	//std::vector< std::vector<Point> > contours;	// Vector para armazenar os contornos
		//	std::vector<Vec4i> hierarchy;
		//	//std::vector<int> IndicesValidosContorno;	// Vector para armazenar os indices dos contornos validos

		//	// Encontra os contornos, o 4 parametros eh interessante pra considerar o level de hierarquia
		//	// o 5 parametro n usar o NONE, de resto acho q ta OK
		//	findContours(processedMat, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_TC89_KCOS);

		//	// Encontra os  contornos
		//	if (!contours.empty()) {
		//		for (size_t i = 0; i < contours.size(); ++i) {
		//			double contour_area = contourArea(contours[i]);
		//			if (contour_area >= cor.minArea && contour_area <= cor.maxArea) // Se o contorno estiver dentro do limite de area
		//				validIndices.push_back(i);
		//		}
		//	}
		//	
		//	for (size_t i = 0; i < validIndices.size(); ++i) {

		//		float centroX, centroY;
		//		// Calculando o centro dos contornoes
		//		cv::Moments momentos = cv::moments(contours[validIndices[i]]);

		//		centroX = momentos.m10 / momentos.m00;
		//		centroY = momentos.m01 / momentos.m00;

		//		cv::Point centroObjeto = cv::Point(centroX, centroY);
		//		// Vetor de pontos dos contornos
		//		posicaoCor.push_back(centroObjeto);				
		//	}
		//}, &teste[i], cores[i], processedMat, &teste2[i], &teste3[i]));

	}
	
	for (int i = 0; i < cores.size(); i++)
	{
		grupoThread[i].join();
	}

	// Desenha os contornos e seus centros

	for (size_t i = 0; i < todosIndicesValidosContornos1->size(); i++)
	{
		for (size_t j = 0; j < todosIndicesValidosContornos1[i].size(); j++)
		{
			if (desenha)
			{
				// Desenha os contornos
				cv::drawContours(originalMat, todosContornos1[i], todosIndicesValidosContornos1[i][j], cv::Scalar(0, 255, 0), 1, 8);
				// Desnha um circulo de raio 0 (um ponto) no centro do contorno 
				cv::circle(originalMat, posicaoObjetos[i][j], 1, cv::Scalar(0, 0, 255), 3);
			}
		}
	}
	return posicaoObjetos;
}

cv::Mat Vision::filtroDeBlobPorArea(cv::Mat matImage, float areaMin, float areaMax){

	std::vector< std::vector<Point> > contours; // Vector for storing contour
	std::vector<Vec4i> hierarchy;
	std::vector<int> small_blobs;
	Mat temp_image;

	// find all contours in the binary image
	matImage.copyTo(temp_image);
	findContours(temp_image, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);

	// Find indices of contours whose area is less than `threshold` 
	if (!contours.empty()) {
		for (size_t i = 0; i < contours.size(); ++i) {
			double contour_area = contourArea(contours[i]);
			if (contour_area < areaMin || contour_area > areaMax)
				small_blobs.push_back(i);
		}
	}

	// Essa tecnica n é muito eficiente mas na hora da calibração acho q estaria OK
	// fill-in all small contours with zeros
	for (size_t i = 0; i < small_blobs.size(); ++i) {
		drawContours(matImage, contours, small_blobs[i], cv::Scalar(0, 0, 0), CV_FILLED, 8);
	}
	return matImage;
}


// TODO: A ser pensado
//Mat filtrodeBlobPorArea(Mat & matImage, float areaMin, float areaMax){
//	int largest_area = 0;
//	int largest_contour_index = 0;
//
//	std::vector< std::vector<Point> > contours; // Vector for storing contour
//	std::vector<Vec4i> hierarchy;
//
//	findContours(matImage, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE); // Find the contours in the image
//
//	for (int i = 0; i< contours.size(); i++) {			// iterate through each contour. 
//		double a = contourArea(contours[i], false);		// Find the area of contour
//		if (a > areaMin && a < areaMax){
//
//		}
//	}
//
//	drawContours(matImage, contours, largest_contour_index, Scalar(255), CV_FILLED, 8, hierarchy); // Draw the largest contour using previously stored index.
//	return matImage;
//}