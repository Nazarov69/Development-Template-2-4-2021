#include "Line.h"

Line::Line() {
	first_point = new Point();
	second_point = new Point();
	del_flag_first_point = false;
	del_flag_second_point = false;
}

Line::Line(const Point* _first_point, const Point* _second_point) {
	first_point = new Point(*_first_point);
	second_point = new Point(*_second_point);
	del_flag_first_point = false;
	del_flag_second_point = false;
}

Line::Line(const double _first_point_x, const double _first_point_y, const double _second_point_x, const double _second_point_y) {
	first_point = new Point(_first_point_x, _first_point_y);
	second_point = new Point(_second_point_x, _second_point_y);
	del_flag_first_point = false;
	del_flag_second_point = false;
}

Line::Line(const Line& line) {
	first_point = new Point(*line.first_point);
	second_point = new Point(*line.second_point);
	del_flag_first_point = false;
	del_flag_second_point = false;
}

Line::~Line() {
	if (!del_flag_first_point) { delete first_point; }
	if (!del_flag_second_point) { delete second_point; }
}

double Line::GetFisrtPointX() { return first_point->GetX(); }

double Line::GetFirstPointY() { return first_point->GetY(); }

double Line::GetSecondPointX() { return second_point->GetX(); }

double Line::GetSecondPointY() { return second_point->GetY(); }

Point* Line::GetFirstPoint() { return first_point; }

Point* Line::GetSecondPoint() { return second_point; }
 
void Line::SetFirstPointX(const double _first_point_x) { first_point->SetX(_first_point_x); }

void Line::SetFirstPointY(const double _first_point_y) { first_point->SetY(_first_point_y); }

void Line::SetSecondPointX(const double _second_point_x) { second_point->SetX(_second_point_x); }
 
void Line::SetSecondPointY(const double _second_point_y) { second_point->SetY(_second_point_y); }

void Line::SetFirstPoint(Point* _first_point){
	if (first_point != NULL) { delete first_point; }
	first_point = _first_point;
	del_flag_first_point = true;
}

void Line::SetSecondPoint(Point* _second_point) {
	if (second_point != NULL) { delete second_point; }
	second_point = _second_point;
	del_flag_second_point = true;
}

void Line::Show() { cout << "Line : (" << first_point->GetX() << ", " << first_point->GetY() << ") (" << second_point->GetX() << ", " << second_point->GetY() << ")" << endl; }

