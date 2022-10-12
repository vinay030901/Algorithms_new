/*
In order to decorate your new house, you need to process some sticks with positive integer length.
You can connect any two sticks of lengths X and Y into one stick by paying a cost of X + Y. Due to the construction needs, 
you must connect all the bars into one.
Return the minimum cost of connecting all the given sticks into one stick in this way.
Please note that you can choose any order of sticks connection

1 \leq sticks.length \leq 10^41≤sticks.length≤10
4

1 \leq sticks[i] \leq 10^41≤sticks[i]≤10
4

Example
Example 1:

Input:
[2,4,3]
Output:
14
Explanation:
First connect 2 and 3 to 5 and cost 5; then connect 5 and 4 to 9; total cost is 14
Example 2:

Input:
 [1,8,3,5]
Output:
30
*/
#include <bits/stdc++.h>
using namespace std;
long long minCost(long long arr[], long long n)
{
    // this question is same as minimum cost to connect ropes, so we will solve it in that way
    long long ans = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++)
        pq.push(arr[i]);

    while (pq.size() > 1)
    {
        long long p1 = pq.top();

        pq.pop();
        long long p2 = pq.top();
        pq.pop();
        ans = ans + (p1 + p2);
        pq.push(p1 + p2);
    }
    return ans;
}
int main()
{
}