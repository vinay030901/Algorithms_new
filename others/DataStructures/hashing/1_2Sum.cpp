//given an array of integers and a target, return the indices so that they add up to the target sum. */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //our simple approach would be take a number from the array and check if (target-number) is in the map or not
    //if not we will put that number in the map with its index, and traverse the whole array to find that unique pair
    vector<int>nums{2,6,5,8,11};
    int target=8;
    vector<int>ans;
    unordered_map<int, int>mp;
    for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
            }
            mp[nums[i]]=i;
        }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}