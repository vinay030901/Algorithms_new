/*Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.



Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]


Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109


Follow up: Could you solve the problem in linear time and in O(1) space?*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> majorityElement(vector<int> &arr)
    {
        int num1 = -1, num2 = -1, c1 = 0, c2 = 0;
        for (auto it : arr)
        {
            if (it == num1)
                c1++;
            else if (it == num2)
                c2++;
            else if (c1 == 0)
            {
                num1 = it;
                c1++;
            }
            else if (c2 == 0)
            {
                num2 = it;
                c2 = 1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        int cnt1 = 0;
        vector<int> ans;
        for (auto it : arr)
            if (it == num1)
                cnt1++;
        if (cnt1 > arr.size() / 3)
            ans.push_back(num1);
        cnt1 = 0;
        if (num1 == num2)
            return ans;
        for (auto it : arr)
            if (it == num2)
                cnt1++;
        if (cnt1 > arr.size() / 3)
            ans.push_back(num2);
        return ans;
    }
};
int main()
{
    // Your code here
    return 0;
}