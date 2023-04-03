/*
Given a string s which represents an expression, evaluate this expression and return its value.

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().



Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5*/
#include <bits/stdc++.h>
using namespace std;
int calculate(string str)
{
    // here we have used the stack for solving the problem
    // first check if it is a digit, since the value of digit could be very long, we will keep checking it, and when we get any
    // operation, then we check if it is +,-,* or /
    // if it is plus or minus, instead of solving it there,we will put it in a stack as a positive or negative number depending on the
    // operation we get
    int n = str.length();
    stack<int> s;
    int res = 0;
    int curr = 0;
    char oper = '+';
    for (int i = 0; i < n; i++)
    {
        char c = str[i];
        if (isdigit(c))
            curr = curr * 10 + int(c - '0');
        if (!isdigit(c) && !isspace(c) || i == n - 1)
        /* why we have i==n-1
        Take the expression "3+2*2" . In this case till i=s.size()-1 in stack value stored are 3 and 2 and in temp value stored is 2
        and sign contains * . If we don't use that condition fun just returns 3+2 i.e. 5 . So, in order to get right evaluation
        we at last also check condition i==s.size()-1 which check whether something is left in temp and sign or not*/
        {
            if (oper == '+')
                s.push(curr);
            else if (oper == '-')
                s.push(-curr);
            else
            {
                int res = 0;
                if (oper == '*')
                    res = curr * s.top();
                else if (oper == '/')
                    res = s.top() / curr;
                s.pop();
                s.push(res);
            }
            oper = c;
            curr = 0;
        }
    }
    int ans = 0;
    while (!s.empty())
        ans += s.top(), s.pop();
    return ans;
}

// we can also solve this problem without using any extra space
/*
Approach 2: Optimised Approach without the stack
Intuition

In the previous approach, we used a stack to track the values of the evaluated expressions.
In the end, we pop all the values from the stack and add to the result.
Instead of that, we could add the values to the result beforehand and keep track of the last calculated number,
thus eliminating the need for the stack. Let's understand the algorithm in detail.

Algorithm

The approach works similar to Approach 1 with the following differences :

Instead of using a stack, we use a variable lastNumber to track the value of the last evaluated expression.
If the operation is Addition (+) or Subtraction (-), add the lastNumber to the result instead of pushing it to the stack.
The currentNumber would be updated to lastNumber for the next iteration.
If the operation is Multiplication (*) or Division (/), we must evaluate the expression lastNumber * currentNumber and
update the lastNumber with the result of the expression. This would be added to the result after the entire string is scanned.*/
int calculate(string str)
{
    int n = str.length();
    int res = 0;
    int last = 0;
    int curr = 0;
    char oper = '+';
    for (int i = 0; i < n; i++)
    {
        char c = str[i];
        if (isdigit(c))
            curr = curr * 10 + int(c - '0');
        if (!isdigit(c) && !isspace(c) || i == n - 1)
        {
            if (oper == '+' || oper == '-')
            {
                res += last;
                last = (oper == '+') ? curr : -curr;
            }
            else if (oper == '*')
                last = last * curr;
            else if (oper == '/')
                last = last / curr;
            oper = c;
            curr = 0;
        }
    }
    res += last;
    return res;
}
int main()
{
}