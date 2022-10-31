#include <bits/stdc++.h>
using namespace std;
main(){
        vector <long long> v;
        int a[26]={0};
        long long i,j;
        string s;
        cin>>s; 
        long long  len=s.length();
        for(i=0;i<len;i++){
            long long  temp=s[i];
            a[temp-65]++;
        }
        for(i=0;i<26;i++) v.push_back(a[i]);
        sort(v.begin(),v.end());
        long long cost=INT_MAX;
        for(i=26;i>0;i--){
            if((len%i)!=0) continue;
            long long fre=len/i,temp=len;
            for(j=v.size()-1;j>=v.size()-i&&j>=0;j--){
                if(v[j]>fre) temp-=fre;
                else temp-=v[j]; 
            }if(cost>temp) cost=temp;
        }
        cout<<cost<<endl;
    }