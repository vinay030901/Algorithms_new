/* in this approach we will again work from right side only because we need to find the nearest greater to the right
the aproach will be like nearest greater to the right side, just change in the signs
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> nearestSmallerToRight(vector<int> &arr, int n)
{
    stack<int> s;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
            ans.push_back(-1);
        else if (s.top() < arr[i])
            ans.push_back(s.top());
        else
        {
            while (!s.empty() && s.top() >= arr[i])
                s.pop();
            if (s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> arr = {0, 2, 1, 0};
    vector<int> ans = nearestSmallerToRight(arr, 4);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}