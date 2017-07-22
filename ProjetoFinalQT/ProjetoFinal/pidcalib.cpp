#include "pidcalib.h"

using namespace cv;

cv::Mat PIDCalib::drawMat;

#pragma region Construtor/Destrutor
PIDCalib::PIDCalib(QWidget *parent)
	: QWidget(parent)
{
	uiPID.setupUi(this);
	cv::namedWindow("Imagem", 1);

	for (size_t i = 0; i < 31; i++)
	{
		dqMediaFPS.push_back(20);
	}

	// Carrega as configuracoes de Testes existentes e poe no combobox
	//for (int i = 0; i < uiPID.tabWidget->count(); i++)
	//{
	//	testes.push_back(uiPID.tabWidget->tabText(i).toStdString());
	//}

	// Inicializacao das coordenadas do teste de linha
	corrdenadasLinhaX[0] = -1;
	corrdenadasLinhaX[1] = -1;
	corrdenadasLinhaY[0] = -1;
	corrdenadasLinhaY[1] = -1;
	
	// Carrega as configuracoes de PID existentes e poe no combobox
	parametrosPid = dbStorage::instance()->getAllParamsControle();
	for (int i = 0; i < parametrosPid.size(); i++)
	{
		uiPID.pidComboBox->addItem(QString::fromStdString(parametrosPid[i].nome));
	}

	// Carrega as configuracoes de Robos existentes e poe no combobox
	objetos = dbStorage::instance()->getAllObjetos();

	for (int i = 0; i < objetos.size(); i++)
	{
		if (objetos[i].tipo == TipoObjeto::Robô)
		{
			// so adiciona o objeto no comboBox se for robo
			uiPID.robotComboBox->addItem(QString::fromStdString(objetos[i].nome));
			if (uiPID.robotComboBox->currentText().toStdString() == objetos[i].nome)
			{
				selecionaRobo(QString::fromStdString(objetos[i].nome), 0);
			}
		}		
	}
	
	// Preenche o combobox de carros secundarios
	for (int i = 0; i < objetos.size(); i++)
	{
		if (objetos[i].tipo == TipoObjeto::Robô)
		{			
			uiPID.robotSecComboBox->addItem(QString::fromStdString(objetos[i].nome));
			if (uiPID.robotSecComboBox->currentText().toStdString() == objetos[i].nome)
			{
				selecionaRobo(QString::fromStdString(objetos[i].nome), 1);
			}
		}
	}

	//uiPID.trajComboBox->addItem(QString::fromStdString(""));
	//uiPID.trajComboBox->addItem(QString::fromStdString("circulo_r120_xc320_yc240"));	
	uiPID.trajComboBox->addItem("");
	trajetorias = dbStorage::instance()->getAllTrajetoria();

	//trajetorias.push_back(dbStorage::instance()->getTrajetoria("circulo_r120_xc320_yc240"));
	for (int i = 0; i < trajetorias.size(); i++)
	{
		uiPID.trajComboBox->addItem(QString::fromStdString(trajetorias[i].nome));
	}

	cores = dbStorage::instance()->getAllCor();

	tmrTimer = new QTimer(this);
	tmrTimer->setInterval(33);
	tmrTimer->setTimerType(Qt::PreciseTimer);
	// Atualizacoes temporais
	connect(tmrTimer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));

	// Alteracoes na aba de teste
	connect(uiPID.tabWidget, SIGNAL(currentChanged(int)), this, SLOT(on_stopTestButton_clicked()));
	// Alteracoes nos comboboxes
	connect(uiPID.robotComboBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
		[=](const QString &text){ selecionaRobo(text, 0); });
	connect(uiPID.pidComboBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
		[=](const QString &text){ selecionaPID(text); });
	connect(uiPID.trajComboBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
		[=](const QString &text){ selecionaTrajetoria(text); });

	connect(uiPID.robotSecComboBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
		[=](const QString &text){ selecionaRobo(text, 1); });

	// Alteracoes nos sliders de Raio
	connect(uiPID.radiusSliderCirculo, SIGNAL(valueChanged(int)), this, SLOT(atualizaRaio(int)));
	connect(uiPID.radiusSliderLemniscata, SIGNAL(valueChanged(int)), this, SLOT(atualizaRaio(int)));
	// Alteracoes nos sliders de Periodo
	connect(uiPID.periodSliderCirculo, SIGNAL(valueChanged(int)), this, SLOT(atualizaPeriodo(int)));
	connect(uiPID.periodSliderLemniscata, SIGNAL(valueChanged(int)), this, SLOT(atualizaPeriodo(int)));
	// Alteracoes nos checBoxes de Sentido
	connect(uiPID.clockwiseCheckBoxCirculo, SIGNAL(stateChanged(int)), this, SLOT(atualizaSentido(int)));
	connect(uiPID.clockwiseCheckBoxLemniscata, SIGNAL(stateChanged(int)), this, SLOT(atualizaSentido(int)));
	connect(uiPID.clockwiseCheckBoxLinha, SIGNAL(stateChanged(int)), this, SLOT(atualizaSentido(int)));
	connect(uiPID.clockwiseCheckBoxTraj, SIGNAL(stateChanged(int)), this, SLOT(atualizaSentido(int)));
	connect(uiPID.manualCheckBox, SIGNAL(stateChanged(int)), this, SLOT(desabiltarParametrosTeste(int)));
	// Alteracoes nos SpinBoxes
	connect(uiPID.PLSpinBox, SIGNAL(valueChanged(double)), this, SLOT(atualizaParamControle()));
	connect(uiPID.DLSpinBox, SIGNAL(valueChanged(double)), this, SLOT(atualizaParamControle()));
	connect(uiPID.ILSpinBox, SIGNAL(valueChanged(double)), this, SLOT(atualizaParamControle()));
	connect(uiPID.PASpinBox, SIGNAL(valueChanged(double)), this, SLOT(atualizaParamControle()));
	connect(uiPID.DASpinBox, SIGNAL(valueChanged(double)), this, SLOT(atualizaParamControle()));
	connect(uiPID.IASpinBox, SIGNAL(valueChanged(double)), this, SLOT(atualizaParamControle()));

	//SetPointVel
	connect(uiPID.velSpinBox, SIGNAL(valueChanged(double)), this, SLOT(atualizaSetPoint()));


	// Eventos no Mouse
