// Logger.h - Abstract
#include <string>
using namespace std;

// Forward declaration
class LoggerImpl;

class Logger
{
public:
	Logger(LoggerImpl* p);
	virtual ~Logger();
	virtual void log(string & str) = 0;
protected:
	LoggerImpl * pimpl;
};

class ConsoleLogger : public Logger
{
public:
	ConsoleLogger();
	~ConsoleLogger();
	void log(string & str);
};

class FileLogger : public Logger
{
public:
	FileLogger(string & file_name);
	~FileLogger();
	void log(string & str);
private:
	string file;
};

class SocketLogger : public Logger
{
public:
	SocketLogger(string & remote_host, int remote_port);
	~SocketLogger();
	void log(string & str);
private:
	string host;
	int    port;
};

class WirelessLogger : public Logger
{
public:
	WirelessLogger(string & remote_host, int remote_port);
	~WirelessLogger();
	void log(string & str);
private:
	string host;
	int    port;
};
