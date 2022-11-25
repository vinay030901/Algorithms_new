#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int findNumber(int n, int k, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    unordered_set<int> st;
    int i = n / 2, j = n / 2;
    st.insert(n / 2);
    k--;
    if (k % 2 != 0)
    {
        while (k != 0)
        {
            i--;
            j++;
            st.insert(i);
            st.insert(j);
            k -= 2;
        }
    }
    else
    {
        unordered_set<int> st1, st2;
        int l = n / 2;
        st1.insert(l);
        int i = l, j = l;
        while (k != 0)
        {
            i--;
            st.insert(i);
            if (k == 0)
                break;
            j++;
            st.insert(j);
        }
        l = n / 2 - 1;
        st2.insert(n / 2 - 1);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n = 3, k = 5;
        vector<int> arr = {2, 0, 0};
        cout << findNumber(n, k, arr) << "\n";
    }
}