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
	bool CLL_racers(CLL& _cll);
	bool CLL_revers(CLL& _cll);
	void ViewCLL(CLL& _cll) {
		element* view = _cll.head;
		/*while(view != NULL){
			cout << view->item << " -> ";
			view = view->next;
		}*/
		for (int i = 0; i < _cll.length; i++) {
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