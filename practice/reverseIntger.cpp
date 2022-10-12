#include<bits/stdc++.h>
using namespace std;
int reverseInt(int x) {
       int ans=0,num;
    num=abs(x);
    long long rev=0;
        int rem;
    while(num>0){
        rem=num%10;
        rev=rev*10+rem;
        num/=10;
    }
    if(x<0)
    rev=-rev;
    if(rev>2147483647 || rev<-2147483647)
        return 0;
    return rev;}
int main()
{
    int str=-120;
    cout<<reverseInt(str)<<endl;
}