#include "Curva.h"


Curva::Curva()
{
}

//
//Curva::~Curva()
//{
//}


Curva::Curva(int _nVert, float* _vertx, float* _verty, float _minx, float _maxx, float _miny, float _maxy)
{
	nvert = _nVert;
	vertx = _vertx;
	verty = _verty;
	minx = _minx;
	maxx = _maxx;
	miny = _miny;
	maxy = _maxy;
}

//Curva::Curva(int _nVert, float* _vertx, float* _verty, float _minx, float _maxx, float _miny, float _maxy, Parametric _poly, Parametric _deriv)
//{
//	nvert = _nVert;
//	vertx = _vertx;
//	verty = _verty;
//	minx = _minx;
//	maxx = _maxx;
//	miny = _miny;
//	maxy = _maxy;
//	poly = _poly;
//	deriv = _deriv;
//}

bool Curva::contem(float _x, float _y)
{
	return mathHelper::pnppolyExtended(nvert, vertx, verty, _x, _y, minx, maxx, miny, maxy);
}