#include "Objeto.h"

#pragma region Construtor/Destrutor

Objeto::Objeto()
{
	posAnterior.x = MAXUINT16;
	posAnterior.y = MAXUINT16;

	Speeds.push_back(0.0);
	Speeds.push_back(0.0);
	Speeds.push_back(0.0);
	Speeds.push_back(0.0);
	//posAnterior.ticks = clock();
	//posAnterior.timev = time(&timev);

	

}

Objeto::~Objeto()
{
	
}

#pragma endregion

void Objeto::setPosAtual(double _x, double _y, double _theta)
{
	
	
	this->posAnterior = posAtual;
	//this->posAtual.x = _x;
	//this->posAtual.y = _y;
	//this->posAtual.ang = _theta;
	this->posAtual.setPos(_x, _y, _theta);
}




void Objeto::setPosAtual(Position pCorPrim, Position pCorSec)
{
	this->posAnterior = posAtual;

	
	double x = (pCorPrim.x + pCorSec.x) / 2;
	double y = (pCorPrim.y + pCorSec.y) / 2;
	
	
	double thetaCirculoUnit = atan2((pCorPrim.y - pCorSec.y), (pCorPrim.x - pCorSec.x));
	//double thetaCirculoUnit = atan2((pCorPrim.x - pCorSec.x), (pCorPrim.y - pCorSec.y));


	double deltaXCirculoUnit = 2 * cos(thetaCirculoUnit);
	double deltaYCirculoUnit = 2 * sin(thetaCirculoUnit);

	
	/*double deltaX = (pCorPrim.x - pCorSec.x);
	double deltaY = (pCorPrim.y - pCorSec.y);*/

	double theta;

	// se posAnterior = segundo quadrante e posAtual = terceiro quadrante
	if (posAnterior.deltaYCirculoUnit >= 0 && posAnterior.deltaXCirculoUnit<0 && deltaYCirculoUnit < 0 && deltaXCirculoUnit < 0){
		posAtual.offset++;
		posAtual.angMin = posAtual.angMin + 2 * M_PI*posAtual.offset;
		posAtual.angMax = posAtual.angMax + 2 * M_PI*posAtual.offset;

	}
	// se posAnterior = quarto terceiro e posAtual = segundo quadrante
	if (posAnterior.deltaYCirculoUnit <= 0 && posAnterior.deltaXCirculoUnit<0 && deltaYCirculoUnit > 0 && deltaXCirculoUnit < 0){
		posAtual.offset--;
		posAtual.angMin = posAtual.angMin + 2 * M_PI*posAtual.offset;
		posAtual.angMax = posAtual.angMax + 2 * M_PI*posAtual.offset;

	}

	//theta = atan2(deltaY, deltaX) + (2 * M_PI)*posAtual.offset + M_PI_4;
	//theta = atan2(deltaX, deltaY) + (2 * M_PI)*posAtual.offset + M_PI_4;
	theta = thetaCirculoUnit +(2 * M_PI)*posAtual.offset -M_PI_4;

	posAtual.setPos(x, y, theta, deltaXCirculoUnit, deltaYCirculoUnit);

	//double theta = atan2((pCorPrim.y - pCorSec.y), (pCorPrim.x - pCorSec.x)) + M_PI_4;



	
	//this->setPosAtual(x, y, theta);
}

Objeto::Objeto(string n, Cor p, Cor s, Cor t, paramControle c, string xbee, TipoObjeto tpObj, double setpVel, Trajetoria pTraj)
{
	nome = n;
	primColor = p;
	secColor = s;
	terColor = t;
	ctrl = c;
	cfgXbee = xbee;
	tipo = tpObj;
	setPointVel = setpVel;
	setPointVelOrig = setpVel;
	traj = pTraj;

	posAnterior.x = MAXUINT16;
	posAnterior.y = MAXUINT16;

	Speeds.push_back(0.0);
	Speeds.push_back(0.0);
	Speeds.push_back(0.0);
	Speeds.push_back(0.0);


}

double Objeto::getVelDerivSuja()
{
	if (posAnterior.x > (MAXUINT16 / 2) || posAnterior.y > (MAXUINT16 / 2) || (posAnterior.x == 0 && posAnterior.y == 0))
	{
		return 0;
	}
	
	double difx = DerivadaSuja(posAnterior.x, posAtual.x, 0.1);
	double dify = DerivadaSuja(posAnterior.y, posAtual.y, 0.1);

	double velocidade = sqrt(pow(difx, 2) + pow(dify, 2));

	return velocidade;
}

