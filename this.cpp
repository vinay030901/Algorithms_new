#include <bits/stdc++.h>
using namespace std;
int getSum(vector<int> arr)
{
    int n = arr.size(), ans = 0;
    for (int i = 0; i < n; i += 2)
    {
        int sum = arr[i] + arr[i + 1];
        sum /= 2;
        if (sum % 2 == 0)
            ans++;
    }
    return ans;
}
int main()
{
    vector<int> v = {2, 0, 5, 0, 0, 0, 1, 0};
    cout << getSum(v) << endl;
}