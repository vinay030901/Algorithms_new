/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.



Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.


Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0*/

#include <bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int> &arr)
{
    vector<int> ans;
    int n = arr.size();
    stack<int> s;
    // important aspect to note is that negative values affect the left side and positive values affect the right side
    // so we will take care about the negative side only
    // so whenever we will encounter a negative value, we will remove the value in the stack until the negative value is greater than
    // stack top or we don't encounter another negative value
    // then we will check if we have same absolute values but opposite signs, then we will pop that too
    // then, if the top is negative, we will push the present value, otherwise we know that it has been removed by a more greater
    // positive value, so we won't push the present value
    for (int i = 0; i < n; i++)
    {
        if (s.empty() || arr[i] > 0)
            s.push(arr[i]);
        else
        {
            while (!s.empty() && s.top() > 0 && s.top() < abs(arr[i]))
                s.pop();
            if (!s.empty() && s.top() == abs(arr[i]))
                s.pop();
            else
            {
                if (s.empty() || s.top() < 0)
                    s.push(arr[i]);
            }
        }
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
}