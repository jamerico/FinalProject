#pragma once
#include <stdint.h>
#include <string>
#include "Position.h"
#include "mathHelper.h"
#include <vector>
#include <tuple>

using namespace std;


class Trajetoria
{
public:
	Trajetoria();
	Trajetoria(string nome, int minx, int maxx, int miny, int maxy, vector<Position> pontos);
	~Trajetoria();

	std::string nome;

	uint16_t minx;
	uint16_t maxx;
	uint16_t miny;
	uint16_t maxy;

	Position* listaPontos;

	float arrx[3001];
	float arry[3001];

	float* _vertx;
	float* _verty;
	int _nvert = 0;

	std::vector<Position> pontos;

	bool contem(uint16_t x, uint16_t y);

	void carregaVertices();
	vector<float> _vx;
	vector<float> _vy;

	tuple<Position, double> getMelhorPonto(Position p);
	tuple<Position, double> getMelhorPonto(uint16_t pX, uint16_t pY);

};

