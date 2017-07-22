#include "dbStorage.h"
#include <ios>
#include <iostream>
#include "Logger.h"


using namespace std;

sqlite3* dbStorage::db;
dbStorage* dbStorage::inst;


#pragma region Cores

Cor dbStorage::getCor(string nome)
{
	Cor c;

	string sql = "SELECT * FROM tb_cor WHERE nome = '" + nome + "'";

	Logger::Log("Buscando cor: " + nome);
	char **results = NULL;
	char* error;
	int rows, columns;
	int rc = sqlite3_get_table(db, sql.c_str(), &results, &rows, &columns, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		if (rows > 0)
		{
			//(nome STRING PRIMARY KEY, minH REAL, maxH REAL, minS REAL, maxS REAL, minV REAL, maxV REAL, minArea REAL, maxArea REAL);";
			c.nome = results[9];
			c.minH = atof(results[10]);
			c.maxH = atof(results[11]);
			c.minS = atof(results[12]);
			c.maxS = atof(results[13]);
			c.minV = atof(results[14]);
			c.maxV = atof(results[15]);
			c.minArea = atof(results[16]);
			c.maxArea = atof(results[17]);
		}

		sqlite3_free_table(results);

	}

	return c;

}

void dbStorage::salvaCor(Cor color)
{
	if (getCor(color.nome).nome == "") //cor não existe na base
	{
		insertCor(color);
	}
	else
	{
		updateCor(color);
	}
}

void dbStorage::updateCor(Cor color)
{
	//(nome STRING PRIMARY KEY, minH REAL, maxH REAL, minS REAL, maxS REAL, minV REAL, maxV REAL, minArea REAL, maxArea REAL);";
	char* error;
	string update = "UPDATE tb_cor SET minH = " + to_string(color.minH)
		+ ", maxH = " + to_string(color.maxH)
		+ ", minS = " + to_string(color.minS)
		+ ", maxS = " + to_string(color.maxS)
		+ ", minV = " + to_string(color.minV)
		+ ", maxV = " + to_string(color.maxV)
		+ ", minArea = " + to_string(color.minArea)
		+ ", maxArea = " + to_string(color.maxArea)
		+ " WHERE nome = '" + color.nome + "'";


	int rc = sqlite3_exec(db, update.c_str(), NULL, NULL, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		Logger::Log("Cor " + color.nome + " atualizada com sucesso");
	}
}

void dbStorage::deleteCor(string name)
{
	string del = "DELETE FROM tb_cor WHERE nome = '" + name + "'";
	char* error;

	int rc = sqlite3_exec(db, del.c_str(), NULL, NULL, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		Logger::Log("Cor " + name + " deletada com sucesso");
	}


}

void dbStorage::insertCor(Cor color)
{
	//(nome STRING PRIMARY KEY, minH REAL, maxH REAL, minS REAL, maxS REAL, minV REAL, maxV REAL, minArea REAL, maxArea REAL);";

	string insert = "INSERT INTO tb_cor VALUES ('"
		+ color.nome + "', "
		+ to_string(color.minH) + ", "
		+ to_string(color.maxH) + ", "
		+ to_string(color.minS) + ", "
		+ to_string(color.maxS) + ", "
		+ to_string(color.minV) + ", "
		+ to_string(color.maxV) + ", "
		+ to_string(color.minArea) + ", "
		+ to_string(color.maxArea) + " )";

	char* error;

	int rc = sqlite3_exec(db, insert.c_str(), NULL, NULL, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		Logger::Log("Cor " + color.nome + " inserida com sucesso");
	}



}

void dbStorage::salvaCores(vector<Cor> vCores)
{
	vector<Cor> vCoresBase = getAllCor();

	for each (Cor c in vCoresBase)
	{
		//Para cada elemento do vetor recebido
		//Se houver algum elemento salvo na base que não esteja no vetor recebido
		//Deleta essa cor
		if (std::find(vCores.begin(), vCores.end(), c) == vCores.end()) //Não contém
		{
			deleteCor(c.nome);
		}
	}

	for each (Cor c in vCores)
	{
		salvaCor(c);
	}


}

