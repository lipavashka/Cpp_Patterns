// example from http://cpp-reference.ru/patterns/structural-patterns/bridge/
// LoggerImpl.cpp - Realise
#include <iostream>
#include "LoggerImpl.h"
using namespace std;

void ST_LoggerImpl::console_log(string & str)
{
	cout << "Single-threaded console logger" << endl;
}

void ST_LoggerImpl::file_log(string & file, string & str)
{
	cout << "Single-threaded file logger" << endl;
}

void ST_LoggerImpl::socket_log(
	string & host, int port, string & str)
{
	cout << "Single-threaded socket logger" << endl;
};

void ST_LoggerImpl::wireless_log(
	string & host, int port, string & str)
{
	cout << "Single-threaded wireless logger" << endl;
};



void MT_LoggerImpl::console_log(string & str)
{
	cout << "Multithreaded console logger" << endl;
}

void MT_LoggerImpl::file_log(string & file, string & str)
{
	cout << "Multithreaded file logger" << endl;
}

void MT_LoggerImpl::socket_log(
	string & host, int port, string & str)
{
	cout << "Multithreaded socket logger" << endl;
}

void MT_LoggerImpl::wireless_log(
	string & host, int port, string & str)
{
	cout << "Multit-threaded wireless logger" << endl;
};
