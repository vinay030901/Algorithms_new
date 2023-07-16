/*Given an array arr[] containing N elements, the task is to count the number of sub-arrays whose XOR of all the elements is equal to the sum of all the elements in the subarray.

Examples:

Input: arr[] = {2, 5, 4, 6}
Output: 5
Explanation:
All the subarrays {{2}, {5}, {4}, {6}} satisfies the above condition since the XOR of the subarrays is same as the sum. Apart from these, the subarray {2, 5} also satisfies the condition:
(2 xor 5) = 7 = (2 + 5)

Input: arr[] = {1, 2, 3, 4, 5}
Output: 7 */

/*we used to sliding window approach to solve this question
we will have two pointers where left will be used for traversing and right be used for checking that
from left to which element, our condition is passing
then we will have ans as right-left, which we will keep adding in our ans*/
#include <bits/stdc++.h>
using namespace std;
int count(vector<int> &arr)
{
    int sum = 0, right = 0, ans = 0;
    for (int left = 0; left < arr.size(); left++)
    {
        while (right < arr.size() && (sum + arr[right]) == (sum ^ arr[right]))
        {
            sum += arr[right];
            right++;
        }
        ans += (right - left);
        if (right == left)
            right++;
        else
            sum -= arr[left];
    }
    return ans;
}