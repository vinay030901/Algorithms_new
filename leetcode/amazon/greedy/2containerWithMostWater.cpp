/*
11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line 
are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int i=0,j=arr.size()-1;
        int mx=0;
        while(i<j)
        {
            mx=max(min(arr[i],arr[j])*(j-i),mx);
            if(arr[i]<=arr[j]) i++;
            else j--;
        }
        return mx;
    }
};
int main()
{

}