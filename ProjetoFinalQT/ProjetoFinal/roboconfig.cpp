#include "roboconfig.h"

#pragma region Construtor/Destrutor

RoboConfig::RoboConfig(QWidget *parent)
	: QWidget(parent)
{
	// Inicializa a tela de configuracao de objetos
	uiRobo.setupUi(this);	
	/*
	  Primeiro: Carrega as opcoes de PID
	  Segundo:  Carrega as opcoes de Cores
	  Terceiro: Carrega as opcoes de endereco do XBee
	  Quarto:   Carrega as opcoes de tipo de objeto 
	  Quinto:   Carrega as opcoes de objeto (Por enquanto precisa ser o ultimo)
	*/
	// Carga dos PIDs	
	nomesPid = dbStorage::instance()->getAllParamsControle();
	for (int i = 0; i <= nomesPid.size(); i++)
	{
		if (i == 0)
		{
			uiRobo.pidComboBox->addItem(QString::fromStdString(" "));
		}
		else
		{
			uiRobo.pidComboBox->addItem(QString::fromStdString(nomesPid[i - 1].nome));
		}
	}

	// Carga das Cores
	cores = dbStorage::instance()->getAllCor();
	for (int i = 0; i <= cores.size(); i++)
	{
		if (i == 0)
		{
			uiRobo.corPriComboBox->addItem(QString::fromStdString(" "));
			uiRobo.corSecComboBox->addItem(QString::fromStdString(" "));
			uiRobo.corTerComboBox->addItem(QString::fromStdString(" "));
		}
		else
		{
			uiRobo.corPriComboBox->addItem(QString::fromStdString(cores[i - 1].nome));
			uiRobo.corSecComboBox->addItem(QString::fromStdString(cores[i - 1].nome));
			uiRobo.corTerComboBox->addItem(QString::fromStdString(cores[i - 1].nome));
		}		
	}

	// Carga dos Enderecos do XBee
	endXBee.push_back(" ");
	endXBee.push_back("AAAA");
	endXBee.push_back("BBBB");
	endXBee.push_back("CCCC");
	endXBee.push_back("ABAB");
	endXBee.push_back("ACAC");
	endXBee.push_back("ABAC");
	endXBee.push_back("ACAB");
	endXBee.push_back("AAAB");
	endXBee.push_back("AAAC");
	endXBee.push_back("BAAB");
	endXBee.push_back("CAAC");
	endXBee.push_back("CCAA");

	for (int i = 0; i < endXBee.size(); i++)
	{
		uiRobo.xBeeAdressComboBox->addItem(QString::fromStdString(endXBee[i]));
	}

	// Carga dos tipos de Objeto
	for (int i = TipoObjeto::Robô; i <= TipoObjeto::Indefinido; i++)
	{	
		string text;
		switch (i)
		{
		case Robô:
			text += std::to_string(i) + " - Robo";
			uiRobo.TipoObjetoComboBox->addItem(QString::fromStdString(text));
			break;
		case Obstaculo:
			text += std::to_string(i) + " - Obstaculo";
			uiRobo.TipoObjetoComboBox->addItem(QString::fromStdString(text));
			break;
		case Indefinido:
			text += std::to_string(i) + " - Indefinido";
			uiRobo.TipoObjetoComboBox->addItem(QString::fromStdString(text));
			break;
		default:
			break;
		}		
	}


	// Carga das Trajetorias
	trajetoriasNames = dbStorage::instance()->getAllTrajetoriaNames();
	uiRobo.trajComboBox->addItem("");
	for each (string name in trajetoriasNames)
	{
		uiRobo.trajComboBox->addItem(QString::fromStdString(name));
	}

	// Carga dos Objetos
	objetos = dbStorage::instance()->getAllObjetos();	

	for (int i = 0; i < objetos.size(); i++)
	{
		uiRobo.nomeComboBox->addItem(QString::fromStdString(objetos[i].nome));

		if (uiRobo.nomeComboBox->currentText().toStdString() == objetos[i].nome)
		{		
			SelecionaRobo(QString::fromStdString(objetos[i].nome));			
		}
	}



	connect(uiRobo.nomeComboBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
		[=](const QString &text){ SelecionaRobo(text); });	
	connect(uiRobo.TipoObjetoComboBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
		[=](const QString &text){ AtualizaTipo(); });
	connect(uiRobo.pidComboBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
		[=](const QString &text){ AtualizaPID(); });
	connect(uiRobo.corPriComboBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
		[=](const QString &text){ AtualizaCorPri(); });
	connect(uiRobo.corSecComboBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
		[=](const QString &text){ AtualizaCorSec(); });
	connect(uiRobo.corTerComboBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
		[=](const QString &text){ AtualizaCorTer(); });
	connect(uiRobo.xBeeAdressComboBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
		[=](const QString &text){ AtualizaEndXBee(); });
	connect(uiRobo.trajComboBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
		[=](const QString &text){ AtualizaTrajetoria(); });

	connect(uiRobo.VelSpinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
		[=](int i){ AtualizaSetPointVel(); });

}

RoboConfig::~RoboConfig()
{

}

