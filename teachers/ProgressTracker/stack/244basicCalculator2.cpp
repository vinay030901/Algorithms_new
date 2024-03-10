#include <bits/stdc++.h>
using namespace std;

// without using extra space
class Solution
{
public:
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
};
int calculate(string str)
{
    // solving this question using extra space
    // https://leetcode.com/problems/basic-calculator-ii/discuss/1645655/C%2B%2B-Intuitive-Solution-(W-explanation)-or-Stack
    vector<int> s;
    int curr = 0, ans = 0, n = str.length();
    char op = '+';
    for (int i = 0; i < n; i++)
    {
        if (isdigit(str[i]))
            curr = curr * 10 + (str[i] - '0');
        if (i == n - 1 || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            if (op == '+')
            {
                s.push_back(curr);
            }
            else if (op == '-')
                s.push_back((-1) * curr);
            else if (op == '*')
            {
                int num = s.back();
                s.pop_back();
                s.push_back(num * curr);
            }
            else if (op == '/')
            {
                int num = s.back();
                s.pop_back();
                s.push_back(num / curr);
            }
            op = str[i];
            curr = 0;
        }
    }
    ans = accumulate(s.begin(), s.end(), 0);
    return ans;
}
int main()
{
    // Your code here
    return 0;
}