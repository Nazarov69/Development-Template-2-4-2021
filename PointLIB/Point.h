#pragma once
#include <iostream>
using namespace std;

class Point {
protected: 
	double x;
	double y;
public:
	Point(double _x = 0, double _y = 0);
	Point(const Point& point);

	double GetX();
	double GetY();

	void SetX(double _x);
	void SetY(double _y);
	 
	virtual void Show();

	bool operator == (Point& point);
	Point& operator = (const Point& point);
};