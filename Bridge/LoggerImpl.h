// LoggerImpl.h - Realise
#include <string>
using namespace std;

class LoggerImpl
{
public:
	         LoggerImpl() { cout << "LoggerImpl constructor" << endl; }
	virtual ~LoggerImpl() { cout << "LoggerImpl distructor" << endl; }
	virtual void console_log(string & str) = 0;
	virtual void file_log( string & file, string & str ) = 0;
	virtual void socket_log( string & host, int port, string & str ) = 0;
	virtual void wireless_log(string & host, int port, string & str) = 0;
};

class ST_LoggerImpl : public LoggerImpl
{
public:
	ST_LoggerImpl() { cout << "ST_LoggerImpl constructor" << endl; }
	virtual ~ST_LoggerImpl() { cout << "ST_LoggerImpl distructor" << endl; }
	void console_log(string & str);
	void file_log(string & file, string & str);
	void socket_log( string & host, int port, string & str );
	void wireless_log(string & host, int port, string & str);	
};

class MT_LoggerImpl : public LoggerImpl
{
public:
	MT_LoggerImpl() { cout << "MT_LoggerImpl constructor" << endl; }
	virtual ~MT_LoggerImpl() { cout << "MT_LoggerImpl distructor" << endl; }
	void console_log(string & str);
	void file_log(string & file, string & str);
	void socket_log( string & host, int port, string & str );
	void wireless_log(string & host, int port, string & str);
};
