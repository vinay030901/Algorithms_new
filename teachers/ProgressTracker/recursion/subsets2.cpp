/*Given an integer array nums that may contain duplicates, return all possible
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]


Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10*/
#include <bits/stdc++.h>
using namespace std;
void generate(vector<int> &arr, int ind, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for (int i = ind; i < arr.size(); i++)
    {
        // the main logic of our code is that we should not take repeating values, means that if I have 1 in vector, and next
        // values are 2 and 2, then we will take one 2 only, that is we will make (1,2) and skip the other two because it will
        // generate the same data structure
        if (i != ind && arr[i] == arr[i - 1])
            continue;
        ds.push_back(arr[i]);
        generate(arr, i + 1, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<int> ds;
    vector<vector<int>> ans;
    generate(arr, 0, ds, ans);
    return ans;
}
int main()
{
    // Your code here
    return 0;
}