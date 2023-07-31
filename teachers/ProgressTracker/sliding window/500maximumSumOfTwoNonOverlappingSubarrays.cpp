#include <bits/stdc++.h>
using namespace std;
int maxSum(vector<int> &p, int l, int m)
{
    int maxL = 0, ans = 0;
    for (int i = l + m; i < p.size(); i++)
    {
        maxL = max(maxL, p[i - m] - p[i - m - l]);
        ans = max(ans, maxL + p[i] - p[i - m]);
    }
    return ans;
}
// https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/solutions/279221/java-python-3-two-easy-dp-codes-w-comment-time-o-n-no-change-of-input/?orderBy=most_votes
int maxSumTwoNoOverlap(vector<int> &arr, int firstLen, int secondLen)
{
    vector<int> prefix(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); i++)
        prefix[i + 1] = prefix[i] + arr[i];
    return max(maxSum(prefix, firstLen, secondLen), maxSum(prefix, secondLen, firstLen));
}