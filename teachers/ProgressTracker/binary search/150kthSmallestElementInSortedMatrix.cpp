/*Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).



Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5


Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2


Follow up:

Could you solve the problem with a constant memory (i.e., O(1) memory complexity)?
Could you solve the problem in O(n) time complexity? The solution may be too advanced for an interview but you may find reading this paper fun.*/
#include <bits/stdc++.h>
using namespace std;
int kthSmallest(vector<vector<int>> &arr, int k)
{
    // https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/1685550/Here's-why-Binary-Search-works.-(Explain-it-to-me-like-I'm-5
    int low = arr[0][0], high = arr[arr.size() - 1][arr[0].size() - 1];
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int count = 0, j = arr[0].size() - 1;
        for (int i = 0; i < arr.size(); i++)
        {
            while (j >= 0 && arr[i][j] > mid)
                j--;
            count += (j + 1);
        }
        if (count < k)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}
int kthSmallest1(vector<vector<int>> &matrix, int k)
{
    // we can also do this question using min heap like the question of k sorted arrays
    // so we take first element from the columns and take the elements accordingly
    auto comp = [&](vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    };
    priority_queue<vector<int>, vector<vector<int>>, greater<>> mn;

    int m = matrix[0].size();
    for (int i = 0; i < matrix.size(); i++)
        mn.push({matrix[i][0], i, 0});
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        auto vec = mn.top();
        mn.pop();
        ans = vec[0];
        int row = vec[1], col = vec[2];
        if (col + 1 < m)
            mn.push({matrix[row][col + 1], row, col + 1});
    }
    return ans;
}
int main()
{
    // Your code here
    return 0;
}