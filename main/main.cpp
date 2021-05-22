#include "TText.h"
//#include "TLink.h"
#include <iostream>
using namespace std;

Mem Link::mem;


int main() {
	Text::InitMemorySystem(100);
	Text text;
	text.Read("text.txt");
	text.Print();
	cout << endl << endl << "Free list : ";
	Text::PrintFreeLink();
	Text::MemCleaner(text);
	cout << endl << "New free list : ";
	Text::PrintFreeLink();
	cout << endl;
	char str[] = "dshdsjdf";
	for (text.Reset(); !text.IsEmpty(); text.GoNext()){
		if (!strcmp(text.GetCurr()->GetStr(), str)){
			text.DeleteDownLine();
			break;
		}
	}
	cout << endl;
	text.Print();
	cout << endl << "Free list : ";
	Text::PrintFreeLink();
	Text::MemCleaner(text);
	cout << endl << "New free list : ";
	Text::PrintFreeLink();
	cout << endl;
	for (text.Reset(); !text.IsEmpty(); text.GoNext()){
		if (!strcmp(text.GetCurr()->GetStr(), str)){
			text.InsertNextLine("new_line");
			break;
		}
	}
	cout << endl;
	text.Print();
	cout << endl << "Free list : ";
	Text::PrintFreeLink();
	Text::MemCleaner(text);
	cout << endl << "New free list : ";
	Text::PrintFreeLink();
	cout << endl;
	for (text.Reset(); !text.IsEmpty(); text.GoNext()){
		if (!strcmp(text.GetCurr()->GetStr(), str)){
			text.DeleteNextLine();
			break;
		}
	}
	cout << endl;
	text.Print();
	cout << endl << "Free list : ";
	Text::PrintFreeLink();
	Text::MemCleaner(text);
	cout << endl << "New free list : ";
	Text::PrintFreeLink();
	cout << endl;
	text.Save("read.txt");
}