#include <bits/stdc++.h>
using namespace std;
class Numchecking
{
public:
    int n;
    Numchecking(int num)
    {
        n = num;
    }
    void final_check(int num)
    {
        if (n % 7 == 0)
            cout << "divisible by 7" << endl;
    }
    void check()
    {
        try
        {
            if (n % 2 == 0)
                cout << "it is even" << endl;
            else
                throw(n);
        }
        catch (int n)
        {
            try
            {
                if (n % 3 == 0)
                    cout << "Divisible by 3" << endl;
                else
                    throw(n);
            }
            catch (int n)
            {
                if (n % 5 == 0)
                    cout << "Divisible by 5" << endl;
                else
                    final_check(n);
            }
        }
    }
};
int main()
{
    int n;
    cout << "enter the number: ";
    cin >> n;
    Numchecking obj(n);
    obj.check();
}