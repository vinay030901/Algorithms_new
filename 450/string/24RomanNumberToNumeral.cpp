/*
Given a Roman numeral, the task is to find its corresponding decimal value.

Example :

Input: IX
Output: 9
IX is a Roman symbol which represents 9

Input: XL
Output: 40
XL is a Roman symbol which represents 40

Input: MCMIV
Output: 1904
M is a thousand,
CM is nine hundred and
IV is four

  I            1
  IV           4
  V            5
  IX           9
  X            10
  XL           40
  L            50
  XC           90
  C            100
  CD           400
  D            500
  CM           900
  M            1000*/
#include <bits/stdc++.h>
using namespace std;
int fun(char ch)
{
    switch (ch)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    }
    return 0;
}
int main()
{
    string str = "MCMIV";
    int ans = 0;
    int n = str.length();
    for(int i=0;i<n;i++)
    {
        if(fun(str[i])<fun(str[i+1]))
        {
            ans+=(fun(str[i+1])-fun(str[i]));
            i++;
        }
        else ans+=fun(str[i]);
    }
    cout << ans;
}
// 5-1 =4  1000-100=900+1000