#include <bits/stdc++.h>
using namespace std;
class Employee
{
public:
    int age, salary, id;
    string emp_name, dep;
};
int main()
{
    fstream f;
    f.open("emp.dat", ios::out);
    if (f.is_open())
        cout << "open";
    f.close();
    int ch = 0;
    do
    {
        cout << "1: insert\n2:display\n3: search\n4: delete\n5: edit\n6: sort\n7:exit\n";
        cout << "Choose your option: ";
        cin >> ch;
        if (ch == 1)
        {
            Employee emp;
            cout << "enter the id,name,age,salary,department";
            cin >> emp.id >> emp.emp_name >> emp.age >> emp.salary >> emp.dep;
        }
    } while (ch != 7);
}