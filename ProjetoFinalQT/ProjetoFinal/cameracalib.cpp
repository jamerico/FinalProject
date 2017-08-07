#include "cameracalib.h"

cv::Mat CameraCalib::processedMat;
using namespace cv;

#pragma region Construtor/Destrutor
CameraCalib::CameraCalib(QWidget *parent)
	: QWidget(parent)
{
	uiCalib.setupUi(this);	

	HabiltarSlider(false);
	cores = dbStorage::instance()->getAllCor();
	
	for (int i = 0; i < cores.size(); i++)
	{
		uiCalib.colorComboBox->addItem(QString::fromStdString(cores[i].nome));

		if (uiCalib.colorComboBox->currentText().toStdString() == cores[i].nome)
		{
			HabiltarSlider(true);
			uiCalib.minHSlider->setValue(cores[i].minH);
			uiCalib.minSSlider->setValue(cores[i].minS);
			uiCalib.minVSlider->setValue(cores[i].minV);
			uiCalib.maxHSlider->setValue(cores[i].maxH);
			uiCalib.maxSSlider->setValue(cores[i].maxS);
			uiCalib.maxVSlider->setValue(cores[i].maxV);
			uiCalib.minAreaSlider->setValue(cores[i].minArea);
			uiCalib.maxAreaSlider->setValue(cores[i].maxArea);
		}
	}
	
	tmrTimer = new QTimer(this);
	connect(tmrTimer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));	
	connect(uiCalib.colorComboBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
		[=](const QString &text){ SelecionaCor(text); });
	tmrTimer->start(33);
}

CameraCalib::~CameraCalib()
{
	
}
#pragma endregion

