#include <../gtest/gtest.h>

#include "Plex.h"
#include "Circle.h"

TEST(Point, can_create_point){
	ASSERT_NO_THROW(Point point);
}

TEST(Point, can_use_copy_constructor) {
	Point point(7, 5);
	ASSERT_NO_THROW(Point copy_point(point));
}

TEST(Point, can_get_first_coordinate){
	Point point(7, 5);
	EXPECT_TRUE(point.GetX() == 7);
}

TEST(Point, can_get_second_coordinate){
	Point point(7, 5);
	EXPECT_TRUE(point.GetY() == 5);
}

TEST(Point, can_set_first_coordinate){
	Point point(7, 5);
	EXPECT_TRUE(point.GetX() == 7);
	ASSERT_NO_THROW(point.SetX(6));
	EXPECT_TRUE(point.GetX() == 6);
}

TEST(Point, can_set_second_coordinate){
	Point point(7, 5);
	EXPECT_TRUE(point.GetY() == 5);
	ASSERT_NO_THROW(point.SetY(9));
	EXPECT_TRUE(point.GetY() == 9);
}



TEST(Line, can_create_line_without_throw_1){
	ASSERT_NO_THROW(Line line);
}

TEST(Line, can_create_line_without_throw_2){
	Point first_point(7, 5), second_point(4, 9);
	ASSERT_NO_THROW(Line line(&first_point, &second_point));
}

TEST(Line, can_create_line_without_throw_3){
	ASSERT_NO_THROW(Line line(7, 5, 4, 9));
}

TEST(Line, can_use_copy_constructor){
	Point first_point(7, 5), second_point(4, 9);
	Line line(&first_point, &second_point);
	ASSERT_NO_THROW(Line copy_line(line));
}

TEST(Line, can_set_first_point_x_correct){
	Line line;
	line.SetFirstPointX(7);
	EXPECT_EQ(line.GetFisrtPointX(), 7);
}

TEST(Line, can_set_first_point_y_correct){
	Line line;
	line.SetFirstPointY(5);
	EXPECT_EQ(line.GetFirstPointY(), 5);
}

TEST(Line, can_set_second_point_x_correct){
	Line line;
	line.SetSecondPointX(7);
	EXPECT_EQ(line.GetSecondPointX(), 7);
}

TEST(Line, can_set_second_point_y_correct){
	Line line;
	line.SetSecondPointY(5);
	EXPECT_EQ(line.GetSecondPointY(), 5);
}

TEST(Line, can_set_first_point_without_throws){
	Line line;
	Point point(7, 5);
	ASSERT_NO_THROW(line.SetFirstPoint(&point));
}

TEST(Line, can_set_second_point_without_throws){
	Line line;
	Point point(7, 5);
	ASSERT_NO_THROW(line.SetSecondPoint(&point));
}



TEST(Plex, can_create_plex_1){
	ASSERT_NO_THROW(Plex plex);
}

TEST(Plex, can_create_plex_2){
	Point* first_point, * second_point;
	first_point = new Point(7, 5);
	second_point = new Point(4, 9);
	ASSERT_NO_THROW(Plex plex(first_point, second_point));
}

TEST(Plex, can_create_copy_plex){
	Point* first_point, * second_point;
	first_point = new Point(7, 5);
	second_point = new Point(4, 9);
	Plex plex(first_point, second_point);
	ASSERT_NO_THROW(Plex copy_plex(plex));
}

TEST(Plex, can_add_line){
	Plex plex;
	Point* first_point, * second_point;
	first_point = new Point(7, 5);
	second_point = new Point(4, 9);
	ASSERT_NO_THROW(plex.Add(first_point, second_point));
}

TEST(Plex, throw_when_add_error_line) {
	Plex plex;
	Point* first_point, * second_point, * third_point, * fourth_point;
	first_point = new Point(7, 5);
	second_point = new Point(4, 9);
	third_point = new Point(3, 8);
	fourth_point = new Point(4, 1);
	plex.Add(first_point, second_point);
	ASSERT_ANY_THROW(plex.Add(third_point, fourth_point));
}

