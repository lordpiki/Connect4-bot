#pragma once
#include <Windows.h>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Connector
{
public:
	Connector();
	~Connector();
	bool connectPipeline();
	void waitForClient();
	void handleClient();
	void sendBoardToClient(const string& resp);
	int getCol();
private:
	HANDLE _pipe;
};

