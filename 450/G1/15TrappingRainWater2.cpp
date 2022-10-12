#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> block;
int trapRainWater(vector<vector<int>> &height)
{

    /*
    we know that overflow must happen by crossing the boundary values, so we will store all the boundary values
    we will process the element with minimum height, if water can't flow from minimum, it isn't possible through other elements

    we will also mark a visited array, we won't process the values which are in the visited array

    now we will use that minimum value with us, we will check for the neighbour of the value, if neighbours are on the boundary,
    then we don't process them. now we have three condition here

    1. neighbour[i][j]<min[i][j]-> in this condition we can store the value, we can add the value of
    min[i][j]-neighbour[i][j] to our answer, we also know that now, we need to process the other values on that side too,
    so, we will change the value of neighbour to that min[i][j] value

    2.. neighbour=min[i][j]-> then we can't anything to our answer because water will flow over us here, so we here too move our
    value to the neighbour and do same for neighbour's neighbour.

    3. neighbour>min[i][j]-> then water is blocked by the neighbour itself, we will delegate to the neighbour to check blockage by it
    */

    priority_queue<block, vector<block>, greater<block>> mn;
    int m = height.size();
    int n = height[0].size();
    bool vis[m][n];
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
            {
                mn.push({height[i][j], {i, j}});
                vis[i][j] = true;
            }
        }
    }
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int water = 0;

    while (mn.size() > 0)
    {
        block p = mn.top();
        mn.pop();
        for (int i = 0; i < dir.size(); i++)
        {
            int rowdash = p.second.first + dir[i][0];
            int coldash = p.second.second + dir[i][1];

            if (rowdash >= 0 && rowdash < m && coldash >= 0 && coldash < n && vis[rowdash][coldash] == false)
            {
                water += max(0, p.first - height[rowdash][coldash]);

                if (p.first > height[rowdash][coldash])
                    mn.push({p.first,{rowdash,coldash}});
                else
                    mn.push({height[rowdash][coldash],{rowdash, coldash}});
            }
            vis[rowdash][coldash] = true;
        }
        
    }
    return water;
}
int main()
{
    vector<vector<int>> heightMap = {{3, 3, 3, 3, 3}, {3, 2, 2, 2, 3}, {3, 2, 1, 2, 3}, {3, 2, 2, 2, 3}, {3, 3, 3, 3, 3}};
    cout << trapRainWater(heightMap);
}