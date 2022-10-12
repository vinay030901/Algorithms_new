#include <bits/stdc++.h>
using namespace std;
int roman(char c){
        switch(c)
        {
            case 'M':
                return 1000;
            case 'D':
                return 500;
            case 'C':
                return 100;
            case 'L':
                return 50;
            case 'X':
                return 10;
            case 'V':
                return 5;
            case 'I':
                return 1;
        }
    return 0;
    }
int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(roman(s[i])<roman(s[i+1]))
                ans=ans-roman(s[i]);
            else
                ans+=roman(s[i]);
        }
        ans+=roman(s[s.length()-1]);
        return ans;
    }
int main()
{
    string str="L";
    int ans=romanToInt(str);
    cout<<ans<<endl;
}