/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
return the area of the largest rectangle in the histogram.

Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4*/
#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int> &arr)
{
    // we need to next smallest to the right and to the left to solve this question

    // first, we will find the next smaller to the right
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
int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(arr);
}