#include<iostream>
#include<string>
#include<cmath>
#include"Calculator.h"
int Priority(char c)
{
	switch (c)
	{
	case'+': return 2;
	case'-': return 2;
	case'*': return 3;
	case'/': return 3;
	case'(':return 1;
	case')':return 1;
	case'^':return 4;
	default: return 0;
	}
}
void Calculator::SetFormula(std::string str)
{
	infix = "";
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
		{
			infix += " ";
		}
		infix += str[i];
	}
	if (CheckBrackets() != true)
	{
		throw 0;
	}
	Stack<char> c(infix.size());
	Stack<double> d(infix.size());
	st_c = c;
	st_d = d;
}

void Calculator::ToPostfix()
{
	st_c.clear_stack();
	st_d.clear_stack();
	postfix = "";
	std::string tmp = "(" + infix + ")";
	for(unsigned int i = 0;i<tmp.size();i++)
	{
		if (Priority(tmp[i]) == 0)
		{
			postfix += tmp[i];
		}
		else
		{
			if (tmp[i] == '(')
			{
				st_c.Push(tmp[i]);
			}
			else
			{
				if (tmp[i] == ')')
				{
					while (st_c.Top() != '(')
					{
						char a = st_c.Pop();
						postfix += ' ';
						postfix += a;
					}
					st_c.Pop();
				}
				else
				{
					while (Priority(st_c.Top()) >= Priority(tmp[i]))
					{
						char a = st_c.Pop();
						postfix += ' ';
						postfix += a;
					}
					st_c.Push(tmp[i]);
				}
			}
		}
	}
	if (!st_c.Empty())
	{
		throw 0;
	}
}
bool Calculator::CheckBrackets()
{
	st_c.clear_stack();
	st_d.clear_stack();
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == '(')
		{
			st_c.Push('(');
		}
		if (infix[i] == ')')
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
	ToPostfix();
	st_c.clear_stack();
	st_d.clear_stack();
	for (int i = 0; i < postfix.size(); i++)
	{
		double a, b;
		switch (postfix[i])
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
		case'^': a = st_d.Pop(); b = st_d.Pop();
			st_d.Push(pow(b, a));
			break;
		default: 
			if (postfix[i] != ' ')
			{
				unsigned int k = i, point = 0, flag = 0;;
				while (postfix[k] != ' ' && k!=postfix.size())
				{
					if (postfix[k] == '.')
					{
						point = k;
						flag = 1;
					}
					k++;
				}
				unsigned int delta = k-i-flag;
				if (flag == 1)
				{
					point = k - point - flag;
				}
				k = i;
				double z = 0;
				while (postfix[k] != ' ' && k != postfix.size())
				{
					if (postfix[k] != '.')
					{
						delta--;
						z += (postfix[k] - '0') * pow(10, delta);
					}
					k++;
				}
				if (flag == 1)
				{
					z /= pow(10, point);
				}
				st_d.Push(z);
				i = k;
			}
			break;
		}
	}
	if (st_d.Size() != 1)
	{
		throw 0;
	}
	return st_d.Pop(); 
}