/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1*/
#include <bits/stdc++.h>
using namespace std;
int area(vector<int> &arr)
{
    stack<pair<int, int>> s;
    vector<int> right, left;
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
            right.push_back(n);
        else if (s.top().first < arr[i])
            right.push_back(s.top().second);
        else
        {
            while (!s.empty() && s.top().first >= arr[i])
                s.pop();
            if (s.empty())
                right.push_back(n);
            else
                right.push_back(s.top().second);
        }
        s.push({arr[i], i});
    }
    reverse(right.begin(), right.end());
    cout << "right: ";
    for (int i = 0; i < right.size(); i++)
        cout << right[i] << " ";
    cout << "\n";
    // now we will find the next smaller element to the left
    stack<pair<int, int>> s1;
    for (int i = 0; i < n; i++)
    {
        if (s1.empty())
            left.push_back(-1);
        else if (s1.top().first < arr[i])
            left.push_back(s1.top().second);
        else
        {
            while (!s1.empty() && s1.top().first >= arr[i])
                s1.pop();
            if (s1.empty())
                left.push_back(-1);
            else
                left.push_back(s1.top().second);
        }
        s1.push({arr[i], i});
    }
    cout << "left: ";
    for (int i = 0; i < right.size(); i++)
        cout << left[i] << " ";
    cout << "\n";
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i] * (right[i] - left[i] - 1));
        cout << mx << " ";
    }
    return mx;
}
// to solve this question, we are taking the row one by one and adding to our vector, but if any element is zero,
// then we make its vector element as 0
int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<int> v(m, 0);
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '0')
                v[j] = 0;
            else
                v[j] += 1;
        }
        mx = max(mx, area(v));
    }
    return mx;
}
int main()
{
    
}