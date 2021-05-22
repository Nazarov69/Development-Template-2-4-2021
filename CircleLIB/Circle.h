#include "Point.h"

class Circle {
protected:
	Point* center;
	double radius;
public:
	Circle();
	Circle(const Point* point, const double _radius);
	Circle(const double _x, const double _y, const double _radius);
	Circle(const Circle& circle);
	virtual ~Circle();

	double GetX();
	double GetY();
	double GetRadius();

	void SetX(const double _x);
	void SetY(const double _y);
	void SetRadius(const double radius);

	void Show() ;
};