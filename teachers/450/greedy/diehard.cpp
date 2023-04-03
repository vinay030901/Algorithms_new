#include<bits/stdc++.h>
using namespace std;
/*int t[1001][1001]={-1};
int maxDays(int h,int a,int flag)
{
    if(h<=0 || a<=0)
    return 0;
    if(t[h][a]==-1)
    return t[h][a];
    if(flag==1){
    return t[h][a]=1+maxDays(h+3,a+2,0);}
    else{
    return t[h][a]=1+max(maxDays(h-5,a-10,1),maxDays(h-20,a+5,1));}
}*/
int find(int h,int a)
{
    char last='x';
    int time=0;
    while(h>0 && a>0)
    {
        if(last=='x' || last=='f' || last=='w')
        {
            h=h+3;
            a=a+2;
            last='a';
            time++;
        }
        else if(last=='a')
        {
            if(h-5>0 && a-10>0)
            {
                h=h-5;
                a=a-10;
                last='w';
                time++;
            }
            else if(h-20>0)
            {
                h=h-20;
                a=a+5;
                last='f';
                time++;
            }
            else
            break;
        }
    }
    return time;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
    int h,a,flag=1;
    cin>>h>>a;
    cout<<find(h,a)<<"\n";
}}