vector<Cor> dbStorage::getAllCor(){

	std::vector<Cor> vetorDeCores;

	string sql = "SELECT * FROM tb_cor ";

	Logger::Log("Buscando cor todas as cores");
	char **results = NULL;
	char* error;
	int rows, columns;
	int rc = sqlite3_get_table(db, sql.c_str(), &results, &rows, &columns, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		for (int i = 1; i <= rows; i++)
		{
			//(nome STRING PRIMARY KEY, minH REAL, maxH REAL, minS REAL, maxS REAL, minV REAL, maxV REAL, minArea REAL, maxArea REAL);";
			int index = i * columns;
			vetorDeCores.push_back(Cor(results[index + 0],
				atof(results[index + 1]), atof(results[index + 2]), atof(results[index + 3]),
				atof(results[index + 4]), atof(results[index + 5]), atof(results[index + 6]),
				atof(results[index + 7]), atof(results[index + 8])));
		}

		sqlite3_free_table(results);

	}

	return vetorDeCores;
}


map<string, Cor> getMapAllCor() {
	vector<Cor> v = dbStorage::getAllCor();
	map<string, Cor> map;
	for (size_t i = 0; i < v.size(); i++)
	{
		map[v[i].nome] = v[i];
	}
	return map;
}


#pragma endregion

#pragma region Controles
//(nome STRING PRIMARY KEY, pLin REAL, iLin REAL, dLin REAL, pAng REAL, iAng REAL, dAng REAL)

paramControle dbStorage::getParamControle(string nome)
{
	paramControle pCtrl;

	string sql = "SELECT * FROM tb_paramcontrole WHERE nome = '" + nome + "'";

	Logger::Log("Buscando controle: " + nome);
	char **results = NULL;
	char* error;
	int rows, columns;
	int rc = sqlite3_get_table(db, sql.c_str(), &results, &rows, &columns, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		if (rows > 0)
		{
			//(nome STRING PRIMARY KEY, pLin REAL, iLin REAL, dLin REAL, pAng REAL, iAng REAL, dAng REAL)

			pCtrl.nome = results[7];
			pCtrl.pLin = atof(results[8]);
			pCtrl.iLin = atof(results[9]);
			pCtrl.dLin = atof(results[10]);
			
			pCtrl.pAng = atof(results[11]);
			pCtrl.iAng = atof(results[12]);
			pCtrl.dAng = atof(results[13]);


		}

		sqlite3_free_table(results);

	}

	return pCtrl;

}

void dbStorage::insertParamControle(paramControle pCtrl)
{
	//(nome STRING PRIMARY KEY, pLin REAL, iLin REAL, dLin REAL, pAng REAL, iAng REAL, dAng REAL)

	string insert = "INSERT INTO tb_paramcontrole VALUES ('"
		+ pCtrl.nome + "', "
		+ to_string(pCtrl.pLin) + ", "
		+ to_string(pCtrl.iLin) + ", "
		+ to_string(pCtrl.dLin) + ", "
		+ to_string(pCtrl.pAng) + ", "
		+ to_string(pCtrl.iAng) + ", "
		+ to_string(pCtrl.dAng) + " ); ";


	char* error;

	int rc = sqlite3_exec(db, insert.c_str(), NULL, NULL, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		Logger::Log("Controle " + pCtrl.nome + " inserido com sucesso");
	}

}

void dbStorage::deleteParamControle(string name)
{
	string del = "DELETE FROM tb_paramcontrole WHERE nome = '" + name + "'";
	char* error;

	int rc = sqlite3_exec(db, del.c_str(), NULL, NULL, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		Logger::Log("Parametros de Controle " + name + " deletado com sucesso");
	}
}

