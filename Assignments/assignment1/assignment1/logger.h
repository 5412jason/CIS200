#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class logger
{
public:
	logger();
	~logger();

	void log(string message);
	void log(string function, string input, int status);
	void log(string error, int status);
	void log(string function, string input, string result, int status);
	void log(string function, char *input, char *result, int status);
	void initLog();
	void closeLogger();

private:
	ofstream *logFile;
};

