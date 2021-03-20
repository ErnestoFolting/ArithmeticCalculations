#pragma once

template <typename T>
class stack
{
private:
	int itsSize;
	const int addedCapacity;
	int itsCapacity;
	int * itsData;
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
itsSize(0), addedCapacity(20), itsCapacity(addedCapacity),  itsData(new T[itsCapacity]), itsCurrent(0)
{}

template <typename T>
stack<T>::stack(int capacity):
itsSize(0), addedCapacity(capacity), itsCapacity(addedCapacity), itsData(new T[itsCapacity]), itsCurrent(0)
{}

template <typename T>
void stack<T>::push(T data)
{
	if(size==0)
	{
		itsData[0]=data;
	}
	else if(itsSize!=itsCapacity)
	{
		itsCurrent++;
		itsData[itsCurrent]=data;
	}
	else if(itsSize==itsCapacity)
	{
		itsCapacity+=addedCapacity;
		int * newData=new T[itsCapacity];
		for(int i=0;i<itsCurrent;i++)
		{
			newData[i]=itsData[i];
		}
		delete itsData;
		itsData=newData;
		itsCurrent++;
		itsData[itsCurrent]=data;
	}
	itsSize++;
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
