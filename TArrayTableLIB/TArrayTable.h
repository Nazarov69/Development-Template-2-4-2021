#pragma once
#include "TTable.h"

template <class TKey, class TValue>
class ArrayTable : public Table<TKey, TValue> {
protected:
	Record<TKey, TValue>* arr;
	int size;
	int currNum;
public:
	ArrayTable(int _size = 1);
	ArrayTable(const ArrayTable<TKey, TValue>& tab);
	~ArrayTable();

	ArrayTable<TKey, TValue>& operator=(const ArrayTable<TKey, TValue>& tab);

	Record<TKey, TValue> GetCurrent() { return arr[currNum]; }
	void SetCurrValue(TValue val) { arr[currNum].SetValue(val); }

	int GetSize() { return size; }
	int GetCurrNum() { return currNum; }
	Record<TKey, TValue> GetArrElem(int n) { return arr[n]; }

	void Reset() { currNum = 0; }
	bool IsEnd() { return currNum == dataCount; }
	void GoNext() { currNum++; }

	bool IsFull() { return size == dataCount; }

	bool TenRecordsLeft() { return currNum == (dataCount - 10); }
};

template <class TKey, class TValue>
ArrayTable<TKey, TValue>::ArrayTable(int _size) {
	size = _size;
	arr = new Record<TKey, TValue>[size];
}

template <class TKey, class TValue>
ArrayTable<TKey, TValue>::ArrayTable(const ArrayTable<TKey, TValue>& tab) {
	size = tab.size;
	arr = new Record<TKey, TValue>[size];
	for (int i = 0; i < size; i++) { arr[i] = tab.arr[i]; }
}

template <class TKey, class TValue>
ArrayTable<TKey, TValue>::~ArrayTable() { delete[] arr; }

template <class TKey, class TValue>
ArrayTable<TKey, TValue>& ArrayTable<TKey, TValue>::operator=(const ArrayTable<TKey, TValue>& tab) {
	if (size != tab.size) {
		size = tab.size;
		delete[] arr;
		arr = new new TRecord<TKey, TValue>[size];
	}
	for (int i = 0; i < size; i++) { arr[i] = tab.arr[i] }

	return *this;
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------

template <class TKey, class TValue>
class SortTable;

template <class TKey, class TValue>
class ScanTable : public ArrayTable<TKey, TValue> {
public:
	ScanTable(int _size = 1) : ArrayTable<TKey, TValue>(_size) {}
	ScanTable(const SortTable<TKey, TValue>& tab);

	ScanTable<TKey, TValue>& operator=(const SortTable<TKey, TValue>& tab);
	bool Find(TKey _key);
	void Insert(Record<TKey, TValue> rec);
	void Delete(TKey _key);
};

template <class TKey, class TValue>
ScanTable<TKey, TValue>::ScanTable(const SortTable<TKey, TValue>& tab) {
	size = tab.size;
	dataCount = tab.dataCount;
	currNum = tab.currNum;
	arr = new Record<TKey, TValue>[size];
	for (int i = 0; i < dataCount; i++) { arr[i] = tab.arr[i]; }
}

template <class TKey, class TValue>
ScanTable<TKey, TValue>& ScanTable<TKey, TValue>::operator=(const SortTable<TKey, TValue>& tab) {
	if (size != tab.GetSize()) {
		size = tab.GetSize();
		delete[] arr;
		arr = new Record<TKey, TValue>[size];
	}
	dataCount = tab.GetDataCount();
	currNum = tab.GetCurrNum();
	arr = new Record<TKey, TValue>[size];
	for (int i = 0; i < dataCount; i++) { arr[i] = tab.GetArrElem(i); }
	return *this;
}

template <class TKey, class TValue>
bool ScanTable<TKey, TValue>::Find(TKey _key) {
	for (int i = 0; i < dataCount; i++) {
		efficiency++;
		if (arr[i].GetKey() == _key) {
			currNum = i;
			return true;
		}
	}
	currNum = dataCount;
	return false;
}

template <class TKey, class TValue>
void ScanTable<TKey, TValue>::Insert(Record<TKey, TValue> rec) {
	if (!Find(rec.GetKey())) {
		arr[currNum] = rec;
		dataCount++;
		efficiency++;
	}
}

template <class TKey, class TValue>
void ScanTable<TKey, TValue>::Delete(TKey _key) {
	if (Find(_key)) {
		arr[currNum] = arr[dataCount - 1];
		dataCount--;
		efficiency++;
	}
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------

template <class TKey, class TValue>
class SortTable : public ArrayTable<TKey, TValue> {
public:
	SortTable(int _size = 1) : ArrayTable<TKey, TValue>(_size) {}
	SortTable(const ScanTable<TKey, TValue>& tab);

	SortTable<TKey, TValue>& operator=(ScanTable<TKey, TValue>& tab);

	bool Find(TKey _key);
	void Insert(Record<TKey, TValue> rec);
	void Delete(TKey _key);

	void QSort(int left, int right);
};


template <class TKey, class TValue>
SortTable<TKey, TValue>::SortTable(const ScanTable<TKey, TValue>& tab) {
	size = tab.size;
	dataCount = tab.dataCount;
	currNum = tab.currNum;
	arr = new Record<TKey, TValue>[size];
	for (int i = 0; i < dataCount; i++) { arr[i] = tab.arr[i]; }
	QSort(0, dataCount - 1);
}

template <class TKey, class TValue>
SortTable<TKey, TValue>& SortTable<TKey, TValue>::operator=(ScanTable<TKey, TValue>& tab) {
	if (size != tab.GetSize()) {
		size = tab.GetSize();
		delete[] arr;
		arr = new Record<TKey, TValue>[size];
	}

	dataCount = tab.GetDataCount();
	currNum = tab.GetCurrNum();

	for (int i = 0; i < dataCount; i++) { arr[i] = tab.GetArrElem(i); }
	QSort(0, dataCount - 1);

	return *this;
}

template <class TKey, class TValue>
bool SortTable<TKey, TValue>::Find(TKey _key) {
	int left = 0, right = dataCount - 1, middle;
	while (left <= right) {
		efficiency++;
		middle = (left + right) / 2;
		if (_key == arr[middle].GetKey()) {
			currNum = middle;
			return true;
		}
		else if (_key > arr[middle].GetKey()) {
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}
	currNum = left;
	return false;
}

template <class TKey, class TValue>
void SortTable<TKey, TValue>::Insert(Record<TKey, TValue> rec) {
	if (!Find(rec.GetKey())) {
		for (int i = dataCount; i > currNum; i--) {
			efficiency++;
			arr[i] = arr[i - 1];
		}
		arr[currNum] = rec;
		dataCount++;
	}
}

template <class TKey, class TValue>
void SortTable<TKey, TValue>::Delete(TKey _key) {
	if (Find(_key)) {
		for (int i = currNum; i < dataCount - 1; i++) {
			efficiency++;
			arr[i] = arr[i + 1];
		}
		dataCount--;
	}
}

template <class TKey, class TValue>
void SortTable<TKey, TValue>::QSort(int left, int right) {
	int middle = (left + right) / 2;
	TKey middle_key = arr[middle].key;
	Record<TKey, TValue> tmp;

	while (left <= right) {
		while (arr[left].key < middle_key) {
			left++;
			efficiency++;
		}
		while (arr[right].key > middle_key) {
			right--;
			efficiency++;
		}
		if (left <= right) {
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
		if (right > left) { QSort(left, right); }
		if (left < right) { QSort(left, right); }
	}
}