/*Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

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


Constraints:

1 <= task.length <= 104
tasks[i] is upper-case English letter.
The integer n is in the range [0, 100].*/

#include <bits/stdc++.h>
using namespace std;
int leastInterval1(vector<char> &arr, int n)
{
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
int leastInterval(vector<char> &arr, int n)
{
    if (n == 0)
        return arr.size();
    unordered_map<char, int> mp;
    int mx = 0;
    for (char c : arr)
    {
        mp[c]++;
        mx = max(mp[c], mx);
    }
    // we will find the mx frequency-
    // for ex- a a a b b  and n=2
    // now we need- a b i a b i a
    // it means that 2 groups of 3 size will be made and 1 extra space for a
    // therefore we will first get 6 by (mx-1)*(n+1)- n+1 because 1 for idle
    // and later we will take the variables which have max values
    int ans = (mx - 1) * (n + 1);
    for (auto it : mp)
    {
        if (it.second == mx)
            ans++;
    }
    ans = max(ans, (int)arr.size());
    return ans;
}
int main()
{
    // Your code here
    return 0;
}