double Objeto::getVel()
{
	if (posAnterior.x < 0 || posAnterior.y < 0)
	{
		return 0;
	}
	
	
	double difX = posAnterior.x - posAtual.x;
	double difY = posAnterior.y - posAtual.y;

	//double difTime = posAtual.timev - posAnterior.timev;
	double difTime = ((posAtual.ticks - posAnterior.ticks)) / ((double)CLOCKS_PER_SEC);
	//double difTime = taxaH;

	if (difTime <= 0)
	{
		return 0;
	}

	double velocidade = sqrt(pow(difX, 2) + pow(difY, 2)) / difTime;

	return velocidade;
}

double Objeto::getAngVel()
{
	double difAng = posAnterior.ang - posAtual.ang;

	double difTime = posAtual.timev - posAnterior.timev;

	return 0;
}

bool Objeto::operator==(const Objeto& other)
{
	bool retorno = true;

	if (this->nome != other.nome) return false;

	if (this->primColor.nome != other.primColor.nome) return false;
	if (this->secColor.nome != other.secColor.nome) return false;
	if (this->terColor.nome != other.terColor.nome) return false;

	if (this->ctrl.nome != other.ctrl.nome) return false;
	if (this->cfgXbee != other.cfgXbee) return false;
	if (this->tipo != other.tipo) return false;

	return retorno;
}

bool Objeto::dentroTrajetoria()
{
	return traj.contem(this->posAtual.x, this->posAtual.y);
}

#pragma region Controle

void Objeto::AtualizaVelocidade()
{
	//velAtual = getVelDerivSuja();
	Speeds.push_back(getVelDerivSuja());
	Speeds.pop_front();
	velAtual = mathHelper::dqAvg(Speeds);
	
	//velAtual = getVel();
}

StrRetorno Objeto::ControleJacoud(){

	return StrRetorno();
}

