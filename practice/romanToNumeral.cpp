#include<bits/stdc++.h>
using namespace std;
int roman(char ch)
{
    switch(ch){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 1;
    }
}
int main()
{
    string str;
    cin>>str;
    int n=str.size();
    int total = roman(str[0]);
    for(int i=1;i<n;i++)
    {
        if(roman(str[i])<roman(str[i+1]))
            
    }
    cout<<total<<endl;
}