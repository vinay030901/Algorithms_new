#include <bits/stdc++.h>
using namespace std;
int MyAtoi(string s)
{
    int n=0,i=0,sign=1;
    while(s[i]==' ')
        i++;
    if(s[i]=='-' || s[i]=='+')
    {
        sign=1-2*(s[i++]=='-');
    }
    while(s[i]>='0' && s[i]<='9'){
        if(n>INT_MAX/10 || (n==INT_MAX/10 && s[i]-'0'>7))
            {
                if(sign==1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
        n=n*10+s[i++]-'0';
    }
    return sign*n;
}
int main()
{
    string s="  a+123";
    int n=MyAtoi(s);
    cout<<n;
}