//	connect(uiPID.videoOut, SIGNAL(MousePressed()), this, SLOT(mousePressed()));
	
	tmrTimer->start();
}

PIDCalib::~PIDCalib()
{
	
}
#pragma endregion

#pragma region Funcoes Auxiliares
cv::Point calculaPontoCirculo(cv::Point centro, float raio, float tempo){

	vector<cv::Point> pontosCirculo;
	float x, y;

	x = raio*cos(tempo) + centro.x;
	y = raio*sin(tempo) + centro.y;
	return cv::Point(x, y);

	//for (float i = 0; i < 10; i+=0.1)
	//{
	//	x = raio*cos(i) + centro.x;
	//	y = raio*sin(i) + centro.y;
	//	pontosCirculo.push_back(cv::Point(x, y));		
	//}
	//return pontosCirculo;
}

cv::Point calculaPontoLemniscata(cv::Point centro, float raio, float tempo){

	vector<cv::Point> pontosLemniscata;
	float x, y;

	x = raio*sqrt(2)*cos(tempo) / (pow(sin(tempo), 2) + 1) + centro.x;
	y = raio*sqrt(2)*cos(tempo)*sin(tempo) / (pow(sin(tempo), 2) + 1) + centro.y;

	return cv::Point(x, y);

	//for (float i = 0; i <= 10; i += 0.01)
	//{
	//	x = raio*sqrt(2)*cos(i) / (pow(sin(i), 2) + 1) + centro.x;
	//	y = raio*sqrt(2)*cos(i)*sin(i) / (pow(sin(i), 2) + 1) + centro.y;
	//	pontosLemniscata.push_back(cv::Point(x, y));
	//}
	//return pontosLemniscata;
}

cv::Point calculaPontoLinha(cv::Point inicio, cv::Point fim, float tempo){

	vector<cv::Point> pontosLinha;
	float x, y, a, b, difY, difX;

	difY = (float)(inicio.y - fim.y);
	difX = (float)(inicio.x - fim.x);
	a = (float)(difY / difX);
	b = inicio.y - (a*inicio.x);
	x = tempo;
	y = a*x + b;

	return cv::Point(tempo, y);

	//for (x = inicio.x; x <= fim.x; x ++)
	//{
	//	y = a*x + b;
	//	pontosLinha.push_back(cv::Point(x, y));
	//}
	//return pontosLinha;
}

void PIDCalib::FindObjects(vector<vector<cv::Point>> posicaoCores){

	double limiar = 100;
	for (int idxObj = 0; idxObj < objetos.size(); idxObj++)
	{
		bool achou = false;
		//pega cor secundária
		Cor corSecTemp = objetos[idxObj].secColor;
		int idxCorSecTemp = Cor::getIdxCorPorNome(corSecTemp.nome, cores);

		Cor corPrimTemp = objetos[idxObj].primColor;
		int idxCorPrimTemp = Cor::getIdxCorPorNome(corPrimTemp.nome, cores);

		//varre todas as posições das cor secundária do objeto em questão
		for (int idxSec = 0; idxSec < posicaoCores[idxCorSecTemp].size() && !achou; idxSec++)
		{
			Position pSec(posicaoCores[idxCorSecTemp][idxSec].x, posicaoCores[idxCorSecTemp][idxSec].y);
			if (pSec.x != -1000)
			{
				//varre todas as posições da cor primária do objeto em questão
				for (int idxPrim = 0; idxPrim < posicaoCores[idxCorPrimTemp].size() && !achou; idxPrim++)
				{
					Position pPrim(posicaoCores[idxCorPrimTemp][idxPrim].x, posicaoCores[idxCorPrimTemp][idxPrim].y);
					if (pPrim.x != -1000)
					{
						if (pPrim.distance(pSec) < limiar)
						{
							achou = true;
							objetos[idxObj].setPosAtual(pPrim, pSec);
							posicaoCores[idxCorPrimTemp][idxPrim].x = -1000;
							posicaoCores[idxCorSecTemp][idxSec].x = -1000;
							if (uiPID.showCarsCheckBox->isChecked())
							{
								DesenhaObjetos(objetos[idxObj]);
							}

						}
					}
				}
			}
		}

	}
}



