/* just like the above questions we will use stack here
since we need to find the smaller to left, we will start our variable from left side only
the intution will be the same just like the above approaches with just some changes in the signs
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> nearestSmallerToLeft(vector<int> &arr, int n)
{
    stack<int> s;
    vector<int> ans;
    for (int i = 0; i < n; i++)
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
    return ans;
}
int main()
{
    vector<int> arr = {0, 2, 1, 3};
    vector<int> ans = nearestSmallerToLeft(arr, 4);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}