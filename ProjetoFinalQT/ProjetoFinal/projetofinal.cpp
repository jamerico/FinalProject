#include "projetofinal.h"

//#include "Serial.h"

#include<QtCore>


using namespace cv;

#pragma region Consturtor/Destrutor

ProjetoFinal::ProjetoFinal(QWidget *parent)
	: QMainWindow(parent)
{
	Logger::Log("-------- Inicio Execução Programa -------------");
	Logger::initializeStatWriter();

	//vector<Trajetoria> v = dbStorage::instance()->getAllTrajetoria();

#ifdef OUTPUTBIEL
	Logger::Output("Inicio Execucao Programa %d\n", 0);
#endif



	Vision::instance(0);

	//Cor c("teste1", 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 0, 999);
	//dbStorage::instance()->salvaCor(c);
	//Cor b = dbStorage::instance()->getCor("teste1");

	//Serial::instance()->EnviarMensagem2(100, 100, "ACAC");
	//Sleep(1000);
	//Serial::instance()->EnviarMensagem2(0, 0, "ACAC");


	cores = dbStorage::instance()->getAllCor();

	//mapCores = dbStorage::instance()->getMapAllCor();
	nomesPid = dbStorage::instance()->getAllParamsControle();
	objetos = dbStorage::instance()->getAllObjetos();

	Trajetoria trajAuxGlob = dbStorage::instance()->getTrajetoria("circulo_r80_xc160_yc120");

	for (int i = 0; i < objetos.size(); i++)
	{
		if (objetos[i].nome == "CarroTeste")
		{
			objetos[i].trajAux = trajAuxGlob;

		}

	}

	
	// Vetor com cores para cada objeto
	coresDrawObj.push_back(cv::Scalar(255,200,200));
	coresDrawObj.push_back(cv::Scalar(255, 255, 0));
	coresDrawObj.push_back(cv::Scalar(255, 0, 255));
	coresDrawObj.push_back(cv::Scalar(255, 255, 255));
	coresDrawObj.push_back(cv::Scalar(255, 255, 255));
	coresDrawObj.push_back(cv::Scalar(255, 255, 255));
	coresDrawObj.push_back(cv::Scalar(255, 255, 255));







	//for each (Objeto obj in objetos)
	//{
	//	mapCorObjeto[obj.nome] = cv::Scalar()
	//}

	
	//for (int idxObj = 0; idxObj < objetos.size(); idxObj++)
	//{
	//	if (objetos[idxObj].nome == "CarroTeste" || objetos[idxObj].nome == "CarroTeste2")
	//	{
	//		objetos[idxObj].traj = dbStorage::instance()->getTrajetoria("circulo_r120_xc320_yc240");
	//	}

	//}
	
	

	//Trajetoria t = dbStorage::instance()->getTrajetoria("circulo_r1");
	//Trajetoria t = dbStorage::instance()->getTrajetoria("circulo_r120_xc320_yc240");
	//bool a = t.contem(0, 0);
	//bool b = t.contem(320, 240);
	//Position p(445, 242);
	//clock_t c = clock();
	//tuple<Position, double> tp = t.getMelhorPonto(p);
	//double tempo = double(clock() - c) / (CLOCKS_PER_SEC/1000);

//#include "opencv2/cudaarithm.hpp"	double teste = p.getValueAt(2);
	
	// Setup da interface grafica
	ui.setupUi(this);

	filtroCam = new CameraCalib;
	pidCam = new PIDCalib;
	roboCam = new RoboConfig;

	tmrTimer = new QTimer(this);
	connect(tmrTimer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));
	tmrTimer->start(33); // esse valor parece ser a taxa de amostragem
	
}

ProjetoFinal::~ProjetoFinal()
{
	Vision::instance()->ReleaseCam();
}

#pragma endregion