bool PIDCalib::FindObjects(vector<vector<cv::Point>> posicaoCores, bool global){
	bool achou = false;

	if (robo.traj.nome != "")
	{

		double limiar = 100;
		//for (int idxObj = 0; idxObj < objetos.size(); idxObj++)
		//{
		//pega cor secundária
		Cor corSecTemp = robo.secColor;
		int idxCorSecTemp = Cor::getIdxCorPorNome(corSecTemp.nome, cores);

		Cor corPrimTemp = robo.primColor;
		int idxCorPrimTemp = Cor::getIdxCorPorNome(corPrimTemp.nome, cores);

		//varre todas as posições das cor secundária do objeto em questão
		for (int idxSec = 0; idxSec < posicaoCores[idxCorSecTemp].size() && !achou; idxSec++)
		{
			Position pSec(posicaoCores[idxCorSecTemp][idxSec].x, posicaoCores[idxCorSecTemp][idxSec].y);
			if (pSec.x != -1000)
			{
				//varre todas as posições da cor primária do objeto em questão
				for (int idxPrim = 0; idxPrim < posicaoCores[idxCorPrimTemp].size() && !achou; idxPrim++)
				{
					Position pPrim(posicaoCores[idxCorPrimTemp][idxPrim].x, posicaoCores[idxCorPrimTemp][idxPrim].y);
					if (pPrim.x != -1000)
					{
						if (pPrim.distance(pSec) < limiar)
						{
							achou = true;
							robo.setPosAtual(pPrim, pSec);
							posicaoCores[idxCorPrimTemp][idxPrim].x = -1000;
							posicaoCores[idxCorSecTemp][idxSec].x = -1000;
							if (uiPID.showCarsCheckBox->isChecked())
							{
								DesenhaObjetos(robo);
							}

						}
					}
				}
			}
			//}
		}

	}
	return achou;
}


#pragma endregion

double MediaDeque(deque<double> pDq){
	double sum = 0;
	for (int i = 0; i < pDq.size(); i++)
	{
		sum += pDq[i];
	}
	return sum / pDq.size();
}

void PIDCalib::processFrameAndUpdateGUI(cv::Mat frame){
	frameNum++;
	FPS = 1 / ((clock() - tempo) / ((double)CLOCKS_PER_SEC));
	tempo = clock();
	dqMediaFPS.pop_front();
	dqMediaFPS.push_back(FPS);
	MediaFPS = MediaDeque(dqMediaFPS);
	robo.taxaH = 1/MediaFPS;
	Logger::Output("FPS: %f\n", FPS);
	Logger::Output("FPS Médio: %f\n", MediaFPS);
	//Logger::Output("FPS : %f\n", FPS);
	
	
	/*queue<double> queueMedia(deque<double>(20));
	
	vector<double> teste(30);

	teste.pop_back
	teste.push_back(FPS);*/


	// Essa função faz todo o processamento da imagem da para o video de calibracao

	// Convert input image to HSV	
	//cv::cvtColor(frame, drawMat, cv::COLOR_BGR2HSV);
	//cv::cvtColor(frame, drawMat, cv::COLOR_BGR2RGB); // por enquanto RGB
	drawMat = frame;

	string testeAtual = uiPID.tabWidget->tabText(uiPID.tabWidget->currentIndex()).toStdString(); // nome da aba atual

	cv::Point(*ponteiroParaFuncaoComRaio) (cv::Point, float, float);		// Ponteiro para funcao com raio
	cv::Point(*ponteiroParaFuncaoSemRaio) (cv::Point, cv::Point, float);	// Ponteiro para funcao sem raio

	if (testeAtual == "Point and Click")
	{
		center1 = cv::Point(coordenadaX, coordenadaY);						// X e Y do objetivo

		ponteiroParaFuncaoComRaio = 0;
		ponteiroParaFuncaoSemRaio = 0;
	}
	else if (testeAtual == "Lemniscata")
	{
		center1 = cv::Point(centroLemniscataX, centroLemniscataY);			// X e Y do do centro da lemniscata

		ponteiroParaFuncaoComRaio = &calculaPontoLemniscata;
		ponteiroParaFuncaoSemRaio = 0;
	}
	else if (testeAtual == "Circulo")
	{
		center1 = cv::Point(centroCirculoX, centroCirculoY);				// X e Y do circulo

		ponteiroParaFuncaoComRaio = calculaPontoCirculo;
		ponteiroParaFuncaoSemRaio = 0;
	}
	else if (testeAtual == "Linha")
	{
		center1 = cv::Point(corrdenadasLinhaX[1], corrdenadasLinhaY[1]);	// X e Y do inicio da linha
		center2 = cv::Point(corrdenadasLinhaX[0], corrdenadasLinhaY[0]);	// X e Y do fim da linha

		ponteiroParaFuncaoComRaio = 0;
		ponteiroParaFuncaoSemRaio = calculaPontoLinha;
	}
	else if (testeAtual == "Carga de trajetoria")
	{		
		ponteiroParaFuncaoComRaio = 0;
		ponteiroParaFuncaoSemRaio = 0;
	}

	vector<cv::Point> pontosASeguir = geraPontoDesenhaTeste(ponteiroParaFuncaoComRaio, ponteiroParaFuncaoSemRaio);

	//Usar a vision para adquirir os objetos
	//desenhar os objetos
	bool achou = FindObjects(Vision::instance()->getPosicaoCores(cores, false), false);

	StrRetorno rtn;

	
	if (runningTest && achou)
	{
		rtn = robo.Controle(paramC, sentido, uiPID.kAngDesSpinBox->value());
		//rtn = robo.ControleJacoud(paramC);
		//rtn = robo.ControleJacoud();

		
		melhorPosition = rtn.melhorPonto;

		if (! uiPID.congelaCheckBox->isChecked())
		{
			atualizaTextoTela(rtn, frameNum, FPS);
		}

		cv::circle(drawMat, cv::Point(melhorPosition.x, melhorPosition.y), 1, cv::Scalar(0, 255, 0), 3);	// desenha um ponto no melhor ponto
		cv::line(drawMat, cv::Point(robo.posAtual.x, robo.posAtual.y), cv::Point(melhorPosition.x, melhorPosition.y), cv::Scalar(255, 255, 0),3);


		double a1 = tan(melhorPosition.ang);
		double b = melhorPosition.y -  a1*melhorPosition.x;
		double x1 = melhorPosition.x - 30;
		double x2 = melhorPosition.x + 30;

		double y1 = a1*x1 + b;
		double y2 = a1*x2 + b;
				
		cv::line(drawMat, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(255, 255, 128), 3);

		double a2 = tan(rtn.angDesejado);
		double br = robo.posAtual.y - a2*robo.posAtual.x;
		double x1r = robo.posAtual.x - 30;
		double x2r = robo.posAtual.x + 30;

		double y1r = a2*x1r + br;
		double y2r = a2*x2r + br;

		cv::line(drawMat, cv::Point(x1r, y1r), cv::Point(x2r, y2r), cv::Scalar(128, 255, 255), 3);
		

	}

	
	// as informações que não são provenientes do controle do robo devem ser adicionadas após o IF, pois o método Objeto::Controle retorna um novo objeto.
	rtn.achou = achou;
	rtn.roboName = robo.nome;
	rtn.trajetoria = robo.traj.nome;
	rtn.posicaoAtual = robo.posAtual;
	rtn.ticks = clock();
	rtn.frameNum = frameNum;
	rtn.FPS = FPS;
	rtn.logaDados = uiPID.LogStatCheckBox->isChecked();
	Logger::asyncStatWriter(rtn);

	waitKey(1);							//delay 33ms
	cv::imshow("Imagem", drawMat);

	// Passa a imagem para a tela
	//QImage qimgDraw((uchar*)drawMat.data, drawMat.cols, drawMat.rows, drawMat.step, QImage::Format_RGB888);
	//uiPID.videoOut->setPixmap(QPixmap::fromImage(qimgDraw));

	//TODO:aqui devemos passar para o objeto selecionado os parametros atuais do PID 
	

	



	//for each (Objeto obj in objetos)
	//{
	//	if (obj.nome == "CarroTeste")
	//	{
	//		if (runningTest)
	//		{
	//			obj.Controle(paramC);
	//			//Serial::instance()->EnviarMensagem2(150, 150, "ACAC");
	//			//ui.XYText->appendPlainText("CONTROLE");
	//		}
	//		else{
	//			/*Serial::instance()->EnviarMensagem2(0, 0, obj.cfgXbee);*/
	//		}
	//	}

	//}

}


