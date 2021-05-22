#pragma once 
#include <iostream>
using namespace std;

template <class type>
struct Link {
	type value;
	Link<type>* pNext;
};

template <class type>
class List {
protected:
	Link<type>* pFirst;
	Link<type>* pLast;
	Link<type>* pCurr;
	Link<type>* pPrev;
	Link<type>* pStop;
	int pos;
	int size;
public:
	List();
	~List() { while (size > 0) DeleteLast(); }
	int GetSize() { return size; }
	int GetPos() { return pos; }
	void SetPos(const int _pos);
	virtual bool IsEmpty() { return pFirst == pStop; }
	void Reset();
	bool IsEnd() { return pCurr == pStop; }
	void GoNext();
	virtual void InsertFirst(const type& elem);
	virtual void InsertLast(const type& elem);
	virtual void InsertCurr(const type& elem);
	virtual void DeleteFirst();
	virtual void DeleteCurr();
	virtual void DeleteLast();
	Link<type>* GetCurr() { return pCurr; }
	Link<type>* GetPrev() { return pPrev; }
	Link<type>* GetFirst() { return pFirst; }
	Link<type>* GetLast() { return pLast; }
};

template <class type>
List<type>::List() {
	pFirst = NULL;
	pLast = NULL;
	pCurr = NULL;
	pPrev = NULL;
    pStop = NULL;
	size = 0;
	pos = -1;
}

template <class type>
void List<type>::SetPos(const int _pos) { for (int i = 0; i < _pos; i++) GoNext(); }

template <class type>
void List<type>::Reset() {
	pCurr = pFirst;
	pos = 0;
	pPrev = pStop;
}

template <class type>
void List<type>::GoNext() {
	pPrev = pCurr;
	pCurr = pCurr->pNext;
	pos++;
}

template <class type>
void List<type>::InsertFirst(const type& elem) {
	Link<type>* item = new Link<type>;
	item->value = elem;
	if (pFirst == NULL) {
		pFirst = item;
		pLast = item;
		pCurr = item;
		pFirst->pNext = pStop;
		pos = 0;
	}
	else {
		item->pNext = pFirst;
		pFirst = item;
	}
	pos++;
	size++;
}
template <class type>
void List<type>::InsertLast(const type& elem) {
	if (pFirst == NULL) { InsertFirst(elem); }
	else {
		Link<type>* item = new Link<type>;
		item->value = elem;
		pLast->pNext = item;
		item->pNext = pStop;
		pLast = item;
		size++;
	}
}

template<class type>
void List<type>::InsertCurr(const type& elem) {
	if (elem > pFirst->value) { InsertFirst(elem); }
	else {
		if (pCurr == pStop) { InsertLast(elem); }
		else {
			Link<type>* item = new Link<type>;
			item->value = elem;
			item->pNext = pCurr;
			pPrev->pNext = item;
			pCurr = item;
			size++;
		}
	}
}

template <class type>
void List<type>::DeleteFirst() {
	if (size == 1) {
		delete pFirst;
		pFirst = NULL;
		pLast = NULL;
		pCurr = NULL;
		pPrev = NULL;
		pStop = NULL;
	}
	else {
		Link<type>* item = pFirst;
		pFirst = pFirst->pNext;
		delete item;
		pCurr = pFirst;
	}
	size--;
	if (pos > 0) { pos--; }
}

template <class type>
void List<type>::DeleteCurr() {
	if (pCurr == pFirst) { DeleteFirst(); }
	else{
		pCurr = pCurr->pNext;
		delete pPrev->pNext;
		pPrev->pNext = pCurr;
		size--;
	}
	if (size == 1) pLast = pFirst;
	if (!size) pFirst = NULL;
}

template <class type>
void List<type>::DeleteLast() {
	if (pLast == pFirst) { DeleteFirst(); }
	else {
		for (Reset(); !(pCurr->pNext == pStop); GoNext()) {}
		delete pLast;
		pLast = pPrev;
		pCurr = pPrev;
		Reset();
		size--;
		pos--;
	}
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



template <class type>
class HeadList :public List<type> {
protected:
	Link<type>* pHead;
public:
	HeadList();
	~HeadList();
	void InsertFirst(const type& elem) override;
	void DeleteFirst() override;
};

template <class type>
HeadList<type>::HeadList() : List() {
	pHead = new Link<type>;
	pStop = pHead;
	pHead->pNext = pHead;
}

template <class type>
HeadList<type>::~HeadList() {
	List<type>::~List();
	delete[] pHead;
}

template <class type>
void HeadList<type>::InsertFirst(const type& elem) {
	List<type>::InsertFirst(elem);
	pHead->pNext = pFirst;
}

template <class type>
void HeadList<type>::DeleteFirst() {
	List<type>::DeleteFirst();
	pHead->pNext = pFirst;
}