#include <bits/stdc++.h>
using namespace std;
void leftSmaller(vector<int> &arr, vector<int> &left)
{
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        if (st.empty())
            left.push_back(-1);
        else if (arr[st.top()] < arr[i])
            left.push_back(st.top());
        else
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                left.push_back(-1);
            else
                left.push_back(st.top());
        }
        st.push(i);
    }
}
void rightSmaller(vector<int> &arr, vector<int> &right)
{
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (st.empty())
            right.push_back(arr.size());
        else if (arr[st.top()] < arr[i])
            right.push_back(st.top());
        else
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                right.push_back(arr.size());
            else
                right.push_back(st.top());
        }
        st.push(i);
    }
    reverse(right.begin(), right.end());
}
int largestRectangleArea(vector<int> &arr)
{
    int n = arr.size();
    vector<int> left, right;
    leftSmaller(arr, left);
    rightSmaller(arr, right);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i] * (right[i] - left[i] - 1));
    }
    return mx;
}