void ProjetoFinal::processFrameAndUpdateGUI(){
	// Funcao q vai processar os disponibilizar a imagem

	if (mostrarImagemNaTela || runningTest || filtroCam->transferirImagemParaCameraCalib || pidCam->transferirImagemParaPIDCalib)
	{
		originalMat =  Vision::instance()->ProcessFramesRtn();
		//ui.XYText->clear();
		//ui.XYText->append
		frameNum += 1;
	}


	if ((!mostrarImagemNaTela) && (filtroCam->transferirImagemParaCameraCalib) && (!(pidCam->transferirImagemParaPIDCalib)))
	{
		//Vision::instance()->ProcessFrames();
		filtroCam->processFrameAndUpdateGUI(Vision::originalMat);
		if (!filtroCam->mostrarOuAtualizar)
		{
			filtroCam->show();
			filtroCam->mostrarOuAtualizar = true;
		}
		else
		{
			filtroCam->update();
		}
	}
	else if ((!mostrarImagemNaTela) && (filtroCam->transferirImagemParaCameraCalib) && (pidCam->transferirImagemParaPIDCalib))
	{
		//Vision::instance()->ProcessFrames();
		filtroCam->processFrameAndUpdateGUI(Vision::originalMat);
		pidCam->processFrameAndUpdateGUI(Vision::originalMat);
		if (!filtroCam->mostrarOuAtualizar)
		{
			filtroCam->show();
			filtroCam->mostrarOuAtualizar = true;
		}
		else
		{
			filtroCam->update();
		}

		if (!pidCam->mostrarOuAtualizar)
		{
			pidCam->show();
			pidCam->mostrarOuAtualizar = true;
		}
		else
		{
			pidCam->update();
		}
	}
	else if ((!mostrarImagemNaTela) && (!(filtroCam->transferirImagemParaCameraCalib)) && (pidCam->transferirImagemParaPIDCalib))
	{
		//Vision::instance()->ProcessFrames();		
		pidCam->processFrameAndUpdateGUI(Vision::originalMat);
		if (!pidCam->mostrarOuAtualizar)
		{
			pidCam->show();
			pidCam->mostrarOuAtualizar = true;
		}
		else
		{
			pidCam->update();
		}
	}
	else if ((mostrarImagemNaTela) && (filtroCam->transferirImagemParaCameraCalib) && (!(pidCam->transferirImagemParaPIDCalib)))
	{		
		filtroCam->processFrameAndUpdateGUI(Vision::originalMat);		
		if (!filtroCam->mostrarOuAtualizar)
		{
			filtroCam->show();
			filtroCam->mostrarOuAtualizar = true;
		}
		else
		{
			filtroCam->update();
		}
	}
	else if ((mostrarImagemNaTela) && (!(filtroCam->transferirImagemParaCameraCalib)) && (pidCam->transferirImagemParaPIDCalib))
	{				
		pidCam->processFrameAndUpdateGUI(Vision::originalMat);
		if (!pidCam->mostrarOuAtualizar)
		{
			pidCam->show();
			pidCam->mostrarOuAtualizar = true;
		}
		else
		{
			pidCam->update();
		}
	}
	else if ((mostrarImagemNaTela) && (filtroCam->transferirImagemParaCameraCalib) && (pidCam->transferirImagemParaPIDCalib))
	{		
		filtroCam->processFrameAndUpdateGUI(Vision::originalMat);
		pidCam->processFrameAndUpdateGUI(Vision::originalMat);
		if (!filtroCam->mostrarOuAtualizar)
		{
			filtroCam->show();
			filtroCam->mostrarOuAtualizar = true;
		}
		else
		{
			filtroCam->update();
		}

		if (!pidCam->mostrarOuAtualizar)
		{
			pidCam->show();
			pidCam->mostrarOuAtualizar = true;
		}
		else
		{
			pidCam->update();
		}
	}
	else if (mostrarImagemNaTela && !runningTest && !filtroCam->transferirImagemParaCameraCalib && !pidCam->transferirImagemParaPIDCalib)
	{
		imshow("Imagem", originalMat);  //print image to screen
		//waitKey(1);							//delay 33ms

	}
	else
	{
		filtroCam->mostrarOuAtualizar = false;
		pidCam->mostrarOuAtualizar = false;
	}

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


	if (filtroCam->atualizaCores)
	{
		cores.clear();
		cores = dbStorage::instance()->getAllCor();
		filtroCam->atualizaCores = false;
	}
	if (pidCam->atualizaControles)
	{
		nomesPid.clear();
		nomesPid = dbStorage::instance()->getAllParamsControle();
		pidCam->atualizaControles = false;
	}
	if (roboCam->atualizaObjetos)
	{
		objetos.clear();
		objetos = dbStorage::instance()->getAllObjetos();
		roboCam->atualizaObjetos = false;
	}

	if (runningTest)
	{
		//double FPS
		//double tempoGasto = clock() - tempo;
		double taxaH = ((clock() - tempo) / ((double)CLOCKS_PER_SEC));
		while (taxaH <= (1.0 / 13.0))
		{
			taxaH = ((clock() - tempo) / ((double)CLOCKS_PER_SEC));
			//Sleep(1);
		}
		
		if (taxaH > 1)
		{
			taxaH = 1.0 / 22.0;
		}
		double FPS = 1.0 / taxaH;
		Logger::Output("------- Frame: %f0 ------- \n", frameNum);
		Logger::Output("FPS: %f0 \n", FPS);

		tempo = clock();
		frameNum++;


		FindObjects(Vision::instance()->getPosicaoCores(cores, false));

		
		if (mostrarTrajetorias)
		{
			DesenhaTrajetorias2();
		}

		/*StrRetorno rtn;*/

		//#omp
		for (int idxObj = 0; idxObj < objetos.size(); idxObj++)
		{
			if (objetos[idxObj].achou && objetos[idxObj].ctrl.nome != "")
			{
				objetos[idxObj].taxaH = taxaH;
				//objetos[idxObj].taxaH = 1.0 / 22.0;
				objetos[idxObj].AtualizaVelocidade();
			}
		}

		Observador();

		//#omp
		for (int idxObj = 0; idxObj < objetos.size(); idxObj++) //varre objetos
		{
			StrRetorno rtn;
			//bool sentido = objetos[idxObj].nome == "CarroTeste";
			//bool sentido = objetos[idxObj].nome == "CarroTeste";
			
			if (objetos[idxObj].achou && objetos[idxObj].ctrl.nome != "")
			{
				//rtn = objetos[idxObj].Controle(objetos[idxObj].ctrl, true, 0.02);
				rtn = objetos[idxObj].ControleJacoud(objetos[idxObj].ctrl);//, true, 0.02);
				Logger::Output("Vel: %f0 \n", rtn.velAtualDerivSuja);
			}

			rtn.achou = objetos[idxObj].achou;
			rtn.roboName = objetos[idxObj].nome;
			rtn.trajetoria = objetos[idxObj].traj.nome;
			rtn.posicaoAtual = objetos[idxObj].posAtual;
			rtn.ticks = clock();
			rtn.frameNum = frameNum;
			rtn.FPS = FPS;
			rtn.logaDados = true;
			Logger::asyncStatWriter(rtn);
		}
		

		if (mostrarImagemNaTela)
		{
			imshow("Imagem", originalMat);
		}
	}

	//if (mostrarImagemNaTela)
	//{

	//	// Transformacao de cor, é importante pq o Opencv parece capturar as cores meio zoado(a imagem original estava azulada)
	//	//cv::cvtColor(originalMat, originalMat, CV_BGR2RGB);
	//	//Imagem original
	//	//QImage qimgOriginal((uchar*)originalMat.data, originalMat.cols, originalMat.rows, originalMat.step, QImage::Format_RGB888);
	//	//ui.videoOut->setPixmap(QPixmap::fromImage(qimgOriginal));
	//}	
}

