#pragma once
#define _CRT_SECURE_NO_WARNINGS  
#include <fstream>
#include "TLink.h"

class Text {
protected:
	Link* pFirst, * pCurr;
	Stack<Link*> st, del_st;
	int level;
public:
	Text(Link* _pFirst = NULL);
	~Text() { if(pFirst != NULL) pFirst = NULL; }
	void GoFirstLink();
	void GoDownLink();
	void GoNextLink();
	void GoPrevLink();

	char* GetLine() { return pCurr->GetStr(); }
	void SetLine(char* _str) { strcpy(pCurr->GetStr(), _str); }
	Link* GetCurr() { return pCurr; }
	void SetCurr(Link* _pCurr) { pCurr = _pCurr; }
	bool IsDownLevel();

	void InsertNextLine(char* _str);
	void InsertNextSection(char* _str);
	void DeleteDownLine(); 
	void DeleteNextLine(); 

	void Reset();
	bool IsEnd() { return st.IsEmpty(); }
	void GoNext();

	void Read(char* file);
	void PrintRecursion(Link* file);
	void Print();

	Link* ReadRecursion(ifstream& file);
	void SaveRecursion(Link* item, ofstream& file);
	void Save(char* _str);
	Link* CopyRecursion(Link* item);
	Link* Copy();

	int DownCount();
	bool HaveNext() { return pCurr->GetNext() != NULL; }
	bool HaveDown() { return pCurr->GetDown() != NULL; }

	bool IsEmpty() { return st.IsEmpty(); }

	static void MemCleaner(Text& _text);
	static void InitMemorySystem(size_t mem);
	static void PrintFreeLink();
};

