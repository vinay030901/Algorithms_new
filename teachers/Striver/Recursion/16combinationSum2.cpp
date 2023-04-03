/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates
where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]*/
#include <bits/stdc++.h>
using namespace std;

// this approach is similar to above combination sum question and therefore we here just simply added a set here, so that we don't get
// the same results, because we need to unique results here.
// but this method takes extra time and therefore fails in time limit tests.
set<vector<int>> ans;
void combination(vector<int> &arr, int ind, int sum, int n, vector<int> &v)
{
    if (ind == n)
    {
        if (sum == 0)
        {
            ans.insert(v);
        }
        return;
    }
    if (sum >= arr[ind])
    {
        v.push_back(arr[ind]);
        combination(arr, ind + 1, sum - arr[ind], n, v);
        v.pop_back();
    }
    combination(arr, ind + 1, sum, n, v);
}
vector<vector<int>> combinationSum2(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    vector<int> v;
    combination(arr, 0, target, arr.size(), v);
    vector<vector<int>> a;
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        vector<int> p = *it;
        a.push_back(p);
    }
    return a;
}

// the second method is also like combination sum but here instead of using a set for us. We used our own approach
// to find the elements which should come in the vector.
// first of all we sorted our vector here, so that all small values comes later and we get zero
// to do this we went to every element in the vectoe and then used a loop from it, the thing is the value in that
// index should not repeat again, in that we will not get duplicate values in our answer
vector<vector<int>> answer;
void combination2(vector<int> &arr, int ind, int sum, vector<int> &v)
{
    if (sum == 0) // if we get sum as zero, then we push the answer and return
    {
        answer.push_back(v);
        return;
    }
    for (int i = ind; i < arr.size(); i++) // we loop over the array and if i is greater than index and both are same, then we don't take them
    {
        if (i > ind and arr[i] == arr[i - 1])
            continue;
        if (arr[i] > sum) // if arr[i] is greater than remaining sum, then we know we can't  get the answer further, so break
            break;
        v.push_back(arr[i]);
        combination2(arr, i + 1, sum - arr[i], v);
        v.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    vector<int> v;
    combination2(arr, 0, target, v);
    return answer;
}
int main()
{
}