void ProjetoFinal::Observador(){

	//int distSegura = 65; //vel 80px/s
	
	cv::Scalar corObj;
	double xd, yd;
	double angDraw = M_PI_4;
	vector<cv::Point> pontos;

	float arrx[7];
	float arry[7];
	double coefFrenagem;
	double distance;
	double raioCarro = 10;
	double minDist = 2.5 * raioCarro;
	double newSetPoint;		
	double kCoefFren = 1;
	double velMax = 0;
	double limiarVelChange = 5;

	for (int idxObj = 0; idxObj < objetos.size(); idxObj++)
	{
		//double distSegura = (0.75)*objetos[idxObj].setPointVelOrig + 37.5;
		//double distSegura = 0.4*objetos[idxObj].setPointVelOrig + 37.5;
		double distSegura = objetos[idxObj].velAtual + 37.5;
		//double distSegura = (2.3)*objetos[idxObj].velAtual + 60;

		pontos.clear();

		pontos.push_back(cv::Point(objetos[idxObj].posAtual.x, objetos[idxObj].posAtual.y));
		arrx[0] = objetos[idxObj].posAtual.x;
		arry[0] = objetos[idxObj].posAtual.y;

		xd = objetos[idxObj].posAtual.x + (distSegura / 3)*cos(objetos[idxObj].posAtual.ang + M_PI_2);
		yd = objetos[idxObj].posAtual.y + (distSegura / 3)*sin(objetos[idxObj].posAtual.ang + M_PI_2);

		pontos.push_back(cv::Point(xd, yd));
		arrx[1] = xd;
		arry[1] = yd;

		xd = objetos[idxObj].posAtual.x + distSegura*cos(objetos[idxObj].posAtual.ang + angDraw);
		yd = objetos[idxObj].posAtual.y + distSegura*sin(objetos[idxObj].posAtual.ang + angDraw);

		pontos.push_back(cv::Point(xd, yd));
		arrx[2] = xd;
		arry[2] = yd;

		xd = objetos[idxObj].posAtual.x + distSegura*cos(objetos[idxObj].posAtual.ang);
		yd = objetos[idxObj].posAtual.y + distSegura*sin(objetos[idxObj].posAtual.ang);

		pontos.push_back(cv::Point(xd, yd));
		arrx[3] = xd;
		arry[3] = yd;

		xd = objetos[idxObj].posAtual.x + distSegura*cos(objetos[idxObj].posAtual.ang - angDraw);
		yd = objetos[idxObj].posAtual.y + distSegura*sin(objetos[idxObj].posAtual.ang - angDraw);
		arrx[4] = xd;
		arry[4] = yd;

		pontos.push_back(cv::Point(xd, yd));

		xd = objetos[idxObj].posAtual.x + (distSegura / 3)*cos(objetos[idxObj].posAtual.ang - M_PI_2);
		yd = objetos[idxObj].posAtual.y + (distSegura / 3)*sin(objetos[idxObj].posAtual.ang - M_PI_2);

		pontos.push_back(cv::Point(xd, yd));
		arrx[5] = xd;
		arry[5] = yd;

		pontos.push_back(cv::Point(objetos[idxObj].posAtual.x, objetos[idxObj].posAtual.y));
		arrx[6] = objetos[idxObj].posAtual.x;
		arry[6] = objetos[idxObj].posAtual.y;
		
		bool alguemDentro = false;
		double minDistRtn = 500;
		
		for (int idxObj2 = 0; idxObj2 < objetos.size(); idxObj2++)
		{
			if (objetos[idxObj].nome != objetos[idxObj2].nome) //é outro cara
			{
				if (mathHelper::pnpoly(4, arrx, arry, objetos[idxObj2].posAtual.x, objetos[idxObj2].posAtual.y))
				{
					alguemDentro = true;
					//coefFrenagem = (objetos[idxObj2].velAtual + objetos[idxObj].velAtual) / (distSegura - minDist);
					//coefFrenagem = (objetos[idxObj2].velAtual + objetos[idxObj].setPointVelOrig) / (distSegura - minDist);
					//coefFrenagem = (objetos[idxObj2].setPointVelOrig + objetos[idxObj].setPointVelOrig) / (distSegura - minDist);

					if (objetos[idxObj].traj.nome == objetos[idxObj2].traj.nome) //mesma trajetória	
					{
						bool existeTrajAux = objetos[idxObj].trajAux.nome != "";
						double minDistU = 500; // ultrapassagem
						if (existeTrajAux)
						{
							for (int idxObj3 = 0; idxObj3 < objetos.size(); idxObj3++)
							{
								if (objetos[idxObj3].nome != objetos[idxObj].nome && objetos[idxObj3].nome != objetos[idxObj2].nome)
								{
									double dist = objetos[idxObj3].posAtual.distance(objetos[idxObj].posAtual);
									if (dist < minDistU)
									{
										minDistU = dist;
									}
								}
							}
						}
						
						if (existeTrajAux && minDistU > distSegura)
						{
							objetos[idxObj].usaTrajAux = true;
						}
						else
						{
							if (objetos[idxObj2].velAtual < limiarVelChange && objetos[idxObj2].velAtual > -limiarVelChange){
								velMax = objetos[idxObj].velAtual;
								kCoefFren = 0.5;
								objetos[idxObj].saidaLinearI = 0.25*objetos[idxObj].saidaLinearI;
								Logger::Output("Setpoint by ME \n");
							}
							else{
								velMax = objetos[idxObj2].velAtual;
								kCoefFren = 1.5;
								//kCoefFren = 2.5;
								Logger::Output("Integral: %f0", objetos[idxObj].saidaLinearI);

								if (objetos[idxObj].saidaLinearI > 550)
								{
									objetos[idxObj].saidaLinearI = 550;
								}
							}

							//coefFrenagem = velMax / (distSegura - minDist);
							if (objetos[idxObj].traj.nome != objetos[idxObj2].traj.nome) //mesma trajetória	
							{
								coefFrenagem = objetos[idxObj].velAtual / (distSegura - minDist);
							}
							else{
								coefFrenagem = mathHelper::abs(objetos[idxObj2].velAtual - objetos[idxObj].velAtual) / (distSegura - minDist);

							}
							Logger::Output("Coef Frenagem: %f0 \n", coefFrenagem);
							
							distance = objetos[idxObj].posAtual.distance(objetos[idxObj2].posAtual);
							Logger::Output("Distance: %f0 \n", distance);
							Logger::Output("Safety Distance: %f0 \n", distSegura);

							newSetPoint = velMax - (kCoefFren*coefFrenagem*(distSegura - distance));
							Logger::Output("New Set Point: %f0 \n", newSetPoint);
							
							objetos[idxObj].setPointVel = mathHelper::upperSat(newSetPoint, objetos[idxObj].setPointVelOrig);
							Logger::Output("New Set Point Sat: %f0 \n", objetos[idxObj].setPointVel);
							//Logger::Output("Integral: %f0 \n", objetos[idxObj].saidaLinearI);
							//objetos[idxObj].saidaLinearI = 0;//.1*objetos[idxObj].saidaLinearI;
							break;
						}
						
						
					}
					else
					{
						objetos[idxObj].setPointVel = objetos[idxObj].setPointVelOrig;
					}

					//if (objetos[idxObj2].velAtual < limiarVelChange && objetos[idxObj2].velAtual > -limiarVelChange){
					//	velMax = objetos[idxObj].velAtual;
					//	kCoefFren = 0.5;
					//	objetos[idxObj].saidaLinearI = 0.25*objetos[idxObj].saidaLinearI;
					//	Logger::Output("Setpoint by ME \n");
					//}
					//else{
					//	velMax = objetos[idxObj2].velAtual;
					//	kCoefFren = 1.5;
					//}

					//coefFrenagem = velMax / (distSegura - minDist);
					//Logger::Output("Coef Frenagem: %f0 \n", coefFrenagem);
					//
					//distance = objetos[idxObj].posAtual.distance(objetos[idxObj2].posAtual);
					//Logger::Output("Distance: %f0 \n", distance);
					//Logger::Output("Safety Distance: %f0 \n", distSegura);

					//newSetPoint = velMax - (kCoefFren*coefFrenagem*(distSegura - distance));
					//Logger::Output("New Set Point: %f0 \n", newSetPoint);
					//
					//objetos[idxObj].setPointVel = mathHelper::upperSat(newSetPoint, objetos[idxObj].setPointVelOrig);
					//Logger::Output("New Set Point Sat: %f0 \n", objetos[idxObj].setPointVel);
					////Logger::Output("Integral: %f0 \n", objetos[idxObj].saidaLinearI);
					////objetos[idxObj].saidaLinearI = 0;//.1*objetos[idxObj].saidaLinearI;
					//break;
				}
				else
				{
					objetos[idxObj].setPointVel = objetos[idxObj].setPointVelOrig;
					if (objetos[idxObj].usaTrajAux)
					{
						double dist = objetos[idxObj].posAtual.distance(objetos[idxObj2].posAtual);
						if (dist < minDistRtn)
						{
							minDistRtn = dist;
						}
					}

				}
			}
		}
		
		if (objetos[idxObj].usaTrajAux && minDistRtn > 60 && minDistRtn < 500)
		{
			objetos[idxObj].usaTrajAux = false;
			//Logger::Output("eu coloquei para false pq eu quis!");
		}

		

		if (ui.checkShowDrawBox->isChecked())
		{
			// Treta pra desenhar a polyline
			const cv::Point *pts = (const cv::Point*) Mat(pontos).data;
			int npts = Mat(pontos).rows;

			// Desenhando
			polylines(originalMat, &pts, &npts, 1,
				false, 					// Desenha o contorno fechado (i.e. junta o ultimo ponto com o primeiro) 
				coresDrawObj[idxObj],		// Cor em RGB 
				1, 						// Espessura da linha
				CV_AA, 0);
		}

		
		
	}

}


