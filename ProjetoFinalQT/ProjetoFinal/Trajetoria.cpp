#include "Trajetoria.h"

Trajetoria::Trajetoria()
{
	_vx = vector<float>(3001);
	_vy = vector<float>(3001);
}


Trajetoria::Trajetoria(string pNome, int pMinx, int pMaxx, int pMiny, int pMaxy, vector<Position> pPontos){
	nome = pNome;
	minx = pMinx;
	maxx = pMaxx;
	miny = pMiny;
	maxy = pMaxy;
	pontos = pPontos;

	this->carregaVertices();

}

Trajetoria::~Trajetoria()
{
}

bool Trajetoria::contem(uint16_t _x, uint16_t _y)
{
	//this->listaPontos
	//return mathHelper::pnppolyExtended(_nvert, _vertx, _verty, _x, _y, minx, maxx, miny, maxy);
	return mathHelper::pnppolyExtended(_nvert, arrx, arry, _x, _y, minx, maxx, miny, maxy);
	//return false;
}


void Trajetoria::carregaVertices()
{
	
	//_vx = std::vector<float>(pontos.size());
	//_vy = std::vector<float>(pontos.size());

	for (std::vector<int>::size_type i = 0; i != pontos.size(); i++) {
		arrx[i] = pontos[i].x;
		arry[i] = pontos[i].y;
	}

	/*for each (Position p in pontos)
	{
		
		_vx.insert(0,p.x);
		_vy.push_back(p.y);
	}*/
	
	this->_nvert = pontos.size();
	this->_vertx = &arrx[0];
	this->_verty = &arry[0];

}

tuple<Position, double> Trajetoria::getMelhorPonto(Position pPos){

	double minDist = DBL_MAX;
	double dist;
	Position minPos;
	for each (Position pos in pontos)
	{
		dist = pos.distance(pPos);
		
		if (dist < minDist) {
			minDist = dist;
			minPos = pos;
		}
		
	}

	return make_tuple(minPos, minDist);

}

tuple<Position, double> Trajetoria::getMelhorPonto(uint16_t pX, uint16_t pY){
	return getMelhorPonto(Position(pX, pY));
}