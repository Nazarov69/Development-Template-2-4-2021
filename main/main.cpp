
#include "Plex.h"
#include "Circle.h"
int main(){
    cout << "__________________________Point__________________________" << endl;
    Point first_point(1, 1);
    cout << "First point (" << first_point.GetX() << ", " << first_point.GetY() << ")" << endl;
    
    Point second_point(2, 3);
    second_point.Show();

    Point copy_point(first_point);
    cout << "Copy point (" << copy_point.GetX() << ", " << copy_point.GetY() << ")" << endl;

    second_point.SetX(5); second_point.SetY(10);
    second_point.Show();

    cout << "__________________________Line__________________________" << endl;
    Line first_line;
    cout << "First line : (" << first_line.GetFisrtPointX() << ", " << first_line.GetFirstPointY() << ") (" << first_line.GetSecondPointX() << ", " << first_line.GetSecondPointY() << ")" << endl;

    Line second_line(&first_point, &second_point);
    second_line.Show();

    Line third_line(5, 7, 1, 8);
    third_line.Show();
   
    cout << third_line.GetFirstPoint()->GetX() << endl;
    cout << third_line.GetSecondPoint()->GetY() << endl;

    third_line.SetFirstPointX(9);
    cout << third_line.GetFisrtPointX() << endl;

    third_line.SetSecondPoint(&second_point);
    third_line.GetSecondPoint()->Show();
    return 0;


}
