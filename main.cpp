#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    string name;
    int age;
};

void print(Person* p)
{
    cout << p->name << " is " << p->age << " years old." << endl;
}

int main()
{
    Person p1;
    p1.name = "Alice";
    p1.age = 30;

    Person p2;
    p2.name = "Bob";
    p2.age = 40;

    print(&p1);
    print(&p2);

    return 0;
}