void PIDCalib::atualizaTextoTela(StrRetorno rtn, long pFrameNum, double pFPS)
{
	uiPID.text->clear();
	//uiPID.text->setText(QString("SetPointVel: %1 \n VelAtual: %2").arg(to_string(rtn.setPoint), to_string(rtn.velAtual)));
	//uiPID.text->setText(QString("SetPointVel: %1 \nVelAtual: %2").arg(QString::number(rtn.setPoint), QString::number(rtn.velAtual)));
	uiPID.text->setText(QString("Velocidade Atual:       %1    FPS: %8  \nVelocidade Derivada Suja:          %2\nErro Velocidade:        %3\nAngulo Atual:           %4\nAngulo Desejado:        %5\nErro Angulo:            %6 SAT:%9 \nDistancia Melhor Ponto: %7")
		.arg(QString::number(rtn.velAtual), QString::number(rtn.velAtualDerivSuja), QString::number(rtn.erroVel), QString::number(rtn.angAtual), QString::number(rtn.angDesejado), QString::number(rtn.erroAng), QString::number(rtn.mDist), QString::number(pFPS), QString::number((int)rtn.satAng)));


}


#pragma region Eventos Disparados
void PIDCalib::desabiltarParametrosTeste(int state){

	if (state == 0)
	{
		uiPID.PLSpinBox->setEnabled(true);
		uiPID.DLSpinBox->setEnabled(true);
		uiPID.ILSpinBox->setEnabled(true);
		uiPID.PASpinBox->setEnabled(true);
		uiPID.DASpinBox->setEnabled(true);
		uiPID.IASpinBox->setEnabled(true);
	}
	else
	{
		uiPID.PLSpinBox->setEnabled(false);
		uiPID.DLSpinBox->setEnabled(false);
		uiPID.ILSpinBox->setEnabled(false);
		uiPID.PASpinBox->setEnabled(false);
		uiPID.DASpinBox->setEnabled(false);
		uiPID.IASpinBox->setEnabled(false);
	}

}

void PIDCalib::selecionaRobo(QString roboSelecionado, int prioridadeRobo){
	// seleciona o robo
	int indexRobo = uiPID.robotComboBox->findText(roboSelecionado);
	if (indexRobo != -1) {
		switch (prioridadeRobo)
		{
		case 1:
			uiPID.robotSecComboBox->setCurrentIndex(indexRobo);
			break;
		default:
			uiPID.robotComboBox->setCurrentIndex(indexRobo);
			break;
		}
	}

	for (int i = 0; i < objetos.size(); i++)
	{
		if (roboSelecionado.toStdString() == objetos[i].nome)
		{
			uiPID.velSpinBox->setValue(objetos[i].setPointVel);


			// Seleciona o PID associado ao objeto
			int indexPID = uiPID.pidComboBox->findText(QString::fromStdString(objetos[i].ctrl.nome));
			if (indexPID != -1) {
				uiPID.pidComboBox->setCurrentIndex(indexPID);
				// seleciona os parametros do pid
				selecionaPID(uiPID.pidComboBox->currentText());
			}
			else
			{
				uiPID.pidComboBox->setCurrentIndex(0);
			}
		}
	}
}

