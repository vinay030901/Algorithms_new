/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result,
and there will not be any division by zero operation.

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22*/
#include <bits/stdc++.h>
using namespace std;
int evalRPN(vector<string> &arr)
{
    // it was easy to implement it, we just put every element into a stack and whenever we encounter any operation, we will 
    // pop two element from the stack and we do the operation on them and push them back again
    stack<string> s;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == "+" || arr[i] == "-" || arr[i] == "*" || arr[i] == "/")
        {
            int first = stoi(s.top());
            s.pop();
            int second = stoi(s.top());
            s.pop();
            int res;
            if (arr[i] == "+")
                res = first + second;
            else if (arr[i] == "-")
                res = second - first;
            else if (arr[i] == "*")
                res = first * second;
            else if (arr[i] == "/")
                res = second / first;
            s.push(to_string(res));
            // cout<<first<<" "<<second<<" "<<res<<endl;
        }
        else
            s.push(arr[i]);
    }
    return stoi(s.top());
}
int main()
{
}