void dbStorage::updateParamControle(paramControle pCtrl)
{
	//(nome STRING PRIMARY KEY, pLin REAL, iLin REAL, dLin REAL, pAng REAL, iAng REAL, dAng REAL)

	char* error;
	string update = "UPDATE tb_paramcontrole SET pLin = " + to_string(pCtrl.pLin)
		+ ", iLin = " + to_string(pCtrl.iLin)
		+ ", dLin = " + to_string(pCtrl.dLin)
		+ ", pAng = " + to_string(pCtrl.pAng)
		+ ", iAng = " + to_string(pCtrl.iAng)
		+ ", dAng = " + to_string(pCtrl.dAng)
		+ " WHERE nome = '" + pCtrl.nome + "'";


	int rc = sqlite3_exec(db, update.c_str(), NULL, NULL, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		Logger::Log("Parâmetros de Controle " + pCtrl.nome + " atualizado com sucesso");
	}
}

void dbStorage::salvaParamControle(paramControle pCtrl)
{
	if (getParamControle(pCtrl.nome).nome == "") //cor não existe na base
	{
		insertParamControle(pCtrl);
	}
	else
	{
		updateParamControle(pCtrl);
	}
}

vector<paramControle> dbStorage::getAllParamsControle(){

	std::vector<paramControle> vetorDeParamControle;

	string sql = "SELECT * FROM tb_paramcontrole ";

	Logger::Log("Buscando todos os parametros de controle");
	char **results = NULL;
	char* error;
	int rows, columns;
	int rc = sqlite3_get_table(db, sql.c_str(), &results, &rows, &columns, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		for (int i = 1; i <= rows; i++)
		{
			//(nome STRING PRIMARY KEY, pLin REAL, iLin REAL, dLin REAL, pAng REAL, iAng REAL, dAng REAL)
			
			int index = i * columns;
			vetorDeParamControle.push_back(paramControle(results[index + 0], atof(results[index + 1]), atof(results[index + 2]), atof(results[index + 3]), atof(results[index + 4]), atof(results[index + 5]), atof(results[index + 6])));
			
		}

		sqlite3_free_table(results);
	}

	return vetorDeParamControle;
}

void dbStorage::salvaParamsControle(vector<paramControle> vControle)
{
	vector<paramControle> vCtrlsBase = getAllParamsControle();

	for each (paramControle c in vCtrlsBase)
	{
		//Para cada elemento do vetor recebido
		//Se houver algum elemento salvo na base que não esteja no vetor recebido
		//Deleta essa cor
		if (std::find(vControle.begin(), vControle.end(), c) == vControle.end()) //Não contém
		{
			deleteParamControle(c.nome);
		}
	}

	for each (paramControle c in vControle)
	{
		salvaParamControle(c);
	}


}
#pragma endregion

#pragma region Objetos
Objeto dbStorage::getObjeto(string nome)
{
	Objeto obj;

	string sql = "SELECT * FROM tb_objeto WHERE nome = '" + nome + "'";

	Logger::Log("Buscando objeto: " + nome);
	char **results = NULL;
	char* error;
	int rows, columns;
	int rc = sqlite3_get_table(db, sql.c_str(), &results, &rows, &columns, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		if (rows > 0)
		{
			//(nome STRING PRIMARY KEY, pColor STRING, sColor STRING, tColor STRING, controle STRING, cfgXbee STRING, tpObjeto INTEGER, FOREIGN KEY(pColor) REFERENCES tb_cor(nome), FOREIGN KEY(sColor) REFERENCES tb_cor(nome), FOREIGN KEY(tColor) REFERENCES tb_cor(nome), FOREIGN KEY(controle) REFERENCES tb_controle(nome)); ";
			obj.nome = results[7];
			obj.primColor = getCor(results[8]);
			obj.secColor = getCor(results[9]);
			obj.terColor = getCor(results[10]);
			obj.ctrl = getParamControle(results[11]);
			obj.cfgXbee = results[12];
			obj.tipo = (TipoObjeto)atoi(results[13]);
			obj.traj = getTrajetoria(results[14]);
				
		}

		sqlite3_free_table(results);

	}

	return obj;

}

