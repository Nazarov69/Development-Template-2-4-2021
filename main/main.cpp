#include "TArrayTable.h"
#include "THashTable.h"
#include "TTreeTable.h"
#include <fstream>
using namespace std;

string RandomSrting(int size);

int main() {
	ifstream ifs("SmellsLikeTeenSpirit.txt");
	if (!ifs.is_open()) {
		cout << "Reading file error\n";
		return 1;
	}

	int count = 1000;
	char buffer[50];
	ScanTable<string, int> scantab(count);
	SortTable<string, int> sorttab(count);
	ArrayHash<string, int> hashtab(count);
	TreeTable<string, int> treetab;	

	while (!ifs.eof()) {
		ifs >> buffer;
		string str(buffer);
		Record<string, int> tmp(str, 1);

		if (scantab.Find(tmp.GetKey())) { scantab.SetCurrValue(scantab.GetCurrent().GetValue() + 1); }
		else {
			if (!scantab.IsFull()) { scantab.Insert(tmp); }
			else {
				cout << "Table size is too small!\n";
				return 1;
			}
		}
		if (sorttab.Find(tmp.GetKey())) { sorttab.SetCurrValue(sorttab.GetCurrent().GetValue() + 1); }
		else {
			if (!sorttab.IsFull()) { sorttab.Insert(tmp); }
			else {
				cout << "Table size is too small!\n";
				return 1;
			}
		}
		if (hashtab.Find(tmp.GetKey())) { hashtab.SetCurrValue(hashtab.GetCurrent().GetValue() + 1); }
		else {
			if (!hashtab.IsFull()) { hashtab.Insert(tmp); }
			else {
				cout << "Table size is too small!\n";
				return 1;
			}
		}
		if (treetab.Find(tmp.GetKey())) { treetab.SetResValue(treetab.GetResRecord().GetValue() + 1); }
		else {
			if (!treetab.IsFull()) { treetab.Insert(tmp); }
			else {
				cout << "Table size is too small!\n";
				return 1;
			}
		}
	}

	//scantab.Print();
	sorttab.Print();
	//hashtab.PrintAll();
	//treetab.Print();
	cout << endl;

	Record<string, int> maximum[10];
	SortTable<int, string> top(count);

	for (sorttab.Reset(); !sorttab.IsEnd(); sorttab.GoNext()) { top.Insert(Record<int, string>(sorttab.GetCurrent().GetValue(), sorttab.GetCurrent().GetKey())); }
	for (top.Reset(); !top.TenRecordsLeft(); top.GoNext());

	int i = 0;
	while (!top.IsEnd()) {
		maximum[i] = Record<string, int>(top.GetCurrent().GetValue(), top.GetCurrent().GetKey());
		i++;
		top.GoNext();
	}
	cout << "maximum:\n";
	for (i = 0; i < 10; i++) {
		maximum[i].Print();
		cout << endl;
	}
	ifs.close();
	return 0;
}



string RandomSrting(int size) {
	string res = "";
	for (int i = 0; i < size; i++) { res += (char)(rand() % 26 + 'a'); }
	return res;
}