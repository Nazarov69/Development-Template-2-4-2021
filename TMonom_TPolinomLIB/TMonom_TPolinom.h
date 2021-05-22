#pragma once
#include "TList.h"

struct Monom {
	double coeff = 0;
	int degX = 0, degY = 0, degZ = 0;
};

bool operator<(const Monom& first_monom, const Monom& second_monom) {
	if (&first_monom == NULL || &second_monom == NULL) return false;

	if (first_monom.degX < second_monom.degX) return true;
	else if (first_monom.degX == second_monom.degX) {
		if (first_monom.degY < second_monom.degY) return true;
		else if (first_monom.degY == second_monom.degY) {
			if (first_monom.degZ < second_monom.degZ) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}

bool operator>(const Monom& first_monom, const Monom& second_monom) {
	if (&first_monom == NULL || &second_monom == NULL) return false;

	if (first_monom.degX > second_monom.degX) return true;
	else if (first_monom.degX == second_monom.degX) {
		if (first_monom.degY > second_monom.degY) return true;
		else if (first_monom.degY == second_monom.degY) {
			if (first_monom.degZ > second_monom.degZ) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}

bool operator==(const Monom& first_monom, const Monom& second_monom) {
	if (&first_monom == NULL || &second_monom == NULL) return false;

	if (first_monom.degX == second_monom.degX && first_monom.degY == second_monom.degY && first_monom.degZ == second_monom.degZ) return true;
	else return false;
}

bool operator>=(const Monom& first_monom, const Monom& second_monom) { return !(first_monom < second_monom); }

bool operator<=(const Monom& first_monom, const Monom& second_monom) { return !(first_monom > second_monom); }

bool operator!=(const Monom& first_monom, const Monom& second_monom) { return !(first_monom == second_monom); }

Monom operator+(const Monom& first_monom, const Monom& second_monom) {
	if (first_monom.degX != second_monom.degX || first_monom.degY != second_monom.degY || first_monom.degZ != second_monom.degZ) 
		throw logic_error("Degrees of these monoms are different");
	
	Monom result;
	result.degX = first_monom.degX;
	result.degY = first_monom.degY;
	result.degZ = first_monom.degZ;
	result.coeff = first_monom.coeff + second_monom.coeff;

	return result;
}

Monom operator-(const Monom& first_monom, const Monom& second_monom) {
	if (first_monom.degX != second_monom.degX || first_monom.degY != second_monom.degY || first_monom.degZ != second_monom.degZ) 
		throw logic_error("Degrees of these monoms are different");
	
	Monom result;
	result.degX = first_monom.degX;
	result.degY = first_monom.degY;
	result.degZ = first_monom.degZ;
	result.coeff = first_monom.coeff - second_monom.coeff;

	return result;
}

Monom operator*(const Monom& first_monom, const Monom& second_monom) {
	Monom result;
	result.degX = first_monom.degX + second_monom.degX;
	result.degY = first_monom.degY + second_monom.degY;
	result.degZ = first_monom.degZ + second_monom.degZ;
	result.coeff = first_monom.coeff * second_monom.coeff;

	return result;
}

Monom operator/(const Monom& first_monom, const Monom& second_monom) {
	Monom result;
	result.degX = first_monom.degX - second_monom.degX;
	result.degY = first_monom.degY - second_monom.degY;
	result.degZ = first_monom.degZ - second_monom.degZ;
	result.coeff = first_monom.coeff / second_monom.coeff;

	return result;
}

Monom operator*(const Monom& monom, const double size) {
	Monom result;
	result.degX = monom.degX;
	result.degY = monom.degY;
	result.degZ = monom.degZ;
	result.coeff = monom.coeff * size;

	return result;
}

ostream& operator<<(ostream& out, const Monom& monom) {
	out << monom.coeff << " x^" << monom.degX << " y^" << monom.degY << " z^" << monom.degZ;
	return out;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Polinom : public HeadList<Monom> {
public:
	Polinom() : HeadList<Monom>() {
		pHead->value.coeff = 0;
		pHead->value.degZ = -1;
	}

	Polinom(Monom* monom, int size) : HeadList<Monom>() {
		pHead->value.coeff = 0;
		pHead->value.degZ = -1;

		for (int i = 0; i < size; i++)
			InsertLast(monom[i]);
	}

	Polinom(Polinom& polinom) : HeadList<Monom>() {
		pHead->value.coeff = 0;
		pHead->value.degZ = -1;

		for (polinom.Reset(); !polinom.IsEnd(); polinom.GoNext()) 
		{ InsertLast(polinom.pCurr->value); }
	}

	

	void InsertByOrder(const Monom& monom);

	Polinom operator*(const double a);
	Polinom operator*(const Monom& monom);
	Polinom operator*(Polinom& polinom);
	//Polinom operator*(Polinom& polinom);

	Polinom& operator=(Polinom& polinom);
	void operator*=(const double size);
	void operator*=(const Monom& monom);
	Polinom& operator *=(const Polinom& polinom);

	void operator+=(Polinom& polinom);
	Polinom operator+(Polinom &polinom);

	void operator-=(Polinom& polinom);
	Polinom operator-(Polinom &polinom);
	

	bool IsStart() { return pCurr == pFirst; }
	double GetCoeff() { return pCurr->value.coeff; }
	int GetX() { return pCurr->value.degX; }
	int GetY() { return pCurr->value.degY; }
	int GetZ() { return pCurr->value.degZ; }
	bool IsEmpty() { return pFirst == NULL; }
	string GetString();

	friend ostream& operator<<(ostream& out, Polinom& polinom) {
		for (polinom.Reset(); !polinom.IsEnd(); polinom.GoNext()){
			out << polinom.pCurr->value << ' ';
		}
		if (!polinom.size)
			out << "Polinom empty";
		return out;
		
		
		/*if (polinom.size) {
			for (polinom.Reset(); !polinom.IsEnd(); polinom.GoNext()) {
				out << polinom.pCurr->value << " + ";
			}
			out << ".";
		}
		else
			out << "0 .";
		return out;*/
	}

protected:
	void NormalView();
};

Polinom& Polinom::operator=(Polinom& polinom) {
	while (size) { DeleteFirst(); }

	for (polinom.Reset(); !polinom.IsEnd(); polinom.GoNext()) { InsertLast(polinom.pCurr->value); }

	return *this;
}

void Polinom::InsertByOrder(const Monom& monom) {
	if (monom.coeff == 0)
		return;

	if (!size) {
		InsertFirst(monom);
		return;
	}

	for (Reset(); !IsEnd(); GoNext()) {
		if (pCurr->value == monom) {
			pCurr->value.coeff += monom.coeff;
			if (pCurr->value.coeff == 0)
				DeleteCurr();
			return;
		}
		if (pCurr->value < monom) {
			InsertCurr(monom);
			return;
		}
	}
	InsertLast(monom);
}

Polinom Polinom::operator*(const double _size) {
	Polinom result;
	for (Reset(); !IsEnd(); GoNext()) result.InsertByOrder(pCurr->value * _size);
	return result;
}

void Polinom::operator*=(const double _size) { for (Reset(); !IsEnd(); GoNext()) pCurr->value.coeff *= _size; }

void Polinom::operator+=(Polinom& polinom) {
	if (size && polinom.size) {
		Reset();
		polinom.Reset();
		while (!IsEnd() || !polinom.IsEnd()) {
			if (pCurr->value == polinom.pCurr->value) {
				pCurr->value.coeff += polinom.pCurr->value.coeff;
				if (pCurr->value.coeff == 0) {
					DeleteCurr();
					polinom.GoNext();
				}
				else {
					GoNext();
					polinom.GoNext();
				}
			}
			else if (pCurr->value < polinom.pCurr->value) {
				InsertCurr(polinom.pCurr->value);
				polinom.GoNext();
			}
			else
				GoNext();
		}
	}
	else if (!size && polinom.size) {
		for (polinom.Reset(); !polinom.IsEnd(); polinom.GoNext())
			InsertByOrder(polinom.pCurr->value);
	}

	//for (polinom.Reset(); !polinom.IsEnd(); polinom.GoNext()) InsertByOrder(polinom.pCurr->value);
}

Polinom Polinom::operator+(Polinom &polinom) {
	Polinom result;
	result += *this;
	result += polinom;
	return result;
}

void Polinom::operator-=(Polinom& polinom) {
	if (!polinom.size) return;

	polinom *= -1.0;
	*this += polinom;
	polinom *= -1.0;
}


Polinom Polinom::operator-(Polinom& polinom) { return *this + (polinom * -1); }

void Polinom::operator*=(const Monom& monom) { for (Reset(); !IsEnd(); GoNext()) pCurr->value = pCurr->value * monom; }

Polinom Polinom::operator*(Polinom& polinom) {
	Polinom* result = new Polinom();

	for (polinom.Reset(); !polinom.IsEnd(); polinom.GoNext()) {
		Polinom item = *this;
		*result += item * polinom.pCurr->value;
	}

	return *result;
}

Polinom Polinom::operator*(const Monom& monom) {
	Polinom* result = new Polinom();

	for (Reset(); !IsEnd(); GoNext()) result->InsertByOrder(pCurr->value * monom);

	return *result;
}

Polinom& Polinom:: operator *=(const Polinom& polinom){
	Polinom this_(*this);
	List<Monom>::~List();
	for (this_.Reset(); !this_.IsEnd(); this_.GoNext()){
		Link<Monom>* curr = polinom.pFirst;
		Polinom tmp;
		while (curr != polinom.pStop){
			tmp.InsertLast(this_.pCurr->value * curr->value);
			curr = curr->pNext;
		}
		*this += tmp;
	}
	return *this;
}

/*Polinom Polinom::operator*(Polinom &polinom) {
	Polinom result;
	for (Reset(); !IsEnd(); GoNext()) {
		for (polinom.Reset(); !polinom.IsEnd(); polinom.GoNext()) {
			result.InsertByOrder(pCurr->value * polinom.pCurr->value);
		}
	}
	return result;
}*/

void Polinom::NormalView() {
	Polinom polinom;

	for (Reset(); !IsEnd(); GoNext()) polinom.InsertFirst(pCurr->value);

	while (size != 0) DeleteFirst();

	for (polinom.Reset(); !polinom.IsEnd(); polinom.GoNext()) InsertByOrder(polinom.pCurr->value);
}

void sum(Polinom& first_polinom, Polinom& second_polinom, Polinom& result) {
	result += first_polinom;
	result += second_polinom;
}

string Polinom::GetString() {
	if (IsEmpty()) return "0";

	string str = "";

	for (Reset(); !IsEnd(); GoNext()) {
		if (!IsStart() && GetCoeff() > 0)
			str += "+";

		if (GetCoeff() != 1 || (!GetX() && !GetY() && !GetZ()))
			str += GetCoeff();

		if (GetX())
			if (GetX() > 1) {
				str += " x^";
				str += GetX();
			}
			else str += "x";

		if (GetY())
			if (GetY() > 1) {
				str += " y^";
				str += GetY();
			}
			else str += "y";

		if (GetZ())
			if (GetZ() > 1) {
				str += "z^";
				str += GetZ();
			}
			else str += "z";

	}

	return str;
}