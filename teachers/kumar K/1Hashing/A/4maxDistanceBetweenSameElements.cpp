/*SOLUTION
the solution of this code is simple,we have to store the first occurrence of an element in the map
then we will traverse the map and check if the element has occured before, if it did, we will check if the distance between the
first occurrence and this occurrence is greater than our present answer
if it is encountered for the first time then we will store the index of the element
*/
/*QUESTION

Given an array with repeated elements, the task is to find the maximum distance between two occurrences of an element.

Example 1:

Input
n= 6
arr = {1, 1, 2, 2, 2, 1}

Output
5

Explanation
arr[] = {1, 1, 2, 2, 2, 1}
Max Distance: 5
Distance for 1 is: 5-0 = 5
Distance for 2 is : 4-2 = 2
Max Distance 5
Example 2:

Input
n = 12
arr = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}

Output
10

Explanation

arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}
Max Distance 10
maximum distance for 2 is 11-1 = 10
maximum distance for 1 is 4-2 = 2
maximum distance for 4 is 10-5 = 5
Your Task:
Complete maxDistance() function which takes both the given array and their size as function arguments and returns the maximum distance between 2 same elements.*/

#include <bits/stdc++.h>
using namespace std;
int maxDistance(int arr[], int n)
{
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i]) == mp.end())
            mp[arr[i]] = i;
        else
            ans = max(ans, i - mp[arr[i]]);
    }
    return ans;
}