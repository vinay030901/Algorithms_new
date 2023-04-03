/*
Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?
You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.
For Example
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.
Input Format:
The first line of the input contains an integer, 'T,’ denoting the number of test cases.

The first line of each test case contains a single integer,' N’, denoting the number of days.

The next ‘N’ lines of each test case have 3 integers corresponding to POINTS[i].
Output Format:
For each test case, return an integer corresponding to the maximum coins  Ninja can collect.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 100000.
1 <= values of POINTS arrays <= 100 .

Time limit: 1 sec*/

#include <bits/stdc++.h>
using namespace std;

// so the questions says that we need to not pick the previoud selected index, so in order to do that we need to use an if statement
// for every value, we will run a loop and check for various values other than previous
//
int recur(vector<vector<int>> &points, int day, int last, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int mx = INT_MIN;
        for (int i = 0; i <= 2; i++)
            if (i != last)
                mx = max(mx, points[0][i]);
        return mx;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    int mx = INT_MIN;
    for (int i = 0; i <= 2; i++)
    {
        if (i != last)
            mx = max(mx, points[day][i] + recur(points, day - 1, i, dp));
    }
    return dp[day][last] = mx;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4));
    return recur(points, n, 3, dp);
}

// now we will move onto the bottom up approach
int ninjaTrainingTabulation(int n, vector<vector<int>> &points)
{
    // the approach used here is conversion of top down approach
    // we need to fill the dp vector here, so at first we are finding the max of every value other than last
    // in this way, the first line of the dp vector will be full here, and we, in the incoming loops,
    // will find the max
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    // this loop will run for every day in the training
    // for every day, we will run a loop to find the max for that last variable
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            // for every last variable value, we will have a loop for the task value
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                    dp[day][last] = max(dp[day][last], points[day][task] + dp[day - 1][task]);
            }
        }
    }
    return dp[n - 1][3];
}

// now we will use the space optimization approach
int ninjaTrainingSpaceOptimization(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        // for every last variable value, we will have a loop for the task value
        for (int last = 0; last < 4; last++)
            for (int task = 0; task <= 2; task++)
                if (task != last)
                    temp[last] = max(temp[last], points[day][task] + prev[task]);

        prev = temp;
    }
    return prev[3];
}
int main()
{
}