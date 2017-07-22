#include <string>

#pragma once
using namespace std;
class paramControle
{
public:
	paramControle();
	~paramControle();
	paramControle(string, float, float, float, float, float, float);

	string nome;
	
	float pLin;
	float iLin;
	float dLin;

	float pAng;
	float iAng;
	float dAng;

	bool operator==(const paramControle& other);
};

