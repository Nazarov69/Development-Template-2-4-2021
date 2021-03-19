#include <iostream>
#include <stack>
using namespace std;
const int LENGTH = 7;

class Spreadsheet_1 {
	int array[LENGTH];
	stack<int> st;
public:
	Spreadsheet_1(int const_array[]) {
		for (int i = 0; i < LENGTH; i++)
			array[i] = const_array[i];
	}

	void CreateMaxArray() {
		st.push(0);
		for (int curr = 1; curr < LENGTH; curr++){
			if (array[curr] > array[curr - 1]) {
				st.pop();
				st.push(curr);
				array[curr - 1] = array[curr];
			}
			else {
				st.push(curr);
				continue;
			}
			st.pop();
			while (st.size() > 0 && array[curr] > array[st.top()]) {
				array[st.top()] = array[curr];
				st.pop();
			}
			st.push(curr);
		}
		int length = st.size();
		for (int i = 0; i < length; i++){
				array[st.top()] = 0;
				st.pop();
		}
	}

	void GetArray() {
		cout << "array : ";
		for (int i = 0; i < LENGTH; i++) { cout << array[i] << " "; }
		cout << endl;
	}
};