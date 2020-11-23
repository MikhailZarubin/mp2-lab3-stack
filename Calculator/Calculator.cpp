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
	//case's':return 1;
	//case'c':return 1;
	//case'l':return 1;
	//case'e':return 1;
	default: return 0;
	}
}
void Calculator::SetFormula(std::string str)
{
	infix = " ";
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (Priority(str[i])!=0)
		{
			infix += " ";
		}
		infix += str[i];
	/*	if (str[i] == 's' || str[i] == 'c' || str[i] == 'e' || str[i] == 'l')
		{
			i += 3;
			if (i >= str.size() - 2)
				throw 0;
		}*/
	}
	infix += ' ';
	if (CheckBrackets() != true)
	{
		throw 0;
	}
	Stack<char> c(infix.size());
	Stack<double> d(infix.size());
	st_c = c;
	st_d = d;
}
bool Calculator::CheckBrackets()
{
	st_c.clear_stack();
	st_d.clear_stack();
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == '(') // || infix[i] == 's' || infix[i] == 'c' || infix[i] == 'e' || infix[i] == 'l')
		{
			st_c.Push(infix[i]);
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
/*double Calculator::res_math()
{
	st_c.clear_stack();
	st_d.clear_stack();
	std::string infix_copy = "(" + infix + ")";
	for (unsigned int i = 0; i < infix_copy.size(); i++)
	{
		if (Priority(infix_copy[i]) == 0)
		{
			if (infix_copy[i] != ' ')
			{
				unsigned int k = i, point = 0, flag = 0;;
				while (infix_copy[k] != ' ' && k != infix_copy.size())
				{
					if (infix_copy[k] == '.')
					{
						point = k;
						flag = 1;
					}
					k++;
				}
				unsigned int delta = k - i - flag;
				if (flag == 1)
				{
					point = k - point - flag;
				}
				k = i;
				double z = 0;
				while (infix_copy[k] != ' ' && k != infix_copy.size())
				{
					if (infix_copy[k] != '.')
					{
						delta--;
						z += (infix_copy[k] - '0') * pow(10, delta);
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
		}
	}
	for (unsigned int i = 0; i < infix_copy.size(); i++)
	{
		if (Priority(infix_copy[i]) > 0)
		{
			if (infix_copy[i] == '(' || infix_copy[i] == 's' || infix_copy[i] == 'c' || infix_copy[i] == 'e' || infix_copy[i] == 'l')
			{
				st_c.Push(infix_copy[i]);
			}
			else
			{
				if (infix_copy[i] == ')')
				{
					while (st_c.Top() != '(' && st_c.Top() != 's' && st_c.Top() != 'c' && st_c.Top() != 'e' && st_c.Top() != 'l')
					{
						char c = st_c.Pop();
						switch (c)
						{
							double a, b;
						case'+': a = st_d.Pop(); 
							b = st_d.Pop();
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
						default:break;
						}
					}
					if (st_c.Top() == '(')
					{
						st_c.Pop();
					}
					else
					{
						switch(st_c.Top())
						{
							double a;
						case's': st_c.Pop();
							a = st_d.Pop();
							st_d.Push(sin(a));			
							break;
						case'c': st_c.Pop();
							 a = st_d.Pop();
							st_d.Push(cos(a));
							break;
						case'e': st_c.Pop();
							 a = st_d.Pop();
							st_d.Push(exp(a));
							break;
						case'l': st_c.Pop();
							 a = st_d.Pop();
							st_d.Push(log(a));
							break;
						}
					}
				}
				else
				{
					while (Priority(st_c.Top()) >= Priority(infix_copy[i]))
					{
						char c = st_c.Pop();
						switch (c)
						{
							double a, b;
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
						default:break;
						}
					}
					st_c.Push(infix_copy[i]);
				}
			}
		}
	}
	if (!st_c.Empty())
	{
		throw 0;
	}
	if (st_d.Size() != 1)
	{
		throw 0;
	}
	return st_d.Pop();
}*/