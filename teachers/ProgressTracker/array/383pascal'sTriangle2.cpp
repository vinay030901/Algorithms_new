/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]


Constraints:

0 <= rowIndex <= 33


Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?*/
#include <bits/stdc++.h>
using namespace std;
vector<int> getRow(int n)
{
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for (int col = 0; col < n; col++)
    {
        ans *= (n - col);
        ans /= (col + 1);
        ansRow.push_back(ans);
    }
    return ansRow;
}

int main()
{
    // Your code here
    return 0;
}