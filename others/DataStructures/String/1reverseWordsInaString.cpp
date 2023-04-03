#include <bits/stdc++.h>
using namespace std;
void reverseWords(string s)
{
    int i=0;
    int p=i,q;
    while(i<s.size()){
        if(s[i]==' '){
            q=i;
            reverse(s.begin()+p, s.begin()+q);
            p=i+1;
        }
        i++;
    }
    reverse(s.begin()+p, s.begin()+s.size()-1);
    cout<<s;
}
int main()
{
    string s="the champ is here!";
    reverseWords(s);
}