void dbStorage::insertObjeto(Objeto obj)
{
	//(nome STRING PRIMARY KEY, pColor STRING, sColor STRING, tColor STRING, controle STRING, cfgXbee STRING, tpObjeto INTEGER, FOREIGN KEY(pColor) REFERENCES tb_cor(nome), FOREIGN KEY(sColor) REFERENCES tb_cor(nome), FOREIGN KEY(tColor) REFERENCES tb_cor(nome), FOREIGN KEY(controle) REFERENCES tb_controle(nome)); ";

	string insert = "INSERT INTO tb_objeto VALUES ('"
		+ obj.nome + "', '"
		+ obj.primColor.nome + "', '"
		+ obj.secColor.nome + "', '"
		+ obj.terColor.nome + "', '"
		+ obj.ctrl.nome + "', '"
		+ obj.cfgXbee + "', "
		+ to_string(obj.tipo) + ", "
		+ to_string(obj.setPointVel) + ", '"
		+ obj.traj.nome + "');";

	

	char* error;

	int rc = sqlite3_exec(db, insert.c_str(), NULL, NULL, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		Logger::Log("Objeto " + obj.nome + " inserido com sucesso");
	}

}

void dbStorage::deleteObjeto(string name)
{
	string del = "DELETE FROM tb_objeto WHERE nome = '" + name + "'";
	char* error;

	int rc = sqlite3_exec(db, del.c_str(), NULL, NULL, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		Logger::Log("Objeto " + name + " deletado com sucesso");
	}
}

void dbStorage::updateObjeto(Objeto obj)
{
	//(nome STRING PRIMARY KEY, pColor STRING, sColor STRING, tColor STRING, controle STRING, cfgXbee STRING, tpObjeto INTEGER, FOREIGN KEY(pColor) REFERENCES tb_cor(nome), FOREIGN KEY(sColor) REFERENCES tb_cor(nome), FOREIGN KEY(tColor) REFERENCES tb_cor(nome), FOREIGN KEY(controle) REFERENCES tb_controle(nome)); ";


	char* error;
	string update = "UPDATE tb_objeto SET pColor = '" + obj.primColor.nome
		+ "', sColor = '" + obj.secColor.nome
		+ "', tColor = '" + obj.terColor.nome
		+ "', controle = '" + obj.ctrl.nome
		+ "', cfgXbee = '" + obj.cfgXbee
		+ "', tpObjeto = " + to_string(obj.tipo)
		+ ", vel = " + to_string(obj.setPointVel)
		+ ", trajetoria = '" + obj.traj.nome 
		+ "' WHERE nome = '" + obj.nome + "'";


	int rc = sqlite3_exec(db, update.c_str(), NULL, NULL, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		Logger::Log("Objeto " + obj.nome + " atualizado com sucesso");
	}
}

void dbStorage::salvaObjeto(Objeto obj)
{
	if (getObjeto(obj.nome).nome == "") //cor não existe na base
	{
		insertObjeto(obj);
	}
	else
	{
		updateObjeto(obj);
	}
}

vector<Objeto> dbStorage::getAllObjetos(){

	std::vector<Objeto> vetorDeObjetos;

	string sql = "SELECT * FROM tb_objeto ";

	Logger::Log("Buscando todos os objetos");
	char **results = NULL;
	char* error;
	int rows, columns;
	int rc = sqlite3_get_table(db, sql.c_str(), &results, &rows, &columns, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		for (int i = 1; i <= rows; i++)
		{
			//(nome STRING PRIMARY KEY, pColor STRING, sColor STRING, tColor STRING, controle STRING, cfgXbee STRING, tpObjeto INTEGER, FOREIGN KEY(pColor) REFERENCES tb_cor(nome), FOREIGN KEY(sColor) REFERENCES tb_cor(nome), FOREIGN KEY(tColor) REFERENCES tb_cor(nome), FOREIGN KEY(controle) REFERENCES tb_controle(nome)); ";

			int index = i * columns;

			vetorDeObjetos.push_back(Objeto(results[index + 0], getCor(results[index + 1]), getCor(results[index + 2]), getCor(results[index + 3]),
				getParamControle(results[index + 4]), results[index + 5], (TipoObjeto)atoi(results[index + 6]), atof(results[index + 7]), getTrajetoria(results[index+8])));
		}

		sqlite3_free_table(results);
	}

	return vetorDeObjetos;
}

