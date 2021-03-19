#include <iostream>
#include <cstdlib>
#include "spreadsheet_1.h"


int main(){
    int arr[LENGTH];
    srand(time(NULL));
    
    for (int i = 0; i < LENGTH; i++) { arr[i] = rand() % 10; }

    Spreadsheet_1 sp(arr);
    sp.GetArray();
    sp.CreateMaxArray();
    sp.GetArray();




    return 0;

}
