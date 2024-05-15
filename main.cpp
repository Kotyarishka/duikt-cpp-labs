#include <iostream>
#include <set>
#include <string>

using namespace std;
class Square
{
private:
    double side;
    double area;
    // Your code here

public:
    Square(double side)
    {
        this -> side = side;
        this -> area = side * side;
    };

    void setSide(double side)
    {
        this->side = side;
        this->area = side * side;
    };
    double getSide()
    {
        return this->side;
    };

    double getArea()
    {
        return this->area;
    }
};

void print(Square* square)
{
    cout << "Square: side=" << square->getSide() << " area=" << square->getArea() << endl;
}
int main()
{
    Square s(4);
    print(&s);
    s.setSide(2);
    print(&s);
    s.setSide(-33.0);
    print(&s);
    return 0;
}