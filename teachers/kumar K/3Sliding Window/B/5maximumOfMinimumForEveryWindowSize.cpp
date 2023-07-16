/*
Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
Note: Window size varies from 1 to the size of the Array.

Example 1:

Input:
N = 7
arr[] = {10,20,30,50,10,70,30}
Output: 70 30 20 10 10 10 10
Explanation:
1.First element in output
indicates maximum of minimums of all
windows of size 1.
2.Minimums of windows of size 1 are {10},
 {20}, {30}, {50},{10}, {70} and {30}.
 Maximum of these minimums is 70.
3. Second element in output indicates
maximum of minimums of all windows of
size 2.
4. Minimums of windows of size 2
are {10}, {20}, {30}, {10}, {10}, and
{30}.
5. Maximum of these minimums is 30
Third element in output indicates
maximum of minimums of all windows of
size 3.
6. Minimums of windows of size 3
are {10}, {20}, {10}, {10} and {10}.
7.Maximum of these minimums is 20.
Similarly other elements of output are
computed.
Example 2:

Input:
N = 3
arr[] = {10,20,30}
Output: 30 20 10
Explanation: First element in output
indicates maximum of minimums of all
windows of size 1.Minimums of windows
of size 1 are {10} , {20} , {30}.
Maximum of these minimums are 30 and
similarly other outputs can be computed
Your Task:
The task is to complete the function maxOfMin() which takes the array arr[] and its size N as inputs and finds the maximum of minimum of every window size and returns an array containing the result.

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)*/
/*The idea is to find the next smaller and previous smaller of each element and update the maximum of window with size as the difference in their indices.*/
#include <bits/stdc++.h>
using namespace std;
void leftSmaller(vector<int> &left, int n, int arr[])
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if (!st.empty())
            left[i] = st.top();
        st.push(i);
    }
}
void rightSmaller(vector<int> &right, int n, int arr[])
{
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if (!st.empty())
            right[i] = st.top();
        st.push(i);
    }
}
void printMaxOfMin(int arr[], int n)
{
    vector<int> left(n, -1), right(n, n);
    leftSmaller(left, n, arr);
    rightSmaller(right, n, arr);
    vector<int> ans(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int len = right[i] - left[i] - 1;
        // arr[i] is a possible answer for this length
        // 'len' interval, check if arr[i] is more than
        // max for 'len'
        ans[len] = max(ans[len], arr[i]);
    }

    // Some entries in ans[] may not be filled yet. Fill
    // them by taking values from right side of ans[]
    for (int i = n - 1; i >= 1; i--)
        ans[i] = max(ans[i], ans[i + 1]);
    for (auto it : ans)
        cout << it << " ";
}
int main()
{
    int arr[] = {10, 20, 30, 50, 10, 70, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    printMaxOfMin(arr, n);
    return 0;
}