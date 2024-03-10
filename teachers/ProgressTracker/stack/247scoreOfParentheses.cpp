/*Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.


Example 1:

Input: s = "()"
Output: 1
Example 2:

Input: s = "(())"
Output: 2
Example 3:

Input: s = "()()"
Output: 2


Constraints:

2 <= s.length <= 50
s consists of only '(' and ')'.
s is a balanced parentheses string.*/
#include <bits/stdc++.h>
using namespace std;
/*cur record the score at the current layer level.

If we meet '(',
we push the current score to stack,
enter the next inner layer level,
and reset cur = 0.

If we meet ')',
the cur score will be doubled and will be at least 1.
We exit the current layer level,
and set cur += stack.pop() + cur

Complexity: O(N) time and O(N) space*/
int scoreOfParentheses(string s)
{
    stack<int> st;
    int cur = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(cur);
            cur = 0;
        }
        else
        {
            cur += (st.top() + max(cur, 1));
            st.pop();
        }
    }
    return cur;
}

/*We count the number of layers.
If we meet '(' layers number l++
else we meet ')' layers number l--

If we meet "()", we know the number of layer outside,
so we can calculate the score res += 1 << l.*/
int scoreOfParentheses(string s)
{
    int res = 0, layers = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            layers++;
        else
            layers--;
        if (s[i] == ')' && s[i - 1] == '(')
            res += 1 << layers;
    }
    return res;
}
int main()
{
    // Your code here
    return 0;
}