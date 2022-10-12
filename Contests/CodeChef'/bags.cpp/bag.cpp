#include<bits/stdc++.h>
using namepace std;
struct obj
{
    int c,r,diff;
}
int maximumBags(vector<int>& cap, vector<int>& rocks, int add) {
    int n=cap.size();
    vector<int>diff(n);
    int cnt=0;
    for(int i=0;i<cap.size();i++)
    {
        diff[i]=cap[i]-rocks[i];
        if(diff[i]==0) cnt++;
    }
    sort(diff.begin(),diff.end());

    for(int i=0;i<n;i++)
    {
        if(diff[i]==0) continue;
        if(add>diff[i]) cnt++;
        if()
        else break;
        add-=diff[i];
    }
    return cnt;
}
int main()
{
}