#include "Converter.h"


int main() {

    Converter foo;
    roman rome;
   
    cout << endl;
    while (1) {
        cout << endl;
        cout << "0 - checkRoman(exit)" << endl << "1 - fromRomanToArabic(exit)" << endl << "2 - fromArabicToRoman(0)" << endl << endl;
        int menu;
        cin >> menu;


        switch (menu) {

        case 0: {
            while (1) {
                cout << "enter the number to check : ";
                cin >> rome.value;
                if (rome.value == "exit") break;
                switch (foo.checkRoman(rome))
                {
                case 0: cout << "ERROR" << endl << endl;
                    break;
                case 1: cout << "TRUTH" << endl << endl;
                    break;
                default:
                    break;
                }
            }
        }
              break;


        case 1:
            while (1) {
                cout << endl;
                cout << "enter the number to convert : ";
                cin >> rome.value;
                if (rome.value == "exit") break;
                if (!foo.checkRoman(rome)) {
                    cout << "ERROR" << endl;
                    continue;
                }
                cout << "result : " << foo.fromRomanToArabic(rome).value << endl ;
            }
            break;


        case 2:
            while (1) {
                arabic arab;
                cout << endl;
                cout << "enter the number to convert : ";
                cin >> arab.value;
                if (arab.value == 0) break;
                if (!foo.checkArabic(arab)) {
                    cout << "ERROR" << endl;
                    continue;
                }
                cout << "result : " << foo.fromArabicToRoman(arab).value << endl;
            }
            break;

        default:
            break;


        }


    }
}



    