StrRetorno Objeto::ControleJacoud(paramControle pParam){

	ofstream objectStream, signalsStream, testStream;

	// log files
	objectStream.open("roboData.txt", ios::out | ios::app);
	signalsStream.open("signalsStream.txt", ios::out | ios::app);
	testStream.open("testStream.txt", ios::out | ios::app);






	// end log files

	clock_t now = clock();
	//double t = (now*0.3) / CLOCKS_PER_SEC;
	double t = (now*0.3) / CLOCKS_PER_SEC;

	double _sin = sin(2 * M_PI * 1 * t); 


	//double AngRef = (-240 * M_PI / 180) + (30 * M_PI / 180.0)* _sin;
	double AngRef = integralESC  + (30 * M_PI / 180.0)* _sin;

	//double AngRef = integralESC + (10 * M_PI / 180.0)* _sin;


	//double PosRef = 160+ 30*sin(2 * M_PI*0.2*t);

	//while (AngRef <= -M_PI){
	//	//Logger::Output("Menor que pi \n", 0);

	//	AngRef = AngRef + 2 * M_PI;
	//}

	//while (AngRef >= M_PI) {
	//	//Logger::Output("Maior que pi \n", 0);

	//	AngRef = AngRef - 2 * M_PI;
	//}




	double erroAng = AngRef - posAtual.ang;
	
	//if (erroAng > (360 * M_PI / 180)){
	//	erroAng = 360 * M_PI / 180;
	//}
	//if (erroAng < (-360 * M_PI / 180)){
	//	erroAng = -360 * M_PI / 180;
	//}




	
	//double erroLin = PosRef - posAtual.x;


	double xSource = objFuncCusto.posX;
	double ySource = objFuncCusto.posY;
	double angSource = objFuncCusto.ang;
	
	//double angSorce = 180-(qAtan2(xSource - posAtual.x, ySource - posAtual.y)) * 180 / M_PI;



	double y = -pow((posAtual.ang - (angSource* M_PI / 180)), 2) + 10;

	LowPassFilter(y, 0.5);
	

	double outputHighPass = y - outputFilter;


	double sinDoubleFreq = _sin*outputHighPass;


	LowPassFilter2(sinDoubleFreq, 0.5);

	double gradientEstimative = outputFilter2;

	integralESC = integralESC + taxaH*gradientEstimative;


	if (integralESC > (360*M_PI/180)){
		integralESC = 360 * M_PI / 180;
	}
	if (integralESC < (-360 * M_PI / 180)){
		integralESC = -360 * M_PI / 180;
	}

	double uEsc = integralESC + (30 * M_PI / 180)*_sin;

	//erroAng = AjustaAngulo(erroAng, true);

	ControleAngular(pParam, erroAng);

	//ControleAngular(pParam, erroAng);

	//ControleCruzeiro(pParam, erroLin);

	//saidaControleAngular = 0; // jean
	//saidaControleLinear = -300; // negativo = pra frente

	//int raio = 120;
	//int xc = 320;
	//int yc = 240;

	//int XRef = xc + raio*cos(2 * M_PI*0.2*t);
	//int YRef = yc + raio*sin(2 * M_PI*0.2*t);

	//double erroPos = sqrt(pow((posAtual.x - XRef), 2) + pow((posAtual.y - YRef), 2));
	//double erroPos = XRef - posAtual.x;
	//double erroPos = YRef - posAtual.y;


	//double kPos = 3;
	//saidaControleLinear = 0;//pParam.pLin*erroPos;

	MontaSinaisTensao();
	//MontaSinaisTensao2(t);

	//float fatorDimensao = 0.0475;	// Fator q se refere ao tamanho do carro/2 isso em metros, ao menos eu acho q eh essa unidade
	//saidaControleLinear = 0;
	//double kAng = pParam.pAng;
	//saidaControleAngular = kAng*erroAng;
	



	// convert from -255/255 scale to -5/5 volts
	double sinalTensao1Volts = sinalTensao1 * 5 / 255;
	double sinalTensao2Volts = sinalTensao2 * 5 / 255;


	//signalsStream << "OutputLowPassFilter" << ',' << "OutputHighPassFilter" << ',' << "GradientEstimative" << "\n";
	signalsStream << y << ',' << outputHighPass << ',' << sinDoubleFreq << ',' << gradientEstimative << ',' << integralESC << ',' << uEsc << "\n";
	// 	objectStream << "SinalTensao1Volts" << ',' << "SinalTensao2Volts" << ',' << "posAtualAng" << ',' << "refAngu" << "\n";
	objectStream << sinalTensao1 << ',' << sinalTensao2 << ',' << saidaControleAngular << ',' << saidaControleLinear << ',' << AngRef << ',' << posAtual.ang << ',' << posAtual.x << ',' << posAtual.y << ',' << t << ',' << angSource << "\n";


	signalsStream.close();

	objectStream.close();
	testStream.close();

	Serial::instance()->EnviarMensagem2(sinalTensao1, sinalTensao2, cfgXbee); // GARANTIR QUE ESSES SINAIS DE TENSAO ESTEJAM ENTRE -255 ATE 255




	return StrRetorno(0, 0, 0, 0, posAtual.ang, AngRef, erroAng, 0, posAtual, saidaControleLinear, saidaControleAngular, sinalTensao1, sinalTensao2, false, angSource);
	//return StrRetorno(0, 0, 0, 0, posAtual.x, PosRef, erroLin, 0, Position(0, 0), saidaControleLinear, saidaControleAngular, sinalTensao1, sinalTensao2, false);

	//return StrRetorno(velAtual, setPointVel, erroVel, posAtual.ang, angDesejado, erroAng, mDist, mPos, saidaControleLinear, saidaControleAngular, sinalTensao1, sinalTensao2);
}

StrRetorno Objeto::Controle(){
	return this->Controle(this->ctrl, true, 0.04);
}

StrRetorno Objeto::Controle(paramControle pParam, bool pSentido, double pKAngDes){
	Position mPos;
	double mDist;

	if (!usaTrajAux)
	{
		tie(mPos, mDist) = traj.getMelhorPonto(posAtual);

	}
	else {
		tie(mPos, mDist) = trajAux.getMelhorPonto(posAtual);
	}

	angDesejado = CalculaAngDesejado(pSentido, mPos, mDist, pKAngDes);

	//double velAtual = getVel();
	//double velAtualDerivSuja = getVelDerivSuja();
	//velAtual = getVelDerivSuja();
	double erroVel = setPointVel - velAtual;

	double erroAng = angDesejado - posAtual.ang;
	erroAng = AjustaAngulo(erroAng, pSentido);
	
	ControleCruzeiro(pParam, erroVel);
	ControleAngular(pParam, erroAng);
	MontaSinaisTensao();
	bool sent=Serial::instance()->EnviarMensagem2(sinalTensao1, sinalTensao2, cfgXbee); // GARANTIR QUE ESSES SINAIS DE TENSAO ESTEJAM ENTRE -255 ATE 255
	//s.EnviarMensagem2(sinalTensao1, sinalTensao2, cfgXbee); // GARANTIR QUE ESSES SINAIS DE TENSAO ESTEJAM ENTRE -255 ATE 255

#ifdef OUTPUTBIEL
	//Logger::Output("Sinal1: %f\n", sinalTensao1);
	//Logger::Output("Sinal2: %f\n", sinalTensao2);

#endif
	//return mPos;
	return StrRetorno(0, velAtual, setPointVel, erroVel, posAtual.ang, angDesejado, erroAng, mDist, mPos, saidaControleLinear, saidaControleAngular, sinalTensao1, sinalTensao2, saturouAng);
}

