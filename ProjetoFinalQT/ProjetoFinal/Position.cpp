#include "Position.h"


Position::Position()
{
	x = 0;
	y = 0;
	ang = 0.0;
}

Position::Position(uint16_t pX, uint16_t pY, double pAng)
{
	x = pX;
	y = pY;
	ang = pAng;
}

Position::Position(uint16_t pX, uint16_t pY)
{
	x = pX;
	y = pY;
}

Position::~Position()
{
}

void Position::setPos(uint16_t pX, uint16_t pY, double pAngle)
{
	x = pX;
	y = pY;
	ang = pAngle;
	ticks = clock();
	
	//timev = time(&timev);

}


bool Position::operator==(const Position& other)
{
	if (this->x != other.x) return false;
	if (this->y != other.y) return false;
	if (this->ang != other.ang) return false;

	return true;
}

double Position::distance(const Position& other)
{
	return sqrt(pow((x - other.x), 2) + pow((y - other.y), 2));
}

double Position::angDiff(const Position& other)
{
	return ang - other.ang;
}

