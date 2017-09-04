#pragma once
#include <Position.h>
#include <string>


class StrRetorno
{
public:
	StrRetorno();
	StrRetorno(double velAtual, double velAtualDerivSuja, double setPoint, double erroVel, double angAtual, double angDesejado, double erroAng, double mDist, Position melhorPonto, double saidaControleLinear, double saidaControleAngular, double sinalControle1, double sinalControle2, bool sat, double pAngSource = 0);
	StrRetorno(double refPos, double erroPos, Position posAtual, double angDesejado, double erroAng, double saidaControleLinear, double saidaControleAngular, double sinalControle1, double sinalControle2, bool sat, double pAngSource = 0);

	~StrRetorno();

	double velAtual;
	double velAtualDerivSuja;
	double setPoint;
	double erroVel;

	double erroPos;
	double refPos;
	double saidaControleLinear;


	double angSource;
	double angAtual;
	double angDesejado;
	double erroAng;
	double saidaControleAngular;
	bool satAng;


	double sinalDeControle1;
	double sinalDeControle2;

	double mDist; //Distância entre ponto do carrinho e melhor ponto calculado

	Position melhorPonto;
	Position posicaoAtual;

	clock_t ticks;

	std::string roboName; //nome robo

	bool achou; //robo encontrado pela câmera
	bool logaDados; //

	std::string trajetoria; //nome trajetória

	long frameNum;
	double FPS;
};

