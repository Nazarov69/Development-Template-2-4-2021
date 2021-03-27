#include <iostream>
#include "TwoPointers.h"
#include <time.h>
#include <stdlib.h>

int main() {
    int length; bool cycle;
    cout << "list length : "; cin >> length;
    int* array = new int[length];
    for (int i = 0; i < length; i++) array[i] = i + 1;
    cout << "cycle? "; cin >> cycle;
    CLL _cll(array, length, cycle);
    cout << "CLL_racers : ";
    if (_cll.CLL_racers()) cout << "CLL" << endl;
    else cout << "NO CLL" << endl;
    _cll.ViewCLL();
    cout << "CLL_reversible : ";
    if (_cll.CLL_revers()) cout << "CLL" << endl;
    else cout << "NO CLL" << endl;
    _cll.ViewCLL();
   

}
