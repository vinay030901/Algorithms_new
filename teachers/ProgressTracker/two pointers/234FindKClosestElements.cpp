/*Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b


Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]


Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104*/
#include <bits/stdc++.h>
using namespace std;
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    vector<int> diff;
    int mn = INT_MAX, mni, n = arr.size();
    for (int i = 0; i < arr.size(); i++)
    {
        diff.push_back(abs(arr[i] - x));
        if (abs(arr[i] - x) < mn)
        {
            mn = abs(arr[i] - x);
            mni = i;
        }
    }
    deque<int> dq;
    dq.push_back(arr[mni]);
    int i = mni - 1, j = mni + 1;
    k--;
    while (k > 0 && i >= 0 && j < n)
    {
        if (abs(arr[i] - x) <= abs(arr[j] - x))
        {
            dq.push_front(arr[i--]);
        }
        else
        {
            dq.push_back(arr[j++]);
        }
        k--;
    }
    while (k > 0 && i >= 0)
    {
        dq.push_front(arr[i--]);
        k--;
    }
    while (k > 0 && j < n)
    {
        dq.push_back(arr[j++]);
        k--;
    }
    vector<int> ans;
    for (auto it : dq)
        ans.push_back(it);
    return ans;
}
int main()
{
    // Your code here
    return 0;
}