void CameraCalib::processFrameAndUpdateGUI(cv::Mat frame){
	// Essa função faz todo o processamento de filtrar a imagem da tela de calibracao

	Cor corDoFiltro; // A cor vermelha é a Troll da brincadeira pq ela é o inicio de fim do range de cores (Ao menos parece)

	//Tentativa de minimar problemas de deteccao com ruidos, isso pode ser resolvido tbm com filtro de area
	//cv::Mat temporaryMat;
	//cv::medianBlur(originalMat, temporaryMat, 3);

	corDoFiltro.minH = (float)uiCalib.minHSlider->value();
	corDoFiltro.minS = (float)uiCalib.minSSlider->value();
	corDoFiltro.minV = (float)uiCalib.minVSlider->value();
	corDoFiltro.maxH = (float)uiCalib.maxHSlider->value();
	corDoFiltro.maxS = (float)uiCalib.maxSSlider->value();
	corDoFiltro.maxV = (float)uiCalib.maxVSlider->value();
	corDoFiltro.minArea = (float)uiCalib.minAreaSlider->value();
	corDoFiltro.maxArea = (float)uiCalib.maxAreaSlider->value();

	uiCalib.minHvalueLabel->setText(QString::number(corDoFiltro.minH));
	uiCalib.minSvalueLabel->setText(QString::number(corDoFiltro.minS));
	uiCalib.minVvalueLabel->setText(QString::number(corDoFiltro.minV));
	uiCalib.maxHvalueLabel->setText(QString::number(corDoFiltro.maxH));
	uiCalib.maxSvalueLabel->setText(QString::number(corDoFiltro.maxS));
	uiCalib.maxVvalueLabel->setText(QString::number(corDoFiltro.maxV));
	uiCalib.minAreavalueLabel->setText(QString::number(corDoFiltro.minArea));
	uiCalib.maxAreavalueLabel->setText(QString::number(corDoFiltro.maxArea));	

	for (int i = 0; i < cores.size(); i++)
	{
		if (uiCalib.colorComboBox->currentText().toStdString() == cores[i].nome)
		{
			cores[i].minH = corDoFiltro.minH;
			cores[i].minS = corDoFiltro.minS;
			cores[i].minV = corDoFiltro.minV;
			cores[i].maxH = corDoFiltro.maxH;
			cores[i].maxS = corDoFiltro.maxS;
			cores[i].maxV = corDoFiltro.maxV;
			cores[i].minArea = corDoFiltro.minArea;
			cores[i].maxArea = corDoFiltro.maxArea;
		}
	}

	// Converte a imagem para HSV	
	processedMat = cv::Mat(frame.cols, frame.rows, CV_8UC3);	
	cv::cvtColor(frame, processedMat, cv::COLOR_BGR2HSV);

	/* PRO VERMELHO PODE SER QUE ISSO VENHA A SER USADO
	
	// Threshold the HSV image, keep only the red pixels
	cv::Mat lower_red_hue_range;
	cv::Mat upper_red_hue_range;
	cv::inRange(processedMat, cv::Scalar(vermelho1.minH, vermelho1.minS, vermelho1.minV), cv::Scalar(vermelho1.maxH, vermelho1.maxS, vermelho1.maxV), lower_red_hue_range);
	cv::inRange(processedMat, cv::Scalar(vermelho2.minH, vermelho2.minS, vermelho2.minV), cv::Scalar(vermelho2.maxH, vermelho2.maxS, vermelho2.maxV), upper_red_hue_range);
	// Combine the above two ranges for color
	cv::Mat red_hue_image;
	cv::addWeighted(lower_red_hue_range, 1.0, upper_red_hue_range, 1.0, 0.0, red_hue_image);
	// Combine the above two ranges for color
	cv::Mat red_hue_image;
	cv::addWeighted(lower_red_hue_range, 1.0, upper_red_hue_range, 1.0, 0.0, red_hue_image);
	
	*/
	cv::Mat filtredMat;
	cv::inRange(processedMat, cv::Scalar(corDoFiltro.minH, corDoFiltro.minS, corDoFiltro.minV), cv::Scalar(corDoFiltro.maxH, corDoFiltro.maxS, corDoFiltro.maxV), filtredMat);
	/*OPERACOES MORFOLOGICAS
	// Fazer operações morfologicas para reduzir a quantidade de ruido do pixel
	// Essa redução tbm pode ser feita ajustando melhor os parametros do filtro de cor

	////morphological opening (remove small objects from the foreground)	
	//erode(filtredMat, filtredMat, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(morphsize, morphsize)));
	//dilate(filtredMat, filtredMat, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(morphsize, morphsize)));
	////morphological closing (fill small holes in the foreground)
	//dilate(filtredMat, filtredMat, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(morphsize * 2, morphsize * 2)));
	//erode(filtredMat, filtredMat, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(morphsize * 2, morphsize * 2)));
	*/

	processedMat = filtroDeBlobPorArea(filtredMat, corDoFiltro.minArea, corDoFiltro.maxArea);

	//processedMat = filtredMat;
	// ----------------------------------TESTE ------------------------------------------

	/*
	// ----------------------------------TESTE 2 ------------------------------------------
	// Setup SimpleBlobDetector parameters.
	SimpleBlobDetector::Params params;

	// Change thresholds
	params.minThreshold = 10;
	params.maxThreshold = 200;

	// Filter by Area.
	params.filterByArea = true;
	params.minArea = 1500;

	// Filter by Circularity
	params.filterByCircularity = true;
	params.minCircularity = 0.1;	

	// Set up detector with params
	Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);

	// Storage for blobs
	std::vector<KeyPoint> keypoints;

	// Detect blobs
	detector->detect(filtredMat, keypoints);

	// Draw detected blobs as red circles.
	// DrawMatchesFlags::DRAW_RICH_KEYPOINTS flag ensures
	// the size of the circle corresponds to the size of blob

	Mat im_with_keypoints;
	drawKeypoints(filtredMat, keypoints, im_with_keypoints, Scalar(0, 0, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

	// Show blobs
	processedMat = im_with_keypoints;*/

	// Passa a imagem na tela
	QImage qimgProcessed((uchar*)processedMat.data, processedMat.cols, processedMat.rows, processedMat.step, QImage::Format_Grayscale8);	
	uiCalib.label->setPixmap(QPixmap::fromImage(qimgProcessed));
}

#pragma region Funcoes Auxiliares
void CameraCalib::HabiltarSlider(bool habilita)
{
	uiCalib.minHSlider->setEnabled(habilita);
	uiCalib.minSSlider->setEnabled(habilita);
	uiCalib.minVSlider->setEnabled(habilita);
	uiCalib.maxHSlider->setEnabled(habilita);
	uiCalib.maxSSlider->setEnabled(habilita);
	uiCalib.maxVSlider->setEnabled(habilita);
	uiCalib.minAreaSlider->setEnabled(habilita);
	uiCalib.maxAreaSlider->setEnabled(habilita);

}

