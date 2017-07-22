#include "Estrategia.h"

#pragma region Construtor/Destrutor
Estrategia::Estrategia(Trajetoria traj, int indiceObj, vector<Objeto> vetorObj){

	objAnalisado = vetorObj[indiceObj];
	trajDesejada = traj;
}

Estrategia::~Estrategia(){

}
#pragma endregion

