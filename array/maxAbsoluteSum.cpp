#include<bits/stdc++.h>
using namespace std;
int maxAbsoluteSum(vector<int>& arr) {
        int currentSumMax=0,currentSumMin=0,mx=0;
        int n=arr.size();
    for(int i=0;i<n;i++)
    {
        currentSumMax+=arr[i];
        currentSumMin+=arr[i];
        mx=max(mx,max(currentSumMax,abs(currentSumMin)));
        if(currentSumMin>0)
            currentSumMin=0;
        if(currentSumMax<0)
            currentSumMax=0;
    }
        return mx;
    }
int main()
{
    vector<int>v={-1,2,-4,3,-4,-6,-7,4};
    cout<<maxAbsoluteSum(v);
}