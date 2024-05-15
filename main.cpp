#include <iostream>
#include <set>
#include <string>

using namespace std;
class Square
{
private:
    double side;
    double area;
    bool wasChanged;
    // Your code here

public:
    Square(double side)
    {
        this -> side = side;
        this -> area = side * side;

        this -> wasChanged = false;
    };

    void print()
    {
        cout << "Square: side=" << this->side << ", area=" << this->area <<  ", was changed=" << this -> wasChanged << endl;
    }

    void setSide(double side)
    {
        if (side < 0)
        {
            side = 0;
        }

        this->side = side;
        this->area = side * side;
        this->wasChanged = true;
    };
    double getSide()
    {
        return this->side;
    };

    double getArea()
    {
        return this->area;
    }

    bool getWasChanged()
    {
        return this->wasChanged;
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