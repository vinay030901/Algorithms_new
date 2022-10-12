#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int dead, profit, id;
};
bool comp(const struct Job &a, const struct Job &b)
{
    if (a.dead != b.dead)
        return (a.dead < b.dead);
    return (a.profit < b.profit);
}
void fun(Job a[], int n)
{
    priority_queue<int> pq;
    sort(a, a + n, comp);
    int mxallow = 0;
    for (int i = 0; i < n; i++)
    {
        pq.push(-a[i].profit); // used a max heap as a min heap by negating the elements
        while (pq.size() > a[i].dead)
            pq.pop();
    }
    int sz = pq.size();
    int ans = 0;
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    ans = -ans;
}