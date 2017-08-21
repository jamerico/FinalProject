#include <time.h>
#include <stdint.h>
#include <cmath>
#include <qmath.h>

#pragma once
class Position
{
public:
	Position();
	~Position();



	double deltaX = 0;
	double deltaY = 0;
	double angMax = M_PI;
	double angMin = -M_PI;
	int offset = 0;

	Position(uint16_t, uint16_t, double);
	Position(uint16_t, uint16_t);
	Position(uint16_t, uint16_t, double,double,double);


	void setPos(uint16_t, uint16_t, double);
	void setPos(uint16_t pX, uint16_t pY, double pAng, double pDeltaX, double pDeltaY);

	
	uint16_t x;
	uint16_t y;

	double ang;
	clock_t ticks;
	
	time_t  timev;

	bool operator==(const Position& other);
	
	double distance(const Position& other);

	double angDiff(const Position& other);
	
	
};

