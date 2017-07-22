#include "paramControle.h"


paramControle::paramControle()
{
}

paramControle::paramControle(string p_Nome, float p_pLin, float p_iLin, float p_dLin, float p_pAng, float p_iAng, float p_dAng)
{
	nome = p_Nome;

	pLin = p_pLin;
	iLin = p_iLin;
	dLin = p_dLin;

	pAng = p_pAng;
	iAng = p_iAng;
	dAng = p_dAng;

}


paramControle::~paramControle()
{
}


bool paramControle::operator==(const paramControle& other)
{
	bool retorno = true;

	if (this->nome != other.nome) return false;

	if (this->pLin != other.pLin) return false;
	if (this->iLin != other.iLin) return false;
	if (this->iLin != other.dLin) return false;

	if (this->pAng != other.pAng) return false;
	if (this->iAng != other.iAng) return false;
	if (this->iAng != other.dAng) return false;

	return retorno;
}