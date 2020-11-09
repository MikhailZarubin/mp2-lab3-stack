#include"Calculator.h"
#include <iostream>
#include<string>
void main()
{
	Calculator calc;
	calc.SetFormula("4 1 1 + / 3 *");
	std::cout << calc.res();
}