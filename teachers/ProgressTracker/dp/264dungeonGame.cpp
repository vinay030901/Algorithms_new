/*The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).

To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Return the knight's minimum initial health so that he can rescue the princess.

Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
Example 1:


Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
Output: 7
Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
Example 2:

Input: dungeon = [[0]]
Output: 1


Constraints:

m == dungeon.length
n == dungeon[i].length
1 <= m, n <= 200
-1000 <= dungeon[i][j] <= 1000*/
#include <bits/stdc++.h>
using namespace std;
// 1st sub step : asking questions

// At any point if our health gets zero of below we dies, athem so : we need 1 + (-mat[i][j]) for our health to be one.
// What if we get some health if we arrive at some cell ? my guess is we still need 1 health in first case to arrive at that cell - cases like these need to be figure out by yourself.
// at any cell what health do we need ? - since we can go only down and right therefore min health required will be minimun health required if we go right or down, ( futher explained in arriving at recurrance relation heading )
// for brief answers/explanation for above point 1 and 2 , assume a 1D matrix this is what is ment by 1st and 2nd point.

// [[-10]]                     :
// ans = 1 + (-(-10)) = 11(explanation to first point mentioned)
//           [[10]] : ans = 1 as we still need 1 health at first place to get
//                    there(explanation to second point mentioned)
//                        [[ -2, -3, 3, -5, -10 ]] : ans = 1 + (-(-17)) = 18 same as 1st case
//                                                             [[ 2, 3, 3, 5, 10 ]]:
// ans = 1 same as 2nd test case, explanation to second point mentioned to asking question 2nd sub step:
// Ariving at recurence relation
//     recurrence relation is pretty straight forward at any cell,
//     if we are at any particular cell we must ask should we go right or down ? if we know the answer for min health req if we go right vs we go down, then we can easily choose image

int getVal(vector<vector<int>> &mat, int i = 0, int j = 0)
{
    int n = mat.size();
    int m = mat[0].size();
    // Base case : we have crossed the matrix, ie. out of bound
    /// if current row crosses then my row is below the princess or
    /// if current column crosses then my column is ahead the column of princess
    /// and beacause we can go only down and right so we wont be able reach princess
    if (i == n || j == m)
        return 1e9;

    // Base Case : we have reached our destination ie. last cell
    /// we reached princess , cheers return this cost;
    if (i == n - 1 and j == m - 1)
        return (mat[i][j] <= 0) ? -mat[i][j] + 1 : 1;

    /// now we must try all possible paths , we ask our right and and down cell
    int IfWeGoRight = getVal(mat, i, j + 1);
    int IfWeGoDown = getVal(mat, i + 1, j);

    /// min of either values and then cost of this cell
    int minHealthRequired = min(IfWeGoRight, IfWeGoDown) - mat[i][j];

    /// point 2 as explained
    return (minHealthRequired <= 0) ? 1 : minHealthRequired;
}

int calculateMinimumHP(vector<vector<int>> &dungeon)
{
    return getVal(dungeon);
}
// Now you know how to solve this recurssively, lets now observe time complexity ... ... yep its exponential ! . but luckily we are doing same task over and over again. ( for example we are asking 6 times the last cell its cost in 3X3 matrix), we can overcome this task by storing the values of cost at each cell ( aka memoization ).

// step4 : memoization-top-down
// lets maintain a DP matrix which will store the calculated values for its cell. next time if we arrive at this cell we will return this calculated value to save recurrsive calls.

int getVal(vector<vector<int>> &mat, vector<vector<int>> &dp, int i = 0, int j = 0)
{
    int n = mat.size();
    int m = mat[0].size();

    if (i == n || j == m)
        return 1e9;

    if (i == n - 1 and j == m - 1)
        return (mat[i][j] <= 0) ? -mat[i][j] + 1 : 1;

    /// if we know the answer for this cell then no need to recalculate those, simply return those values
    if (dp[i][j] != 1e9)
        return dp[i][j];

    int IfWeGoRight = getVal(mat, dp, i, j + 1);
    int IfWeGoDown = getVal(mat, dp, i + 1, j);

    int minHealthRequired = min(IfWeGoRight, IfWeGoDown) - mat[i][j];

    /// before returning the values, we must store the answers for this cell which we hacve calculated
    /// in next recurssive call this value will be used to save some computation, aka repetative work which we are doing.
    dp[i][j] = (minHealthRequired <= 0) ? 1 : minHealthRequired;
    return dp[i][j];
}

int calculateMinimumHP(vector<vector<int>> &dungeon)
{

    int n = dungeon.size();
    int m = dungeon[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 1e9));

    return getVal(dungeon, dp);
}
// so now you know the recursive solution, you have also tried memoization, so try coming up with bottomUp solution yourself, HINT : as you might have observed final destination is the last cell, so why dont we start with the bottom cell itself.then work all the way up to first cell.

//                                                                                                                                                                                                  step 5 : You know the base casses,
//                                                                                                                                   you know the sub problems so try coming up with bottom up solution
//                                                                                                                                   yourself(hint in above paragraph)

int calculateMinimumHP(vector<vector<int>> &dungeon)
{

    int n = dungeon.size();
    int m = dungeon[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
    dp[n][m - 1] = 1;
    dp[n - 1][m] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
            // store this value
            dp[i][j] = need <= 0 ? 1 : need;
        }
    }
    return dp[0][0];
}
// it takes a lots of time and effort to write post like these, if you learned something then, then consider upvoting, so that this post reach beginners.
int main()
{
    // Your code here
    return 0;
}