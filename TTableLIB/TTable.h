#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class TKey, class TValue>
class Record {
protected:
	TKey key;
	TValue value;
public:

	Record();
	Record(TKey _key, TValue _value);
	Record(const Record<TKey, TValue>& rec);

	Record& operator=(const Record<TKey, TValue>& rec);
	bool operator == (const Record<TKey, TValue>& rec);
	TKey GetKey() { return key; }
	TValue GetValue() { return value; }
	void SetKey(TKey _key) { key = _key; }
	void SetValue(TValue _value) { value = _value; }

	void Print() { cout << key << " - " << value; }
};

template <class TKey, class TValue>
Record<TKey, TValue>::Record() {
	key = TKey();
	value = TValue();
}

template <class TKey, class TValue>
Record<TKey, TValue>::Record(TKey _key, TValue _value) {
	key = _key;
	value = _value;
}

template <class TKey, class TValue>
Record<TKey, TValue>::Record(const Record<TKey, TValue>& rec) {
	key = rec.key;
	value = rec.value;
}

template <class TKey, class TValue>
Record<TKey, TValue>& Record<TKey, TValue>::operator=(const Record<TKey, TValue>& rec) {
	if (this == &rec) return *this;
	key = rec.key;
	value = rec.value;
	return *this;
}

template <class TKey, class TValue>
bool Record<TKey, TValue>::operator==(const Record<TKey, TValue>& rec) { return key == rec.key; }

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------

template <class TKey, class TValue>
class Table {
protected:
	int dataCount;
	int efficiency;
public:
	Table() { dataCount = 0; efficiency = 0; }

	int GetDataCount() { return dataCount; }

	bool IsEmpty() { return dataCount == 0; }
	virtual bool IsFull() = 0;

	virtual bool Find(TKey _key) = 0;
	virtual void Insert(Record<TKey, TValue> rec) = 0;
	virtual void Delete(TKey _key) = 0;

	virtual void Reset() = 0;
	virtual bool IsEnd() = 0;
	virtual void GoNext() = 0;

	virtual Record<TKey, TValue> GetCurrent() = 0;
	virtual void SetCurrValue(TValue val) = 0;

	int GetEfficiency() { return efficiency; }

	void Print() {
		Record<TKey, TValue> tmp;
		int i = 0;
		for (Reset(); !IsEnd(); GoNext()) {
			tmp = GetCurrent();
			cout << i << ") " << tmp.GetKey() << " - " << tmp.GetValue() << endl;
			i++;
		}
	}
};










