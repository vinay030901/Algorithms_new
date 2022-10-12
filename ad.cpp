#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    int n;
    cin >> str;
    cin >> n;
    string state = "", serNum, vehNum, fullNum;
    vector<char> v(9,' ');
    string c="";
    c+=str[0];
    c+=str[1];
    state += v[2];
    if (str[3] <= 'A' && str[3] <= 'Z')
    {
        v[3] = str[3];
        state += v[3];
    }
    int num = 0;
    vector<int>v(5,0);
    for (int i = 4; i < str.length(); i++)
    {
        v[i] = str[i];
        num = num * 10 + (str[i] - '0');
    }
    while (n--)
    {
        cout<<c<<state<<num;
        num+=1;
        if(num==99999) num
    }
}