TEST(Plex, can_get_second_point) {
	Plex plex;
	Point* first_point, * second_point;
	first_point = new Point(7, 5);
	second_point = new Point(4, 9);
	plex.Add(first_point, second_point);
	EXPECT_TRUE(plex.GetPlexSecondPoint() == second_point);
}

TEST(Plex, can_get_first_point){
	Plex plex;
	Point* first_point, * second_point;
	first_point = new Point(7, 5);
	second_point = new Point(4, 9);
	plex.Add(first_point, second_point);
	EXPECT_TRUE(plex.GetPLexFirstPoint() == first_point);
}

TEST(Plex, can_set_second_point){
	Plex plex;
	Point* first_point, * second_point, * third_point;
	first_point = new Point(7, 5);
	second_point = new Point(4, 9);
	third_point = new Point(3, 8);
	plex.Add(first_point, second_point);
	EXPECT_TRUE(plex.GetPlexSecondPoint() == second_point);
	plex.SetPlexSecondPoint(third_point);
	EXPECT_TRUE(plex.GetPlexSecondPoint() == third_point);
}

TEST(Plex, can_set_first_point){
	Plex plex;
	Point* first_point, * second_point, * third_point;
	first_point = new Point(7, 5);
	second_point = new Point(4, 9);
	third_point = new Point(3, 8);
	plex.Add(first_point, second_point);
	EXPECT_TRUE(plex.GetPLexFirstPoint() == first_point);
	plex.SetPlexFirstPoint(third_point);
	EXPECT_TRUE(plex.GetPLexFirstPoint() == third_point);
}




TEST(Circle, can_create_circle_without_throws_1){
	ASSERT_NO_THROW(Circle circle);
}

TEST(Circle, can_create_circle_without_throws_2){
	Point point(7, 5);
	ASSERT_NO_THROW(Circle circle(&point, 1));
}

TEST(Circle, can_throw_when_create_circle_with_negative_radius_1){
	Point point(7, 5);
	ASSERT_ANY_THROW(Circle circle(&point, -1));
}

TEST(Circle, can_create_circle_without_throws_3){
	ASSERT_NO_THROW(Circle circle(7, 5, 1));
}

TEST(Circle, can_throw_when_create_circle_with_negative_radius_2){
	ASSERT_ANY_THROW(Circle circle(7, 5, -1));
}

TEST(Circle, can_use_copy_constructor){
	Circle circle(7, 5, 1);
	ASSERT_NO_THROW(Circle copy_circle(circle));
}

TEST(Circle, can_get_x_correct){
	Circle circle(7, 5, 1);
	EXPECT_EQ(circle.GetX(), 7);
}

TEST(Circle, can_get_y_correct){
	Circle circle(7, 5, 1);
	EXPECT_EQ(circle.GetY(), 5);
}

TEST(Circle, can_get_radius_correct){
	Circle circle(7, 5, 1);
	EXPECT_EQ(circle.GetRadius(), 1);
}

TEST(Circle, can_throw_if_set_negative_radius){
	Circle circle(7, 5, 1);
	ASSERT_ANY_THROW(circle.SetRadius(-1));
}

TEST(Circle, can_set_x_correct){
	Circle circle(7, 5, 1);
	circle.SetX(4);
	EXPECT_EQ(circle.GetX(), 4);
}

TEST(Circle, can_set_y_correct){
	Circle circle(7, 5, 1);
	circle.SetY(6);
	EXPECT_EQ(circle.GetY(), 6);
}

TEST(Circle, can_set_radius_correct){
	Circle circle(7, 5, 1);
	circle.SetRadius(9);
	EXPECT_EQ(circle.GetRadius(), 9);
}