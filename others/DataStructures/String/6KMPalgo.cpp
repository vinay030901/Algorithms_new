#include <bits/stdc++.h>
using namespace std;
void computeLPS(char *pat,int m,int *lps)
{
    int len=0,i=1;
    lps[0]=0;
    while(i<m)
    {
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;    
        }
        else{
            if(len!=0)
                len=lps[len-1];
            else{
            lps[i]=0;
            i++;
        }}
    }
}
void KMPSearch(char *txt,char *pat)
{
    int n=strlen(txt);
    int m=strlen(pat);
    int lps[m];
    computeLPS(pat,m,lps);
    int i=0,j=0;
    while(i<n){
        if(txt[i]==pat[j]){
            i++;
            j++;
        }
        if(j==m)
        {
            cout<<"found pattern at "<<i-j<<endl;
            j=lps[j-1];
        }
        else if(i<n && txt[i]!=pat[j]){
            if(j!=0)
                j=lps[j-1];
            else
                i+=1;
        }
        
    }
}

int main()
{
    char txt[]="ababcabcabababd";
    char pat[]="ababd";
    KMPSearch(txt,pat);
}