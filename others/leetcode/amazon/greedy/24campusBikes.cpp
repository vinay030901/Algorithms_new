/*
On a campus represented as a 2D grid, there are N workers and M bikes, with N <= M. Each worker and bike is a
\2D coordinate on this grid.

Our goal is to assign a bike to each worker. Among the available bikes and workers, we choose the (worker, bike) pair
with the shortest Manhattan distance between each other, and assign the bike to that worker. (If there are multiple (worker, bike) pairs with the same shortest Manhattan distance, we choose the pair with the smallest worker index; if there are multiple ways to do that, we choose the pair with the smallest bike index). We repeat this process until there are no available workers.

The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.

Return a vector ans of length N, where ans[i] is the index (0-indexed) of the bike that the i-th worker is assigned to.



Example 1:



Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
Output: [1,0]
Explanation:
Worker 1 grabs Bike 0 as they are closest (without ties), and Worker 0 is assigned Bike 1. So the output is [1, 0].
Example 2:



Input: workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
Output: [0,2,1]
Explanation:
Worker 0 grabs Bike 0 at first. Worker 1 and Worker 2 share the same distance to Bike 2, thus Worker 1 is assigned to Bike 2, and Worker 2 will take Bike 1. So the output is [0,2,1].
 */

#include <bits/stdc++.h>
using namespace std;
vector<int> assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes)
{
    /* this is a sorting based question, the first approach which comes into the mind is to find the manhattan distance between
    every bikers and the bike, and that's what we do here, the only process we will not do here is sorting the distances and
    then using the find the answer

    instead we will take a vector of vector for our answer and whatever the answer will be, we will store it in that vector
    */
    int n = workers.size();
    int m = bikes.size();
    vector<vector<pair<int, int>>> v(2001); // 2001 due to constraint, that is, distance will be max 2000

    // here we are finding the distance between every bike and rider, and pushing the pair in manhattan distance index
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int distance = abs(workers[i][0] - bikes[i][0]) + abs(workers[i][1] - bikes[i][1]);
            v[distance].push_back({i, j});
        }
    }

    vector<int> ans(n, -1);
    vector<bool> bikeUsed(m, false);

    // then we will run a loop for the 2000 values and we will check if the bike is previously assigned and rider is not already assigned
    // if not we will assign them and change their values, later we we return the ans vector
    for (int d = 0; d < 2001; d++)
    {
        if (v[d].empty())
            continue;
        for (int k = 0; k < v[d].size(); k++)
        {
            if (ans[v[d][k].first] == -1 && !bikeUsed[v[d][k].second])
            {
                bikeUsed[v[d][k].second] = true;
                ans[v[d][k].first] = v[d][k].second;
            }
        }
    }
    return ans;
}
int main()
{
}