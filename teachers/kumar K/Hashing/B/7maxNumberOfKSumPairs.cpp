/*You are given an integer array nums and an integer k.
In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.
Return the maximum number of operations you can perform on the array.
Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.*/
/*we will traverse the array and use a map
if we have an element which makes the pair, we will incerement the ans and decrement the frequency of that number
otherwise we will increment the frequency of arr[i]
in that way we will take present element only when we don't find any pair associated with it*/
#include <bits/stdc++.h>
using namespace std;
int maxOperations(vector<int> &arr, int k)
{
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (mp.find(k - arr[i]) != mp.end() && mp[k - arr[i]] > 0)
        {
            ans++;
            mp[k - arr[i]] -= 1;
        }
        else
            mp[arr[i]]++;
    }
    return ans;
}
int main()
{
}