void PIDCalib::selecionaPID(QString pidSelecionado){
	// seleciona os parametros do PID
	for (int i = 0; i < parametrosPid.size(); i++)
	{
		if (pidSelecionado.toStdString() == parametrosPid[i].nome)
		{
			uiPID.PLSpinBox->setValue(parametrosPid[i].pLin);
			uiPID.ILSpinBox->setValue(parametrosPid[i].iLin);
			uiPID.DLSpinBox->setValue(parametrosPid[i].dLin);
			uiPID.PASpinBox->setValue(parametrosPid[i].pAng);
			uiPID.DASpinBox->setValue(parametrosPid[i].dAng);
			uiPID.IASpinBox->setValue(parametrosPid[i].iAng);

			atualizaParamControle();
		}
	}

	string roboAtual = uiPID.robotComboBox->currentText().toStdString();
	for (int i = 0; i < objetos.size(); i++)
	{
		if (roboAtual == objetos[i].nome)
		{
			objetos[i].ctrl.nome = pidSelecionado.toStdString();
		}
	}
}

void PIDCalib::selecionaTrajetoria(QString trajSelecionada){
	// seleciona a Trajetoria
	for (int i = 0; i < trajetorias.size(); i++)
	{
		if (trajSelecionada.toStdString() == trajetorias[i].nome)
		{
			trajAtual = trajetorias[i];
			desenhouTraj = false;
		}
	}
}

void PIDCalib::atualizaPeriodo(int valor){
	// para os testes onde faz sentido, atualiza o periodo, definindo a velocidade a ser percorrida
	periodo = (float)valor / 1000.0;

	string testeAtual = uiPID.tabWidget->tabText(uiPID.tabWidget->currentIndex()).toStdString();
	if (testeAtual == "Lemniscata")
	{
		uiPID.periodLabelLemniscata->setText(QString::number(periodo));
	}
	else if (testeAtual == "Circulo")
	{
		uiPID.periodLabelCirculo->setText(QString::number(periodo));
	}
}

void PIDCalib::atualizaRaio(int valor){
	// para os testes onde faz sentido, atualiza o raio da figura
	raio = (float)valor; /// 10.0;

	string testeAtual = uiPID.tabWidget->tabText(uiPID.tabWidget->currentIndex()).toStdString();
	if (testeAtual == "Lemniscata")
	{
		uiPID.radiusLabelLemniscata->setText(QString::number(raio));
	}
	else if (testeAtual == "Circulo")
	{
		uiPID.radiusLabelCirculo->setText(QString::number(raio));
	}
}

void PIDCalib::atualizaSentido(int valor){
	// para os testes onde faz sentido, atualiza o sentido que o robo devera fazer no teste
	if (valor == 0)
	{
		sentido = false;
	}
	else if (valor == 2)
	{
		sentido = true;
	}

	string testeAtual = uiPID.tabWidget->tabText(uiPID.tabWidget->currentIndex()).toStdString();
	if (testeAtual == "Linha")
	{
		if (valor == 0)
		{
			uiPID.sentidoLabelLinha->setText("Baixo/Esquerda");
		}
		else
		{
			uiPID.sentidoLabelLinha->setText("Cima/Direita");
		}
		
	}	
}

void PIDCalib::atualizaPL(double valor){
	// atualiza o ganho proporcional linear do vetor para a configuracao correspondente
	string pidAtual = uiPID.pidComboBox->currentText().toStdString();
	for (int i = 0; i < parametrosPid.size(); i++)
	{
		if (pidAtual == parametrosPid[i].nome)
		{
			parametrosPid[i].pLin = valor;
		}
	}
}

void PIDCalib::atualizaDL(double valor){
	// atualiza o ganho derivativo linear do vetor para a configuracao correspondente
	string pidAtual = uiPID.pidComboBox->currentText().toStdString();
	for (int i = 0; i < parametrosPid.size(); i++)
	{
		if (pidAtual == parametrosPid[i].nome)
		{
			parametrosPid[i].dLin = valor;
		}
	}
}

void PIDCalib::atualizaIL(double valor){
	// atualiza o ganho integrador linear do vetor para a configuracao correspondente
	string pidAtual = uiPID.pidComboBox->currentText().toStdString();
	for (int i = 0; i < parametrosPid.size(); i++)
	{
		if (pidAtual == parametrosPid[i].nome)
		{
			parametrosPid[i].iLin = valor;
		}
	}
}

void PIDCalib::atualizaPA(double valor){
	// atualiza o ganho proporcional angular do vetor para a configuracao correspondente
	string pidAtual = uiPID.pidComboBox->currentText().toStdString();
	for (int i = 0; i < parametrosPid.size(); i++)
	{
		if (pidAtual == parametrosPid[i].nome)
		{
			parametrosPid[i].pAng = valor;
		}
	}
}

void PIDCalib::atualizaDA(double valor){
	// atualiza o ganho derivativo angular do vetor para a configuracao correspondente
	string pidAtual = uiPID.pidComboBox->currentText().toStdString();
	for (int i = 0; i < parametrosPid.size(); i++)
	{
		if (pidAtual == parametrosPid[i].nome)
		{
			parametrosPid[i].dAng = valor;
		}
	}
}

void PIDCalib::atualizaIA(double valor){
	// atualiza o ganho integrador angular do vetor para a configuracao correspondente
	string pidAtual = uiPID.pidComboBox->currentText().toStdString();
	for (int i = 0; i < parametrosPid.size(); i++)
	{
		if (pidAtual == parametrosPid[i].nome)
		{
			parametrosPid[i].iAng = valor;
		}
	}
}

void PIDCalib::atualizaCentros(int x1, int y1, int x2, int y2){
	center1 = cv::Point(x1,y1);
	center2 = cv::Point(x1, y1);
}

void PIDCalib::atualizaSetPoint()
{
	string roboSelecionado = uiPID.robotComboBox->currentText().toStdString();

	for (int i = 0; i < objetos.size(); i++)
	{
		if (roboSelecionado == objetos[i].nome)
		{
			objetos[i].setPointVel = uiPID.velSpinBox->value();
			robo.setPointVel = uiPID.velSpinBox->value();
		}
	}
}

