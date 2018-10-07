#pragma once
#include <string>
#include <array>
#define SIZE 25

using namespace std;

class myString
{
public:
	myString();
	~myString();
	int size();
	void addStart(myString mystring);
	void addEnd(myString mystring);
	myString partString(int startPos, int length);
	void replPartString(myString mystring, int startPos);
	void replWholeString(myString mystring);
	bool compareString(myString mystring);
	void initString();
	void setString(string str);
	void setString(std::array<char, SIZE> arr);
	void printStringScreen();
	bool numericString();
	bool alphabeticString();
	char* getString();
	int getStatus();

private:
	int status;
	std::array<char, SIZE> strArray;
};

