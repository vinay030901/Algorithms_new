/*
Given an expression with only ‘}’ and ‘{‘. The expression may not be balanced. Find minimum number of bracket reversals to make the expression balanced.
Examples:

Input:  exp = "}{"
Output: 2
We need to change '}' to '{' and '{' to
'}' so that the expression becomes balanced,
the balanced expression is '{}'

Input:  exp = "{{{"
Output: Can't be made balanced using reversals

Input:  exp = "{{{{"
Output: 2

Input:  exp = "{{{{}}"
Output: 1

Input:  exp = "}{{}}{{{"
Output: 3
*/
#include <bits/stdc++.h>
using namespace std;
int findMin(string str, int n)
{
    if (n % 2)
        return -1;
    stack<char> st;
    // in this approach we will first remove those brackets which are balanced, so we will use the stack 
    // and if the top elements isn't the closing bracket for the openining brackets, we will push that element
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '}' && !st.empty())
        {
            if(st.top()=='{') st.pop();
            else st.push(str[i]);
        }
        else
            st.push(str[i]);
    }
    int size=st.size(),open_count=0;
    while(!st.empty())
    {
        if(st.top()=='{')
            open_count++;
        st.pop();
    }
    int close_count=size-open_count;
    // now we got the count of closed and open brackets, we will find the answer according to them
    /* }}} {{{{{
    so if like above we have 3 closed and 5 open brackets, 
    for open({{{{{), we will do- }{}{}- means we turned 3 brackets-> ceil(5/2)
    and for close(}}})- we will turn only one bracket, so we turn two brackets here-> ceil(3/2)*/
    return (ceil(close_count/2)+ceil(open_count/2));
}
int main()
{
    string str = "}}{}{{{{";
    int n = str.length();
    int ans = 0;
    cout << findMin(str, n);
}