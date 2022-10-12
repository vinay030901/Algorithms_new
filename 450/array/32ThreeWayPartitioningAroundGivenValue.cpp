/*
Given an array and a range [lowVal, highVal], partition the array around the range such that array is divided in three parts.
1) All elements smaller than lowVal come first.
2) All elements in range lowVal to highVVal come next.
3) All elements greater than highVVal appear in the end.
The individual elements of three sets can appear in any order.

Examples:

Input: arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32}
        lowVal = 14, highVal = 20
Output: arr[] = {1, 5, 4, 2, 1, 3, 14, 20, 20, 98, 87, 32, 54}

Input: arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32}
       lowVal = 20, highVal = 20
Output: arr[] = {1, 14, 5, 4, 2, 1, 3, 20, 20, 98, 87, 32, 54} */
#include <bits/stdc++.h>
using namespace std;
int main()
{
        int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32}, lowval = 14, highval = 20;
        int n = sizeof(arr) / sizeof(arr[0]);
        // the first method which comes to our mind is to do sorting of this array
        // sorting the array will put all the elements to their proper place without specifying anything.
        sort(arr, arr + n);
        cout << "three way partitioning using sorting: ";
        for (int i = 0; i < n; i++)
                cout << arr[i] << " ";

        /* another method we could employ is to traverse the array first and count how many elements are less than
        lowval, greater than highval, and others.
        in the next traversal we could just put all these elements in the array*/
        int a[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
        // first traversal for counting the elements.
        int low = 0, high = n - 1, mid = 0;
        while (mid <= high)
        {
                if (a[mid] < lowval)
                {
                        swap(a[mid++], a[low++]);
                }
                else if (a[mid] <= highval && a[mid] >= lowval)
                        mid++;
                else if (a[mid] > highval)
                {
                        swap(a[mid], a[high--]);
                }
                cout << "\narray: ";
                for (int i = 0; i < n; i++)
                        cout << a[i] << " ";
                cout << "low: " << low << " mid: " << mid << " high: " << high << endl;
        }
        cout << "\nUsing dutch flag algo: ";
        for (int i = 0; i < n; i++)
                cout << a[i] << " ";
}