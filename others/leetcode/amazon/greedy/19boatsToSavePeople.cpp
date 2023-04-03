/*
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat
can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of
those people is at most limit.

Return the minimum number of boats to carry every given person.

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
*/
#include <bits/stdc++.h>
using namespace std;
int numRescueBoats(vector<int> &arr, int limit)
{
    // we know that maximum two people can be on a boat, so we will use two pointer technique here
    // will sum lowest with highest, if sum crosses the limit, then we know that whatever we will add to max, it will cross the limit
    // so we will increment the count and decrease j value
    // else we will increase i and decrease j and increase the count
    // we will have condition for i and j, if they both end up being equal, then we increment the answer and return count
    // because there's no other value to add to it
    sort(arr.begin(), arr.end());
    int count = 0, sum = 0, people = 0, n = arr.size();

    for (int i = 0, j = n - 1;;)
    {
        if (i > j)
            break;
        else if (i == j)
        {
            ++count;
            break;
        }
        sum = arr[i] + arr[j];
        if (sum > limit)
        {
            j--;
            count++;
        }
        else
        {
            count++;
            i++;
            j--;
        }
    }
    return count;
}
int main()
{
}