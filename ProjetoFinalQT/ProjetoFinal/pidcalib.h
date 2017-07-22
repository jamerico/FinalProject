#ifndef PIDCALIB_H
#define PIDCALIB_H

#include <QWidget>
#include "ui_pidcalib.h"
#include <QtCore>
#include <QCloseEvent>
#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>
#include "Cor.h"
#include "Vision.h"
#include <vector>
#include "dbStorage.h"
#include "Logger.h"
#include <QInputDialog>
#include "roboconfig.h"
#include "auxiliarqlabel.h"
#include <QKeyEvent>
#include "SerialClass.h"
#include <string>
#include "StrRetorno.h"
#include <queue>

class PIDCalib : public QWidget
{
	Q_OBJECT

public:
	PIDCalib(QWidget *parent = 0);
	~PIDCalib();
	void processFrameAndUpdateGUI(cv::Mat);
	bool mostrarOuAtualizar = false;					// se false então usa show se true então usa Update
	bool transferirImagemParaPIDCalib = false;			// se true mostra a imagem filtrada por cor da webCam na tela de Calibracao de cor
	void closeEvent(QCloseEvent *evento);				// no momento q fecharmos a tela vamos fazer o booleano acima como false
	//void desabiltarParametrosTeste();					// desabilita os sliders e o checkBox para os parametros de teste	
	void atualizaCentros(int, int, int, int);
	vector<cv::Point> geraPontoDesenhaTeste(cv::Point(*)(cv::Point, float, float), cv::Point(*) (cv::Point, cv::Point, float));
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);
	void FindObjects(vector<vector<cv::Point>>);
	bool FindObjects(vector<vector<cv::Point>>, bool);
	void DesenhaObjetos(Objeto);
	

	vector<Cor> cores;
	
	vector<paramControle> parametrosPid;
	vector<Objeto> objetos;
	vector<Trajetoria> trajetorias;

	Objeto robo;
	Objeto roboSecundario;

	Position melhorPosition = Position(0, 0, 0);

	//Serial s;

	bool atualizaControles = false;

private slots:
	void on_saveButton_clicked();
	void on_newRobotButton_clicked();
	void on_newPIDButton_clicked();
	void on_startTestButton_clicked();
	void on_stopTestButton_clicked();	
	void selecionaRobo(QString, int);
	void selecionaPID(QString);
	void selecionaTrajetoria(QString);
	void atualizaPeriodo(int);
	void atualizaRaio(int);
	void atualizaSentido(int);	
	void atualizaPL(double);
	void atualizaDL(double);
	void atualizaIL(double);
	void atualizaPA(double);
	void atualizaDA(double);
	void atualizaIA(double);
	void atualizaParamControle();
	void atualizaSetPoint();
	void mousePressed();
	void desabiltarParametrosTeste(int);

private:
	Ui::PIDCalib uiPID;

	static cv::Mat drawMat;					// Matriz usada para as execucoes com o Opencv
	QImage qimgDraw;
	QTimer* tmrTimer;

	bool runningTest = false;				// booleano que diz se tem um teste rodando	

	int coordenadaX = -1;					// coordenada X clicada para o teste Point and Click
	int coordenadaY = -1;					// coordenada Y clicada para o teste Point and Click

	int centroCirculoX = -1;				// coordenada X clicada para o centro do teste Circulo
	int centroCirculoY = -1;				// coordenada Y clicada para o centro do teste Circulo

	int centroLemniscataX = -1;				// coordenada X clicada para o centro do teste Lemniscata
	int centroLemniscataY = -1;				// coordenada Y clicada para o centro do teste Lemniscata

	int corrdenadasLinhaX[2];				// coordenadas X clicadas para o teste Linha
	int corrdenadasLinhaY[2];				// coordenadas Y clicadas para o teste Linha
	
	float periodo = 0;						// Valor do periodo do teste (Caso tenha)
	float raio = 0;							// Valor do raio do teste (Caso tenha)
	bool sentido = false;					// Sentido anti-horario se "false", sentido horario caso contrario para movimentos circulares
											// para movimentos lineares diz o sentido que será seguido; true = cima/direita, false = baixo/esquerda

	paramControle paramC = paramControle("", 0, 0, 0, 0, 0, 0);		// parametros de controle
	cv::Point center1 = cv::Point(-1, -1);							// ponto clicado 1
	cv::Point center2 = cv::Point(-1, -1);							// ponto clicado 2 caso exista
	Trajetoria trajAtual;											// ultima trajetoria selecionada
	RoboConfig *roboCam;											// ponteiro para chamar a tela de configuracao de robos

	void atualizaTextoTela(StrRetorno rtn, long, double);

	cv::Mat imgTrajetoria;
	bool desenhouTraj = false;
	
	long frameNum = 0;
	clock_t tempo;
	double FPS;
	double MediaFPS;
	deque<double> dqMediaFPS;

};

#endif // PIDCALIB_H
