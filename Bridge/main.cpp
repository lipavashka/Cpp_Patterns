// Main.cpp
#include <string>
#include <iostream>
#include "Logger.h"
using namespace std;

int main()
{
	Logger * p_C = new ConsoleLogger();
	Logger * p_F = new FileLogger(string("log.txt"));
	Logger * p_S = new SocketLogger((string ("localhost")), 127);
	Logger * p_W = new WirelessLogger((string("localhost")), 127);

	cout << endl;
	p_C->log(string("message"));
	p_F->log(string("message"));
	p_S->log(string("message"));
	p_W->log(string("message"));
	cout << endl;


	delete p_C;
	delete p_F;
	delete p_S;
	delete p_W;
	return 0;
}
