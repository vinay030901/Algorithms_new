/*Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.



Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]


Constraints:

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.*/

/*this question is same as finding the missing and repeating number in an array*/
#include <bits/stdc++.h>
using namespace std;
vector<int> singleNumber(vector<int> &arr)
{
    unsigned int xorr = 0;
    // now we will find the xor of all the numbers in the array, that will eliminate all the repeating numbers and we will be remaining with xor of single numbers
    for (int i = 0; i < arr.size(); i++)
        xorr ^= arr[i];

    // now we will the two numbers using their first differentiating bit from the right
    // we will create a bit mask, and then again do XOR of the numbers with that.
    // that bit will make rsb of xor one, because that is the first different bit in those single numbers
    // then we will divide the array by doing xor, and at last we will remain with two numbers only
    unsigned int rsbMask = xorr & ~(xorr - 1);
    int num1 = 0, num2 = 0;
    for (auto it : arr)
    {
        if ((rsbMask & it) > 0) // and product with mask, if the bit is 1, then it is greater than 1, otherwise it is 0
            num1 ^= it;
        else
            num2 ^= it;
    }
    return {num1, num2};
}
int main()
{
    // Your code here
    return 0;
}