cv::Mat CameraCalib::filtroDeBlobPorArea(cv::Mat matImage, float areaMin, float areaMax){

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

void CameraCalib::LoadColorHSV(string colorName){

	float minH, minS, minV, maxH, maxS, maxV, minArea, maxArea;
	minH = (float)uiCalib.minHSlider->value();
	minS = (float)uiCalib.minSSlider->value();
	minV = (float)uiCalib.minVSlider->value();
	maxH = (float)uiCalib.maxHSlider->value();
	maxS = (float)uiCalib.maxSSlider->value();
	maxV = (float)uiCalib.maxVSlider->value();
	minArea = (float)uiCalib.minAreaSlider->value();
	maxArea = (float)uiCalib.maxAreaSlider->value();

	int index = -1;
	for (int i = 0; i < cores.size(); i++)
	{
		if (colorName == cores[i].nome)
		{
			index = i;
		}
	}

	// Se a cor selecionada existir no banco entao carrega os valores dela , caso contrario carrega o ultimo valor registrado nos sliders
	if (index == -1)
	{
		uiCalib.minHSlider->setValue(minH);
		uiCalib.minSSlider->setValue(minS);
		uiCalib.minVSlider->setValue(minV);
		uiCalib.maxHSlider->setValue(maxH);
		uiCalib.maxSSlider->setValue(maxS);
		uiCalib.maxVSlider->setValue(maxV);
		uiCalib.minAreaSlider->setValue(minArea);
		uiCalib.maxAreaSlider->setValue(maxArea);
	}
	else
	{
		uiCalib.minHSlider->setValue(cores[index].minH);
		uiCalib.minSSlider->setValue(cores[index].minS);
		uiCalib.minVSlider->setValue(cores[index].minV);
		uiCalib.maxHSlider->setValue(cores[index].maxH);
		uiCalib.maxSSlider->setValue(cores[index].maxS);
		uiCalib.maxVSlider->setValue(cores[index].maxV);
		uiCalib.minAreaSlider->setValue(cores[index].minArea);
		uiCalib.maxAreaSlider->setValue(cores[index].maxArea);
	}
}

void CameraCalib::SelecionaCor(QString text){
	HabiltarSlider(true);
	LoadColorHSV(text.toStdString());
}
#pragma endregion

#pragma region Funcionalidades do Usuario
void CameraCalib::on_saveCamCalibButton_clicked(){

	dbStorage::instance()->salvaCores(cores);

	atualizaCores = true;
}

void CameraCalib::on_addColorButton_clicked(){
	bool ok;
	QString text = QInputDialog::getText(0, QObject::tr("QInputDialog::getText()"), QObject::tr("Nome da cor:"), QLineEdit::Normal, "", &ok);
	if (ok)
	{
		uiCalib.colorComboBox->addItem(text);
		int index = uiCalib.colorComboBox->findText(text);
		if (index != -1) { // -1 for not found
			uiCalib.colorComboBox->setCurrentIndex(index);
			// Inicializa com os os valores default dos sliders
			cores.push_back(Cor(text.toStdString(), 0, 0, 0, 180, 255, 255, 0, 154000));
		}
	}
}

void CameraCalib::on_deleteButton_clicked(){

	string nome = uiCalib.colorComboBox->currentText().toStdString();
		
	for (int i = 0; i < cores.size(); i++)
	{
		if (nome == cores[i].nome)
		{
			cores.erase(cores.begin() + i);
			int index = uiCalib.colorComboBox->findText(QString::fromStdString(nome));
			uiCalib.colorComboBox->removeItem(index);
		}
	}
}

void CameraCalib::closeEvent(QCloseEvent *evento)
{
	transferirImagemParaCameraCalib = false;
	evento->accept();

	//QMessageBox::StandardButton resBtn = QMessageBox::question(this, APP_NAME,
	//	tr("Are you sure?\n"),
	//	QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
	//	QMessageBox::Yes);
	//if (resBtn != QMessageBox::Yes) {
	//	event->ignore();
	//}
	//else {
	//	event->accept();
	//}
}
#pragma endregion






