/*
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.
It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.

Example 1:


Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
Example 2:


Input: arr = [4,11]
Output: 44*/
#include <bits/stdc++.h>
using namespace std;
int mctFromLeafValues(vector<int> &arr)
{
    // here we are just following the greedy algorithm
    // its obvioud we need to multiply the lower values first and since it is inorder, it should be left or right of the array
    // so we just take every minimum element, multiple with next or previous, whoever is smaller and then pop the minimum element
    // at last we will get the result
    int res = 0;
    while (arr.size() > 1)
    {
        int mnv = INT_MAX, mni = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] < mnv)
            {
                mnv = arr[i];
                mni = i;
            }
        }
        if (mni > 0 && mni < arr.size() - 1)
            res += (arr[mni] * min(arr[mni - 1], arr[mni + 1]));
        else
        {
            if (mni == 0)
                res += (arr[mni] * arr[mni + 1]);
            else
                res += (arr[mni] * arr[mni - 1]);
        }
        arr.erase(arr.begin() + mni);
    }
    return res;
}
int main()
{
}