void dbStorage::salvaObjetos(vector<Objeto> vObjeto)
{
	vector<Objeto> vObjsBase = getAllObjetos();

	for each (Objeto o in vObjsBase)
	{
		//Para cada elemento do vetor recebido
		//Se houver algum elemento salvo na base que não esteja no vetor recebido
		//Deleta essa cor
		if (std::find(vObjeto.begin(), vObjeto.end(), o) == vObjeto.end()) //Não contém
		{
			deleteObjeto(o.nome);
		}
	}

	for each (Objeto o in vObjeto)
	{
		salvaObjeto(o);
	}


}
#pragma endregion

#pragma region Trajetoria


void dbStorage::salvaTrajetoria(Trajetoria t)
{
	if (getTrajetoria(t.nome).nome == "") //cor não existe na base
	{
		insertTrajetoria(t);
	}
	else
	{
		updateTrajetoria(t);
	}

	//Para garantir sempre deletamos todos os pontos e salvamos novamente.
	salvaPontos(t);
}

void dbStorage::insertTrajetoria(Trajetoria t)
{
	//" CREATE TABLE tb_trajetoria (nome STRING PRIMARY KEY, minx INTEGER, maxx INTEGER, miny INTEGER, maxy INTEGER); ";

	string insert = "INSERT INTO tb_trajetoria VALUES ('"
		+ t.nome + "', "
		+ to_string(t.minx) + ", "
		+ to_string(t.maxx) + ", "
		+ to_string(t.minx) + ", "
		+ to_string(t.maxx) + "); ";

	char* error;

	int rc = sqlite3_exec(db, insert.c_str(), NULL, NULL, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		Logger::Log("Trajetoria " + t.nome + " inserida com sucesso");
	}

}

void dbStorage::updateTrajetoria(Trajetoria t)
{
	//" CREATE TABLE tb_trajetoria (nome STRING PRIMARY KEY, minx INTEGER, maxx INTEGER, miny INTEGER, maxy INTEGER); ";
	char* error;
	string update = "UPDATE tb_trajetoria SET minx = " + to_string(t.minx)
		+ ", maxx = " + to_string(t.maxx)
		+ ", miny = " + to_string(t.miny)
		+ ", maxy = " + to_string(t.maxy)
		+ " WHERE nome = '" + t.nome + "'; ";


	int rc = sqlite3_exec(db, update.c_str(), NULL, NULL, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		Logger::Log("Trajetoria " + t.nome + " atualizada com sucesso");
	}


}

void dbStorage::deleteTrajetoria(string trajetoria)
{
	string del = "DELETE FROM tb_trajetoria WHERE nome = '" + trajetoria + "'";
	char* error;

	int rc = sqlite3_exec(db, del.c_str(), NULL, NULL, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		Logger::Log("Trajetoria " + trajetoria + " deletada com sucesso");
	}

}


vector<string> dbStorage::getAllTrajetoriaNames(){
	vector<string> rtnVector;

	string sql = "SELECT nome FROM tb_trajetoria WHERE flg_ativo = 'S' AND resolucao = '320x240' ORDER BY nome";

	Logger::Log("Buscando nomes trajetorias");

	char **results = NULL;
	char* error;
	int rows, columns;
	int rc = sqlite3_get_table(db, sql.c_str(), &results, &rows, &columns, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		for (int i = 1; i <= rows; i++)
		{
			int index = i * columns;
			rtnVector.push_back(results[index + 0]);

		}

		sqlite3_free_table(results);

	}

	return rtnVector;
}

