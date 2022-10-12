#include<bits/stdc++.h>
using namespace std;
bool isRotate(string str1,string str2) {
    if(str1.length()!=str2.length())
    return false;
    string a=str1+str1;
    cout<<a<<endl;
    if(a.find(str2)!=string::npos)
    return true;
    else return false;
}
int main()
{
    string str1="abcd",str2="cdab";
    cout<<isRotate(str1,str2)<<endl;
}