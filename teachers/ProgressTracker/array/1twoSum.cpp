#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        if(mp.find(target-arr[i])!=mp.end()) return {mp[target-arr[i]],i};
        else mp[arr[i]]=i;
        return {};
    }
};