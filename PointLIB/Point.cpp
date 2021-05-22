#include "Point.h"

Point::Point(double _x, double _y) {
	x = _x;
	y = _y;
}

Point::Point(const Point& point) {
	x = point.x;
	y = point.y;
}

double Point::GetX() { return x; }

double Point::GetY() { return y; }

void Point::SetX(const double _x) { x = _x; }

void Point::SetY(const double _y) { y = _y; }

void Point::Show() { cout << "Point (" << x << ", " << y << ")" << endl; }

bool Point::operator == (Point& point) { return GetX() == point.GetX() && this->GetY() == point.GetY(); }

Point& Point::operator = (const Point& point) {
	if (this == &point) return *this;
	x = point.x;
	y = point.y;
	return *this;
}