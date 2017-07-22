#include "Cor.h"


Cor::Cor()
{
}

Cor::~Cor()
{
}

Cor::Cor(string pNome, float pMinH, float pMaxH, float pMinS, float pMaxS, float pMinV, float pMaxV, float pMinArea, float pMaxArea)
{
	nome = pNome;
	minH = pMinH;
	maxH = pMaxH;
	minS = pMinS;
	maxS = pMaxS;
	minV = pMinV;
	maxV = pMaxV;
	minArea = pMinArea;
	maxArea = pMaxArea;
}

bool Cor::operator==(const Cor& other)
{
	bool retorno = true;

	if (this->nome != other.nome) return false;
	
	if (this->minH != other.minH) return false;

	if (this->maxH != other.maxH) return false;

	if (this->minS != other.minS) return false;

	if (this->maxS != other.maxS) return false;

	if (this->minV != other.minV) return false;

	if (this->maxV != other.maxV) return false;

	if (this->minArea != other.minArea) return false;

	if (this->maxArea != other.maxArea) return false;

	return retorno;
}

int Cor::getIdxCorPorNome(string name, vector<Cor> vCores)
{
	for (int idxCores = 0; idxCores < vCores.size(); idxCores++)
	{
		if (vCores[idxCores].nome == name)
		{
			return idxCores;
		}
	}

	return -1;
}

//inline bool operator==(const X& lhs, const X& rhs){ /* do actual comparison */ }
//inline bool operator!=(const X& lhs, const X& rhs){ return !(lhs == rhs); }