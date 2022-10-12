/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.



Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void combination(int arr[], int ind, int sum, int n, vector<int> &v)
{
    // this question is like printing ths subsequences with given sum, with the only difference is an element can come any number of times.
    // therefore at one end we will not increase the indix so that the same element would be taken into account.
    // and on the other side, we will take the next element.
    // we will stop going down when we reach at the end of index or further substraction will lead to negative number.

    if (ind == n) // if we reach the end of index, we check if sum is zero or target has become zero
    {
        if (sum == 0)
        {
            ans.push_back(v);
            return;
        }
        else
            return;
    }
    if (sum > arr[ind]) // so if sum is more than element, that means we won't reach negative, we will push the element into the 
    // vector and therefore now send decreased value of sum here.
    {
        v.push_back(arr[ind]);
        combination(arr, ind, sum - arr[ind], n, v);
        v.pop_back(); // here we will pop back when the call is complete, if didn't make the call, there's no need for this to call, 
        // therefore this is under if condition
    }
    combination(arr, ind + 1, sum, n, v); // if we don't take the element, we can simply move forward
}
int main()
{
    int arr[] = {2, 3, 6, 7};
    int n = 4;
    int target = 7;
    vector<int> v;
    combination(arr, 0, target, n, v);
    cout << "answer is: ";
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}