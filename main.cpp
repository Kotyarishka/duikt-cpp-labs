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

    void print()
    {
        cout << "Square: side=" << this->side << " area=" << this->area << endl;
    }

    void setSide(double side)
    {
        if (side < 0)
        {
            side = 0;
        }

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

int main()
{
    Square s(4);
    s.print();
    s.setSide(2);
    s.print();
    s.setSide(-33.0);
    s.print();
    return 0;
}