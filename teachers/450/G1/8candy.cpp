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
The third child gets 1 candy because it satisfies the above two conditions.
*/

#include <bits/stdc++.h>
using namespace std;
int candy(vector<int> &arr)
{
    int n = arr.size();
    vector<int> l(n, 1), r(n, 1);
    // so we will traverse the array from both the sides,
    // first we will compare the array to the left neighbour and it its rating is greater than its neighbours
    // then we will add one to its left array.

    for (int i = 1; i < n; i++)
        if (arr[i] > arr[i - 1])
            l[i] += l[i - 1];

    // we will do the same for the right part of the array, and compare each of the right ratings and if it is higher than the
    // neighbours,we will add 1 to the r array
    for (int i = n - 2; i >= 0; i--)
        if (arr[i] > arr[i + 1])
            r[i] += r[i + 1];

    // at last, we will sum them, we will add the max of the left and right array, so that the value must be greater than its neighbours
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += max(l[i], r[i]);
    return sum;
}
int main()
{
    vector<int> arr = {1, 0, 2};
    // this problem states that of the ratings of any child is greater than its neighbours, then he should get more candies
    // as compared to its neighbours

    cout << "no of candies is: " << candy(arr);
}