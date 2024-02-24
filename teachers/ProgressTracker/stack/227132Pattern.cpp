/*Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.



Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].


Constraints:

n == nums.length
1 <= n <= 2 * 105
-109 <= nums[i] <= 109*/

/*why stack-
when there is a dependent condition such as
for(int i=0;i<n;i++)
for(int j=I=1;j<n;j++)

we are going traverse from n-1 to 0 because we are going to find the max number in the right side, and if we encounter something smaller than it
that could be our k, and if we encounter something bigger than it, that would be our j, and mx would be our k
*/
#include <bits/stdc++.h>
using namespace std;
bool find132pattern(vector<int> &arr)
{
    int num3 = INT_MIN;
    int n = arr.size();
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        if (num3 > arr[i])
            return true;
        // here arr[i] is the largest candidate and we need to find the greatest num3, therefore we keep popping stack and store it in num3,
        while (!s.empty() && s.top() < arr[i])
            num3 = s.top(), s.pop();
        s.push(arr[i]);
    }
    return false;
}
int main()
{
    // Your code here
    return 0;
}