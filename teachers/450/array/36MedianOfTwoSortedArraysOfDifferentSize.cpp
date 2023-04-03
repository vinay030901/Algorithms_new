/*
Given two sorted arrays, a[] and b[], the task is to find the median of these sorted arrays, in O(log n + log m) time complexity, when n is the number of elements in the first array, and m is the number of elements in the second array.
This is an extension of median of two sorted arrays of equal size problem. Here we handle arrays of unequal size also.

Example:

Input: ar1[] = {-5, 3, 6, 12, 15}
        ar2[] = {-12, -10, -6, -3, 4, 10}
Output : The median is 3.
Explanation : The merged array is :
        ar3[] = {-12, -10, -6, -5 , -3,
                 3, 4, 6, 10, 12, 15},
       So the median of the merged array is 3

Input: ar1[] = {2, 3, 5, 8}
        ar2[] = {10, 12, 14, 16, 18, 20}
Output : The median is 11.
Explanation : The merged array is :
        ar3[] = {2, 3, 5, 8, 10, 12, 14, 16, 18, 20}
        if the number of the elements are even,
        so there are two middle elements,
        take the average between the two :
        (10 + 12) / 2 = 11.*/

#include <bits/stdc++.h>
using namespace std;
double FindMedian(int arr1[], int arr2[], int n1, int n2)
{
    // so what we are doing is
    // we need to find the best partition, some portion from arr1 and some from arr2, after which the are sorted at that point
    // that is, the element to next of that portion should be greater than previous
    /*for ex- arr1={1,3,4,7,10,12,13,14}, arr2={2,3,6,15}
    so the best partition -
    arr1-  1,3,4 || 7,10,12
    arr2-    2,3 || 6,15
    so we can see that 4<=6 and 3<=7
    so median = (max(4,3)+min(6,7))/2=(4+6)/2=5.
    wrong partition-
    arr1- 1,3 || 4,7,10,12
    arr2 - 2,3,6 || 15
    here 6>4 and this is wrong

    now we will solve this*/
    if (n2 < n1)
        return FindMedian(arr2, arr1, n2, n1);
    int low = 0, high = n1; // low and high are used for checking the different values in arr1 amd finding, where to make the partition

    while (low <= high)
    {
        int cut1 = (low + high) / 2;         // our first cut is in the middle, later the value of low and high changes
        int cut2 = (n1 + n2 + 1) / 2 - cut1; // since we need the same size of both sides, then we decrease cut1 from half of total

        // this is our top left, if cut1 value is 0, then we put it INT_MIN because by default, the value on other side is high
        // or else, its value is arr[cut1-1]
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];

        // l2 is also similar but it belongs to the second array, it is the bottom left
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];

        // r1 belongs to arr1 and the other half of partition, it is INT_MAX if cut1 is last value of our array
        int r1 = cut1 == n1 ? INT_MAX : arr1[cut1];

        // r2 belongs to arr2 and is on bottom right, we compare it with l1
        int r2 = cut2 == n2 ? INT_MAX : arr2[cut2];

        if (l1 < r2 && l2 < r1) // now if this condition is true, that is our partition has all low elements on one side,
        // then we calculate median, if array total size is even then only this partition occurs
        // if odd, the middle element is median, so just give max of middle element as median
        {
            if ((n1 + n2) % 2 == 0)
                return (max(l1, l2) + min(r1, r2)) / 2;
            else
                return max(l1, l2);
        }
        else if (l1 > r2)
            high = cut1 - 1; // if l1 is bigger, then arr1 need to go right side, so we will decrease the value of high
        // now when cut1 will be calculated, it would be lower, same is in the else case where we increase the value of low,
        // so when cut1 is calculated, it would be higher
        else
            low = cut1 + 1;
    }
    return 0.0;
}
int main()
{
    // in this question we need to find the median in LogN time, so it is obvious that we need to use binary search for this
    int arr1[] = {1, 2};
    int arr2[] = {3, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << FindMedian(arr1, arr2, n1, n2) << endl;
}