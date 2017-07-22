#ifndef PROJETOFINAL_H
#define PROJETOFINAL_H

#include <QtWidgets/QMainWindow>
#include <QCloseEvent>
#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>
#include "cameracalib.h"
#include "Cor.h"
#include "dbStorage.h"
#include "Logger.h"
#include "ui_projetofinal.h"
#include "Vision.h"
#include <thread>
#include "pidcalib.h"
#include "roboconfig.h"
#include "SerialClass.h"
//#include "opencv2/cudafilters.hpp"
//#include "opencv2/cudaimgproc.hpp"
#include "Curva.h"
#include <QKeyEvent>


//using namespace cv;

//namespace Ui{
//class ProjetoFinal;
//}

class ProjetoFinal : public QMainWindow
{
	Q_OBJECT

public:
	ProjetoFinal(QWidget *parent = 0);
	~ProjetoFinal();	
	vector<Cor> cores;							// vetor de cores que serao carregadas do banco no comboBox
	//map<string, Cor> mapCores;
	vector<paramControle> nomesPid;				// vetor de configuracoes de PID que serao carregadas do banco	
	vector<Objeto> objetos;						// vetor de objetos que serao carregadas do banco
	map<string, cv::Mat> desenhosTrajetorias;
	map<string, bool> mapTrajetoriasDesenhadas;
	//map<string, cv::Scalar> mapCorObjeto;
	vector<cv::Scalar> coresDrawObj;
	void keyReleaseEvent(QKeyEvent *event);

	void FindObjects(vector<vector<cv::Point>>); // Encontra os objetos apartir do vetor de cores identificado

	void ProjetoFinal::closeEvent(QCloseEvent *evento);

public slots:
	void processFrameAndUpdateGUI();

private slots:
	void on_startButton_clicked();
	void on_pauseButton_clicked();
	void on_checkShowBlob_stateChanged(int state);
	void on_checkShowimageBox_stateChanged(int state);
	void on_checkShowDrawBox_stateChanged(int state);
	void on_actionCalibrar_Filtros_de_Cor_triggered();
	void on_actionCalibrar_Controle_triggered();
	void on_actionNovo_Robo_triggered();
	void on_checkShowTraj_stateChanged(int state);
	

private:
	Ui::ProjetoFinalClass ui;
	CameraCalib *filtroCam;
	PIDCalib *pidCam;
	RoboConfig *roboCam;

	//Trajetoria trajAux;

	cv::VideoCapture capWebCam;

	cv::Mat originalMat;
	//cv::Mat processedMat;

	QImage qimgOriginal;
	//QImage qimgProcessed;

	//Vision frame = Vision(0);

	QTimer* tmrTimer;	
	void Observador();


	void DesenhaTrajetorias();
	void DesenhaTrajetorias2();

	bool mostrarImagemNaTela = false;	// se true cria uma tela para mostrar a imagem da webCam
	bool mostrarTrajetorias = false;
	bool runningTest = false;

	long frameNum = 0;
	clock_t tempo;
	double FPS;
	double MediaFPS;
	deque<double> dqMediaFPS;
	
	//bool transferirImagemParaCameraCalib = false;		// se true mostra a imagem filtrada por cor da webCam na tela de Calibracao de cor


	//int getIdxCorPorNome(string, vector<Cor>);
	void DrawCar(Objeto obj);
	void DrawCar(Objeto obj, cv::Scalar pCor);
};

#endif // PROJETOFINAL_H