#pragma once

template <typename T>
class stack
{
private:
	int itsSize;
	int itsCapacity;
public:
	void push(T data);
	void pop();
	const T & top();
	int size();
	bool empty();
};

template <typename T>
void stack<T>::push(T data)
{
	
}

template <typename T>
void stack<T>::pop()
{
	
}

template <typename T>
const T & stack<T>::top()
{
	
}

template <typename T>
int stack<T>::size()
{
	return itsSize;
}

template <typename T>
bool stack<T>::empty()
{
	return (size>0)?true:false;
}
