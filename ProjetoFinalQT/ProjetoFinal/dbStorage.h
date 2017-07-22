#pragma once
//#include <sqlite3.h>
//#import "sqlite"
#include "sqlite3.h"
#include "Cor.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "paramControle.h"
#include "Objeto.h"
#include "Trajetoria.h"
#include <map>

class dbStorage
{


public:
	dbStorage();
	~dbStorage();
	static dbStorage *instance();

	static void salvaCor(Cor);
	static Cor getCor(string);
	static void deleteCor(string);
	static vector<Cor> getAllCor();
	static map<string, Cor> getMapAllCor();
	static void salvaCores(vector<Cor>);

	static void salvaParamControle(paramControle);
	static paramControle getParamControle(string);
	static void deleteParamControle(string);
	static vector<paramControle> getAllParamsControle();
	static void salvaParamsControle(vector<paramControle>);

	static void salvaObjeto(Objeto); 
	static Objeto getObjeto(string); 
	static void deleteObjeto(string); 
	static vector<Objeto> getAllObjetos(); 
	static void salvaObjetos(vector<Objeto>);

	static vector<Position> getPontos(string);
	static Position * getListaPontos(string trajetoria);

	
	static void salvaTrajetoria(Trajetoria);
	static void deleteTrajetoria(string);
	static Trajetoria getTrajetoria(string);
	static vector<Trajetoria> getAllTrajetoria();
	static vector<string> getAllTrajetoriaNames();
	static void salvaTrajetorias(vector<Trajetoria>);


private:
	static sqlite3 *db;
	static dbStorage* inst;

	static void insertCor(Cor);
	static void updateCor(Cor);

	static void insertParamControle(paramControle);
	static void updateParamControle(paramControle);

	static void insertObjeto(Objeto); 
	static void updateObjeto(Objeto); 
	
	static void insertTrajetoria(Trajetoria);
	static void updateTrajetoria(Trajetoria);
	
	static void salvaPontos(Trajetoria);
	static void insertPonto(Position, string);

};

