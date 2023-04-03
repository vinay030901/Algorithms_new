/*
Given a sequence of words, and a limit on the number of characters that can be put in one line (line width).
Put line breaks in the given sequence such that the lines are printed neatly. Assume that the length of each word is
smaller than the line width.
The word processors like MS Word do task of placing line breaks. The idea is to have balanced lines. In other words,
not have few lines with lots of extra spaces and some lines with small amount of extra spaces.


The extra spaces includes spaces put at the end of every line except the last one.
The problem is to minimize the following total cost.
 Cost of a line = (Number of extra spaces in the line)^3
 Total Cost = Sum of costs for all lines

For example, consider the following string and line width M = 15
 "Geeks for Geeks presents word wrap problem"

Following is the optimized arrangement of words in 3 lines
Geeks for Geeks
presents word
wrap problem

The total extra spaces in line 1, line 2 and line 3 are 0, 2 and 3 respectively.
So optimal value of total cost is 0 + 2*2 + 3*3 = 13
The greedy solution is to place as many words as possible in the first line. Then do the same thing for the second
line and so on until all words are placed. This solution gives optimal solution for many cases, but doesn’t give
optimal solution in all cases. For example, consider the following string “aaa bb cc ddddd” and line width as 6.
Greedy method will produce following output.

aaa bb
cc
ddddd
Extra spaces in the above 3 lines are 0, 4 and 1 respectively. So total cost is 0 + 64 + 1 = 65.
But the above solution is not the best solution. Following arrangement has more balanced spaces. Therefore less value
of total cost function.

aaa
bb cc
ddddd
Extra spaces in the above 3 lines are 3, 1 and 1 respectively. So total cost is 27 + 1 + 1 = 29.
Despite being sub-optimal in some cases, the greedy approach is used by many word processors like MS Word
and OpenOffice.org Writer.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cout << "enter size: ";
    cin >> n;
    int arr[n + 1];
    cout << "enter the elements of the array: ";
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    cout << "enter limit: ";
    cin >> k;
    /* so we know greedy approach is wrong and doesn't give optimal solution.
    therefore we will use dp solution for this which is little confusing though.

    first we will create a cost table,

    3   9   0   inf inf
    2       16  INF INF
    2           16  INF
    5               1

    so, in this table I have calculated the length after placing every word, like for
    3-> k-3=3
    then cost= 3^2=9
    when we place 2 with 3
    (3+2)+1(space)->k-6=0
    then cost=0^2=0

    so this has happened with every index*/
    int space[n + 1][n + 1];
    // this space will first calculate the space between elements, which will squared later if it is non-negative
    /* for {3,2,2,5} and k=6, it is:

    3   3   0   neg neg
    2       4   1   neg
    2           4   neg
    5               1*/
    for (int i = 1; i <= n; i++)
    {
        space[i][i] = k - arr[i];
        for (int j = i + 1; j <= n; j++)
        {
            space[i][j] = space[i][j - 1] - arr[j] - 1;
        }
    }
    int dp[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (space[i][j] < 0)
                dp[i][j] = INT_MAX; // space is less than 0, then it is infinite.
            else if (j == n and space[i][j] >= 0)
                dp[i][j] = 0;
            else
                dp[i][j] = space[i][j] * space[i][j];
        }
    }
    /*now we create two array, cost and arrangement array
    cost array will have the cost from one particular index to another.
    while arrangement will have he positional value*/
    cout << "dp:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int cost[n + 1] = {0}, arrangement[n + 1];

    cost[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cost[i] = INT_MAX;
        /*we are starting from start of cost, and if our previous value in cost is not equal to INT_MAX
        and dp at there is also not max, then if cost + dp is less than cost at that position, then
        we will give new value to cost*/
        for (int j = 1; j <= i; j++)
        {
            if (cost[j - 1] != INT_MAX and dp[j][i] != INT_MAX and cost[j - 1] + dp[j][i] < cost[i])
            {
                cost[i] = cost[j - 1] + dp[j][i];
                arrangement[i] = j;
            }
            for (int l = 1; l <= n; l++)
                cout << cost[l] << " ";
            cout << endl;
        }
    }
    for (int l = 1; l <= n; l++)
        cout << cost[l] << " ";
    cout << endl;
    cout << "\narrangement: \n";
    for (int i = 1; i <= n; i++)
        cout << arrangement[i] << " ";
}