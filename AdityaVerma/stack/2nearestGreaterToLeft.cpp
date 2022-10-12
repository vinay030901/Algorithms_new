/*now we need to find the nearest greater to the left
just like the nearest greater to the right
we will use stack
but instead of right, we will traverse from left this time
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> nearestGreaterToLeft(vector<int> &arr, int n)
{
    stack<int> s;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
            ans.push_back(-1);
        else if (s.top() > arr[i])
            ans.push_back(s.top());
        else
        {
            while (!s.empty() && s.top() <= arr[i])
                s.pop();
            if (s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }
        s.push(arr[i]);
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 3, 2, 4};
    vector<int> ans = nearestGreaterToLeft(arr, 4);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}