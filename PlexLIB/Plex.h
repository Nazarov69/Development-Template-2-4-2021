#include "Point.h"
#include "Line.h"
#include <stack>

class Plex : public Point {
protected:
	Point* plex_first_point;
	Point* plex_second_point;
public:
	Plex();
	Plex(Point* _plex_second_point, Point* _plex_first_point);
	Plex(const Plex& plex);

	Point* GetPLexFirstPoint();
	Point* GetPlexSecondPoint();

	void Add(Point* _plex_second_point, Point* _plex_first_point);
	void SetPlexFirstPoint(Point* _plex_first_point);
	void SetPlexSecondPoint(Point* _plex_second_point);

	Point* Show(Plex* plex);
};