#pragma region Funcionalidades do Usuario

void ProjetoFinal::keyReleaseEvent(QKeyEvent *event){
	switch (event->key()) {
	case Qt::Key_Z:
		for (int idxObj = 0; idxObj < objetos.size(); idxObj++)
		{
			if (objetos[idxObj].nome == "CarroTeste")
			{
				ui.XYText->appendPlainText("CarroTeste pausado");
				objetos[idxObj].setPointVel = 0;
				objetos[idxObj].setPointVelOrig = 0;
				break;
			}
		}
		break;
	case Qt::Key_X:
		for (int idxObj = 0; idxObj < objetos.size(); idxObj++)
		{
			if (objetos[idxObj].nome == "CarroTeste2")
			{
				ui.XYText->appendPlainText("CarroTeste2 pausado");
				objetos[idxObj].setPointVel = 0;
				objetos[idxObj].setPointVelOrig = 0;
				break;
			}
		}
		break;
	case Qt::Key_C:
		for (int idxObj = 0; idxObj < objetos.size(); idxObj++)
		{
			if (objetos[idxObj].nome == "CarroTeste")
			{
				ui.XYText->appendPlainText("CarroTeste pausado");
				objetos[idxObj].setPointVel = 60;
				objetos[idxObj].setPointVelOrig = 60;
				break;
			}
		}
		break;
	case Qt::Key_V:
		for (int idxObj = 0; idxObj < objetos.size(); idxObj++)
		{
			if (objetos[idxObj].nome == "CarroTeste2")
			{
				ui.XYText->appendPlainText("CarroTeste2 pausado");
				objetos[idxObj].setPointVel = 40;
				objetos[idxObj].setPointVelOrig = 40;
				break;
			}
		}
		break;
	}

}

