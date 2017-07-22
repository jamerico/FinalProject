#include "Logger.h"
//#include <debugapi.h>

using namespace std;

string Logger::path = "";
Logger *Logger::inst = 0;
time_t  Logger::timev = time(&timev);

string Logger::statisticsPath = "";
string Logger::delimiter = "|";
bool Logger::headers = true; //utiliza header ou não no arquivo de saída
bool Logger::trocaPontoPorVirgula = false; // substitui ponto por virgula para utilização no Excel

vector<Colunas> Logger::statColumns;


Logger::Logger()
{
	path = "log.txt"; 
}

string Logger::getStatisticsFileName() {
    stringstream currentDateTime;
    // current date/time based on current system
    time_t ttNow = time(0);
    tm * ptmNow;

    ptmNow = localtime(&ttNow);
    

    currentDateTime << 1900 + ptmNow->tm_year;

    //month
    if (ptmNow->tm_mon < 9)
        //Fill in the leading 0 if less than 10
        currentDateTime << "0" << 1 + ptmNow->tm_mon;
    else
        currentDateTime << (1 + ptmNow->tm_mon);

    //day
    if (ptmNow->tm_mday < 9)
        currentDateTime << "0" << 1 + ptmNow->tm_mday << "_";
    else
        currentDateTime << (1 + ptmNow->tm_mday) << "_";

    //hour
    if (ptmNow->tm_hour < 10)
        currentDateTime << "0" << ptmNow->tm_hour;
    else
        currentDateTime << ptmNow->tm_hour;

    //min
    if (ptmNow->tm_min < 10)
        currentDateTime << "0" << ptmNow->tm_min;
    else
        currentDateTime << ptmNow->tm_min;

    //sec
    if (ptmNow->tm_sec < 10)
        currentDateTime << "0" << ptmNow->tm_sec;
    else
        currentDateTime << ptmNow->tm_sec;

	currentDateTime << ".txt";

    return currentDateTime.str();
}

Logger::~Logger()
{
}

Logger *Logger::instance()
{
	if (!inst){
		inst = new Logger();
	}

	return inst;
}

void Logger::Log(string msg)
{
	auto task = async(write, msg);
	task.get();
}

void Logger::Output(const char* msg, double val)
{
	
	char msgbuf[1024];
	sprintf(msgbuf, msg, val);
	wchar_t wtext[20];
	mbstowcs(wtext, msgbuf, strlen(msgbuf) + 1);//Plus null
	LPWSTR ptr = wtext;
	OutputDebugString(ptr);
	
}

void Logger::Output(const char* msg)
{

	//char msgbuf[1024];
	//sprintf(msgbuf, msg, val);
	wchar_t wtext[20];
	mbstowcs(wtext, msg, strlen(msg) + 1);//Plus null
	LPWSTR ptr = wtext;
	OutputDebugString(ptr);

}

void Logger::write(string pMsg)
{
	ofstream myfile;
	myfile.open("log.txt", std::fstream::app);

	timev = time(&timev);
	char buff[20];

	strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&timev));
	myfile << buff << " " << pMsg << endl;
	myfile.close();


}

void Logger::asyncStatWriter(string pMsg, bool pTimeStamp)
{
	auto task = async(statWrite, pMsg, pTimeStamp);
	task.get();
}

void Logger::statWrite(string pMsg, bool pTimestamp)
{
	ofstream myfile;
	myfile.open(statisticsPath, std::fstream::app);

	if (pTimestamp)
	{
		timev = time(&timev);
		char buff[20];
		strftime(buff, 20, "%Y%m%d_%H%M%S", localtime(&timev));
		myfile << buff << delimiter ;

	}

	myfile << pMsg << endl;
	
	myfile.close();

}

string Logger::DblToStr(double num)
{
	if (num <-10000000000000)
	{
		return "";
	}
	
	string rtn = to_string(num);
	if (Logger::trocaPontoPorVirgula)
	{
		replace(rtn.begin(), rtn.end(), '.', ',');
	}
	return rtn;
}

void Logger::statWriteStrRetorno(StrRetorno pDados)
{
	stringstream ss;
	for each (Colunas col in statColumns)
	{
		
		
		switch (col)
		{
		case Timestamp:
			break;
		case Ticks:
			ss << pDados.ticks << delimiter;
			break;
		case FrameNum:
			ss << pDados.frameNum << delimiter;
			break;
		case FPS:
			ss << DblToStr(pDados.FPS) << delimiter;
			break;
		case Robo:
			ss << pDados.roboName << delimiter;
			break;
		case Xd:
			ss << pDados.melhorPonto.x << delimiter;
			break;
		case Yd:
			ss << pDados.melhorPonto.y << delimiter;
			break;
		case Xa:
			ss << pDados.posicaoAtual.x << delimiter;
			break;
		case Ya:
			ss << pDados.posicaoAtual.y << delimiter;
			break;
		case DistMelhorPonto:
			ss << DblToStr(pDados.mDist) << delimiter;
			break;
		case velAtual:
			ss << DblToStr(pDados.velAtual) << delimiter;
			break;
		case velDesejada:
			ss << DblToStr(pDados.setPoint) << delimiter;
			break;
		case erroVel:
			ss << DblToStr(pDados.erroVel) << delimiter;
			break;
		case angAtual:
			ss << DblToStr(pDados.angAtual) << delimiter;
			break;
		case angDesejado:
			ss << DblToStr(pDados.angDesejado) << delimiter;
			break;
		case erroAng:
			ss << DblToStr(pDados.erroAng) << delimiter;
			break;
		case achou:
			ss << pDados.achou << delimiter;
			break;
		case trajetoria:
			ss << pDados.trajetoria << delimiter;
			break;
		case LogaDados:
			ss << pDados.logaDados << delimiter;
			break;
		case SaidaControleLinear:
			ss << DblToStr(pDados.saidaControleLinear) << delimiter;
			break;
		case SaidaControleAngular:
			ss << DblToStr(pDados.saidaControleAngular) << delimiter;
			break;
		case SinalControle1:
			ss << DblToStr(pDados.sinalDeControle1) << delimiter;
			break;
		case SinalControle2:
			ss << DblToStr(pDados.sinalDeControle2) << delimiter;
			break;

		case velAtualDerivSuja:
			ss << DblToStr(pDados.velAtualDerivSuja) << delimiter;
			break;



		default:
			break;
		}

		
	}

	//ss << pDados.ticks << delimiter << pDados.frameNum << delimiter << pDados.FPS ;

	Logger::statWrite(ss.str(), true);
}


