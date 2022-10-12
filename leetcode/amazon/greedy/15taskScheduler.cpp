/*
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.



Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation:
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
Example 3:

Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation:
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
*/
#include <bits/stdc++.h>
using namespace std;
int leastInterval(vector<char> &arr, int n)
{
    // the best approach for this question is using our own mind, we can see that if we have a value A, and n value is 2
    // then there will be 3 space needed for it, one for A and other two is the cooldown period
    // we can device that formula using this only that output=(freq(A)-1)*(n+1)+1
    // if we have other values with same max frequency too, then we can add 1 to it, since they will be inbetween those
    // cooldown peroid only

    unordered_map<char, int> mp;
    int mx = INT_MIN;
    for (char c : arr)
    {
        mp[c]++;
        mx = max(mx, mp[c]);
    }
    int ans = (mx - 1) * (n + 1);
    for (auto it : mp)
    {
        if (it.second == mx)
            ans++;
    }
    ans = max(ans, (int)arr.size());
    return ans;
}

int leastInterval(vector<char> &arr, int n)
{
    // another approach is to use the heap for this process
    // we will go till a length of n in every iteration in our process
    // we will take the help of map for storing the count of every element
    unordered_map<char, int> mp;
    int ans = 0;
    for (int it : arr)
        mp[it]++;
    priority_queue<int> mx;
    for (auto it : mp)
        mx.push(it.second);
    
    // we will work on our heap, where every element will be used after a span of n 
    
    while (!mx.empty())
    {
        vector<int> temp;
        for (int i = 0; i <= n; i++)
        {
            if (!mx.empty())
            {
                temp.push_back(mx.top());
                mx.pop();
            }
        }
        for (int it : temp)
        {
            if (--it > 0)
                mx.push(it);
        }
        ans += (mx.empty() ? temp.size() : n + 1);
    }
    return ans;
}
int main()
{
}