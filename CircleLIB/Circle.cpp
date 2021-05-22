#include "Circle.h"

Circle::Circle() {
	center = new Point();
	radius = 1;
}

Circle::Circle(const Point* point, double _radius) {
	if (_radius <= 0) { throw logic_error("Error radius"); }

	center = new Point(*point);
	radius = _radius;
}

Circle::Circle(const double _x, const double _y, const double _radius) {
	if (_radius <= 0) { throw logic_error("Error radius"); }
	center = new Point(_x, _y);
	radius = _radius;
}

Circle::Circle(const Circle& circle) {
	center = new Point(*circle.center);
	radius = circle.radius;
}

Circle::~Circle() {
	if (center != NULL) { delete center; }
	radius = 0;
}

double Circle::GetX() { return center->GetX(); }

double Circle::GetY() { return center->GetY(); }

double Circle::GetRadius() { return radius; }

void Circle::SetX(const double _x) { center->SetX(_x); }

void Circle::SetY(const double _y) { center->SetY(_y); }

void Circle::SetRadius(const double _radius) {
	if (_radius <= 0) { throw logic_error("Error radius"); }
	radius = _radius;
}

void Circle::Show() {
	cout << "Circle : ";
	cout << "center : "; center->Show();
	cout << "radius :" << radius << endl;
}