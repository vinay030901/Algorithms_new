#include <bits/stdc++.h>
using namespace std;
void fun()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> ans(n);
    ans[0] = v[0];
    int f = 0;
    for (int i = 1; i < n; i++)
    {
        int num1 = v[i] + ans[i - 1];
        int num2 = v[i] - ans[i - 1];
        if (num2 < 0 && v[i] != 0)
        {
            f = 1;
            break;
        }
        else
            ans[i] = num1;
    }
    if (f == 1)
        cout << "-1\n";
    else
    {
        if (f == 0)
            for (auto it : ans)
                cout << it << " ";
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        fun();
    }
}