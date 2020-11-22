#include"Calculator.h"
#include <iostream>
#include<string>
void main()
{
	Calculator calc;
	while (true)
	{
		try 
		{
			std::string str;
			std::cin >> str;
			calc.SetFormula(str);
			std::cout << std::endl << calc.res() << std::endl;
		}
		catch(int)
		{
			std::cout << "Error";
		}
	}
}