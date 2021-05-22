#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class type>
class Stack {
	type* pStack;
	int top;
	int length;

public:
	Stack(int _size = 200);
	Stack(const Stack<type>& other);
	void PushStack(const type& elem);
	type GetStack();
	type ShowStack();
	~Stack();
	bool IsFull() { return (top + 1 >= length); }
	bool IsEmpty() { return (top == -1); }
	void Clear() { top = -1; }
	int GetTop() { return top; }
	int GetLength() { return length; }

	Stack<type>& operator=(const Stack<type>& other);
	type& operator[] (const int index);
	bool operator==(const Stack<type>& other);
	bool operator!=(const Stack<type>& other);

	template <class type>
	friend ostream& operator<< (ostream& out, const Stack<type>& other);
	template <class type>
	friend istream& operator >> (istream& in, Stack<type>& other);
};



template <class type>
Stack<type>::Stack(int _size) {
	if(_size > 0) {
		length = _size;
		pStack = new type[length];
		top = -1;
	}
	else throw logic_error("Input error: invalide value of Stack length in constructor");
}

template <class type>
Stack<type>::Stack(const Stack<type>& other) {
	top = other.top;
	length = other.length;
	pStack = new type[length];
	for (int i = 0; i < top + 1; i++) { pStack[i] = other.pStack[i]; }
}

template <class type>
void Stack<type>::PushStack(const type& elem) {
		if (IsFull())
			throw logic_error("Input error: invalide value of Stack length in PushStack");
		top++;
		pStack[top] = elem;
}

template<class type>
type Stack<type>::GetStack() {
	if (IsEmpty())
		throw logic_error("Input error: invalide value of Stack length in GetStack");
	type elem = pStack[top];
	top--;
	return elem;
}

template <class type>
type Stack<type>::ShowStack() {
	if (IsEmpty())
		throw logic_error("Input error: invalide value of Stack length in GetStack");
	return pStack[top];
}

template <class type>
Stack<type>::~Stack() {
	length = 0;
	top = -1;
	if (pStack != NULL) {
		delete[] pStack;
		pStack = NULL;
	}
}

	
template <class type>
Stack<type>& Stack<type>:: operator=(const Stack<type>& other) {
	if (this != &other) {
		if (length != other.length) {
			delete[] pStack;
			length = other.length;
		}
		top = other.top;
		pStack = new type[length];
		for (int i = 0; i < top + 1; i++) { pStack[i] = other.pStack[i]; }
	}
	return *this;
}

template <class type>
type& Stack<type>::operator[](const int index) {
	if (index < 0 || index >= length)
		throw logic_error("Input error: invalide value of Stack index in operator[]");
	return pStack[index];
}

template <class type>
bool Stack<type>::operator==(const Stack<type>& other) {
	if (length != other.length) { return false; }
	if (top != other.top) { return false; }

	for (int i = 0; i < top + 1; i++) {
		if (pStack[i] != other.pStack[i])
			return false;
	}
	return true;
}

template <class type>
bool Stack<type>::operator!=(const Stack<type>& other) { return !(this == &other); }

template <class type>
ostream& operator<< (ostream& out, const Stack<type>& other) {
	for (int i = 0; i < other.length; i++)
		out << other.pStack[i] << endl;
	return out;
}

template <class type>
istream& operator >> (istream& in, Stack<type>& other) {
	int count;
	in >> count;
	for (int i = 0; i < count; i++) {
		type elem;
		in >> elem;
		other.PushStack(elem);
	}
	return in;
}