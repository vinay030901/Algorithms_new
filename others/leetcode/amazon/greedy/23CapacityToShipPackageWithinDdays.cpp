/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt
(in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.



Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts
like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1


THIS QUESTION IS SAME AS SPLIT ARRAY MAX SUM*/
#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<int> &arr, int n, int m, int mid)
{
    int students = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return false;
        sum += arr[i];
        if (sum > mid)
        {
            students++;
            sum = arr[i];
        }
    }
    if (students > m)
        return false;
    return true;
}
int shipWithinDays(vector<int> &arr, int m)
{
    // as the question, we need to find the minimum value for max number of pages the student will read
    // we will use binary search here

    // we can easily say that minimum number of pages student will read is equal to 0 and max is the sum of array here
    // but we have a constraint that one student has to read atleast one book, so we will give him the book with the most value here
    // so atleast one student has to read the book with the most number of pages and therefore we will have our minimum in the range
    // as this maximum value

    // now we will find the find the center and the center value will be the max number of pages a student should read
    // depending on books, we will increase and decrease the value of that center, so that all the book will be in the range

    // for ex we have 10,20,30,40 as the values
    // then the center is 50
    // for s1: 10+20=30<50
    // for s2: 30<50
    // now we have 40 still remaining with us which will another student value, so we will increase the range here
    // now new mid is 50+100/2=75
    // for s1=10+20+30
    // for s2=40
    // so all book are read here and it is completing using two students only
    // now we will go to 62, and then do the same
    // the answer will be same as above here.
    // now we will do this work for 56 here
    // at last we will have 60 as our answer
    int n = arr.size();
    if (n < m)
        return -1;
    int start = *max_element(arr.begin(), arr.end());
    int end = accumulate(arr.begin(), arr.end(), 0);
    int res = -1;
    // here our minimum the least element and the highest is the sum of the values of the array
    while (start <= end)
    {
        // we find the mid of the start and end values and call the function to divide the values
        int mid = start + (end - start) / 2;

        // if the function returns true, that means we can divide the values using the mid and therfore we will decrease the value of end
        // here, to find a more small answer
        if (isValid(arr, n, m, mid) == true)
        {
            res = mid;
            end = mid - 1;
        }
        // if it isnt't true, that means we sent a very small value and therefore we need to increase the value of the mid
        else
            start = mid + 1;
    }
    return res;
}