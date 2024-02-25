/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.



Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> permuteUnique(vector<int> &str)
{
    int n = str.size();
    sort(str.begin(), str.end());
    vector<vector<int>> ans;
    do
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back(str[i]);
        }
        ans.push_back(v);
    } while (next_permutation(str.begin(), str.end()));
    return ans;
}
int main()
{
    // Your code here
    return 0;
}