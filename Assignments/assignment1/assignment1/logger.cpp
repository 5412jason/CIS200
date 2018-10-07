#include "pch.h"
#include "logger.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

string logFileName;

logger::logger()
{
	
}


logger::~logger()
{
}

void logger::log(string function, string input, int status)
{
	if (logFile.is_open) {
		logFile << "Function: " << function << "   Input: '" << input << "'   Status: " << status << endl;
	}
}

void logger::log(string function, string input, string result, int status)
{
	if (logFile.is_open) {
		logFile << "Function: " << function << "   Input: '" << input << "'   Result: " << result << "   Status: " << status << endl;
	}
}

void logger::log(string function, char *input, char *result, int status)
{
	if (logFile.is_open) {
		logFile << "Function: " << function << "   Input: '" << input << "'   Result: " << result << "   Status: " << status << endl;
	}
}

void logger::log(string message) {
	if (logFile.is_open) {
		logFile << message << endl;
	}
}

void logger::log(string error, int status) {
	if (logFile.is_open) {
		logFile << "Status: " << "   " << error << endl;
	}
}

void logger::closeLogger() {
	logFile.close();
}

void logger::initLog()
{
	string logFileName = time(NULL) + ".txt";
	logFile = ofstream (logFileName);
}
