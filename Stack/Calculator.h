#pragma once
#include "Stack.h"
#include <iostream>
#include <string>
class Calculator
{
	std::string formula;
	Stack<char> st_c;
	Stack<double> st_d;
public:
	void SetFormula(std::string str);
	bool CheckBrackets();
	double res();
};