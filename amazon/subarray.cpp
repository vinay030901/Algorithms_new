#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int fun(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> st;
        int res = arr[i];
        st.insert(res);
        for (int j = 0; j <= i; j++)
        {
            res = gcd(res, arr[j]);
            st.insert(res);

            if (st.size() == i - j + 1)
                ans++;
            else
                break;
        }
    }
    return ans;
}
int main()
{
    int n = 4;
    int arr[] = {18, 6, 24, 1};
    cout << fun(arr, n) << endl;
}