void ProjetoFinal::on_startButton_clicked()
{	
	//if (tmrTimer->isActive() == false)
	//{
	//	ui.XYText->appendPlainText("Reiniciado");		
	//	tmrTimer->start(33);
	//}
	ui.pauseButton->setEnabled(true);
	ui.startButton->setEnabled(false);

	runningTest = true;
	ui.XYText->appendPlainText("Running Test");


	Serial::instance()->EnviarMensagem2(0, 0, "ACAC");

//#pragma omp parallel shared(runningTest)
//	{
//		while (runningTest)
//		{
//			ui.XYText->appendPlainText("~-=~");
//		}
//
//	}

//#pragma omp sections
//	{
//#pragma omp section
//		{
//			while (runningTest)
//			{
//				ui.XYText->appendPlainText("~-=~");
//			}
//		}
//	}
}

void ProjetoFinal::on_pauseButton_clicked(){
	//if (tmrTimer->isActive() == true)
	//{
	//	ui.XYText->appendPlainText("Pausado");
	//	tmrTimer->stop();
	//}
	ui.pauseButton->setEnabled(false);
	ui.startButton->setEnabled(true);

	runningTest = false;
	ui.XYText->appendPlainText("Not Running Test");

	for (int idxObj = 0; idxObj < objetos.size(); idxObj++)
	{
		objetos[idxObj].saidaLinearI = 0;
		objetos[idxObj].saidaAngularI = 0;
		Serial::EnviarMensagem2(0, 0, objetos[idxObj].cfgXbee);

	}

	
}

