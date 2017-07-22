#pragma once

#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>
#include <vector>
#include "Position.h"
#include "Objeto.h"
#include "Trajetoria.h"

class Estrategia
{
public:
	Estrategia(Trajetoria, int, vector<Objeto>);
	~Estrategia();

	Objeto objAnalisado;
	Trajetoria trajDesejada;
};