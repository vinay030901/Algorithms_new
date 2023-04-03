#include<bits/stdc++.h>
using namespace std;
int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mn;
        for(int i=0;i<nums.size();i++)
            mn.push({nums[i],i});
        while(k!=0)
        {
            auto n=mn.top();
            mn.pop();
            if(n.first==0)
                k=0;
            nums[n.second]*=(-1);
            k--;
            mn.push({nums[n.second],n.second});
            for(int i=0;i<nums.size();i++)
                cout<<nums[i]<<" ";
            cout<<endl;
        }
        for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
        cout<<endl;
        int sum=accumulate(nums.begin(),nums.end(),0);
        return sum;
    }
int main()
{
    vector<int>nums={2,-3,-1,4,-4};
    cout<<largestSumAfterKNegations(nums,2);
}