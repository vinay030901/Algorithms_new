/*SOLUTION
so the question says that we need to shoot the array from a particular position and then burst the max number of balloons

one important catch for this question is that for all balloons that are to be shot down, they should be on the same slope
so, we will traverse the array and calculate the slope of coordination with relation to the point taken, we will use an unordered
map for this task which will be double to int, and we will find the max count.

so simple solution is: take every element, find the slopes of every other element with respect to it and then find the maxmimum number of slopes encountered
do this with every element and find the maximum
TC: O(N^2)
SC: O(N)
*/
/*QUESTION

You are given an infinite two-dimensional grid. There are N balloons placed at certain coordinates of the grid. You have an arrow with yourself, which you will be using to shoot the balloons. You can select any point on the grid as your starting point and any point on the grid as the target point. When you fire the arrow, all ballons lying on the shortest path between the starting point and target point will be burst. Given the coordinates of the N ballons in an array arr, your task is to find out the maximum number of balloons that you can fire in one arrow shot.

Example 1:

Input:
N = 3
arr[] = {{1, 2}, {2, 3}, {3, 4}}
Output:
3
Explanation:
If you position yourself at point (1,2)
and fire the arrow aiming at the point (3,4).
Then all the balloons will burst.
Example 2:

Input:
N = 3
arr[] = {{2,2}, {0,0}, {1,2}}
Output:
2
Explanation:
If you position yourself at point (2,2)
and fire the arrow aiming at the point (0,0).
Then the two balloons present at the two points
will burst.*/

#include <bits/stdc++.h>
using namespace std;
int mostBalloons(int N, pair<int, int> arr[])
{
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        double x = arr[i].first, y = arr[i].second;
        unordered_map<double, int> mp;
        int cnt = 0;
        for (int j = 0; j < N; j++)
        {
            double p = arr[j].first, q = arr[j].second;
            if (p == x && q == y)
                cnt++;
            double slope = double(q - y) / double(p - x);
            mp[slope]++;
        }
        for (auto it : mp)
            ans = max(ans, it.second + cnt);
    }
    return ans;
}
int main()
{
}