//void Objeto::PID(double valorDesejado, double valorAtual, float kP, float kI, float kD, bool isLinear)
void Objeto::PID(double erro, float kP, float kI, float kD, bool isLinear)
{
	double saidaP, saidaD;

	saidaP = kP * erro;
	saidaD = kD * CalculaDerivadaSuja(isLinear, erro);

	if (isLinear)
	{
		saidaLinearI = kI * (saidaLinearI + taxaH * (erro));
		saidaControleLinear = saidaP + saidaLinearI + saidaD;
	}
	else
	{
		saidaAngularI = kI * (saidaAngularI + taxaH * (erro));
		saidaControleAngular = saidaP + saidaAngularI + saidaD;
	}
}

void Objeto::LowPassFilter(double input, double omegaH)
{
	//double omegaH = 0.25;// tem que matar a senoide
	//double omegaH = 0.35;// tem que matar a senoide

	outputFilter = (1 - taxaH * omegaH)*outputFilter + taxaH*omegaH*input;

}

void Objeto::LowPassFilter2(double input, double omegaH)
{
	//double omegaH = 0.25;// tem que matar a senoide
	//double omegaH = 0.35;// tem que matar a senoide

	outputFilter2 = (1 - taxaH * omegaH)*outputFilter2 + taxaH*omegaH*input;

}



void Objeto::ControleCruzeiro(paramControle pParam, double pErro){
	/*double velAtual = getVel();
	double erro = setPointVel - velAtual;*/
#ifdef OUTPUTBIEL
	//Logger::Output("Vel Atual: %f\n", velAtual);
	//Logger::Output("Erro Vel Linear: %f\n", erro);

#endif

	//PID(erro, ctrl.pLin, ctrl.iLin, ctrl.dLin, true);
	PID(pErro, pParam.pLin, pParam.iLin, pParam.dLin, true);
	//return velAtual;
}

void Objeto::ControleAngular(paramControle pParam, double pErro){
	//double erro = angDesejado - posAtual.ang;

	//double erro = AjustaAngulo(pErro, true);

	//PID(erro, ctrl.pAng, ctrl.iAng, ctrl.dAng, false);
	PID(pErro, pParam.pAng, pParam.iAng, pParam.dAng, false);

}

void Objeto::MontaSinaisTensao(){
	float fatorDimensao = 0.0475;	// Fator q se refere ao tamanho do carro/2 isso em metros, ao menos eu acho q eh essa unidade


	//saidaControleAngular = 0.6 / 0.0413;

	sinalTensao1 = mathHelper::sat(((0.05 * saidaControleLinear) + (0.05 * saidaControleAngular) / fatorDimensao),255);
	sinalTensao2 = mathHelper::sat(((0.05 * saidaControleLinear) - (0.05 * saidaControleAngular) / fatorDimensao),255);	



	//if (posAtual.timev - posAnterior.timev == 0) // não atualizou
	//{
	//	sinalTensao1 = 0;
	//	sinalTensao2 = 0;
	//}
	//else{
	//	sinalTensao1 = sinalTensao1;
	//}

}

