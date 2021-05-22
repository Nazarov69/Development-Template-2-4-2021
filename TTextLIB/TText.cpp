#include "TText.h"
#include <cstring>

Text::Text(Link* _pFirst) {
	if (_pFirst == NULL) _pFirst = new Link();
	pCurr = _pFirst;
	pFirst = _pFirst;
	level = 0;
}

void Text::GoFirstLink() {
	while (!st.IsEmpty()) { st.GetStack(); }
	pCurr = pFirst;
}

void Text::GoDownLink() {
	if (pCurr->GetDown() == NULL) return;
	st.PushStack(pCurr);
	pCurr = pCurr->GetDown();
}

void Text::GoNextLink() {
	if (pCurr->GetNext() == NULL) return;
	st.PushStack(pCurr);
	pCurr = pCurr->GetNext();
}

void Text::GoPrevLink() {
	if (st.IsEmpty()) return;
	pCurr = st.GetStack();
}

bool Text::IsDownLevel() { return (st.ShowStack()->GetDown() == pCurr); }

void Text::InsertNextLine(char* _str) {
	Link* item = new Link(_str, pCurr->GetNext(), NULL);
	pCurr->SetNext(item);
	pCurr = pCurr->GetNext();
}

void Text::InsertNextSection(char* _str) {
	Link* item = new Link(_str, NULL, NULL);
	if (pCurr->GetDown() != NULL) {
		Link* curr_down = pCurr->GetDown();
		pCurr->SetDown(item);
		pCurr = pCurr->GetDown();
		pCurr->SetNext(curr_down);
		return;
	}
	pCurr->SetDown(item);
	pCurr = pCurr->GetDown();
}

void Text::DeleteDownLine() {
	if (pCurr->GetDown() != NULL) { delete pCurr->GetDown(); }
	pCurr->SetDown(NULL);
}

void Text::DeleteNextLine() {
	if (pCurr->GetNext() != NULL) { delete pCurr->GetNext(); }
	pCurr->SetNext(NULL);
}

void Text::Reset() {
	pCurr = pFirst;
	st.Clear();
	st.PushStack(pCurr);
	if (pFirst->GetDown() != NULL) { st.PushStack(pFirst->GetDown()); }
	if (pFirst->GetNext() != NULL) { st.PushStack(pFirst->GetNext()); }
}

void Text::GoNext() {
	pCurr = st.GetStack();
	if (pCurr != pFirst) {
		if (pCurr->GetDown() != NULL) { st.PushStack(pCurr->GetDown()); }
		if (pCurr->GetNext() != NULL) { st.PushStack(pCurr->GetNext()); }
	}
}

void Text::Read(char* file) {
	ifstream read(file);
	pFirst = ReadRecursion(read);
}

void Text::PrintRecursion(Link* file) {
	if (file != NULL) {
		for (int i = 0; i < level; i++) { cout << " "; }
		cout << file->GetStr() << endl;
		level++;
		PrintRecursion(file->GetDown());
		level--;
		PrintRecursion(file->GetNext());
	}
}

void Text::Print() {
	level = 0;
	PrintRecursion(pFirst);
}

Link* Text::ReadRecursion(ifstream& file) {
	char buf[80];
	Link* item = NULL, * first_item = NULL;
	while (!file.eof()) {
		file.getline(buf, 80, '\n');
		if (buf[0] == '}') break;
		else {
			if (buf[0] == '{') { item->SetDown(ReadRecursion(file)); }
			else {
				if (first_item == NULL) {
					first_item = new Link(buf);
					item = first_item;
				}
				else {
					item->SetNext(new Link(buf));
					item = item->GetNext();
				}
			}
		}
	}
	return first_item;
}

void Text::SaveRecursion(Link* item, ofstream& file) {
	file << item->GetStr() << endl;
	if (item->GetDown()) {
		file << "{\n";
		SaveRecursion(item->GetDown(), file);
		file << "}\n";
	}
	if (item->GetNext()) { SaveRecursion(item->GetNext(), file); }
}

void Text::Save(char* _str) {
	ofstream file(_str);
	SaveRecursion(pFirst, file);
}

Link* Text::CopyRecursion(Link* item) {
	Link* _pNext = NULL, * _pDown = NULL;
	if (item->GetDown()) { _pDown = CopyRecursion(item->GetDown()); }
	if (item->GetNext()) { _pNext = CopyRecursion(item->GetNext()); }
	Link* result = new Link(item->GetStr(), _pNext, _pDown);
	return result;
}

Link* Text::Copy() {
	return CopyRecursion(pFirst);
}

int Text::DownCount() {
	if (pCurr->GetDown() == NULL) return 1;
	Link* item = pCurr;
	int count = 0;
	st.Clear();
	st.PushStack(pCurr = pCurr->GetDown());
	for (; !IsEnd(); GoNext()) { count++; }
	pCurr = item;
	return ++count;
}

void Text::MemCleaner(Text& _text) {
	for (_text.Reset(); !_text.IsEnd(); _text.GoNext()) { strcat(_text.GetCurr()->str, "*"); }
	Link* item = Link::mem.pFree;
	while (item != NULL) {
		strcpy(item->str, "*");
		item = item->pNext;
	}
	item = Link::mem.pFirst;
	while (item != Link::mem.pLast) {
		if (strstr(item->str, "*") == NULL) { item->str[strlen(item->str) - 1] = '\0'; }
		item++;
	}
}

void Text::InitMemorySystem(size_t memory) {
	Link::mem.pFirst = (Link*) new char[sizeof(Link) * memory];
	Link::mem.pFree = Link::mem.pFirst;
	Link::mem.pLast = Link::mem.pFirst + (memory - 1);
	Link* item = Link::mem.pFree;
	for (int i = 0; i < memory - 1; i++) {
		item->SetStr("\\");
		item->pNext = item + 1;
		item++;
	}
	Link::mem.pLast->pNext = NULL;
	Link::mem.pLast->SetStr("\\");
}

void Text::PrintFreeLink() {
	Link* item = Link::mem.pFree;
	int iter = 0;
	while (item != NULL) {
		cout << item->str << endl;
		item = item->pNext;
		iter++;
	}
	cout << iter;
}






