/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]*/

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
void powerSet(int ind,vector<int>&arr,int n,vector<int>&v)
{
    // in this method, we used the same approach
    // that is either we take the elment or we don't take it
    // so here, we get the element, we add it to the vector, then we call recursive function by increasing the index
    // then we pop back our element and call the recursive function for it too
    // when we reach the end of the index, we push the vector into tbe answer
    if(ind==n)
    {
        ans.push_back(v);
        return;
    }
    v.push_back(arr[ind]);
    powerSet(ind+1,arr,n,v);
    v.pop_back();
    powerSet(ind+1,arr,n,v);
}
vector<vector<int>> subsets(vector<int>& arr) {
    vector<int>v;
    powerSet(0,arr,arr.size(),v);
    return ans;
}

//another method using this 
vector<vector<int>>powerset;
vector<int>sets;
void generateSets(vector<int>&nums,int n)
{
    powerset.push_back(sets);
    for(int i=n;i<nums.size();i++)
    {
        sets.push_back(nums[i]);
        generateSets(nums,i+1);
        sets.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    generateSets(nums,0);
    return powerset;
}
int main()
{
    vector<int>arr={1,2,3};
    vector<vector<int>>ans=subsets(arr);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
}