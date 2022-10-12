//find longest subarray with 0 sum*/
#include<bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int>vec, int n)
{
    int maxStreak=0;
    map<int,int>mp;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=vec[i];
        if(sum==0)
            maxStreak=i+1;
        if(mp.find(sum)!=mp.end())
        {
            maxStreak=max(maxStreak,i-mp[sum]);
        }
        else
            mp[sum]=i;
    }
    return maxStreak;
}
int main()
{
    vector<int>vec{1,-1,3,2,-2,-8,1,7,10,23};
    vector<int>vec1{15,-2,2,-8,1,7,10,23};
    int n=longestSubarray(vec1,vec.size());
    cout<<n;
}