void PIDCalib::atualizaParamControle(){

	paramC.pLin =  uiPID.PLSpinBox->value();
	paramC.iLin =  uiPID.ILSpinBox->value();
	paramC.dLin =  uiPID.DLSpinBox->value();
	paramC.pAng =  uiPID.PASpinBox->value();
	paramC.iAng =  uiPID.IASpinBox->value();
	paramC.dAng =  uiPID.DASpinBox->value();

	for (int i = 0; i < parametrosPid.size(); i++)
	{
		if (uiPID.pidComboBox->currentText().toStdString() == parametrosPid[i].nome)
		{
			
			parametrosPid[i].pLin = paramC.pLin;
			parametrosPid[i].iLin = paramC.iLin;
			parametrosPid[i].dLin = paramC.dLin;
			parametrosPid[i].pAng = paramC.pAng;
			parametrosPid[i].iAng = paramC.iAng;
			parametrosPid[i].dAng = paramC.dAng;


			//
			//uiPID.PLSpinBox->setValue(parametrosPid[i].pLin);
			//uiPID.ILSpinBox->setValue(parametrosPid[i].iLin);
			//uiPID.DLSpinBox->setValue(parametrosPid[i].dLin);
			//uiPID.PASpinBox->setValue(parametrosPid[i].pAng);
			//uiPID.DASpinBox->setValue(parametrosPid[i].dAng);
			//uiPID.IASpinBox->setValue(parametrosPid[i].iAng);

		}
	}

}

#pragma endregion

#pragma region Funcionalidades do Usuário
void PIDCalib::keyPressEvent(QKeyEvent *event){
	switch (event->key()) {
	case Qt::Key_A:
		uiPID.periodLabelLemniscata->setText("LLLLLLLLL");		
		Serial::instance()->EnviarMensagem2(32, 64, robo.cfgXbee);
		/*Serial::instance()->EnviarMensagem(2, 1, 0.5, 1, 1);*/
		break;
	case Qt::Key_D:
		uiPID.periodLabelLemniscata->setText("RRRRRRRRR");
		Serial::instance()->EnviarMensagem2(64, 32, robo.cfgXbee);
		//Serial::instance()->EnviarMensagem(2, 1, 1, 1, 0.5);
		break;
	case Qt::Key_S:
		uiPID.periodLabelLemniscata->setText("DDDDDDDDDD");
		Serial::instance()->EnviarMensagem2(-64, -64, robo.cfgXbee);
		//Serial::instance()->EnviarMensagem(2, 0, 1, 0, 1);
		break;
	case Qt::Key_W:
		uiPID.periodLabelLemniscata->setText("UUUUUUUUUU");
		Serial::instance()->EnviarMensagem2(64, 64, robo.cfgXbee);
		break;
	case Qt::Key_J:
		uiPID.periodLabelLemniscata->setText("2 - Esquerda");
		Serial::instance()->EnviarMensagem2(32, 64, roboSecundario.cfgXbee);
		/*Serial::instance()->EnviarMensagem(2, 1, 0.5, 1, 1);*/
		break;
	case Qt::Key_L:
		uiPID.periodLabelLemniscata->setText("2 - Direita");
		Serial::instance()->EnviarMensagem2(64, 32, roboSecundario.cfgXbee);
		//Serial::instance()->EnviarMensagem(2, 1, 1, 1, 0.5);
		break;
	case Qt::Key_K:
		uiPID.periodLabelLemniscata->setText("2 - Tras");
		Serial::instance()->EnviarMensagem2(-64, -64, roboSecundario.cfgXbee);
		//Serial::instance()->EnviarMensagem(2, 0, 1, 0, 1);
		break;
	case Qt::Key_I:
		uiPID.periodLabelLemniscata->setText("2 - Frente");
		Serial::instance()->EnviarMensagem2(64, 64, roboSecundario.cfgXbee);
		break;
	case Qt::Key_Escape:
		uiPID.PLSpinBox->clearFocus();
		uiPID.DLSpinBox->clearFocus();
		uiPID.ILSpinBox->clearFocus();
		uiPID.PASpinBox->clearFocus();
		uiPID.DASpinBox->clearFocus();
		uiPID.IASpinBox->clearFocus();
		break;
	}
}

void PIDCalib::keyReleaseEvent(QKeyEvent *event){
	switch (event->key()) {
	case Qt::Key_A:
		uiPID.periodLabelLemniscata->setText("AAAAAAAAA");
		Serial::instance()->EnviarMensagem2(0, 0, robo.cfgXbee);		
		//Serial::instance()->EnviarMensagem2(0, 0, "ACAC");
		break;
	case Qt::Key_D:
		uiPID.periodLabelLemniscata->setText("DDDDDDDDD");
		Serial::instance()->EnviarMensagem2(0, 0, robo.cfgXbee);
		//Serial::instance()->EnviarMensagem2(0, 0, "ACAC");
		break;
	case Qt::Key_S:
		uiPID.periodLabelLemniscata->setText("SSSSSSSSS");
		Serial::instance()->EnviarMensagem2(0, 0, robo.cfgXbee);
		//Serial::instance()->EnviarMensagem2(0, 0, "ACAC");
		break;
	case Qt::Key_W:
		uiPID.periodLabelLemniscata->setText("WWWWWWWWW");
		Serial::instance()->EnviarMensagem2(0, 0, robo.cfgXbee);
		//Serial::instance()->EnviarMensagem2(0, 0, "ACAC");
		break;
	case Qt::Key_J:
		uiPID.periodLabelLemniscata->setText("2 - Sem Esquerda");
		Serial::instance()->EnviarMensagem2(0, 0, roboSecundario.cfgXbee);
		//Serial::instance()->EnviarMensagem2(0, 0, "ACAC");
		break;
	case Qt::Key_L:
		uiPID.periodLabelLemniscata->setText("2 - Para Direita");
		Serial::instance()->EnviarMensagem2(0, 0, roboSecundario.cfgXbee);
		//Serial::instance()->EnviarMensagem2(0, 0, "ACAC");
		break;
	case Qt::Key_K:
		uiPID.periodLabelLemniscata->setText("2 - Para Tras");
		Serial::instance()->EnviarMensagem2(0, 0, roboSecundario.cfgXbee);
		//Serial::instance()->EnviarMensagem2(0, 0, "ACAC");
		break;
	case Qt::Key_I:
		uiPID.periodLabelLemniscata->setText("2 - Para Frente");
		Serial::instance()->EnviarMensagem2(0, 0, roboSecundario.cfgXbee);
		//Serial::instance()->EnviarMensagem2(0, 0, "ACAC");
		break;
	}
}

