#pragma once

template <typename T>
class stack
{
public:
	void push(T data);
	void pop();
	const T & top();
	int size();
	bool empty();
};