vector<Trajetoria> dbStorage::getAllTrajetoria(){
	std::vector<Trajetoria> vetorAllTraj;

	string sql = "SELECT * FROM tb_trajetoria WHERE flg_ativo = 'S' AND resolucao = '320x240';";

	Logger::Log("Buscando todas as trajetorias");
	char **results = NULL;
	char* error;
	int rows, columns;
	int rc = sqlite3_get_table(db, sql.c_str(), &results, &rows, &columns, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		for (int i = 1; i <= rows; i++)
		{
			//CREATE TABLE tb_trajetoria(nome STRING PRIMARY KEY, minx INTEGER, maxx INTEGER, miny INTEGER, maxy INTEGER); ";
			int index = i * columns;

			vetorAllTraj.push_back(Trajetoria(results[index + 0],  //nome
				atoi(results[index + 1]),						//minx
				atoi(results[index + 2]),						//maxx
				atoi(results[index + 3]),						//miny
				atoi(results[index + 4]),						//maxy
				getPontos(results[index + 0])					//Pontos
				));

		}

		sqlite3_free_table(results);

	}


	return vetorAllTraj;
}



Trajetoria dbStorage::getTrajetoria(string trajetoria)
{
	Trajetoria t;

	string sql = "SELECT * FROM tb_trajetoria WHERE nome = '" + trajetoria + "'";

	Logger::Log("Buscando trajetoria: " + trajetoria);
	char **results = NULL;
	char* error;
	int rows, columns;
	int rc = sqlite3_get_table(db, sql.c_str(), &results, &rows, &columns, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		if (rows > 0)
		{
			//CREATE TABLE tb_trajetoria(nome STRING PRIMARY KEY, minx INTEGER, maxx INTEGER, miny INTEGER, maxy INTEGER); ";
			t.nome = results[7];
			t.minx = atoi(results[8]);
			t.maxx = atoi(results[9]);
			t.miny = atoi(results[10]);
			t.maxy = atoi(results[11]);
			t.pontos = getPontos(t.nome);
			//t.listaPontos = getListaPontos(t.nome);
		}

		sqlite3_free_table(results);

	}

	t.carregaVertices();

	return t;

}

Position * dbStorage::getListaPontos(string trajetoria)
{
	vector<Position> v = getPontos(trajetoria);
	//const int num = v.size();
	Position posArr[3000];
	std::copy(v.begin(), v.end(), posArr);

	return posArr;

}

vector<Position> dbStorage::getPontos(string trajetoria)
{
	vector<Position> pontos;

	string sql = "SELECT * FROM tb_ponto WHERE trajetoria = '" + trajetoria + "'";

	Logger::Log("Buscando pontos para trajetoria: " + trajetoria);
	char **results = NULL;
	char* error;
	int rows, columns;
	int rc = sqlite3_get_table(db, sql.c_str(), &results, &rows, &columns, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		if (rows > 0)
		{
			//CREATE TABLE tb_ponto (trajetoria STRING, x INTEGER, y INTEGER, ang DOUBLE, FOREIGN KEY(trajetoria) REFERENCES tb_trajetoria(nome) ); ";

			for (int i = 1; i <= rows; i++)
			{
				int index = i * columns;
				pontos.push_back(Position(atoi(results[index + 1]), atoi(results[index + 2]), stod(results[index + 3])));
			}

			sqlite3_free_table(results);

		}


	}

	return pontos;

}

void dbStorage::salvaPontos(Trajetoria t)
{
	string del = "DELETE FROM tb_ponto WHERE trajetoria = '" + t.nome + "'";

	char* error;

	int rc = sqlite3_exec(db, del.c_str(), NULL, NULL, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		Logger::Log("Pontos da trajetoria " + t.nome + " deletados com sucesso");
	}

	for each (Position ponto in t.pontos)
	{
		insertPonto(ponto, t.nome);
	}

}

