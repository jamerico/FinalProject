#ifndef CAMERACALIB_H
#define CAMERACALIB_H

#include<QtCore>
#include <QWidget>
#include <QCloseEvent>
#include "ui_cameracalib.h"
#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>
#include "Cor.h"
#include "Vision.h"
#include <vector>
#include "dbStorage.h"
#include "Logger.h"
#include <QInputDialog>

class CameraCalib : public QWidget
{
	Q_OBJECT

public:
	CameraCalib(QWidget *parent = 0);
	~CameraCalib();

	void processFrameAndUpdateGUI(cv::Mat);
	bool mostrarOuAtualizar = false;					// se false então usa show se true então usa Update
	bool transferirImagemParaCameraCalib = false;		// se true mostra a imagem filtrada por cor da webCam na tela de Calibracao de cor
	void closeEvent(QCloseEvent *evento);				// no momento q fecharmos a tela vamos fazer o booleano acima como false
	void HabiltarSlider(bool habilita);					// habilita os sliders para os parametros da cor

	vector<Cor> cores;									// Vetor contendo as cores

	bool atualizaCores = false;

	private slots:
	void on_saveCamCalibButton_clicked();
	void on_addColorButton_clicked();
	void on_deleteButton_clicked();
	void SelecionaCor(QString);

private:
	Ui::CameraCalib uiCalib;

	cv::Mat filtroDeBlobPorArea(cv::Mat, float, float);	// filtra os blobs pela area Minima e pela Maxima
	void LoadColorHSV(string colorName);

	static cv::Mat processedMat;
	QImage qimgProcessed;
	QTimer* tmrTimer;
};

#endif // CAMERACALIB_H
