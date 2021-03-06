
#include "pch.h"
#include "myString.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>
using namespace std;

int main()
{
	// create the log file

	ofstream logFile;
	logFile.open("log.txt");
	if (logFile.is_open()) {
		logFile << "Starting application log\n";
	}
	else {
		cout << "\n**Error: Unable to write to log file**";
	}

	myString mystring;
	mystring.initString();
	int status = 0;

	string userInput = "";
	cout << "\nEnter a string 25 characters or less: ";
	cin >> userInput;

	mystring.setString(userInput);
	status = mystring.getStatus();
	if (logFile.is_open()) {
		logFile << "\nFunction: setString Input: '" << userInput << "'   Status: " << status;
	}
	else {
		cout << "**Error: Unable to write to log file**";
	}
	cout << "\nCreated a new myString based on the input.";

	bool loop = true;
	int userSelection = 0;
	bool validSelection = false;

	while (loop) {
		validSelection = false;
		while (!validSelection) {
			cout << "\nSelect a function: ";
			cout << "\n[0] Close Program"
				<< "\n[1] size"
				<< "\n[2] addStart"
				<< "\n[3] addEnd"
				<< "\n[4] partString"
				<< "\n[5] replPartString"
				<< "\n[6] replWholeString"
				<< "\n[7] compareString"
				<< "\n[8] initString"
				<< "\n[9] setString"
				<< "\n[10] getString"
				<< "\n[11] printStringScreen"
				<< "\n[12] numericString"
				<< "\n[13] alphabeticString"
				<< "\n: ";

			if (cin >> userSelection) {
				if (userSelection <= 13 || userSelection > 0) {
					validSelection = true;
				}
				else {
					cout << "\n**Error Invalid function selection**";
					if (logFile.is_open()) {
						logFile << "\n**Error Invalid function selection**";
					}
					else {
						cout << "\n**Error: Unable to write to log file**";
					}
					validSelection = false;
				}
			}
		}

		switch (userSelection) {
		case 0:
		{
			loop = false;
		}
		case 1: 
		{
			int size = mystring.size();
			status = mystring.getStatus();
			if (logFile.is_open()) {
				logFile << "\nFunction: size Input: '" << "" << "'   Output: '" << size << "'   Status: " << status;
			}
			else {
				cout << "\n**Error: Unable to write to log file**";
			}
			cout << "\nSize = " << size;
			break;
		}
		case 2:
		{
			string newInput = "";
			myString newMyString;
			newMyString.initString();

			cout << "\nEnter in a string to insert at the start: ";
			if (cin >> newInput) {
				newMyString.setString(newInput);
				status = newMyString.getStatus();

				if (logFile.is_open()) {
					logFile << "\nFunction: setString Input: '" << newInput << "'   Output: '" << "" << "'   Status: " << status;
				}
				else {
					cout << "\n**Error: Unable to write to log file**";
				}

				mystring.addStart(newMyString);
				status = mystring.getStatus();

				if (logFile.is_open()) {
					logFile << "\nFunction: addStart Input: '" << newMyString.getString() << "'   Output: '" << mystring.getString() << "'   Status: " << status;
				}
				else {
					cout << "\n**Error: Unable to write to log file**";
				}

				cout << "\nNew string: " << mystring.getString();
				mystring.printStringScreen();
			}

			break;
		}
		}
	}

	logFile.close();
}