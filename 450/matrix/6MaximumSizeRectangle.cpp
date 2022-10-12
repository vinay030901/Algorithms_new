/*
Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.

Example:

Input:
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
Output :
8
Explanation :
The largest rectangle with only 1's is from
(1, 0) to (2, 3) which is
1 1 1 1
1 1 1 1

Input:
0 1 1
1 1 1
0 1 1
Output:
6
Explanation :
The largest rectangle with only 1's is from
(0, 1) to (2, 2) which is
1 1
1 1
1 1*/
#include <bits/stdc++.h>
using namespace std;
int Area(vector<int> arr)
{
    int n = arr.size();
    stack<int> s;
    vector<int> left(n), right(n);
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.empty())
            left[i] = -1;
        else
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
        if (s.empty())
            left[i] = -1;
        else
            left[i] = s.top();
        s.push(i);
    }
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
            right[i] = n;
        else
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
        if (st.empty())
            right[i] = n;
        else
            right[i] = st.top();
        st.push(i);
    }
    // reverse(right.begin(), right.end());
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int x = right[i] - left[i] - 1;
        if (x * arr[i] > mx)
            mx = x * arr[i];
    }
    return mx;
}
int main()
{
    vector<vector<int>> arr = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
    int n = arr.size(), m = arr[0].size();

    /* this question could be done using stack, it is like maximum size histogram but the slight difference is
    we need to calculate the the max area after all the rows

    the intution is-
    we have 0  1  1 0
    so first we will left smaller and right smaller for every in, we calculate the length and multiply it by length of 1
    here we have answer as - 0 2 2 0-> since index 1 has 1 length and 2 has length, since 0 arrives second to right, max=2

    now second-> 1 2 2 1
    here we have added the previous values to it, if the new values are 1, now maxarea is 4

    third-> 2 3 3 2
    now max area has reach to 6, since 1 length is 3 and right smallest is difference 2 for index 1

    fourth-> 3 4 0 0
    since these new elements were zero, we have them as zero here
    maxarea now reaches to 8 as we have 4 as length and 2 has width, so answer=8*/

    vector<int> v(m, 0);
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
                v[j] = v[j] + arr[i][j];
            else
                v[j] = 0;
        }
        int count = Area(v);
        mx = max(mx, count);
    }
    cout << "maximum rectangle size: " << mx << endl;
}