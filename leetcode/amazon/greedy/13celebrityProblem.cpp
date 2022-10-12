/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people,
find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is
set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.

Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0},
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity.

Example 2:

Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.*/
#include <bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> &m, int n)
{
    // we will use stack in this question, as we can see that celebrity doesn't anyone,
    /* so we will take out to values at a time and then check both know each other or not
    if a knows b, then a is not celibrity and will not be pushed in stack  and if b knows a, then b will not celibrity and
     would not be pushed back into the stack
     */
    stack<int> st;
    for (int i = 0; i < n; i++)
        st.push(i);
    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (m[a][b] == 1)
            st.push(b);
        else if (m[b][a] == 1)
            st.push(a);
    }
    if (st.empty())
        return -1;
    int val = st.top();
    for (int i = 0; i < n; i++)
    {
        if (m[val][i] == 1)
            return -1;
        if (i != val && m[i][val] == 0)
            return -1;
    }
    return val;
}
int main()
{
}