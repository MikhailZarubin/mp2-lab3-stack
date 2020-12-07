#pragma once
#include "../Stack/Stack.h"
#include <iostream>
#include <string>
class Calculator
{
	std::string infix;
	std::string postfix;
	Stack<char> st_c;
	Stack<double> st_d;
	void ToPostfix();
	bool CheckBrackets();
public:
	void SetFormula(std::string str);
	double res();
};
