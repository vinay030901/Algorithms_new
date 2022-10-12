// we have to find the minimum element without using any extra space
#include <bits/stdc++.h>
using namespace std;
stack<int> s;
int minEle;
void push(int val)
{
    if (s.empty())
    {
        s.push(val);
        minEle = val;
    }
    else if (val < minEle)
    {
        minEle = val;
        s.push(2 * val - s.top());
    }
    else
        s.push(val);
}

void pop()
{
    if (minEle > s.top())
        minEle = 2 * minEle - s.top();
    s.pop();
}

int top()
{
    if (s.empty())
        return -1;
    else if (minEle > s.top())
        return minEle;
    else
        return s.top();
}

int getMin()
{
    if (s.empty())
        return -1;
    return minEle;
}
int main()
{
}