#pragma endregion

#pragma region Eventos Disparados

void RoboConfig::SelecionaRobo(QString nome){

	// Encontra o indice do Objeto no vetor
	for (int i = 0; i < objetos.size(); i++)
	{
		if (nome.toStdString() == objetos[i].nome)
		{			
			// Seleciona o tipo do objeto
			string text;
			switch (objetos[i].tipo)
			{
			case Robô:
				text += std::to_string(objetos[i].tipo) + " - Robo";
				break;
			case Obstaculo:
				text += std::to_string(objetos[i].tipo) + " - Obstaculo";
				break;
			case Indefinido:
				text += std::to_string(objetos[i].tipo) + " - Indefinido";
				break;
			default:
				break;
			}
			int indexTipo = uiRobo.TipoObjetoComboBox->findText(QString::fromStdString(text));
			if (indexTipo != -1) {
				uiRobo.TipoObjetoComboBox->setCurrentIndex(indexTipo);
			}

			// Seleciona o PID associado ao objeto
			int indexPID = uiRobo.pidComboBox->findText(QString::fromStdString(objetos[i].ctrl.nome));
			if (indexPID != -1) {
				uiRobo.pidComboBox->setCurrentIndex(indexPID);
			}
			else
			{
				uiRobo.pidComboBox->setCurrentIndex(0);
			}
			// Seleciona a cor Primaria associada ao objeto
			int indexCorPri = uiRobo.corPriComboBox->findText(QString::fromStdString(objetos[i].primColor.nome));
			if (indexCorPri != -1) {
				uiRobo.corPriComboBox->setCurrentIndex(indexCorPri);
			}
			else
			{
				uiRobo.corPriComboBox->setCurrentIndex(0);
			}
			// Seleciona a cor Secundaria associada ao objeto
			int indexCorSec = uiRobo.corSecComboBox->findText(QString::fromStdString(objetos[i].secColor.nome));
			if (indexCorSec != -1) {
				uiRobo.corSecComboBox->setCurrentIndex(indexCorSec);
			}
			else
			{
				uiRobo.corSecComboBox->setCurrentIndex(0);
			}
			// Seleciona a cor Terciaria associada ao objeto
			int indexCorTer = uiRobo.corTerComboBox->findText(QString::fromStdString(objetos[i].terColor.nome));
			if (indexCorTer != -1) {
				uiRobo.corTerComboBox->setCurrentIndex(indexCorTer);
			}
			else
			{
				uiRobo.corTerComboBox->setCurrentIndex(0);
			}
			// Seleciona a configuracao do XBee associada ao objeto
			int indexXBee = uiRobo.xBeeAdressComboBox->findText(QString::fromStdString(objetos[i].cfgXbee));
			if (indexXBee != -1) {
				uiRobo.xBeeAdressComboBox->setCurrentIndex(indexXBee);
			}
			else
			{
				uiRobo.xBeeAdressComboBox->setCurrentIndex(0);
			}

			//Seleciona a Trajetoria
			int indexTraj = uiRobo.trajComboBox->findText(QString::fromStdString(objetos[i].traj.nome));
			if (indexTraj != -1)
			{
				uiRobo.trajComboBox->setCurrentIndex(indexTraj);
			}
			else{
				uiRobo.trajComboBox->setCurrentIndex(0);
			}

			//Preenche SetPointVel
			uiRobo.VelSpinBox->setValue(objetos[i].setPointVel);
		}
	}	
}

void RoboConfig::AtualizaTipo(){	
	// Atualiza o tipo do objeto no VETOR n no banco

	// Isso pode ser feito pois o preenchimento e construido na msm ordem que o vetor
	//objetos[uiRobo.nomeComboBox->currentIndex()].tipo = (TipoObjeto)uiRobo.TipoObjetoComboBox->currentIndex();

	for (int i = 0; i < objetos.size(); i++)
	{		
		if (uiRobo.nomeComboBox->currentText().toStdString() == objetos[i].nome)
		{
			objetos[i].tipo = (TipoObjeto)uiRobo.TipoObjetoComboBox->currentIndex();
		}
	}

	string tipoAtual = uiRobo.TipoObjetoComboBox->currentText().toStdString();
	if (tipoAtual != "0 - Robo")
	{
		HabilitaComboBox(false);
	}
	else
	{
		HabilitaComboBox(true);
	}
}

void RoboConfig::AtualizaPID(){
	// Atualiza a configuracao de PID do objeto no VETOR n no banco

	//objetos[uiRobo.nomeComboBox->currentIndex()].ctrl.nome = uiRobo.pidComboBox->currentText().toStdString();

	for (int i = 0; i < objetos.size(); i++)
	{
		if (uiRobo.nomeComboBox->currentText().toStdString() == objetos[i].nome)
		{
			objetos[i].ctrl.nome = uiRobo.pidComboBox->currentText().toStdString();
		}
	}
}

