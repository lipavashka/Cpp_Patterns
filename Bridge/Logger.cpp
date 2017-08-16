// example from http://cpp-reference.ru/patterns/structural-patterns/bridge/
// Logger.cpp - Abstarct
#include <iostream>
#include "Logger.h"
#include "LoggerImpl.h"
using namespace std;

Logger::Logger(LoggerImpl* p) : pimpl(p)
{ 
	cout << "Logger constructor" << endl;
}

Logger::~Logger()
{
	cout << "Logger distructor" << endl;
	delete pimpl;
}

ConsoleLogger::ConsoleLogger() : Logger(
#ifdef MT
	new MT_LoggerImpl()
#else
	new ST_LoggerImpl()
#endif
	)
{ 
	cout << "ConsoleLogger constructor" << endl;
}
ConsoleLogger::~ConsoleLogger()
{
	cout << "ConsoleLogger distructor" << endl;
}

void ConsoleLogger::log(string & str)
{
	pimpl->console_log(str);
}

FileLogger::FileLogger(string & file_name) : Logger(
#ifdef MT
	new MT_LoggerImpl()
#else
	new ST_LoggerImpl()
#endif
	), file(file_name)
{
	cout << "FileLogger constructor" << endl;
}
FileLogger::~FileLogger()
{
	cout << "FileLogger distructor" << endl;
}

void FileLogger::log(string & str)
{
	pimpl->file_log(file, str);
}

SocketLogger::SocketLogger(string & remote_host,
	int remote_port) : Logger(
#ifdef MT
	new MT_LoggerImpl()
#else
	new ST_LoggerImpl()
#endif
	), host(remote_host), port(remote_port)
{
	cout << "SocketLogger constructor" << endl;
}
SocketLogger::~SocketLogger()
{
	cout << "SocketLogger distructor" << endl;
}

void SocketLogger::log(string & str)
{
	pimpl->socket_log(host, port, str);
}

WirelessLogger::WirelessLogger(string & remote_host,
	int remote_port) : Logger(
#ifdef MT
	new MT_LoggerImpl()
#else
	new ST_LoggerImpl()
#endif
	), host(remote_host), port(remote_port)
{
	cout << "WirelessLogger constructor" << endl;
}
WirelessLogger::~WirelessLogger()
{
	cout << "WirelessLogger distructor" << endl;
}

void WirelessLogger::log(string & str)
{
	pimpl->wireless_log(host, port, str);
}