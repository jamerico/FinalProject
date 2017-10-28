#include "StrRetorno.h"


StrRetorno::StrRetorno()
{
	satAng = false;

	velAtual = 0.0;
	velAtualDerivSuja = 0.0;
	setPoint = 0.0;
	erroVel = 0.0;
	saidaControleLinear = 0.0;

	angAtual = 0.0;
	angDesejado = 0.0;
	erroAng = 0.0;
	saidaControleAngular = 0.0;

	sinalDeControle1 = 0.0;
	sinalDeControle2 = 0.0;

	mDist = 0.0;
	melhorPonto = Position(0,0,0.0);
	roboName = "";
	achou = false;
	logaDados = false;
	FPS = 0.0;
	frameNum = 0;
	trajetoria = "";

}


StrRetorno::~StrRetorno()
{
}


StrRetorno::StrRetorno(double pVelAtual, double pVelAtualDerivSuja, double pSetPoint, double pErroVel, double pAngAtual, double pAngDesejado, double pErroAng, double pMDist, Position pMelhorPonto, double pSaidaControleLinear, double pSaidaControleAngular, double pSinalControle1, double pSinalControle2, bool pSat, double pAngSource)
{
	satAng = pSat;

	velAtual = pVelAtual  ;
	velAtualDerivSuja = pVelAtualDerivSuja;
	setPoint = pSetPoint  ;
	erroVel = pErroVel  ;
	saidaControleLinear = pSaidaControleLinear;

	angAtual = pAngAtual  ;
	angDesejado = pAngDesejado  ;
	erroAng = pErroAng  ;
	saidaControleAngular = pSaidaControleAngular;

	sinalDeControle1 = pSinalControle1;
	sinalDeControle2 = pSinalControle2;

	mDist = pMDist;
	melhorPonto = pMelhorPonto ;
	angSource = pAngSource;
}

StrRetorno::StrRetorno(double pRefPos, double pErroPos, Position pPosAtual, double pAngDesejado, double pErroAng, double pSaidaControleLinear, double pSaidaControleAngular, double pSinalControle1, double pSinalControle2, bool pSat, double pAngSource, double pIntegralEsc, double pt)
{
	satAng = pSat;

	refPos = pRefPos;
	erroPos = pErroPos;
	saidaControleLinear = pSaidaControleLinear;

	this->posicaoAtual = pPosAtual;
	angDesejado = pAngDesejado;
	erroAng = pErroAng;
	saidaControleAngular = pSaidaControleAngular;

	sinalDeControle1 = pSinalControle1;
	sinalDeControle2 = pSinalControle2;

	angSource = pAngSource;
	integralEsc = pIntegralEsc;
	t = pt;
}