void ProjetoFinal::on_checkShowBlob_stateChanged(int state)
{
	if (state == 0)
	{
		ui.XYText->appendPlainText("Nao mostrar os blobs");
	}
	else
	{
		ui.XYText->appendPlainText("Mostrar os blobs");
		/*Vision::getBlobs(cores);*/
	}
}

void ProjetoFinal::on_checkShowDrawBox_stateChanged(int state)
{
	if (state == 0)
	{
		ui.XYText->appendPlainText("Nao mostrar os desenhos");
	}
	else
	{
		ui.XYText->appendPlainText("Mostrar os desenhos");
		/*Vision::getBlobs(cores);*/
	}
}


void ProjetoFinal::on_checkShowTraj_stateChanged(int state)
{
	if (state == 0)
	{
		ui.XYText->appendPlainText("Não mostrar trajetorias");
		mostrarTrajetorias = false;
	}
	else
	{
		ui.XYText->appendPlainText("Mostrar Trajetorias");
		mostrarTrajetorias = true;
	}
}

void ProjetoFinal::on_checkShowimageBox_stateChanged(int state){
	// Esta funcao define se a imagem da camera sera visualizada ou nao
	if (state == 0)
	{
		ui.XYText->appendPlainText("Nao mostrar vídeo");
		mostrarImagemNaTela = false;
		destroyWindow("Imagem");

		ui.checkShowBlob->setChecked(false);
		ui.checkShowBlob->setEnabled(false);

		ui.checkShowDrawBox->setChecked(false);
		ui.checkShowDrawBox->setEnabled(false);

		ui.checkShowTraj->setChecked(false);
		ui.checkShowTraj->setEnabled(false);
	}
	else
	{
		ui.XYText->appendPlainText("Mostrar vídeo");
		mostrarImagemNaTela = true;

		ui.checkShowBlob->setEnabled(true);
		ui.checkShowDrawBox->setEnabled(true);
		ui.checkShowTraj->setEnabled(true);

		namedWindow("Imagem", 1);					//create window to show 
//		long frameNum = 0;
//		clock_t tempo = clock();
//
//		//Mat processedMat = cv::Mat(originalMat.cols, originalMat.rows, CV_8UC3);
//		while (mostrarImagemNaTela) {
//#ifdef OUTPUTBIEL
//			Logger::Output("------- Frame: %f0 ------- \n", frameNum);
//			Logger::Output("FPS: %f0 \n", 1/((clock() - tempo) / ((double)CLOCKS_PER_SEC)));
//
//			tempo = clock();
//
//#endif
//			Vision::instance()->ProcessFrames();
//			// Convert input image to HSV	
//			//cvtColor(originalMat, originalMat, COLOR_BGR2HSV);
//
//			//std::thread hMin([](Vision frame, Ui::ProjetoFinalClass ui, vector<Cor> cores){
//			//	Vision::instance()->getBlobs(cores[2], ui.checkShowBlob->isChecked());
//			//}, frame, ui, cores);
//
//			//hMin.detach();
//			////hMin.join();
//
//			//processedMat = cv::Mat(originalMat.cols, originalMat.rows, CV_8UC3);
//			/*cv::cvtColor(originalMat, processedMat, cv::COLOR_BGR2HSV);*/
//
//			/*clock_t beginNovo = clock();*/
//
//
//
//	/*		vector<Cor> newCores;
//			for each (Objeto obj in objetos)
//			{
//				if (obj.nome == "CarroTeste")
//				{
//					newCores.push_back(obj.primColor);
//					newCores.push_back(obj.secColor);
//				}
//			}
//*/
//			/*for each (Cor myCor in newCores)
//			{
//				posicaoCores.push_back(Vision::instance()->getBlobs(myCor, ui.checkShowBlob->isChecked()));
//
//			}*/
//
//
//			//Comentado versão single thread
//			/*clock_t tempoPosicao = clock();
//			vector<vector <cv::Point> > posicaoCores;
//			for (int i = 0; i < cores.size(); i++)
//			{
//					posicaoCores.push_back(Vision::instance()->getBlobs(cores[i], ui.checkShowBlob->isChecked()));
//			}
//			Logger::Output("Tempo get posição: %f0 \n", ((clock() - tempoPosicao) / ((double)CLOCKS_PER_SEC)) * 1000);*/
//
//			clock_t tempoPosicao = clock();
//
//			vector<vector <cv::Point> > posicaoCores = Vision::instance()->getPosicaoCores(cores, false);
//
//			Logger::Output("Tempo get posição: %f0 \n", ((clock() - tempoPosicao) / ((double)CLOCKS_PER_SEC))*1000);
//
//
//			Vision::originalMat.copyTo(originalMat);
//			FindObjects(posicaoCores);
//			
//			/*parallel_for_		*/
//
//			for each (Objeto obj in objetos)
//			{
//				if (obj.nome == "CarroTeste")
//				{
//					obj.Controle();
//					//Serial::instance()->EnviarMensagem2(150, 150, "ACAC");
//					//ui.XYText->appendPlainText("CONTROLE");
//				}
//			}
//
//			//Vision::instance()->getAllBlobs(cores, ui.checkShowBlob->isChecked());			
//			waitKey(1);							//delay 33ms
//			imshow("window", originalMat);  //print image to screen
//			//imshow("window", Vision::originalMat);  //print image to screen
//			//imshow("window", Mat(Vision::originalGpuMat));
//			//float tempoGpuNovo = float(clock() - beginNovo) / CLOCKS_PER_SEC;
//			frameNum++;
//		}		
	}

}