void RoboConfig::AtualizaCorPri(){
	// Atualiza a cor primaria do objeto no VETOR n no banco

	//objetos[uiRobo.nomeComboBox->currentIndex()].primColor.nome = uiRobo.corPriComboBox->currentText().toStdString();

	for (int i = 0; i < objetos.size(); i++)
	{
		if (uiRobo.nomeComboBox->currentText().toStdString() == objetos[i].nome)
		{
			objetos[i].primColor.nome = uiRobo.corPriComboBox->currentText().toStdString();
		}
	}
}

void RoboConfig::AtualizaCorSec(){
	// Atualiza a cor secundaria do objeto no VETOR n no banco
	
	//objetos[uiRobo.nomeComboBox->currentIndex()].secColor.nome = uiRobo.corSecComboBox->currentText().toStdString();

	for (int i = 0; i < objetos.size(); i++)
	{
		if (uiRobo.nomeComboBox->currentText().toStdString() == objetos[i].nome)
		{
			objetos[i].secColor.nome = uiRobo.corSecComboBox->currentText().toStdString();
		}
	}
}

void RoboConfig::AtualizaCorTer(){
	// Atualiza a cor terciaria do objeto no VETOR n no banco

	//objetos[uiRobo.nomeComboBox->currentIndex()].terColor.nome = uiRobo.corTerComboBox->currentText().toStdString();

	for (int i = 0; i < objetos.size(); i++)
	{
		if (uiRobo.nomeComboBox->currentText().toStdString() == objetos[i].nome)
		{
			objetos[i].terColor.nome = uiRobo.corTerComboBox->currentText().toStdString();
		}
	}
}

void RoboConfig::AtualizaEndXBee(){
	// Atualiza o endereco do XBee do objeto no VETOR n no banco

	//objetos[uiRobo.nomeComboBox->currentIndex()].cfgXbee = uiRobo.xBeeAdressComboBox->currentText().toStdString();

	for (int i = 0; i < objetos.size(); i++)
	{
		if (uiRobo.nomeComboBox->currentText().toStdString() == objetos[i].nome)
		{
			objetos[i].cfgXbee = uiRobo.xBeeAdressComboBox->currentText().toStdString();
		}
	}
}

void RoboConfig::AtualizaTrajetoria(){
	for (int i = 0; i < objetos.size(); i++)
	{
		if (uiRobo.nomeComboBox->currentText().toStdString() == objetos[i].nome)
		{
			objetos[i].traj = dbStorage::instance()->getTrajetoria(uiRobo.trajComboBox->currentText().toStdString());
		}
	}

}

void RoboConfig::AtualizaSetPointVel(){
	for (int i = 0; i < objetos.size(); i++)
	{
		if (uiRobo.nomeComboBox->currentText().toStdString() == objetos[i].nome)
		{
			objetos[i].setPointVel = uiRobo.VelSpinBox->value();
		}
	}

}

void RoboConfig::closeEvent(QCloseEvent *evento)
{
	chamaConfigRobo = false;
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

#pragma region Funcionalidades do Usuario

void RoboConfig::on_saveButton_clicked(){
	// salva as configuracoes dos robos

	for (int i = 0; i < objetos.size(); i++)
	{
		if (objetos[i].tipo != TipoObjeto::Robô)
		{
			objetos[i].cfgXbee = "";
			objetos[i].ctrl = paramControle::paramControle();
		}

		
	}

	dbStorage::instance()->salvaObjetos(objetos);

	atualizaObjetos = true;
}

void RoboConfig::on_newButton_clicked(){
	// inicializa uma nova configuracao de robo
	bool ok;
	QString text = QInputDialog::getText(0, QObject::tr("QInputDialog::getText()"), QObject::tr("Nome:"), QLineEdit::Normal, "", &ok);
	if (ok)
	{
		uiRobo.nomeComboBox->addItem(text);
		int index = uiRobo.nomeComboBox->findText(text);
		if (index != -1) { // -1 for not found
			uiRobo.nomeComboBox->setCurrentIndex(index);
			objetos.push_back(Objeto());
			objetos.back().nome = text.toStdString();
			
			// seleciona as opcoes default
			uiRobo.TipoObjetoComboBox->setCurrentIndex(TipoObjeto::Indefinido);
			uiRobo.corPriComboBox->setCurrentIndex(0);
			uiRobo.corSecComboBox->setCurrentIndex(0);
			uiRobo.corTerComboBox->setCurrentIndex(0);
			uiRobo.xBeeAdressComboBox->setCurrentIndex(0);
		}
	}
}

void RoboConfig::on_deleteButton_clicked(){
	// deleta uma configuracao de robo
	string nome = uiRobo.nomeComboBox->currentText().toStdString();

	for (int i = 0; i < objetos.size(); i++)
	{
		if (nome == objetos[i].nome)
		{
			objetos.erase(objetos.begin() + i);
			int index = uiRobo.nomeComboBox->findText(QString::fromStdString(nome));
			uiRobo.nomeComboBox->removeItem(index);
		}
	}
}

#pragma endregion

#pragma region Funcoes Auxiliares

void RoboConfig::HabilitaComboBox(bool habilita){
	uiRobo.xBeeAdressComboBox->setEnabled(habilita);
	uiRobo.pidComboBox->setEnabled(habilita);
}

#pragma endregion