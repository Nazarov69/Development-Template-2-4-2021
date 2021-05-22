#pragma once
#include "TText.h"
#include <cstring>

Link::Link(char* _str, Link* _pNext, Link* _pDown) {
	pNext = _pNext;
	pDown = _pDown;
	if (_str != NULL) { strcpy(str, _str); }
	else { str[0] = '\0'; }
}

void Link::SetStr(char* _str) {
	if (_str != NULL) { strcpy(str, _str); }
	else { str[0] = '\0'; }
}

void* Link::operator new(size_t top){
	Link* item = mem.pFree;
	if (mem.pFree != NULL) { mem.pFree = mem.pFree->pNext; }
	return item;
}

void Link::operator delete (void* pMem) {
	if (pMem != NULL) {
		Link* item = (Link*)pMem;
		item->pNext = mem.pFree;
		mem.pFree = item;
	}
	else { throw logic_error("error mem"); }
}

ostream& operator <<(ostream& out, Link& _other) {
	out << _other.str;
	return out;
}