void ProjetoFinal::on_actionCalibrar_Filtros_de_Cor_triggered(){
	// Esta funcao ativa uma nova tela para configurar os filtros de Cor
	ui.XYText->appendPlainText("Calibracao de Cores aberta");
	filtroCam->transferirImagemParaCameraCalib = true;
}

void ProjetoFinal::on_actionCalibrar_Controle_triggered(){
	// Esta funcao deve criar uma nova tela para configurar os parametros de controle dos carrinhos
	ui.XYText->appendPlainText("Calibracao de PID aberta");
	pidCam->transferirImagemParaPIDCalib = true;		
}

void ProjetoFinal::on_actionNovo_Robo_triggered(){
	ui.XYText->appendPlainText("Tela para criar novo robo aberta");
	roboCam->chamaConfigRobo = true;
}

void ProjetoFinal::closeEvent(QCloseEvent *evento)
{
	mostrarImagemNaTela = false;	// Caso o video esteja aberto
	evento->accept();

	//QMessageBox::StandardButton resBtn = QMessageBox::question(this, APP_NAME,
	//	tr("Tem certeza?\n"),
	//	QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
	//	QMessageBox::Yes);
	//if (resBtn != QMessageBox::Yes) {
	//	evento->ignore();
	//}
	//else {
	//	evento->accept();
	//}
}

#pragma endregion

#pragma region Funcoes Auxiliares

void ProjetoFinal::DesenhaTrajetorias()
{

	/*map<string, cv::Mat> desenhosTrajetorias;
	map<string, bool> mapTrajetoriasDesenhadas;*/
	cv::Mat imgTrajetoria;

	for (int idxObj = 0; idxObj < objetos.size(); idxObj++)
	{
		if (objetos[idxObj].traj.nome != "")
		{
			if (!mapTrajetoriasDesenhadas[objetos[idxObj].traj.nome])
			{
				imgTrajetoria = cv::Mat(originalMat.rows, originalMat.cols, CV_8UC3);
				imgTrajetoria.setTo(cv::Scalar(0, 0, 0));

				vector<cv::Point> pontos;

				for (int i = 0; i < objetos[idxObj].traj.pontos.size(); i++)
				{
					pontos.push_back(cv::Point(objetos[idxObj].traj.arrx[i], objetos[idxObj].traj.arry[i]));
				}

				// Treta pra desenhar a polyline
				const cv::Point *pts = (const cv::Point*) Mat(pontos).data;
				int npts = Mat(pontos).rows;

				// Desenhando
				polylines(imgTrajetoria, &pts, &npts, 1,
					false, 					// Desenha o contorno fechado (i.e. junta o ultimo ponto com o primeiro) 
					coresDrawObj[idxObj],		// Cor em RGB 
					1, 						// Espessura da linha
					CV_AA, 0);

				desenhosTrajetorias[objetos[idxObj].traj.nome] = imgTrajetoria;

				mapTrajetoriasDesenhadas[objetos[idxObj].traj.nome] = true;

			}
			else {
				imgTrajetoria = desenhosTrajetorias[objetos[idxObj].traj.nome];
			}


			add(originalMat, imgTrajetoria, originalMat);
		}
	}
}