void PIDCalib::on_startTestButton_clicked(){
	// inicia/reinicia o teste
	runningTest = true;
	// TODO: selecionar o teste para rodar, atualizar a trajetoria do carrinho
	string testeAtual = uiPID.tabWidget->tabText(uiPID.tabWidget->currentIndex()).toStdString();
	string roboSelecionado = uiPID.robotComboBox->currentText().toStdString();
	string roboSecundarioSelecionado = uiPID.robotSecComboBox->currentText().toStdString();
	
	for (int i = 0; i < objetos.size(); i++)
	{
		if (roboSelecionado == objetos[i].nome)
		{
			robo = objetos[i];
		}

		if (roboSecundarioSelecionado == objetos[i].nome)
		{
			roboSecundario = objetos[i];
		}
	}

	if (testeAtual == "Point and Click")
	{
		// Chama o teste		
	}
	else if (testeAtual == "Lemniscata")
	{		
		// Chama o teste
	}
	else if (testeAtual == "Circulo")
	{		
		// Chama o teste
	}
	else if (testeAtual == "Linha")
	{		
		// Chama o teste
	}
	else if (testeAtual == "Carga de trajetoria")
	{
		// Chama o teste
		robo.traj = trajAtual;
	}
}

void PIDCalib::on_stopTestButton_clicked(){
	// para o testeC
	runningTest = false;

	if (robo.cfgXbee != "")
	{
		Serial::instance()->EnviarMensagem2(0, 0, robo.cfgXbee);
		robo.saidaLinearI = 0;
		robo.saidaAngularI = 0;

	}


	/*for each (Objeto obj in objetos)
	{
		if (obj.nome == "CarroTeste")
		{
			Serial::instance()->EnviarMensagem2(0, 0, obj.cfgXbee);

		}
	}*/

	// atualiza periodo, raio e sentido
	string testeAtual = uiPID.tabWidget->tabText(uiPID.tabWidget->currentIndex()).toStdString();
	if (testeAtual == "Lemniscata")
	{
		atualizaPeriodo(uiPID.periodSliderLemniscata->value());
		atualizaRaio(uiPID.radiusSliderLemniscata->value());
		atualizaSentido(uiPID.clockwiseCheckBoxLemniscata->checkState());
		atualizaCentros(centroLemniscataX, centroLemniscataY, -1, -1);
	}
	else if (testeAtual == "Circulo")
	{
		atualizaPeriodo(uiPID.periodSliderCirculo->value());
		atualizaRaio(uiPID.radiusSliderCirculo->value());
		atualizaSentido(uiPID.clockwiseCheckBoxCirculo->checkState());
		atualizaCentros(centroCirculoX, centroCirculoY, -1, -1);
	}
	else if (testeAtual == "Linha")
	{		
		atualizaSentido(uiPID.clockwiseCheckBoxLinha->checkState());
		atualizaCentros(corrdenadasLinhaX[1], corrdenadasLinhaY[1], corrdenadasLinhaX[0], corrdenadasLinhaY[0]);
	}
	else if (testeAtual == "Point and Click")
	{
		atualizaCentros(coordenadaX, coordenadaY, -1, -1);
	}
	else if (testeAtual == "Carga de trajetoria")
	{
		atualizaCentros(-1, -1, -1, -1);
		atualizaSentido(uiPID.clockwiseCheckBoxTraj->checkState());
	}
}

