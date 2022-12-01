#include <bits/stdc++.h>
using namespace std;
long long solve(int n, vector<int>v)
{
    vector<int>sc;
    for(int i=0; i<n; i++)
    sc.push_back(v[i]);
    sort(sc.begin(), sc.end());
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        if(v[i]!=sc[i]) sum-=v[i];
        else sum += v[i];
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout<<solve(n,v);
}