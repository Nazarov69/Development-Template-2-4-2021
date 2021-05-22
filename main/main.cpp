#include <time.h>
#include "TMonom_TPolinom.h"
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
	cout << "Select an operation for polinoms from the suggested ones" << "\t" << "+" << "\t" << "+=" << "\t" << "*" << "\t" << "*=" << endl;
	while (true){
		Monom* first_monom = new Monom[1], * second_monom = new Monom[1];
		bool flag = true;
		string p;
		cin >> p;
		if (p == "+"){
			first_monom[0].coeff = 15;
			first_monom[0].degX = 7;
			first_monom[0].degY = -2;
			first_monom[0].degZ = 1;

			second_monom[0].coeff = 4;
			second_monom[0].degX = -8;
			second_monom[0].degY = 5;
			second_monom[0].degZ = 9;

			Polinom first_polinom(first_monom, 1), second_polinom(second_monom, 1);
			Polinom res = first_polinom + second_polinom;

			cout << endl << first_monom[0] << " + " << second_monom[0] << " = " << res << endl;

			delete[] first_monom;
			delete[] second_monom;
			flag = false;
		}
		if (p == "+="){
			first_monom[0].coeff = 15;
			first_monom[0].degX = 7;
			first_monom[0].degY = -2;
			first_monom[0].degZ = 1;

			second_monom[0].coeff = 4;
			second_monom[0].degX = -8;
			second_monom[0].degY = 5;
			second_monom[0].degZ = 9;

			Polinom first_polinom(first_monom, 1), second_polinom(second_monom, 1);

			cout << endl << first_polinom << " += " << second_polinom << " = ";
			first_polinom += second_polinom;
			cout << first_polinom << std::endl;

			delete[] first_monom;
			delete[] second_monom;
			flag = false;
		}
		if (p == "*"){
			int item;
			std::cin >> item;
			switch (item){
			case(1):{
				Polinom res;
				first_monom[0].coeff = 15;
				first_monom[0].degX = 7;
				first_monom[0].degY = -2;
				first_monom[0].degZ = 1;

			    cout << endl << "Number=";
				double val;
				cin >> val;
				Polinom first_polinom(first_monom, 1);
				res = first_polinom * val;
				cout << endl << first_polinom << " * " << val << " = " << res << endl;
				delete[] first_monom;
				break;
			}
			case(2): {
				Polinom res;
				first_monom[0].coeff = 15;
				first_monom[0].degX = 7;
				first_monom[0].degY = -2;
				first_monom[0].degZ = 1;

				second_monom[0].coeff = 4;
				second_monom[0].degX = -8;
				second_monom[0].degY = 5;
				second_monom[0].degZ = 9;

				Polinom first_polinom(first_monom, 1);
				res = first_polinom * second_monom[0];
				cout << endl << first_polinom << " * " << second_monom[0] << " = " << res << endl;
				delete[] first_monom;
				delete[] second_monom;
				break;
			}
			case(3):{
				Polinom res;
				first_monom[0].coeff = 15;
				first_monom[0].degX = 7;
				first_monom[0].degY = -2;
				first_monom[0].degZ = 1;

				second_monom[0].coeff = 4;
				second_monom[0].degX = -8;
				second_monom[0].degY = 5;
				second_monom[0].degZ = 9;

				Polinom first_polinom(first_monom, 1), second_polinom(second_monom, 1);
				res = first_polinom * second_polinom;
				cout << endl << first_polinom << " * " << second_polinom << " = " << res << std::endl;
				delete[] first_monom;
				delete[] second_monom;
				break;
			}
			default:
				break;
			}
			flag = false;
		}
		if (p == "*="){
			Polinom res;
			first_monom[0].coeff = 15;
			first_monom[0].degX = 7;
			first_monom[0].degY = -2;
			first_monom[0].degZ = 1;

			second_monom[0].coeff = 4;
			second_monom[0].degX = -8;
			second_monom[0].degY = 5;
			second_monom[0].degZ = 9;
			Polinom first_polinom(first_monom, 1), second_polinom(second_monom, 1);

			cout << std::endl << first_polinom << " *= " << second_polinom << " = ";
			first_polinom *= second_polinom;
			std::cout << first_polinom << std::endl;
			flag = false;
		}
		if (flag)
			break;
	}
	return 0;
	
	
	
	
	
	
	
	
	
	
	
	/*Monom* first_monom = new Monom[1], * second_monom = new Monom[1];

	first_monom[0].coeff = 15;
	first_monom[0].degX = 7;
	first_monom[0].degY = -2;
	first_monom[0].degZ = 1;

	second_monom[0].coeff = 4;
	second_monom[0].degX = -8;
	second_monom[0].degY = 5;
	second_monom[0].degZ = 9;

	cout << "first_monom = " << first_monom[0] << "\nsecond_monom = " << second_monom[0] << endl;

	Polinom p(first_monom, 1), q(second_monom, 1);

	//TPolinom res = p + q;
	Polinom res;
	res += p;
	res += q;
	//sum(p, q, &res);


	cout << res << endl;

	delete[] first_monom;
	delete[] second_monom;

	return 0;*/
}