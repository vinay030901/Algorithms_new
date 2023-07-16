/*
Given two sorted arrays and a number x, find the pair whose sum is closest to x and the pair has an element from each array.
We are given two arrays ar1[0…m-1] and ar2[0..n-1] and a number x, we need to find the pair ar1[i] + ar2[j] such that absolute value of (ar1[i] + ar2[j] – x) is minimum.
Example:

Input:  ar1[] = {1, 4, 5, 7};
        ar2[] = {10, 20, 30, 40};
        x = 32
Output:  1 and 30

Input:  ar1[] = {1, 4, 5, 7};
        ar2[] = {10, 20, 30, 40};
        x = 50
Output:  7 and 40*/
#include <bits/stdc++.h>
using namespace std;
int findClosest(vector<int> ar1, vector<int> ar2, int x)
{
    int n = ar1.size(), m = ar2.size();
    int i = n - 1, j = 0, mn = INT_MAX;
    while (i >= 0 && j < m)
    {
        if (abs(ar1[i] + ar2[j] - x) < mn)
        {
            mn = abs(ar1[i] + ar2[i] - x);
            if (mn == 0)
                break;
        }
        if (ar1[i] + ar2[j] > x)
            i--;
        else
            j++;
    }
}
int main()
{
}