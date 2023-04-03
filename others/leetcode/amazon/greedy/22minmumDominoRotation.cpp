/*
In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino.
(A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

If it cannot be done, return -1.



Example 1:


Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
Output: 2
Explanation:
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
Output: -1
Explanation:
In this case, it is not possible to rotate the dominoes to make one row of values equal.
*/
#include <bits/stdc++.h>
using namespace std;
int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
{
    unordered_map<int, int> mp;
    int mx = 0, mxNum;
    for (int i = 0; i < tops.size(); i++)
    {
        mp[tops[i]]++;
        if (mp[tops[i]] > mx)
        {
            mx = mp[tops[i]];
            mxNum = mp[tops[i]];
        }
    }
    for (int i = 0; i < bottoms.size(); i++)
    {
        mp[bottoms[i]]++;
        if (mp[bottoms[i]] > mx)
        {
            mx = mp[bottoms[i]];
            mxNum = bottoms[i];
        }
    }
    cout << mx << endl;
    if (mx < tops.size())
        return -1;

    int top = 0, bottom = 0;
    int ftop = 0, fbottom = 0;
    for (int i = 0; i < tops.size(); i++)
    {
        if (tops[i] == mxNum)
            continue;
        else if (bottoms[i] == mxNum)
            top++;
        else
            ftop = 1;
    }
    for (int i = 0; i < bottoms.size(); i++)
    {
        if (bottoms[i] == mxNum)
            continue;
        else if (tops[i] == mxNum)
            bottom++;
        else
            fbottom = 1;
    }
    if (ftop == 1 && fbottom == 1)
        return -1;
    else if (ftop == 0 && fbottom == 0)
        return min(top, bottom);
    else if (ftop == 1)
        return bottom;
    return top;
}

/*
ALGORITHM
We will keep faceA for count the occurences of numbers in tops.
faceB for count the occurences of n umbers in bottoms.
same for counting the same occurences in top & bottom.
We wiil try all possibilities of domino from 1 to 6.
If we can make number i in a whole row it should satisfy that faceA[i] + faceB[i] - same[i] == n
eg the first test Case.
tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
faceA[2] = 4 , as tops[0] = tops[2] = tops[4] = tops[5]
faceB[2] = 3, as bottoms[1] = bottoms[3] = bottoms[5]
same[2] = 1, as tops[5] = bottoms[5]
Therefore we have faceA[2] + faceB[2] - same[2] = 6, (size of arr)
Therfore we can make 2 in a whole row.*/
int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
{
    vector<int> faceA(7), faceB(7), same(7);
    int n = tops.size();
    for (int i = 0; i < n; i++)
    {
        faceA[tops[i]]++;
        faceB[bottoms[i]]++;
        if (tops[i] == bottoms[i])
            same[tops[i]]++;
    }
    int mn = INT_MAX;
    for (int i = 1; i <= 6; i++)
    {
        if (faceA[i] + faceB[i] - same[i] == n)
            mn = min(mn, min(faceA[i], faceB[i]) - same[i]);
    }
    return mn;
}
int main()
{
}