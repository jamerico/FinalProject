#ifndef ROBOCONFIG_H
#define ROBOCONFIG_H

#include <QWidget>
#include "ui_roboconfig.h"
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

class RoboConfig : public QWidget
{
	Q_OBJECT

public:
	RoboConfig(QWidget *parent = 0);
	~RoboConfig();
	void processFrameAndUpdateGUI();
	bool mostrarOuAtualizar = false;			// se false então usa show se true então usa Update
	bool chamaConfigRobo = false;				// se true então a tela eh chamada, caso contrario ela eh deletada ou n eh chamada
	void closeEvent(QCloseEvent *evento);		// no momento q fecharmos a tela vamos fazer o booleano acima como false
	void HabilitaComboBox(bool habilita);		// habilita ou desabilita os combobox de PID e endereco do XBee	

	vector<Cor> cores;							// vetor de cores que serao carregadas do banco no comboBox
	vector<paramControle> nomesPid;				// vetor de configuracoes de PID que serao carregadas do banco no comboBox
	vector<string> endXBee;						// vetor de enderecos do XBee que serao carregadas no comboBox
	vector<Objeto> objetos;						// vetor de objetos que serao carregadas do banco no comboBox
	vector<string> trajetoriasNames;

	bool atualizaObjetos = false;

private slots:
	void on_saveButton_clicked();
	void on_newButton_clicked();
	void on_deleteButton_clicked();
	void SelecionaRobo(QString);
	void AtualizaTipo();
	void AtualizaPID();
	void AtualizaCorPri();
	void AtualizaCorSec();
	void AtualizaCorTer();
	void AtualizaEndXBee();
	void AtualizaSetPointVel();
	void AtualizaTrajetoria();

private:
	Ui::RoboConfig uiRobo;	
};

#endif // ROBOCONFIG_H
