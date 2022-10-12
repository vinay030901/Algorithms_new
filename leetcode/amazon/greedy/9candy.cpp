/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.



Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.*/

#include <bits/stdc++.h>
using namespace std;
int candy(vector<int> &arr)
{
    // according to the question, each child should get one candy and therefore we will vector with previous size as 1
    // this question is solved using two traversal, one from forward and one from backward, just like max product array
    int n = arr.size();
    vector<int> l(n, 1), r(n, 1);


    // here we will keep comparing the values with their left neighbors, and if their value is higher than neighbors, then
    // their value will increase, so we will add neighbor value to it, and when one is added to neighbor value, it will be
    // higher than neighbor value.
    // same is being done for right neighbors too
    for (int i = 1, j = n - 2; i < n; i++, j--)
    {
        if (arr[i] > arr[i - 1])
            l[i] += l[i - 1];
        if (arr[j] > arr[j + 1])
            r[j] += r[j + 1];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += max(l[i], r[i]);
    return ans;
}
int main()
{
}