void dbStorage::insertPonto(Position p, string trajetoria)
{
	//CREATE TABLE tb_ponto (trajetoria STRING, x INTEGER, y INTEGER, ang DOUBLE, FOREIGN KEY(trajetoria) REFERENCES tb_trajetoria(nome) ); ";

	string insert = "INSERT INTO tb_ponto VALUES ('"
		+ trajetoria + "', "
		+ to_string(p.x) + ", "
		+ to_string(p.y) + ", "
		+ to_string(p.ang) + "); ";

	char* error;

	int rc = sqlite3_exec(db, insert.c_str(), NULL, NULL, &error);
	if (rc)
	{
		string str(sqlite3_errmsg(db));
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);
	}
	else
	{
		Logger::Log("Ponto da trajetória " + trajetoria + " inserido com sucesso");
	}
}

#pragma endregion



dbStorage *dbStorage::instance()
{
	if (!inst){
		inst = new dbStorage();
	}

	return inst;
}

dbStorage::dbStorage()
{
	int rc;
	char *error;
	//
	Logger::Log("Inicio Construtor dbStorage ");
	rc = sqlite3_open("MyDb.db", &db);
	if (rc)
	{
		Logger::Log("Error opening SQLite3 database: ");
		Logger::Log(sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	else
	{
		Logger::Log("Opened MyDb.db.");
	}


#pragma region verificação tb_cor
	const char *sqlSelect = "SELECT * FROM tb_cor;";
	char **results = NULL;
	int rows, columns;

	rc = sqlite3_get_table(db, sqlSelect, &results, &rows, &columns, &error);

	if (rc)
	{

		std::string str(error);
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);

		Logger::Log("Criando tabela tb_cor ");

		const char *sqlCreateTable = "CREATE TABLE tb_cor (nome STRING PRIMARY KEY, minH REAL, maxH REAL, minS REAL, maxS REAL, minV REAL, maxV REAL, minArea REAL, maxArea REAL);";
		rc = sqlite3_exec(db, sqlCreateTable, NULL, NULL, &error);
		if (rc)
		{
			string str(sqlite3_errmsg(db));
			Logger::Log("Error executing SQLite3 statement: " + str);
			sqlite3_free(error);
		}
		else
		{
			Logger::Log("tb_cor criada com sucesso");
		}
	}
	else
	{
		Logger::Log("Tabela tb_cor já existe.");
	}
#pragma endregion

#pragma region verificação tb_controle
	sqlSelect = "SELECT * FROM tb_paramcontrole;";
	results = NULL;
	//int rows, columns;

	rc = sqlite3_get_table(db, sqlSelect, &results, &rows, &columns, &error);

	if (rc)
	{

		std::string str(error);
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);

		Logger::Log("Criando tabela tb_paramcontrole ");

		const char *sqlCreateTable = "CREATE TABLE tb_paramcontrole (nome STRING PRIMARY KEY, pLin REAL, iLin REAL, dLin REAL, pAng REAL, iAng REAL, dAng REAL);";
		rc = sqlite3_exec(db, sqlCreateTable, NULL, NULL, &error);
		if (rc)
		{
			string str(sqlite3_errmsg(db));
			Logger::Log("Error executing SQLite3 statement: " + str);
			sqlite3_free(error);
		}
		else
		{
			Logger::Log("tb_paramcontrole criada com sucesso");
		}
	}
	else
	{
		Logger::Log("Tabela tb_paramcontrole já existe.");
	}
#pragma endregion

#pragma region verificação tb_objeto
	sqlSelect = "SELECT * FROM tb_objeto;";
	results = NULL;
	//int rows, columns;

	rc = sqlite3_get_table(db, sqlSelect, &results, &rows, &columns, &error);

	if (rc)
	{

		std::string str(error);
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);

		Logger::Log("Criando tabela tb_objeto ");

		//const char *sqlCreateTable = "CREATE TABLE tb_objeto (nome STRING PRIMARY KEY, pColor STRING, sColor STRING, tColor STRING, controle STRING, cfgXbee STRING, tpObjeto INTEGER, FOREIGN KEY(pColor) REFERENCES tb_cor(nome), FOREIGN KEY(sColor) REFERENCES tb_cor(nome), FOREIGN KEY(tColor) REFERENCES tb_cor(nome), FOREIGN KEY(controle) REFERENCES tb_controle(nome) ) ;";

		const char *sqlCreateTable = "CREATE TABLE tb_objeto(nome STRING PRIMARY KEY, pColor STRING, sColor STRING, tColor STRING, controle STRING, cfgXbee STRING, tpObjeto INTEGER, vel DOUBLE, trajetoria STRING, FOREIGN KEY(trajetoria) REFERENCES tb_trajetoria(nome), FOREIGN KEY(pColor) REFERENCES tb_cor(nome), FOREIGN KEY(sColor) REFERENCES tb_cor(nome), FOREIGN KEY(tColor) REFERENCES tb_cor(nome), FOREIGN KEY(controle) REFERENCES tb_controle(nome))";
		rc = sqlite3_exec(db, sqlCreateTable, NULL, NULL, &error);
		if (rc)
		{
			string str(sqlite3_errmsg(db));
			Logger::Log("Error executing SQLite3 statement: " + str);
			sqlite3_free(error);
		}
		else
		{
			Logger::Log("tb_objeto criada com sucesso");
		}
	}
	else
	{
		Logger::Log("Tabela tb_objeto já existe.");
	}
