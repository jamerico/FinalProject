#include "mathHelper.h"


mathHelper *mathHelper::inst = 0;

mathHelper::mathHelper()
{
}


mathHelper::~mathHelper()
{
}

double mathHelper::abs(double pIn)
{
	if (pIn < 0)
	{
		return -pIn;
	}
	return pIn;
}


bool mathHelper::pnppolyExtended(int nvert, float *vertx, float *verty, float testx, float testy, float minx, float maxx, float miny, float maxy)
{
	if (testx > maxx || testx < minx || testy > maxy || testy < miny)
	{
		return false;
	}
	else
	{
		return pnpoly(nvert, vertx, verty, testx, testy);
	}

}

int mathHelper::pnpoly(int nvert, float *vertx, float *verty, float testx, float testy)
{
	int i, j, c = 0;
	for (i = 0, j = nvert - 1; i < nvert; j = i++) {
		if (((verty[i]>testy) != (verty[j]>testy)) &&(testx < (vertx[j] - vertx[i]) * (testy - verty[i]) / (verty[j] - verty[i]) + vertx[i]))
			c = !c;
	}
	return c;
}

mathHelper *mathHelper::instance()
{
	if (!inst){
		inst = new mathHelper();
	}

	return inst;
}

float mathHelper::distance(float x1, float y1, float x2, float y2)
{
	return sqrt(powf(x2 - x1,2) + powf(y2 - y1,2));
}

float mathHelper::distance(Position p1, Position p2)
{
	return distance(p1.x, p1.y, p2.x, p2.y);
}

float mathHelper::Rad2Deg(float angRad){
	return (180 * angRad) / M_PI;
}

float mathHelper::Deg2Rad(float angDeg){
	return (M_PI * angDeg) / 180;
}

int mathHelper::sgn(float number){
	return (number > 0) ? 1 : ((number < 0) ? -1 : 0);
}

double mathHelper::upperSat(double pVal, double pSat)
{
	if (pVal > pSat)
	{
		pVal = pSat;
	}
	return pVal;
}

double mathHelper::sat(double pVal, double pSat){

	if (pVal > pSat)
	{
		pVal = pSat;
	}
	else if (pVal < -pSat)
	{
		pVal = -pSat;
	}

	return pVal;
}

double mathHelper::dqAvg(std::deque<double> pDq){

	double sum = 0.0;
	for (int i = 0; i < pDq.size(); i++)
	{
		sum += pDq[i];
	}
	
	return sum/pDq.size();
}