#include <bits/stdc++.h>
using namespace std;
vector<int> help_classmate(vector<int> arr, int n)
{
    // Your code goes here
    stack<int> st;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
            ans.push_back(-1);
        else if (arr[i] > st.top())
            ans.push_back(st.top());
        else
        {
            while (!st.empty() && arr[i] <= st.top())
                st.pop();
            if (st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
        }
        st.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{

    return 0;
}