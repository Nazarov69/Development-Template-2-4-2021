#include "TwoPointers.h"

CLL::CLL(int _array[], int _length, bool _cycle) {
	length = _length;
	int _firstindex = 0;
	head = new element;
	cur = head;
	element* cycle = head;
	srand(time(NULL));
	if (length > 2) _firstindex = rand() % (length - 2);
	else _firstindex = 0;
	head->item = _array[0];
	head->next = NULL;
	for (int i = 1; i < _length; i++) {
		if (i <= _firstindex) {
			cycle->next = new element;
			cycle = cycle->next;
			cycle->item = _array[i];
			cur = cycle;
		}
		else {
			cur->next = new element;
			cur = cur->next;
			cur->item = _array[i];
		}
	}

	if (_cycle == true && length > 2)
		cur->next = cycle;
	else cur->next = NULL;
}




bool CLL::CLL_racers(CLL& _cll) {
	element* racer_h = _cll.head;
	if (racer_h != NULL) {
		element* racer_hn = _cll.head->next;
		if (racer_hn != NULL) {
			element* racer_hnn = _cll.head->next->next;
			if (racer_hnn != NULL) {
				do {
					racer_hn = racer_hn->next;
					if (racer_hnn->next != NULL) {
						racer_hnn = racer_hnn->next->next;
					}
					else { return false; }
					if (racer_hn == racer_hnn)
						return true;
				} while (racer_hn != NULL && racer_hnn != NULL);
				return false;
			}
			else { return false; }
		}
		else { return false; }
	}
	else { return false; }
}

bool CLL::CLL_revers(CLL& _cll) {
	element* curr = _cll.head;
	element* forward = NULL;
	element* previous = NULL;

	while (curr != NULL) {
		forward = curr->next; 
		curr->next = previous; 
		previous = curr;
		curr = forward;	
	}

	if (_cll.head == previous && _cll.length > 2)
		return true;
	else {
		_cll.head = previous;
		return false;
	}
	
}


