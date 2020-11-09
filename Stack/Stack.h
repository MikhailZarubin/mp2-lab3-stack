#include<iostream>
template<class T>
class Stack
{
	T * mas;
	int size, max_size;
public:
	Stack(int m = 10);
	Stack(const Stack<T>& s);
	~Stack();
	Stack<T>& operator =(const Stack<T>& s);
	int operator == (const Stack<T>& s);
	int operator != (const Stack<T>& s);
	bool Empty();
	bool Full();
	void Push(T a);
	T Pop();
	T Top();
};
template <class T>
Stack<T>::Stack(int m)
{
	if (m <= 0)
	{
		throw m;
	}
	max_size = m;
	mas = new T[max_size];
	for (int i = 0; i <max_size; i++)
		mas[i] = 0;
	size = 0;
}
template <class T>
Stack<T>::Stack(const Stack <T>& s)
{
	size = s.size;
	max_size = s.max_size;
	mas = new T[max_size];
	for (int i = 0; i < size; i++)
		mas[i] = s.mas[i];
}
template<class T>
Stack<T>::~Stack()
{
	delete[] mas;
}
template<class T>
Stack<T>& Stack<T>:: operator = (const Stack<T>& s) 
{
	if (this != &s)
	{
		if (max_size != s.max_size)
		{
			max_size = s.max_size;
			delete[] mas;
			mas = new T[max_size];
		}
		size = s.size;
		for (int i = 0; i < size; i++)
		{
			mas[i] = s.mas[i];
		}
	}
	return (*this);
}
template <class T>
int Stack<T>:: operator == (const Stack<T>& s) 
{
	if (this != &s)
	{
		if (max_size != s.max_size || size!= s.size)
			return -1;
		for (int i = 0; i < size; i++)
		{
			if (mas[i] != s.mas[i])
				return -1;
		}
	}
	return 1;
}
template <class T>
int Stack<T>:: operator != (const Stack<T>& s) 
{
	return !(*this == s);
}
template <class T>
bool Stack<T>::Empty() 
{
	if (size == 0)
		return true;
	return false;
}
template <class T>
bool Stack<T>::Full() 
{
	if (size == max_size)
		return true;
	return false;
}
template <class T>
void Stack<T>::Push(T a)
{
	if (Full() == true)
	{
		throw max_size;
	}
	mas[size] = a;
	size++;
}
template <class T>
T Stack<T>::Pop()
{
	if (Empty() == true)
	{
		throw 0;
	}
	return mas[--size];
}
template <class T>
T Stack <T>::Top()
{
	if (Empty() == true)
	{
		throw 0;
	}
	return mas[size - 1];
}