/*Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.



Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109*/
#include <bits/stdc++.h>
using namespace std;
static bool compare(int num1, int num2)
{
    string n1 = to_string(num1);
    string n2 = to_string(num2);
    return n1 + n2 > n2 + n1;
}
string largestNumber(vector<int> &nums)
{
    string ans = "";
    sort(nums.begin(), nums.end(), compare);
    for (int i = 0; i < nums.size(); i++)
        ans += to_string(nums[i]);
    if (ans[0] == '0')
        return "0";
    return ans;
}
int main()
{
    // Your code here
    return 0;
}