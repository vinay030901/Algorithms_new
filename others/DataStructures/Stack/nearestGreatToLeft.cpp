#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n), ans;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    stack<int> s;
    ans.push_back(-1);
    s.push(v[0]);
    for (int i = 1; i < n; i++)
    {
        bool f = false;
        while (v[i] >= s.top())
        {
            s.pop();
            if (s.empty())
            {
                ans.push_back(-1);
                f = true;
                s.push(v[i]);
                break;
            }
        }
        if (f == false)
        {
            ans.push_back(s.top());
            s.push(v[i]);
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "  ";
}