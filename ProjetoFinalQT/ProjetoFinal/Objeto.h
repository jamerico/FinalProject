#pragma once
#include "Position.h"
#include "Cor.h"
#include "paramControle.h"
#include <string>
#include "qmath.h"
#include "Trajetoria.h"
#include "SerialClass.h"
#include <stdio.h>
#include "Logger.h"
#include "StrRetorno.h"
#include <deque>

using namespace std;


enum TipoObjeto
{
	Robô,
	Obstaculo,
	Indefinido
};


class Objeto
{
public:
	Objeto();
	~Objeto();
	Objeto(string, Cor, Cor, Cor, paramControle, string, TipoObjeto, double, Trajetoria);

	Position posAtual;
	Position posAnterior;
	Cor primColor;
	Cor secColor;
	Cor terColor;

	TipoObjeto tipo;

	deque<double> Speeds;

	paramControle ctrl;

	string nome;
	string cfgXbee;

	double setPointVel;
	double setPointVelOrig;

	Trajetoria traj;
	Trajetoria trajAux;
	bool usaTrajAux = false;

	void setPosAtual(double, double, double);
	void setPosAtual(Position, Position);

	double getVel();
	double getVelDerivSuja();
	double getAngVel();
	
	bool operator==(const Objeto& other);
	bool dentroTrajetoria();

#pragma region Controle
	// Atributos
	float delta = 0.0003; // delta da formula da derivada suja
	//double taxaH = 1.0 / 30; // eh o inverso da taxa de amostragem, no caso foi considerada 33fps
	double taxaH = 1.0 / 20; // eh o inverso da taxa de amostragem, no caso foi considerada 33fps


	double angAuxDerivadaSuja = 0.0;			// variavel auxiliar para calcular a derivada suja (caso angular)
	double velAuxDerivadaSuja = 0.0;			// variavel auxiliar para calcular a derivada suja (caso linear)
	double angAuxAntigaDerivadaSuja = 0.0;		// variavel auxiliar anterior para calcular a derivada suja (caso angular)
	double velAuxAntigaDerivadaSuja = 0.0;		// variavel auxiliar anterior para calcular a derivada suja (caso linear)

	double saidaLinearI = 0.0;					// saida parcial parte integral do controle linear
	double saidaAngularI = 0.0;					// saida parcial parte integral do controle angular

	double saidaControleAngular;				// Saida total do controle angular
	double saidaControleLinear;					// Saida total do controle linear

	double velDesejada, angDesejado;	// Velocidades angular e linear desejadas
	double velAtual; 
	double sinalTensao1, sinalTensao2;			// Sinais de tensao q serao enviados ao carrinho
	bool saturouAng;
	double outputFilter = 0;;
	double outputFilter2 = 0;;
	double integralESC = 0;

	void LowPassFilter(double input, double omegaH);
	void LowPassFilter2(double input, double omegaH);

	//Serial s;

	// Metodos
	StrRetorno Controle();								// Concentra o calculo do controle e envia as mensagens
	StrRetorno ControleJacoud(paramControle);
	StrRetorno ControleJacoud();
	StrRetorno Controle(paramControle, bool sentido, double);	// SobreCarga do metodo de Controle
	void PID(double, float, float, float, bool);		// Calcula a saida do sinal de controle (bloco PID)
	void ControleCruzeiro(paramControle, double);		// Calcula o sinal de controle da parte Linear
	void ControleAngular(paramControle, double);		// Calcula o sinal de controle da parte Angular
	void AtualizaVelocidade();
	void MontaSinaisTensao();							// Constroi o sinal de tensao de cada roda q sera enviada ao carro

	
	bool achou = false;

	// Metodos Auxiliares
	double DerivadaSuja(double, double, double);
	float CalculaDerivadaSuja(bool, double);			// Calcula a derivada suja de uma variavel
	float CalculaAngDesejado(bool, Position, double, double);	// Calcula o valor de refencia do angulo
	float AjustaAngulo(float, bool);					// Faz uns ajustes de quadrante para o angulo do robo

#pragma endregion

};