void Logger::initializeStatWriter()
{
	timev = time(&timev);
	char buff[20];
	strftime(buff, 20, "%Y%m%d_%H%M%S", localtime(&timev));



	//Somente serão logadas as colunas que estiverem no vector abaixo. 
	//Para deixar de logar uma informação basta comentar a linha correspondente.
	//Para alterar a ordem de exibição basta alterar a ordem de inserção no vector
	statColumns.push_back(Colunas::Timestamp);		// |
	statColumns.push_back(Colunas::Ticks);			// |
	statColumns.push_back(Colunas::FrameNum);		// | Dados genéricos para todos os robôs
	statColumns.push_back(Colunas::FPS);			// |
	statColumns.push_back(Colunas::LogaDados);		// |

	statColumns.push_back(Colunas::Robo);                          // |
	statColumns.push_back(Colunas::achou);						   // |
	statColumns.push_back(Colunas::trajetoria);					   // |
	statColumns.push_back(Colunas::Xd);	// Desejado				   // |
	statColumns.push_back(Colunas::Yd);	// Desejado				   // |
	statColumns.push_back(Colunas::Xa);	// Atual				   // |
	statColumns.push_back(Colunas::Ya);	// Atual				   // |
	statColumns.push_back(Colunas::DistMelhorPonto);			   // | Dados específicos para cada robô
	statColumns.push_back(Colunas::velAtual);					   // |
	statColumns.push_back(Colunas::velAtualDerivSuja);			   // |
	statColumns.push_back(Colunas::velDesejada);				   // |
	statColumns.push_back(Colunas::erroVel);					   // |
	statColumns.push_back(Colunas::SaidaControleLinear);		   // |
	statColumns.push_back(Colunas::angAtual);					   // |
	statColumns.push_back(Colunas::angDesejado);				   // |
	statColumns.push_back(Colunas::erroAng);					   // |
	statColumns.push_back(Colunas::SaidaControleAngular);		   // |
	statColumns.push_back(Colunas::SinalControle1);		           // |
	statColumns.push_back(Colunas::SinalControle2);		           // |


	statisticsPath = "stat/" + Logger::getStatisticsFileName();
	if (headers)
	{
		stringstream ss;
		for each (Colunas col in statColumns)
		{
			ss << getColNames(col) << delimiter;
		}

		asyncStatWriter(ss.str(), false);
	}


}

void Logger::asyncStatWriter(StrRetorno pDados)
{
	auto task = async(statWriteStrRetorno, pDados);
	task.get();

	
}

string Logger::getColNames(Colunas pCol)
{
	switch (pCol)
	{
	case Timestamp:
		return "TimeStamp";
		break;
	case Ticks:
		return "Ticks";
		break;
	case FrameNum:
		return "FrameNum";
		break;
	case FPS:
		return "FPS";
		break;
	case Robo:
		return "Robo";
		break;
	case Xd:
		return "Xd";
		break;
	case Yd:
		return "Yd";
		break;
	case Xa:
		return "Xa";
		break;
	case Ya:
		return "Ya";
		break;
	case DistMelhorPonto:
		return "DistMelhorPonto";
		break;
	case velAtual:
		return "velAtual";
		break;
	case velDesejada:
		return "velDesejada";
		break;
	case erroVel:
		return "erroVel";
		break;
	case angAtual:
		return "angAtual";
		break;
	case angDesejado:
		return "angDesejado";
		break;
	case erroAng:
		return "erroAng";
		break;
	case achou:
		return "achou";
		break;
	case trajetoria:
		return "trajetoria";
		break;
	case LogaDados:
		return "LogaDados";
		break;
	case SaidaControleLinear:
		return "SaidaControleLinear";
		break;
	case SaidaControleAngular:
		return "SaidaControleAngular";
		break;
	case SinalControle1:
		return "SinalDeControle1";
		break;
	case SinalControle2:
		return "SinalDeControle2";
		break;
	case velAtualDerivSuja:
		return "velAtualDerivSuja";
		break;
	default:
		return "col";
		break;
	}
}