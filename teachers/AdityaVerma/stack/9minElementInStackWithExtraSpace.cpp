// implement a stack which can find minimum element in contant time but with extra space
#include <bits/stdc++.h>
using namespace std;
stack<int> s;
stack<int> st;
void push(int val)
{
    s.push(val);
    if (st.empty() || s.top() <= st.top())
        st.push(s.top());
}

void pop()
{
    if (!st.empty())
        if (s.top() == st.top())
            st.pop();
    s.pop();
}

int top()
{
    return s.top();
}

int getMin()
{
    if (st.empty())
        return -1;
    return st.top();
}
int main()
{
}