#include<iostream>
#include"Calculator.h"
void Calculator::SetFormula(std::string str)
{
	formula = str;
	Stack<char> c(formula.size());
	Stack<double> d(formula.size());
	st_c = c;
	st_d = d;
}

bool Calculator::CheckBrackets()
{
	for (int i = 0; i < formula.size(); i++)
	{
		if (formula[i] == '(')
		{
			st_c.Push('(');
		}
		if (formula[i] == ')')
		{
			if (st_c.Empty() == true)
			{
				return false;
			}
			st_c.Pop();
		}
	}
	return st_c.Empty();
}
double Calculator::res()
{
	for (int i = 0; i < formula.size(); i++)
	{
		double a, b;
		switch (formula[i])
		{
		case'+': a = st_d.Pop(); b = st_d.Pop();
			st_d.Push(a + b);
			break;
		case'-': a = st_d.Pop(); b = st_d.Pop();
			st_d.Push(b - a);
			break;
		case'*': a = st_d.Pop(); b = st_d.Pop();
			st_d.Push(b * a);
			break;
		case'/': a = st_d.Pop(); b = st_d.Pop();
			st_d.Push(b / a);
			break;
		default: if (formula[i] != ' ')
			st_d.Push(formula[i] - '0');
			break;
		}
	}
	return st_d.Pop(); 
	/*for (int i = 0; i < formula.size(); i++)
	{
		if (formula[i] != ' ')
		{
			if (formula[i] != '+' && formula[i] != '-' && formula[i] != '*' && formula[i] != '/')
			{
				st_d.Push(formula[i] - '0');
			}
			else
			{
				double a = st_d.Pop();
				double b = st_d.Pop();
				switch (formula[i])
				{
				case'+': st_d.Push(a + b); break;
				case'-': st_d.Push(b - a); break;
				case'*': st_d.Push(a * b); break;
				case'/': st_d.Push(b / a); break;
				default:
					break;
				}
			}
		}
	}
	return st_d.Pop();*/
}