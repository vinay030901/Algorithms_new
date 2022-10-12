/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.



Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]


Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.*/

#include <bits/stdc++.h>
using namespace std;
vector<int> largestDivisibleSubset(vector<int> &arr)
{
    int n = arr.size(), mx = 1, last_index = 0;
    vector<int> lds(n, 1), hash(n);
    sort(arr.begin(), arr.end());
    for (int i = 1; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] % arr[j] == 0 && lds[i] < lds[j] + 1)
            {
                lds[i] = lds[j] + 1;
                hash[i] = j;
            }
        }
        if (lds[i] > mx)
        {
            mx = lds[i];
            last_index = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[last_index]);
    while (hash[last_index] != last_index)
    {
        last_index = hash[last_index];
        temp.push_back(arr[last_index]);
    }

    return temp;
}
int main()
{
}