void PIDCalib::closeEvent(QCloseEvent *evento)
{
	transferirImagemParaPIDCalib = false;
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

void PIDCalib::on_saveButton_clicked(){
	// Salva as configuracoes de PID e os objetos
	dbStorage::instance()->salvaParamsControle(parametrosPid);
	dbStorage::instance()->salvaObjetos(objetos);

	atualizaControles = true;
}

void PIDCalib::on_newRobotButton_clicked(){
	// Chama a tela para configurar um novo robo

	roboCam = new RoboConfig;
	roboCam->chamaConfigRobo = true;
	// Verifica se a tela de Conf. de robo esta em execucao
	if (roboCam->chamaConfigRobo)
	{
		// Verifica se eh a primeira chamada ou n, caso seja usa show
		if (!roboCam->mostrarOuAtualizar)
		{
			roboCam->show();
			roboCam->mostrarOuAtualizar = true;
		}
		else
		{
			roboCam->update();
		}
	}
	else
	{
		roboCam->mostrarOuAtualizar = false;
	}
}

void PIDCalib::on_newPIDButton_clicked(){
	// Cria uma nova configuracao de PID
	bool ok;
	QString text = QInputDialog::getText(0, QObject::tr("QInputDialog::getText()"), QObject::tr("Nome:"), QLineEdit::Normal, "", &ok);
	if (ok)
	{
		uiPID.pidComboBox->addItem(text);
		int index = uiPID.pidComboBox->findText(text);
		if (index != -1) { // -1 for not found
			uiPID.pidComboBox->setCurrentIndex(index);
			parametrosPid.push_back(paramControle(text.toStdString(), 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));		
			selecionaPID(text);
		}
	}
}

void PIDCalib::mousePressed(){
	// Verifica em qual teste esta e define o(s) valor(es) das coordenada(s) daquele teste

	string testeAtual = uiPID.tabWidget->tabText(uiPID.tabWidget->currentIndex()).toStdString();
	if (testeAtual == "Point and Click")
	{
//		coordenadaX = uiPID.videoOut->x;
//		coordenadaY = uiPID.videoOut->y;
	}
	else if (testeAtual == "Lemniscata")
	{
		//centroLemniscataX = uiPID.videoOut->x;
		//centroLemniscataY = uiPID.videoOut->y;
	}
	else if (testeAtual == "Circulo")
	{
		//centroCirculoX = uiPID.videoOut->x;
		//centroCirculoY = uiPID.videoOut->y;
	}
	else if (testeAtual == "Linha")
	{
		corrdenadasLinhaX[0] = corrdenadasLinhaX[1];
		corrdenadasLinhaY[0] = corrdenadasLinhaY[1];

		//corrdenadasLinhaX[1] = uiPID.videoOut->x;
		//corrdenadasLinhaY[1] = uiPID.videoOut->y;
	}
}
#pragma endregion

#pragma region Desenho
vector<cv::Point> PIDCalib::geraPontoDesenhaTeste(cv::Point(*funcaoComRaio) (cv::Point, float, float), cv::Point(*funcaoSemRaio) (cv::Point, cv::Point, float)){

	vector<cv::Point> pontos;

	if (!desenhouTraj)
	{
		imgTrajetoria = cv::Mat(drawMat.rows, drawMat.cols, CV_8UC3);
		imgTrajetoria.setTo(cv::Scalar(0, 0, 0));
		
		//cvSet(imgTrajetoria, CV_RGB(0, 0, 0));

		//imgTrajetoria = cvCreateImage(drawMat.cols, drawMat.rows,)



		if (center1.x >= 0 && center1.y >= 0)
		{
			cv::circle(drawMat, center1, 1, cv::Scalar(0, 255, 0), 3);	// desenha um ponto no local clicado

			// Se o ponteiro n for null entra
			if (funcaoComRaio)
			{
				for (float i = 0; i < 10; i += 0.01)
				{
					// Chama a funcao para calcular o ponto e adiciona no vetor
					pontos.push_back(funcaoComRaio(center1, raio, i));
				}
			}
		}
		else
		{
			string testeAtual = uiPID.tabWidget->tabText(uiPID.tabWidget->currentIndex()).toStdString(); // nome da aba atual
			if (testeAtual == "Carga de trajetoria")
			{
				for (int i = 0; i < trajAtual.pontos.size(); i++)
				{
					pontos.push_back(cv::Point(trajAtual.arrx[i], trajAtual.arry[i]));
				}
			}
			else
			{
				pontos.push_back(cv::Point(-1, -1));
				return pontos;						// N tem nenhum ponto clicado
			}
		}

		if (center2.x >= 0 && center2.y >= 0)
		{
			cv::circle(drawMat, center2, 1, cv::Scalar(0, 255, 0), 3);	// desenha um ponto no local clicado(ponto final)

			//cv::arrowedLine(matrizEntradaSaida, center2, center1, cv::Scalar(0, 0, 255), 2);
			//cv::line(drawMat, center1, center2, cv::Scalar(0, 0, 255), 2);

			if (funcaoSemRaio)
			{
				if (center1.x <= center2.x)
				{
					for (float i = center1.x; i <= center2.x; i += 0.01)
					{
						// Chama a funcao para calcular o ponto e adiciona no vetor
						pontos.push_back(funcaoSemRaio(center1, center2, i));
					}
				}
				else
				{
					for (float i = center2.x; i <= center1.x; i += 0.01)
					{
						// Chama a funcao para calcular o ponto e adiciona no vetor
						pontos.push_back(funcaoSemRaio(center1, center2, i));
					}
				}
			}
		}

		// Treta pra desenhar a polyline
		const cv::Point *pts = (const cv::Point*) Mat(pontos).data;
		int npts = Mat(pontos).rows;

		// Desenhando
		polylines(imgTrajetoria, &pts, &npts, 1,
			false, 					// Desenha o contorno fechado (i.e. junta o ultimo ponto com o primeiro) 
			Scalar(0, 0, 255),		// Cor em RGB 
			1, 						// Espessura da linha
			CV_AA, 0);

		desenhouTraj = true;
	}

	//addWeighted(drawMat, 0.5, imgTrajetoria, 0.5, 0.0, drawMat);
	add(drawMat, imgTrajetoria, drawMat);

	return pontos;
}

void PIDCalib::DesenhaObjetos(Objeto obj){
	int raioDesenho = 10;
	cv::Point centrObj = cv::Point(obj.posAtual.x, obj.posAtual.y);
	cv::circle(drawMat, centrObj, raioDesenho, cv::Scalar(255, 255, 255), 3);
	double x, y;

	x = raioDesenho * cos(obj.posAtual.ang) + obj.posAtual.x;
	y = raioDesenho * sin(obj.posAtual.ang) + obj.posAtual.y;

	cv::Point ponto2 = cv::Point(x, y);
	cv::line(drawMat, centrObj, ponto2, cv::Scalar(255, 0, 0), 3);
}
#pragma endregion