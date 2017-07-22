#pragma once
#include "Position.h"
#include <cmath>
#include "qmath.h"
#include <deque>

class mathHelper
{
public:
	mathHelper();
	~mathHelper();

	static mathHelper *instance();


	static int pnpoly(int nvert, float *vertx, float *verty, float testx, float testy);
	static bool pnppolyExtended(int nvert, float *vertx, float *verty, float testx, float testy, float minx, float maxx, float miny, float maxy);
	static float distance(float x1, float y1, float x2, float y2);
	static float distance(Position p1, Position p2);

	static float Rad2Deg(float);							// Converte o angulo de radiano para grau
	static float Deg2Rad(float);							// Converte o angulo de grau para radiano
	static int sgn(float);									// Verifica se o numero eh positivo, negativo ou zero

	static double sat(double, double);
	static double upperSat(double, double);
	static double dqAvg(std::deque<double>);
	static double abs(double);
	
private:
	static mathHelper* inst;
};

