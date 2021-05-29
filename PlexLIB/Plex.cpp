#include "Plex.h"

Plex::Plex() {
	plex_first_point = NULL;
	plex_second_point = NULL;
}

Plex::Plex(Point* _plex_second_point, Point* _plex_first_point) {
	plex_first_point = _plex_first_point;
	plex_second_point = _plex_second_point;
}

Plex::Plex(const Plex& plex) {
	Plex* copy_first_point = dynamic_cast <Plex*> (plex.plex_first_point);
	Plex* copy_second_point = dynamic_cast <Plex*> (plex.plex_second_point);

	if (copy_first_point != NULL) { plex_first_point = new Plex(*copy_first_point); }
	else { plex_first_point = new Point(*plex.plex_first_point); }

	if (copy_second_point != NULL) { plex_second_point = new Plex(*copy_second_point); }
	else { plex_second_point = new Point(*plex.plex_second_point); }
}

Point* Plex::GetPLexFirstPoint() { return plex_first_point; }

Point* Plex::GetPlexSecondPoint() { return plex_second_point; }

void Plex::Add(Point* _plex_second_point, Point* _plex_first_point) {
	if (plex_first_point == NULL && plex_second_point == NULL) {
		plex_first_point = _plex_first_point;
		plex_second_point = _plex_second_point;
	}
	else {
		stack<Point*> stack_point;
		stack<Plex*> stack_plex;

		stack_point.push(plex_second_point);
		stack_point.push(plex_first_point);
		stack_plex.push(this);
		stack_plex.push(this);
		bool flag = true;

		while (flag && (!stack_point.empty() || !stack_plex.empty())) {
			Point* point = stack_point.top();
			stack_point.pop();
			Plex* plex = dynamic_cast <Plex*> (point);
			Plex* supp_plex = stack_plex.top();
			stack_plex.pop();
			if (point->GetX() == _plex_second_point->GetX() && point->GetY() == _plex_second_point->GetY()) {
				if (supp_plex->plex_first_point == point) { supp_plex->plex_first_point = new Plex(_plex_first_point, _plex_second_point); }
				else { supp_plex->plex_second_point = new Plex(_plex_first_point, _plex_second_point); }
				flag = false;
			}
			else if (point->GetX() == _plex_first_point->GetX() && point->GetY() == _plex_first_point->GetY()) {
				if (supp_plex->plex_first_point == point) { supp_plex->plex_first_point = new Plex(_plex_second_point, _plex_first_point); }
				else { supp_plex->plex_second_point = new Plex(_plex_second_point, _plex_first_point); }
				flag = false;
			}
			else if (plex != NULL) {
				stack_point.push(plex->plex_first_point);
				stack_point.push(plex->plex_second_point);
				stack_plex.push(plex);
				stack_plex.push(plex);
			}
		}
		if (flag) throw logic_error("error line");
	}
}

void Plex::SetPlexFirstPoint(Point* _plex_first_point) { plex_first_point = _plex_first_point; }
 
void Plex::SetPlexSecondPoint(Point* _plex_second_point) { plex_second_point = _plex_second_point; }

Point* Plex::Show(Plex* plex) {
	if (plex->plex_first_point == NULL && plex->plex_second_point == NULL) throw logic_error("plex is empty");
	Plex* plex_first, * plex_second;
	Point* point_first, * point_second;
	plex_first = dynamic_cast <Plex*> (plex->plex_first_point);
	plex_second = dynamic_cast <Plex*> (plex->plex_second_point);

	if (plex_first != NULL) { point_first = Show(plex_first); }
	else { point_first = plex->plex_first_point; }

	if (plex_second != NULL) { point_second = Show(plex_second); }
	else { point_second = plex->plex_second_point; }

	Line line(point_first, point_second);
	line.Show();
	return point_first;
}


