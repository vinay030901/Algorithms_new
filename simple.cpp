#include <bits/stdc++.h>
using namespace std;
int num(int n)
{
    int mn = 9, mx = 0;
    while (n)
    {
        int rem = n % 10;
        if (rem > mx)
        {
            mx = rem;
        }
        if (rem < mn)
        {
            mn = rem;
        }
        n /= 10;
    }
    int sum = 0;
    string str = to_string(n);
    cout<<str<<endl;
    cout << mn << " " << mx << endl;
    for (int i = 0; i < str.length(); i++){
        cout<<str[i]<<" ";
        if (str[i] - '0' == mn || str[i] - '0' == mx)
            continue;
        else
            sum = sum * 10 + (str[i] - '0');
    }
    cout<<endl;
    cout << sum << endl;
    return sum;
}
int reward(int n, int arr[])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += num(arr[i]);
    return sum;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << reward(n, arr);
    return 0;
}