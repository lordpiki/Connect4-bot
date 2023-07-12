#pragma once
#include <Windows.h>
#include <iostream>

using std::cout;
using std::endl;


class Connector
{
public:
	Connector();
	~Connector();
	bool connectPipeline();
	void waitForClient();
	void handleClient();
private:
	HANDLE _pipe;
};

