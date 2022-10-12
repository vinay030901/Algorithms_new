/*
You are given N number of books. Every ith book has Ai number of pages. The books are arranged in ascending order.

You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so. In each permutation,
one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that
particular permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other
permutations and print this minimum value.

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for
better understanding).

Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in
following ways:{12} and {34, 67, 90}
Maximum Pages = 191{12, 34} and {67, 90}
Maximum Pages = 157{12, 34, 67} and {90}
Maximum Pages =113. Therefore, the minimum
of these cases is 113, which is selected
as the output.

Example 2:

Input:
N = 3
A[] = {15,17,20}
M = 2
Output:32
Explanation: Allocation is done as
{15,17} and {20}*/

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
int findPages(vector<int> &arr, int m)
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
int main()
{
    vector<int> arr = {12, 34, 67, 90};
    int m = 2; // No. of students

    cout << "Minimum number of pages = "
         << findPages(arr, m) << endl;
    return 0;
}