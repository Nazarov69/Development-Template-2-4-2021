#pragma once
#include "TTable.h"
#include <stack>

template <class TKey, class TValue>
class Node {
public:
	Record<TKey, TValue> record;
	Node<TKey, TValue>* pLeft, * pRight;
	int balance;

	Node() {
		record = new Record<TKey, TValue>();
		pLeft = pRight = nullptr;
		balance = 0;
	}

	Node(Record<TKey, TValue> _record, Node<TKey, TValue>* _pLeft = nullptr, Node<TKey, TValue>* _pRight = nullptr) {
		record = _record;
		pLeft = _pLeft;
		pRight = _pRight;
	}
};

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------


template <class TKey, class TValue>
class TreeTable : public Table<TKey, TValue> {
protected:
	Node<TKey, TValue>* pRoot, * pCurr;
	Node<TKey, TValue>** pRes;
	stack<Node<TKey, TValue>*> st;
	int nodeCount;
public:
	TreeTable();

	bool IsFull() { return false; }

	bool Find(TKey _key);
	void Insert(Record<TKey, TValue> rec);
	void Delete(TKey _key);

	void Reset();
	bool IsEnd();
	void GoNext();

	Record<TKey, TValue> GetCurrent() { return pCurr->record; }
	void SetCurrValue(TValue val) { pCurr->record.SetValue(val); }

	Record<TKey, TValue> GetResRecord() { return (*pRes)->record; }
	void SetResValue(TValue val) { (*pRes)->record.SetValue(val); }
};

template <class TKey, class TValue>
TreeTable<TKey, TValue>::TreeTable() {
	pRoot = nullptr;
	pCurr = nullptr;
	pRes = nullptr;
}

template <class TKey, class TValue>
bool TreeTable<TKey, TValue>::Find(TKey _key) {
	pRes = &pRoot;

	while (*pRes != nullptr) {
		efficiency++;

		if ((*pRes)->record.GetKey() == _key) { return true; }
		else if ((*pRes)->record.GetKey() < _key) { pRes = &((*pRes)->pRight); }
		else { pRes = &((*pRes)->pLeft); }
	}
	return false;
}

template <class TKey, class TValue>
void TreeTable<TKey, TValue>::Insert(Record<TKey, TValue> rec) {
	if (!Find(rec.GetKey())) {
		*pRes = new Node<TKey, TValue>(rec);
		dataCount++;
	}
}

template <class TKey, class TValue>
void TreeTable<TKey, TValue>::Delete(TKey _key) {
	if (Find(_key)) {
		Node<TKey, TValue>* dnode = *pRes;

		if (dnode->pLeft == nullptr) { *pRes = dnode->pRight; }
		else if (dnode->pRight == nullptr) { *pRes = dnode->pLeft; }
		else {
			Node<TKey, TValue>* curr = dnode->pLeft;
			Node<TKey, TValue>** prev = &(dnode->pLeft);

			while (curr->pRight) {
				prev = &(curr->pRight);
				curr = curr->pRight;
			}

			dnode->record = curr->record;
			dnode = curr;
			*prev = curr->pLeft;
		}
		dataCount--;
		delete dnode;
	}
}

template <class TKey, class TValue>
void TreeTable<TKey, TValue>::Reset() {
	while (!st.empty()) { st.pop(); }
	nodeCount = 0;
	pCurr = pRoot;
	while (pCurr->pLeft) {
		st.push(pCurr);
		pCurr = pCurr->pLeft;
	}
	st.push(pCurr);
}

template <class TKey, class TValue>
bool TreeTable<TKey, TValue>::IsEnd() { return nodeCount == dataCount; }

template <class TKey, class TValue>
void TreeTable<TKey, TValue>::GoNext() {
	if (!st.empty()) { st.pop(); }

	if (pCurr->pRight) {
		pCurr = pCurr->pRight;
		while (pCurr->pLeft) {
			st.push(pCurr);
			pCurr = pCurr->pLeft;
		}
		st.push(pCurr);
	}
	else { if (!st.empty()) { pCurr = st.top(); }
	}
	nodeCount++;
}