void ProjetoFinal::DesenhaTrajetorias2()
{

	cv::Mat imgTrajetoria;
	Trajetoria trajDraw;

	for (int idxObj = 0; idxObj < objetos.size(); idxObj++)
	{
		if (objetos[idxObj].traj.nome != "")
		{
			if (objetos[idxObj].usaTrajAux)
			{
				trajDraw = objetos[idxObj].trajAux;
			}
			else
			{
				trajDraw = objetos[idxObj].traj;
			}
			
			if (!mapTrajetoriasDesenhadas[trajDraw.nome])
			{
				imgTrajetoria = cv::Mat(originalMat.rows, originalMat.cols, CV_8UC3);
				imgTrajetoria.setTo(cv::Scalar(0, 0, 0));

				vector<cv::Point> pontos;

				for (int i = 0; i < trajDraw.pontos.size(); i++)
				{
					pontos.push_back(cv::Point(trajDraw.arrx[i], trajDraw.arry[i]));
				}

				// Treta pra desenhar a polyline
				const cv::Point *pts = (const cv::Point*) Mat(pontos).data;
				int npts = Mat(pontos).rows;

				// Desenhando
				polylines(imgTrajetoria, &pts, &npts, 1,
					false, 					// Desenha o contorno fechado (i.e. junta o ultimo ponto com o primeiro) 
					coresDrawObj[idxObj],		// Cor em RGB 
					1, 						// Espessura da linha
					CV_AA, 0);

				desenhosTrajetorias[trajDraw.nome] = imgTrajetoria;

				mapTrajetoriasDesenhadas[trajDraw.nome] = true;

			}
			else {
				imgTrajetoria = desenhosTrajetorias[trajDraw.nome];
			}


			add(originalMat, imgTrajetoria, originalMat);
		}
	}
}




void ProjetoFinal::FindObjects(vector<vector<cv::Point>> posicaoCores){

	//double limiar = 45;
	double limiar = 9.5;
	for (int idxObj = 0; idxObj < objetos.size(); idxObj++)
	{
		objetos[idxObj].achou = false;
		if (objetos[idxObj].traj.nome != "")
		{
			//pega cor secundária
			Cor corSecTemp = objetos[idxObj].secColor;
			int idxCorSecTemp = Cor::getIdxCorPorNome(corSecTemp.nome, cores);

			Cor corPrimTemp = objetos[idxObj].primColor;
			int idxCorPrimTemp = Cor::getIdxCorPorNome(corPrimTemp.nome, cores);

			//varre todas as posições das cor secundária do objeto em questão
			for (int idxSec = 0; idxSec < posicaoCores[idxCorSecTemp].size() && !objetos[idxObj].achou; idxSec++)
			{
				Position pSec(posicaoCores[idxCorSecTemp][idxSec].x, posicaoCores[idxCorSecTemp][idxSec].y);
				if (pSec.x != -1000)
				{
					//varre todas as posições da cor primária do objeto em questão
					for (int idxPrim = 0; idxPrim < posicaoCores[idxCorPrimTemp].size() && !objetos[idxObj].achou; idxPrim++)
					{
						Position pPrim(posicaoCores[idxCorPrimTemp][idxPrim].x, posicaoCores[idxCorPrimTemp][idxPrim].y);
						if (pPrim.x != -1000)
						{
							if (pPrim.distance(pSec) < limiar)
							{
								objetos[idxObj].setPosAtual(pPrim, pSec);
								posicaoCores[idxCorPrimTemp][idxPrim].x = -1000;
								posicaoCores[idxCorSecTemp][idxSec].x = -1000;
								objetos[idxObj].achou = true;
								if (ui.checkShowDrawBox->isChecked())
								{
									DrawCar(objetos[idxObj], coresDrawObj[idxObj]);
								}
							}
						}
					}
				}
			}
		}
	}
}

//int ProjetoFinal::getIdxCorPorNome(string name, vector<Cor> vCores)
//{
//	for (int idxCores = 0; idxCores < vCores.size(); idxCores++)
//	{
//		if (vCores[idxCores].nome == name)
//		{
//			return idxCores;
//		}
//	}
//
//	return -1;
//}

void ProjetoFinal::DrawCar(Objeto obj)
{
	int raioDesenho = 20;
	cv::Point centrObj = cv::Point(obj.posAtual.x, obj.posAtual.y);
	cv::circle(originalMat, centrObj, raioDesenho, cv::Scalar(255, 255, 255), 3);
	double x, y;

	x = raioDesenho * cos(obj.posAtual.ang) + obj.posAtual.x;
	y = raioDesenho * sin(obj.posAtual.ang) + obj.posAtual.y;

	cv::Point ponto2 = cv::Point(x,y);
	cv::line(originalMat, centrObj, ponto2, cv::Scalar(255, 255, 255), 2);
}

void ProjetoFinal::DrawCar(Objeto obj, cv::Scalar pCor)
{
	int raioDesenho = 10;
	cv::Point centrObj = cv::Point(obj.posAtual.x, obj.posAtual.y);
	cv::circle(originalMat, centrObj, raioDesenho, pCor, 3);
	double x, y;

	x = raioDesenho * cos(obj.posAtual.ang) + obj.posAtual.x;
	y = raioDesenho * sin(obj.posAtual.ang) + obj.posAtual.y;

	cv::Point ponto2 = cv::Point(x, y);
	cv::line(originalMat, centrObj, ponto2, pCor, 2);
}
#pragma endregion