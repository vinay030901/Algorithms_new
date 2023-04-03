#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*
    we are given an array and we need to find the greater element just right of that particular of that element
    vec- 1 3 2 4
    ans- 3 4 4 -1

    vec- 1 3 0 0 1 2 4
    ans- 3 4 1 1 2 4 -1


    so what we will do to process this problem is use of stack

    since we want to get greater to right, we will process from right only, as the rightmost element will have the answer as 1
    then we push the element in the stack
    then we will move left, and compare the element, if the element is smaller than top, we will push the element into it and push the answer
    but if the element is greater, we will pop the element till we get a top which is greater than that element
    and then at the end, we will push  that element into the stack

    if we have 1 3 2 4
    1. 4- empty stack
    stack- 4  ans- -1

    2. 2 - less than 4
    stack 4 2 ans- -1 4

    3. 3- greater than 2-
    pop 2
    less than 4- push
    stack- 4 3 ans- -1 4 4

    4. 1- less than 3
    stack- 4 3 1 ans- -1 4 3 3

    now we reverse our answer- 3 3 4 -1
    */

    vector<int> v = {1, 3, 2, 4}, ans;
    stack<int> s;
    int n = v.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
            ans.push_back(-1);
        else if (s.top() > v[i])
        {
            ans.push_back(s.top());
        }
        else
        {
            while (!s.empty() && s.top() <= v[i])
                s.pop();
            if (s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }
        s.push(v[i]);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}