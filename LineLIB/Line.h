#pragma once
#include "Point.h"

class Line : public Point {
protected:
	Point* first_point;
	Point* second_point;
	bool del_flag_first_point;
	bool del_flag_second_point;
public:
	Line();
	Line(const Point* _first_point, const Point* _second_point);
	Line(const double _first_point_x, const double _first_point_y, const double _second_point_x, const double _second_point_y);
	Line(const Line& line);
	virtual ~Line();

	double GetFisrtPointX();
	double GetFirstPointY();
	double GetSecondPointX();
	double GetSecondPointY();
	Point* GetFirstPoint();
	Point* GetSecondPoint();

	void SetFirstPointX(const double _first_point_x);
	void SetFirstPointY(const double _first_point_y);
	void SetSecondPointX(const double _second_point_x);
	void SetSecondPointY(const double _second_point_y);
	void SetFirstPoint(Point* _first_point);
	void SetSecondPoint(Point* _second_point);

	void Show() override;
};