void Objeto::MontaSinaisTensao2(double t){
	float fatorDimensao = 0.0475;	// Fator q se refere ao tamanho do carro/2 isso em metros, ao menos eu acho q eh essa unidade


	//saidaControleAngular = 0.6 / 0.0413;
	//saidaControleAngular = saidaControleAngular + (0.5*sin(2 * 3.141592 * 20 * t)) / 0.0413; // << --_signalStream_saved_identificacao_jitter

	sinalTensao1 = mathHelper::sat(((0.05 * saidaControleLinear) + (0.05 * saidaControleAngular) / fatorDimensao), 255);
	sinalTensao2 = mathHelper::sat(((0.05 * saidaControleLinear) - (0.05 * saidaControleAngular) / fatorDimensao), 255);



	//if (posAtual.timev - posAnterior.timev == 0) // não atualizou
	//{
	//	sinalTensao1 = 0;
	//	sinalTensao2 = 0;
	//}
	//else{
	//	sinalTensao1 = sinalTensao1;
	//}

}

#pragma region Funcoes Auxiliares de Controle

double Objeto::DerivadaSuja(double pValAnterior, double pValAtual, double pDelta)
{
	pDelta = 1.43*taxaH;
	//pDelta = 10*taxaH;
	//pDelta = 4 * taxaH;
	
	double velAuxDerivadaSuja = (pDelta / (pDelta + taxaH)) * pValAnterior + (taxaH / (pDelta + taxaH)) * pValAtual;
	return ((-1 / pDelta) * velAuxDerivadaSuja + (1 / pDelta) * pValAtual);
}


float Objeto::CalculaDerivadaSuja(bool isLinear, double erro){
	float derivada;
	if (isLinear)
	{
		velAuxDerivadaSuja = (delta / (delta + taxaH)) * velAuxAntigaDerivadaSuja + (taxaH / (delta + taxaH)) * erro;
		derivada = (-1 / delta) * velAuxDerivadaSuja + (1 / delta) * erro;
	}
	else
	{
		angAuxDerivadaSuja = (delta / (delta + taxaH)) * angAuxAntigaDerivadaSuja + (taxaH / (delta + taxaH)) * erro;
		derivada = (-1 / delta) * angAuxDerivadaSuja + (1 / delta) * erro;
	}
	return derivada;
}

float Objeto::CalculaAngDesejado(bool sentido, Position mPos, double mDist, double pKAngDes){
	//double k = 2;			// Fator de ajuste do angulo desejado(valor proporcional ao erro angular para gerar um ang desejado
	//double k = 0.04;			// Fator de ajuste do angulo desejado(valor proporcional ao erro angular para gerar um ang desejado
	double k  = pKAngDes;
	//de forma a obrigar o carro a ir para a trajetoria desejada)
	bool dentro = false;
	if (!usaTrajAux)
	{
		dentro = traj.contem(posAtual.x, posAtual.y);
	}
	else {
		dentro = trajAux.contem(posAtual.x, posAtual.y);
	}


	double angDesejado, diferenca;
	float satAngRad = mathHelper::Deg2Rad(85);	// Saturacao da diferenca angular em radianos

	//tuple<Position, double> tpDist = traj.getMelhorPonto(posAtual);
	/*Position mPos;
	double mDist;
	tie(mPos, mDist) = traj.getMelhorPonto(posAtual);*/

	if (k*mDist < 2)
	{
		int a = 1;

	}
	
	double angMa = mPos.ang;

	diferenca = k * mDist * pow(-1, dentro) * pow(-1, sentido);

	if (abs(diferenca) > satAngRad){
		diferenca = mathHelper::sgn(diferenca) * satAngRad;
		saturouAng = true;
	}
	else{
		saturouAng = false;
	}

	float angMaOriginal = mathHelper::Rad2Deg(angMa);

	if (sentido == 0){
		angMa = 0 - (M_PI - angMa);
	}

	if (diferenca < angMa)
	{
		int b = 1;
	}

	angDesejado = (angMa - diferenca);

	return angDesejado;
}

float Objeto::AjustaAngulo(float erroAng, bool sentido){
	/*Logger::Output(" ");
	Logger::Output(" ");
	Logger::Output("====Ajusta Angulo==== \n", 0);
	Logger::Output("Entrada: %f\n", erroAng);*/

	if (erroAng < -10000000000000)
	{
		erroAng = 0;
	}
	//float angAjustado = erroAng

	while (erroAng <= -M_PI){
		//Logger::Output("Menor que pi \n", 0);

		erroAng = erroAng + 2 * M_PI;
	}

	while (erroAng >= M_PI) {
		//Logger::Output("Maior que pi \n", 0);

		erroAng = erroAng - 2 * M_PI;
	}

	//Logger::Output("Saída: %f\n", erroAng);

	return erroAng;
}

#pragma endregion

#pragma endregion