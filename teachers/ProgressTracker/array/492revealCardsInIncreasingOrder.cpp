#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // https://leetcode.com/problems/reveal-cards-in-increasing-order/solutions/200515/java-c-python-simulate-the-reversed-process/?orderBy=most_votes
    vector<int> deckRevealedIncreasing(vector<int> &arr)
    {
        deque<int> dq;
        sort(arr.rbegin(), arr.rend());
        dq.push_back(arr[0]);
        for (int i = 1; i < arr.size(); i++)
        {
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(arr[i]);
        }
        vector<int> ans(dq.begin(), dq.end());
        return ans;
    }
};
