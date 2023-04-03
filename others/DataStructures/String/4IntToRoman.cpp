#include <bits/stdc++.h>
using namespace std;
string IntToRoman(int n)
{
    string ans="";
    int p;
    int num[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    int i=12;
    string str[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    while(n>0){
        p=n/num[i];
        n=n%num[i];
        while(p--)
            ans+=str[i];
        i--;
    }
    return ans;
}
int main()
{
    int n=1994;
    string ans=IntToRoman(n);
    cout<<ans;
}