#pragma once
#include "mathHelper.h"

class Curva
{
public:
	int nvert;
	float* vertx;
	float* verty;
	float minx;
	float maxx;
	float miny;
	float maxy;


	Curva();
	//~Curva();
	Curva(int, float*, float*, float, float, float, float);
	//Curva(int, float*, float*, float, float, float, float, Parametric, Parametric);

	bool contem(float x, float y);


};
