#pragma once
#include "TTable.h"

template <class TKey, class TValue>
class HashTable : public Table<TKey, TValue> {
protected:
	int HashFunc(TKey _key) {
		int hash = 0;
		for (int i = 0; i < _key.length(); i++) 
		{ hash += _key[i] << i; }
		return hash;
	}
};

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------

template <class TKey, class TValue>
class ArrayHash : public HashTable<TKey, TValue> {
protected:
	int size;
	int step;
	int currNum;
	Record<TKey, TValue>* arr;
public:
	ArrayHash(int _size = 100);
	~ArrayHash();

	bool IsFull() { return dataCount == size; }

	bool Find(TKey _key);
	void Insert(Record<TKey, TValue> rec);
	void Delete(TKey _key);

	void Reset();
	bool IsEnd();
	void GoNext();

	Record<TKey, TValue> GetCurrent();
	void SetCurrValue(TValue val);

	void Print();
	void PrintAll();

	friend char* GetString(string str);
};

template <class TKey, class TValue>
ArrayHash<TKey, TValue>::ArrayHash(int _size) {
	size = _size;
	step = 13;
	arr = new Record<TKey, TValue>[size];
	for (int i = 0; i < size; i++) { arr[i].GetKey() = ""; }
}

template <class TKey, class TValue>
ArrayHash<TKey, TValue>::~ArrayHash() { delete[] arr; }

template <class TKey, class TValue>
bool ArrayHash<TKey, TValue>::Find(TKey _key) {
	currNum = HashFunc(_key) % size;
	int free_pos = -1;

	for (int i = 0; i < size; i++) {
		efficiency++;

		if (arr[currNum].GetKey() == "") {
			if (free_pos == -1) {
				return false;
			}
			else {
				currNum = free_pos;
				return false;
			}
		}
		if (arr[currNum].GetKey() == _key) { return true; }
		if (free_pos == -1 && arr[currNum].GetKey() == "&") { free_pos = currNum; }
		currNum = (currNum + step) % size;
	}
	return false;
}

template <class TKey, class TValue>
void ArrayHash<TKey, TValue>::Insert(Record<TKey, TValue> rec) {
	if (!Find(rec.GetKey())) {
		arr[currNum] = rec;
		dataCount++;
	}
}

template <class TKey, class TValue>
void ArrayHash<TKey, TValue>::Delete(TKey _key) {
	if (Find(_key)) {
		arr[currNum].GetKey() = "&";
		dataCount--;
	}
}

template <class TKey, class TValue>
void ArrayHash<TKey, TValue>::Reset() {
	currNum = 0;
	while ((arr[currNum].GetKey() == "&" || arr[currNum].GetKey() == "") && currNum < size) {
		currNum++;
	}
}

template <class TKey, class TValue>
bool ArrayHash<TKey, TValue>::IsEnd() { return currNum >= size; }

template <class TKey, class TValue>
void ArrayHash<TKey, TValue>::GoNext() {
	while ((++currNum < size)) {
		if (((arr[currNum].GetKey() != "&") && (arr[currNum].GetKey() != "")))
			break;
	}
}

template <class TKey, class TValue>
Record<TKey, TValue> ArrayHash<TKey, TValue>::GetCurrent() {
	if (currNum < 0 || currNum >= size)
		throw "Current number is incorrect";
	return arr[currNum];
}

template <class TKey, class TValue>
void ArrayHash<TKey, TValue>::SetCurrValue(TValue val) { arr[currNum].SetValue(val); }

template <class TKey, class TValue>
void ArrayHash<TKey, TValue>::Print() {
	Record<TKey, TValue> tmp;
	for (Reset(); !IsEnd(); GoNext()) {
		tmp = GetCurrent();
		cout << currNum << ") " << GetString(tmp.GetKey()) << " - " << tmp.GetValue() << endl;
	}
}

template <class TKey, class TValue>
void ArrayHash<TKey, TValue>::PrintAll() {
	Record<TKey, TValue> tmp;
	for (int i = 0; i < size; i++) {
		currNum = i;
		tmp = GetCurrent();
		cout << currNum << ") " << GetString(tmp.GetKey()) << " - " << tmp.GetValue() << endl;
	}
}

char* GetString(string str) {
	int length = str.length();
	char* result = new char[length + 1];
	for (int i = 0; i < length; i++) { result[i] = str[i]; }
	result[length] = '\0';
	return result;
}