#include <time.h>
#include <stdint.h>
#include <cmath>

#pragma once
class Position
{
public:
	Position();
	~Position();

	Position(uint16_t, uint16_t, double);
	Position(uint16_t, uint16_t);


	void setPos(uint16_t, uint16_t, double);
	
	uint16_t x;
	uint16_t y;

	double ang;
	clock_t ticks;
	
	time_t  timev;

	bool operator==(const Position& other);
	
	double distance(const Position& other);

	double angDiff(const Position& other);
	
	
};

