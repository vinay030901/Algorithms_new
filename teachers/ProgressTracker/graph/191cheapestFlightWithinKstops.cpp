/*
here are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei]
indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is
no such route, return -1.



Example 1:

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.*/

#include <bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    /*so this solution uses bellman-ford algorithm
    since, we can have atmost k stops, after reading the question the only thought which comes in mind is that
    we need to move from one place to another using our source node only and since using bellman, we process over the whole
    adjacent list, the prices vector will change for every  node collectively,
    to resolve this problem, we can use the extra vector,
    the distance will 1e8 value on it, and we will traverse the flights, the changes will be made only in temp vector
    since at the start, we made the src 0, the changes will take place in vector one by one, and if the didn't reach our destination
    in k attemps, we will return -1*/
    vector<int> prices(n, 1e8), temp;
    prices[src] = 0;
    for (int i = 0; i <= k; i++)
    {
        temp = prices;
        for (int j = 0; j < flights.size(); j++)
        {
            int u = flights[j][0], v = flights[j][1], wt = flights[j][2];
            if (prices[u] + wt < temp[v])
                temp[v] = prices[u] + wt;
        }
        prices = temp;
    }
    if (prices[dst] == 1e8)
        return -1;
    return prices[dst];
}
int main()
{
}