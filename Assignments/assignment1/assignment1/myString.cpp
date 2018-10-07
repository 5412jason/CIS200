#include "pch.h"
#include "myString.h"
#include <string.h>
#include <array>

#define SIZE 25

using namespace std;

int status;
array<char, SIZE> strArray = { 0 };

myString::myString()
{
	initString();
}

int myString::size() {
	int size = 0;
	for (int i = 0; i < SIZE; i++) {
		if (strArray[i] != NULL) {
			size++;
		}
	}
	status = 0;
	return size;
}

void myString::addStart(myString mystring) {
	int inSize = mystring.size();
	char *inArray = mystring.getString();
	array<char, SIZE> tempArray = { 0 };
	for (int i = 0; i < SIZE; i++) {
		if (i < inSize) {
			tempArray[i] = inArray[i];
		}
		else {
			tempArray[i] = strArray[i - inSize];
		}
	}
	strArray = tempArray;
	status = 0;
}

void myString::addEnd(myString mystring) {
	int currentSize = size();
	char *inArray = mystring.getString();

	for (int i = currentSize; i < SIZE; i++) {
		strArray[i] = inArray[i - currentSize];
	}

	status = 0;
}

myString myString::partString(int startPos, int length) {
	myString newString = myString();
	array<char, SIZE> newArray;

	if (startPos < 0 || startPos >= SIZE) {
		status = 1;
		return newString;
	}
	else {
		for (int i = startPos; i < length; i++) {
			newArray[i-startPos] = strArray[i];
		}
		newString.setString(newArray);
		status = 0;
		return newString;
	}
}

void myString::replPartString(myString mystring, int startPos) {
	int inSize = mystring.size();

	if (startPos > SIZE) {
		status = 1;
		return;
	}
	else if(inSize+startPos >= SIZE) {
		status = 1;
		return;
	}
	else {
		array<char, SIZE> inArray = strArray;
		
		for (int i = startPos; i < SIZE; i++) {
			if (i - startPos < inSize) {
				strArray[i] = inArray[i - startPos];
			}
		}
		status = 0;
		return;
	}
}

void myString::replWholeString(myString mystring) {
	char *newArray = mystring.getString();
	status = 0;
	return;
}

bool myString::compareString(myString mystring) {
	if (mystring.getString() == getString()) {
		status = 0;
		return true;
	}
	else {
		status = 0;
		return false;
	}
}

void myString::initString() {
	for (int i = 0; i < SIZE; i++) {
		strArray[i] = NULL;
	}
	status = 0;
	return;
}

void myString::setString(string str) {
	int strSize = str.size();
	initString();
	for (int i = 0; i < strSize; i++) {
		strArray[i] = str[i];
	}
	status = 0;
	return;
}

void myString::setString(array<char, SIZE> arr) {
	strArray = arr;
}

void myString::printStringScreen() {
	printf("\n");
	int strSize = size();

	printf("[");
	for (int i = 0; i < strSize; i++) {
		printf("%s, ", strArray[i]);
	}
	printf("]");

	status = 0;
}

char* myString::getString() {
	status = 0;
	char arr[SIZE] = { 0 };

	for (int i = 0; i < SIZE; i++) {
		arr[i] = strArray[i];
	}
	return arr;
}

int myString::getStatus()
{
	return status;
}

bool myString::numericString() {
	bool allNumeric = true;
	int strSize = size();
	for (int i = 0; i < strSize; i++) {
		if (!isdigit(strArray[i])) {
			allNumeric = false;
			status = 0;
			return allNumeric;
		}
	}

	status = 0;
	return allNumeric;
}

bool myString::alphabeticString() {
	bool allAlpha = true;
	int strSize = size();
	for (int i = 0; i < strSize; i++) {
		if (!isalpha(strArray[i])) {
			allAlpha = false;
			status = 0;
			return allAlpha;
		}
	}

	status = 0;
	return allAlpha;
}

myString::~myString()
{
}

