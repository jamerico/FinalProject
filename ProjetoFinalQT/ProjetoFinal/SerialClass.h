#pragma once

#ifndef SERIALCLASS_H_INCLUDED
#define SERIALCLASS_H_INCLUDED

#define ARDUINO_WAIT_TIME 2000

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

class Serial
{
private:
	//Serial comm handler
	static HANDLE hSerial;
	//Connection status
	static bool connected;
	//Get various information about the connection
	static COMSTAT status;
	//Keep track of last error
	static DWORD errors;

	static void FinalizarConexao();

	static Serial* inst;

public:
	static Serial *instance();
	
	//Initialize Serial communication with the given COM port
	Serial(char *portName);
	Serial();
	//Close the connection
	~Serial();
	//Read data in a buffer, if nbChar is greater than the
	//maximum number of bytes available, it will return only the
	//bytes available. The function return -1 when nothing could
	//be read, the number of bytes actually read.
	static int ReadData(char *buffer, unsigned int nbChar);
	//Writes data from a buffer through the Serial connection
	//return true on success.
	static bool WriteData(char *buffer, unsigned int nbChar);
	//Check if we are actually connected
	static bool IsConnected();

	static bool EnviarMensagem(int carro, bool sentido1, float velocidade1, bool sentido2, float velocidade2);
	static bool EnviarMensagem(std::string address, bool sentido1, float velocidade1, bool sentido2, float velocidade2);
	static bool EnviarMensagem2(float velocidade1, float velocidade2, std::string address);

};

#endif // SERIALCLASS_H_INCLUDED