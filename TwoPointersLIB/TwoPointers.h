#ifndef _CLLIST_
#define _CLLIST_
#include <iostream>

using namespace std;


class CLL{
	struct element {
		int item;
		element* next;
	};
	element* head;
	element* cur;
	int length;
public:
	
	CLL(int _array[], int _length, bool cir = true);
	bool CLL_racers();
	bool CLL_revers();
	void ViewCLL() {
		element* view = head;
		/*while(view != NULL){
			cout << view->item << " -> ";
			view = view->next;
		}*/
		for (int i = 0; i < length; i++) {
			cout << view->item << " -> ";
			view = view->next;
		}
		if (view != NULL) {
			cout << view->item;
			view = view->next;
		}
		cout << endl << endl;
	}
};









#endif // !_CLLIST_