/*
Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive 
number is followed by negative and vice-versa maintaining the order of appearance.
Number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the 
end of the array. If there are more negative numbers, they too appear in the end of the array.

Examples :

Input:  arr[] = {1, 2, 3, -4, -1, 4}
Output: arr[] = {-4, 1, -1, 2, 3, 4}

Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
output: arr[] = {-5, 50, -2, 2, -8, 4, 7, 1, 8, 0}*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // since, I have to do this in O(n) time and O(1) space, first I will put all the negative numbers on one side
    // and all the positive on one, then swap them accordingly, the remaining number will number will remain on one side

    int arr[] = {1, 2, 3, -4, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    int f = 1;
    for (int i = 0; i < n; i++)
    {
        if (f == 1)
            f = 0;
        else
        {
            swap(arr[i], arr[j]);
            j++;
            f = 1;
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
}