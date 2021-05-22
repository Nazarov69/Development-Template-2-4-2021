#pragma once
#define _CRT_SECURE_NO_WARNINGS  
#include <cstring>
#include <iostream>
#include "TStack.h"
using namespace std;

class Link;
struct Mem {
	Link* pFirst,
		* pLast,
		* pFree;
};

class Link {
protected:
	char str[80];
	Link* pNext,
		* pDown;
public:
	Link(char* _str = NULL, Link* _pNext = NULL, Link* _pDowm = NULL);
	void SetNext(Link* _pNext) { pNext = _pNext; }
	void SetDown(Link* _pDown) { pDown = _pDown; }
	Link* GetNext() { return pNext; }
	Link* GetDown() { return pDown; }
	void SetStr(char* _str);
	char* GetStr() { return str; }
	void* operator new(size_t top);
	void operator delete (void* pMem);
	bool IsAtomar() { return pDown == NULL; }
	friend ostream& operator<<(ostream& out, Link& _other);
	friend class Text;
	static Mem mem;
};




