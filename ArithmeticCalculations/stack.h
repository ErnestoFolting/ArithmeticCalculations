#pragma once

template <typename T>
class stack
{
private:
	int itsSize;
	const int addedCapacity;
	int itsCapacity;
	T * itsData;
	int itsCurrent; 
public:
	stack();
	stack(int capacity);
	void push(T data);
	void pop();
	const T & top();
	int size();
	bool empty();
};

template <typename T>
stack<T>::stack():
itsSize(0), addedCapacity(20), itsCapacity(addedCapacity),
itsData(new T[itsCapacity]), itsCurrent(-1)
{}

template <typename T>
stack<T>::stack(int capacity):
itsSize(0), addedCapacity(capacity), itsCapacity(addedCapacity),
itsData(new T[itsCapacity]), itsCurrent(-1)
{}

template <typename T>
void stack<T>::push(T data)
{
	itsCurrent++;
	itsSize++;
	if(itsSize <= itsCapacity)
	{
		itsData[itsCurrent] = data;
	}
	else
	{
		itsCapacity += addedCapacity;
		T * newData = new T[itsCapacity];
		for(int i = 0;i < itsCurrent;i++)
		{
			newData[i] = itsData[i];
		}
		delete []itsData;
		itsData = newData;
		itsData[itsCurrent] = data;
	}
}

template <typename T>
void stack<T>::pop()
{
	if(itsSize != 0)
	{
		itsSize--;
		itsCurrent--;
	}
}

template <typename T>
const T & stack<T>::top()
{
	return itsData[itsCurrent];
}

template <typename T>
int stack<T>::size()
{
	return itsSize;
}

template <typename T>
bool stack<T>::empty()
{
	return (itsSize == 0)?true:false;
}
