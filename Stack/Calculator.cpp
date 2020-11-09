#include"Stack.h"
#include"Calculator.h"
void Calculator::SetFormula(std::string str)
{
	Stack<char> c(str.size()); 
	Stack <double> d(str.size());
	st_c = c;
	st_d = d;
	formula = str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			st_c.Push(str[i]);
		}
		else
			if(str[i]!= ' ')
			st_d.Push(str[i]);
	}
}
bool Calculator::CheckBrackets()
{
	Stack<char> c(formula.size());
	for (int i = 0; i < formula.length(); i++)
	{
		if (formula[i] == '(')
		{
			if (c.Full() == true)
			{
				return false;
			}
		c.Push('(');
	    }
		if (formula[i] == ')')
		{
			if (c.Empty() == true)
			{
				return false;
			}
			char k = c.Pop();
		}
	}
		return c.Empty();
}
double Calculator::res()
{
	for (int i = 0; st_d.Size() > 1; i++)
	{
		double a, b;
		a = st_d.Pop();
		b = st_d.Pop();
		if (st_c.Pop() == '+')
		{
			st_d.Push(a + b);
		}
		if (st_c.Pop() == '-')
		{
			st_d.Push(a - b);
		}
		if (st_c.Pop() == '*')
		{
			st_d.Push(a * b);
		}
		if (st_c.Pop() == '/')
		{
			st_d.Push(b/a);
		}
	}
	return st_d.Top();
}