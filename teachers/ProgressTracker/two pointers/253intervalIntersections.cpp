/*You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].



Example 1:


Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Example 2:

Input: firstList = [[1,3],[5,9]], secondList = []
Output: []


Constraints:

0 <= firstList.length, secondList.length <= 1000
firstList.length + secondList.length >= 1
0 <= starti < endi <= 109
endi < starti+1
0 <= startj < endj <= 109
endj < startj+1*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &first, vector<vector<int>> &second)
    {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < first.size() && j < second.size())
        {
            int a_start = first[i][0], a_end = first[i][1];
            int b_start = second[j][0], b_end = second[j][1];
            if (a_start <= b_end && a_end >= b_start)
                ans.push_back({max(a_start, b_start), min(a_end, b_end)});
            if (b_end >= a_end)
                i++;
            else
                j++;
        }
        return ans;
    }
};
int main()
{
    // Your code here
    return 0;
}