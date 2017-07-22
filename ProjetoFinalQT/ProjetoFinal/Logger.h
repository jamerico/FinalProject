#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <thread>
#include <future>
#include <stdio.h>
//#include <debugapi.h>
#include <windows.h>
#include <ctime>
#include <iostream>
#include <sstream>
#include <StrRetorno.h>

using namespace std;

enum Colunas{
	Timestamp, Ticks, FrameNum, FPS, Robo, Xd, Yd, Xa, Ya,
	DistMelhorPonto, velAtual, velDesejada, erroVel, angAtual, angDesejado, erroAng, achou, trajetoria, LogaDados,
	SaidaControleLinear, SaidaControleAngular, SinalControle1, SinalControle2, velAtualDerivSuja
};

class Logger
{

public:
	Logger();
	~Logger();
	static void Log(string msg);
	static void Output(const char*, double);
	static void Output(const char* msg);
	static Logger *instance();
	static string getStatisticsFileName();
	static void statWrite(string, bool);
	static void initializeStatWriter();
	static void asyncStatWriter(string pMsg, bool pTimeStamp);
	static void asyncStatWriter(StrRetorno);
	static void statWriteStrRetorno(StrRetorno pDados);
	static vector<Colunas> statColumns;


private:
	static string statisticsPath;
	static string delimiter;
	static bool headers;
	static bool trocaPontoPorVirgula;
	static string DblToStr(double num);

	static string path;
	static Logger* inst;
	static time_t  timev;
	static void write(string);
	static string getColNames(Colunas);
};

