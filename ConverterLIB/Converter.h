#ifndef INCLUDE_CONVERTOR_H_
#define INCLUDE_CONVERTOR_H_

#include <string>
#include <map>
#include <iostream>
using namespace std;

struct roman {
	string value;
};

struct arabic {
	int value;
};

class Converter {
public:
	arabic fromRomanToArabic(roman romanValue);
	roman fromArabicToRoman(arabic arabicValue);

	bool checkRoman(roman& romanValue);   
	bool checkArabic(arabic& arabicValue);
};


arabic Converter::fromRomanToArabic(roman romanValue) {
	map<char, int> rome = {
	   {'I', 1},
	   {'V', 5},
	   {'X', 10},
	   {'L', 50},
	   {'C', 100},
	   {'D', 500},
	   {'M', 1000},

	};

	arabic timeValue = { 0 };
	arabic result = { 0 };
	int arabicValue = 0;

	for (char NumChar : romanValue.value) {
		arabicValue = rome[NumChar];
		if (arabicValue <= timeValue.value) {
			result.value += timeValue.value;
			timeValue.value = arabicValue;
		}
		else {
			if (timeValue.value == 0)
				timeValue.value = arabicValue;
			else {
				result.value += (arabicValue - timeValue.value);
				timeValue.value = 0;
			}
		}

	}
	result.value += timeValue.value;
	return result;

}

inline roman Converter::fromArabicToRoman(arabic arabicValue) {
	map <int, string> arab = {
		{1000,"M"},
		{900, "CM"},
		{500, "D"},
		{400, "CD"},
		{100, "C"},
		{90, "XC"},
		{50, "L"},
		{40, "XL"},
		{10, "X"},
		{9, "IX"},
		{5, "V"},
		{4, "IV"},
		{1, "I"},
	};

	int Array[] = { 
		1000, 
		900, 
		500, 
		400, 
		100, 
		90, 
		50, 
		40, 
		10, 
		9, 
		5, 
		4, 
		1 
	};

	string result = "";

	for (int timeInt : Array) {
		while (arabicValue.value >= timeInt) {
				result += arab[timeInt];
				arabicValue.value -= timeInt;
		}
	}
	return roman{ result };
}

inline bool Converter::checkArabic(arabic& arabicValue) {
	if (fromRomanToArabic(fromArabicToRoman(arabicValue)).value == arabicValue.value)
		return true;
	else {
		arabicValue.value = fromRomanToArabic(fromArabicToRoman(arabicValue)).value;
		return false;
	}
}

inline bool Converter::checkRoman(roman& romanValue) {
	if (fromArabicToRoman(fromRomanToArabic(romanValue)).value == romanValue.value)
		return true;
	else {
		romanValue.value = fromArabicToRoman(fromRomanToArabic(romanValue)).value;
		return false;
	}
}


#endif  // INCLUDE_CONVERTOR_H_