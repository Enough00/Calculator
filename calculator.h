#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
#include <string>
#include <vector>
#include "menu.h"
using std::string;
//klasa wykonujaca konwersje
class calculator {
public:
	string value;
	calculator();
	void dec(string);
	void BinToDec(string);
	void HexToDec(string);
	void OctToDec(string);
	void DecToHex(int);
	void DecToBin(int);
	void DecToOct(int);
};
#endif CALCULATOR_H