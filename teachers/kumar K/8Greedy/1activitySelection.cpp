/*
Given N activities with their start and finish day given in array start[ ] and end[ ]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.
Example 1:

Input:
N = 2
start[] = {2, 1}
end[] = {2, 2}
Output:
1
Explanation:
A person can perform only one of the
given activities.
Example 2:

Input:
N = 4
start[] = {1, 3, 2, 5}
end[] = {2, 4, 3, 6}
Output:
3
Explanation:
A person can perform activities 1, 2
and 4.*/
#include <bits/stdc++.h>
using namespace std;
int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });
    int n = points.size(), end = points[0][1], a = 1;
    for (int i = 1; i < n; i++)
    {
        int start = points[i][0];
        if (end < start)
        {
            a++;
            end = points[i][1];
        }
    }
    return a;
}
int main()
{

    return 0;
}