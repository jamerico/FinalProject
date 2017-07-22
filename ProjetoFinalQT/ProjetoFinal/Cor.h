#include <string>
#include <vector>

using namespace std;

#pragma once
class Cor
{
public:
	Cor();
	Cor(string, float, float, float, float, float, float, float, float);
	~Cor();

	string nome;

	float minH;
	float maxH;

	float minS;
	float maxS;

	float minV;
	float maxV;

	float minArea;
	float maxArea;

	bool operator==(const Cor& other);

	static int getIdxCorPorNome(string, vector<Cor>);
};

