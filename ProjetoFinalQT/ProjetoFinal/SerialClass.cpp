#include "SerialClass.h"


HANDLE Serial::hSerial;
//Connection status
bool Serial::connected;
//Get various information about the connection
COMSTAT Serial::status;
//Keep track of last error
DWORD Serial::errors;

Serial* Serial::inst;

Serial::Serial()
{
	char * portName = "COM3";
	//We're not yet connected
	this->connected = false;

	//Try to connect to the given port throuh CreateFile
	this->hSerial = CreateFileA(portName,
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	//Check if the connection was successfull
	if (this->hSerial == INVALID_HANDLE_VALUE)
	{
		//If not success full display an Error
		if (GetLastError() == ERROR_FILE_NOT_FOUND){

			//Print Error if neccessary
			printf("ERROR: Handle was not attached. Reason: %s not available.\n", portName);

		}
		else
		{
			printf("ERROR!!!");
		}
	}
	else
	{
		//If connected we try to set the comm parameters
		DCB dcbSerialParams = { 0 };

		//Try to get the current
		if (!GetCommState(this->hSerial, &dcbSerialParams))
		{
			//If impossible, show an error
			printf("failed to get current serial parameters!");
		}
		else
		{
			//Define serial connection parameters for the arduino board
			dcbSerialParams.BaudRate = CBR_9600;
			dcbSerialParams.ByteSize = 8;
			dcbSerialParams.StopBits = ONESTOPBIT;
			dcbSerialParams.Parity = NOPARITY;
			//Setting the DTR to Control_Enable ensures that the Arduino is properly
			//reset upon establishing a connection
			dcbSerialParams.fDtrControl = DTR_CONTROL_ENABLE;

			//Set the parameters and check for their proper application
			if (!SetCommState(this->hSerial, &dcbSerialParams))
			{
				printf("ALERT: Could not set Serial Port parameters");
			}
			else
			{
				//If everything went fine we're connected
				this->connected = true;
				//Flush any remaining characters in the buffers 
				PurgeComm(this->hSerial, PURGE_RXCLEAR | PURGE_TXCLEAR);
				//We wait 2s as the arduino board will be reseting
				Sleep(ARDUINO_WAIT_TIME);
			}
		}
	}
}

Serial::Serial(char *portName)
{
	//We're not yet connected
	this->connected = false;

	//Try to connect to the given port throuh CreateFile
	this->hSerial = CreateFileA(portName,
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	//Check if the connection was successfull
	if (this->hSerial == INVALID_HANDLE_VALUE)
	{
		//If not success full display an Error
		if (GetLastError() == ERROR_FILE_NOT_FOUND){

			//Print Error if neccessary
			printf("ERROR: Handle was not attached. Reason: %s not available.\n", portName);

		}
		else
		{
			printf("ERROR!!!");
		}
	}
	else
	{
		//If connected we try to set the comm parameters
		DCB dcbSerialParams = { 0 };

		//Try to get the current
		if (!GetCommState(this->hSerial, &dcbSerialParams))
		{
			//If impossible, show an error
			printf("failed to get current serial parameters!");
		}
		else
		{
			//Define serial connection parameters for the arduino board
			dcbSerialParams.BaudRate = CBR_9600;
			dcbSerialParams.ByteSize = 8;
			dcbSerialParams.StopBits = ONESTOPBIT;
			dcbSerialParams.Parity = NOPARITY;
			//Setting the DTR to Control_Enable ensures that the Arduino is properly
			//reset upon establishing a connection
			dcbSerialParams.fDtrControl = DTR_CONTROL_ENABLE;

			//Set the parameters and check for their proper application
			if (!SetCommState(this->hSerial, &dcbSerialParams))
			{
				printf("ALERT: Could not set Serial Port parameters");
			}
			else
			{
				//If everything went fine we're connected
				this->connected = true;
				//Flush any remaining characters in the buffers 
				PurgeComm(this->hSerial, PURGE_RXCLEAR | PURGE_TXCLEAR);
				//We wait 2s as the arduino board will be reseting
				Sleep(ARDUINO_WAIT_TIME);
			}
		}
	}

}

Serial::~Serial()
{
	FinalizarConexao();
	//Check if we are connected before trying to disconnect
	if (this->connected)
	{
		//We're no longer connected
		this->connected = false;
		//Close the serial handler
		CloseHandle(this->hSerial);
	}
}

int Serial::ReadData(char *buffer, unsigned int nbChar)
{
	//Number of bytes we'll have read
	DWORD bytesRead;
	//Number of bytes we'll really ask to read
	unsigned int toRead;

	//Use the ClearCommError function to get status info on the Serial port
	ClearCommError(hSerial, &errors, &status);

	//Check if there is something to read
	if (status.cbInQue>0)
	{
		//If there is we check if there is enough data to read the required number
		//of characters, if not we'll read only the available characters to prevent
		//locking of the application.
		if (status.cbInQue>nbChar)
		{
			toRead = nbChar;
		}
		else
		{
			toRead = status.cbInQue;
		}

		//Try to read the require number of chars, and return the number of read bytes on success
		if (ReadFile(hSerial, buffer, toRead, &bytesRead, NULL))
		{
			return bytesRead;
		}

	}

	//If nothing has been read, or that an error was detected return 0
	return 0;

}


bool Serial::WriteData(char *buffer, unsigned int nbChar)
{
	DWORD bytesSend;

	//Try to write the buffer on the Serial port
	if (!WriteFile(hSerial, (void *)buffer, nbChar, &bytesSend, 0))
	{
		//In case it don't work get comm error and return false
		ClearCommError(hSerial, &errors, &status);

		return false;
	}
	else
		return true;
}

bool Serial::IsConnected()
{
	//Simply return the connection status
	return connected;
}


bool Serial::EnviarMensagem(std::string address, bool sentido1, float velocidade1, bool sentido2, float velocidade2)
{
	unsigned char* bufferread2;

	int newV1;
	int newV2;

	newV2 = velocidade2 * 255;
	newV1 = velocidade1 * 255;


	unsigned char sum = 0;
	char msg[12] = "";

	

	msg[5] = std::stoi(address.substr(0, 2) , 0, 16);
	msg[6] = std::stoi(address.substr(2, 2), 0, 16);


	//switch (carro)
	//{
	//case 0:
	//	msg[5] = 0xAA;
	//	msg[6] = 0xAA;
	//	break;
	//case 1:
	//	msg[5] = 0xAB;
	//	msg[6] = 0xAB;
	//	break;
	//case 2:
	//	//msg[5] = 0xAC;
	//	msg[6] = 0xAC;

	//	msg[5] = std::stoi("AC", 0, 16);
	//	//msg[6] = std::stoi("AC", 0, 16);

	//	break;
	//}

	if (sentido1 == 1 && sentido2 == 1)
	{
		msg[8] = 0xFF;
	}
	else if (sentido1 == 1 && sentido2 == 0)
	{
		msg[8] = 0xF0;
	}
	else if (sentido1 == 0 && sentido2 == 1)
	{
		msg[8] = 0x0F;
	}
	else if (sentido1 == 0 && sentido2 == 0)
	{
		msg[8] = 0x00;
	}

	msg[0] = 0x7E;
	msg[1] = 0x00;
	msg[2] = 0x08;
	msg[3] = 0x01;
	msg[4] = 0x01;
	msg[7] = 0x01;
	msg[9] = newV1;
	msg[10] = newV2;


	for (int i = 0; i < 12; i++)
	{
		if (i>2 && i < 11)
		{
			sum = sum + msg[i];
		}
	}
	sum = 0xFF - sum;
	sum = 0xFF & sum;
	msg[11] = sum;




	return (WriteData(msg, 12));


}

bool Serial::EnviarMensagem2(float velocidade1, float velocidade2, std::string address)
{
	unsigned char* bufferread2;

	bool sentido1 = velocidade1 > 0;
	bool sentido2 = velocidade2 > 0;

	int newV1;
	int newV2;

	newV1 = abs(velocidade1);
	newV2 = abs(velocidade2);


	unsigned char sum = 0;
	char msg[12] = "";

	msg[5] = std::stoi(address.substr(0, 2), 0, 16);
	msg[6] = std::stoi(address.substr(2, 2), 0, 16);

	if (sentido1  && sentido2 )
	{
		msg[8] = 0xFF;
	}
	else if (sentido1 && !sentido2 )
	{
		msg[8] = 0xF0;
	}
	else if (!sentido1  && sentido2 )
	{
		msg[8] = 0x0F;
	}
	else if (!sentido1  && !sentido2 )
	{
		msg[8] = 0x00;
	}

	msg[0] = 0x7E;
	msg[1] = 0x00;
	msg[2] = 0x08;
	msg[3] = 0x01;
	msg[4] = 0x01;
	msg[7] = 0x01;
	msg[9] = newV1;
	msg[10] = newV2;


	for (int i = 0; i < 12; i++)
	{
		if (i>2 && i < 11)
		{
			sum = sum + msg[i];
		}
	}
	sum = 0xFF - sum;
	sum = 0xFF & sum;
	msg[11] = sum;





	return (WriteData(msg, 12));


}

bool Serial::EnviarMensagem(int carro, bool sentido1, float velocidade1, bool sentido2, float velocidade2)
{

	

	switch (carro)
	{
	case 0:
		//msg[5] = 0xAA;
		//msg[6] = 0xAA;
		return EnviarMensagem("ACAC", sentido1, velocidade1, sentido2, velocidade2);
		break;
	case 1:
		/*msg[5] = 0xAB;
		msg[6] = 0xAB;*/
		return EnviarMensagem("ACAC", sentido1, velocidade1, sentido2, velocidade2);
		break;
	case 2:
		//msg[5] = 0xAC;
		//msg[6] = 0xAC;

		//msg[5] = std::stoi("AC",0,16);
		return EnviarMensagem("ACAC", sentido1, velocidade1, sentido2, velocidade2);
		//msg[6] = std::stoi("AC", 0, 16);

		break;
	}

	
}


void Serial::FinalizarConexao()
{
/*	try
	{
		
		*///std::cout << "destrutor" << std::endl;
		//Logger::Log("Inicio Destrutor objeto serial");

		

		EnviarMensagem(0, 1, 0, 1, 0);
		EnviarMensagem(0, 1, 0, 1, 0);
		EnviarMensagem(0, 1, 0, 1, 0);

		EnviarMensagem(1, 1, 0, 1, 0);
		EnviarMensagem(1, 1, 0, 1, 0);
		EnviarMensagem(1, 1, 0, 1, 0);

		EnviarMensagem(2, 1, 0, 1, 0);
		EnviarMensagem(2, 1, 0, 1, 0);
		EnviarMensagem(2, 1, 0, 1, 0);

		//serialport.Close();
		//Logger::Log("Fim Destrutor objeto serial");
	//}
	//catch (std::exception& ex)
	//{
	//	//Logger::Log(ex.what());
	//	//Logger::Log("Fim Destrutor objeto serial");
	//}
}

Serial *Serial::instance()
{
	if (!inst){
		inst = new Serial();
	}

	return inst;
}