#pragma endregion

#pragma region verificação tb_trajetoria
	sqlSelect = "SELECT * FROM tb_trajetoria;";
	results = NULL;
	//int rows, columns;

	rc = sqlite3_get_table(db, sqlSelect, &results, &rows, &columns, &error);

	if (rc)
	{
		std::string str(error);
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);

		Logger::Log("Criando tabela tb_trajetoria ");

		const char *sqlCreateTable = " CREATE TABLE tb_trajetoria (t); ";
			
		rc = sqlite3_exec(db, sqlCreateTable, NULL, NULL, &error);
		if (rc)
		{
			string str(sqlite3_errmsg(db));
			Logger::Log("Error executing SQLite3 statement: " + str);
			sqlite3_free(error);
		}
		else
		{
			Logger::Log("tb_trajetoria criada com sucesso");
		}
	}
	else
	{
		Logger::Log("Tabela tb_trajetoria já existe.");
	}

#pragma endregion

#pragma region verificação tb_ponto
	sqlSelect = "SELECT * FROM tb_ponto;";
	results = NULL;
	//int rows, columns;

	rc = sqlite3_get_table(db, sqlSelect, &results, &rows, &columns, &error);

	if (rc)
	{
		std::string str(error);
		Logger::Log("Error executing SQLite3 statement: " + str);
		sqlite3_free(error);

		Logger::Log("Criando tabela tb_ponto ");

		const char *sqlCreateTable = " CREATE TABLE tb_ponto (trajetoria STRING, x INTEGER, y INTEGER, ang DOUBLE, FOREIGN KEY(trajetoria) REFERENCES tb_trajetoria(nome) ); ";

		rc = sqlite3_exec(db, sqlCreateTable, NULL, NULL, &error);
		if (rc)
		{
			string str(sqlite3_errmsg(db));
			Logger::Log("Error executing SQLite3 statement: " + str);
			sqlite3_free(error);
		}
		else
		{
			Logger::Log("tb_ponto criada com sucesso");
		}
	}
	else
	{
		Logger::Log("Tabela tb_ponto já existe.");
	}


#pragma endregion



	

}

dbStorage::~dbStorage()
{
	sqlite3_close(db);
}
