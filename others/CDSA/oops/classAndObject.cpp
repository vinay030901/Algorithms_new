#include <iostream>
#include <string>
using namespace std;
class Person
{
    string name;
    int age;

public:
    void setName(string name)
    {
        this->name = name;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    string getName()
    {
        return name;
    }
    int getAge() { return age; }
};
int main()
{
    Person p1;
    p1.setName("John");
    p1.setAge(23);
    cout << p1.getName() << " " << p1.getAge() << endl;
}