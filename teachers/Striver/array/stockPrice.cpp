#include <bits/stdc++.h>
using namespace std;
int fun(vector<int> &arr, int n, int k)
{
    int left = 0, right = 0, mx = 0, sum = 0;
    unordered_map<int, int> mp;
    while (right < n)
    {
        mp[arr[right]]++;
        if (mp[arr[right]] > 1)
        {
            while (left <= right && mp[arr[right]] > 1)
            {
                mp[arr[left]]--;
                sum -= arr[left++];
            }
        }
        sum += arr[right];
        if (right - left + 1 == k)
        {
            mx = max(mx, sum);
            cout << "found: " << left << " " << right << " " << sum << endl;
            sum -= arr[left];
            mp[arr[left++]]--;
        }
        right++;
    }

    return mx;
}
int main()
{
    vector<int> arr = {2, 1, 2, 7, 8, 8, 5, 6, 5, 4, 7, 6};
    cout << fun(arr, arr.size(), 3);
    cout<<"\nfirst element: "<<*arr.begin()<<endl;
    auto mid=next(arr.begin(),2);
    cout<<*mid;
}