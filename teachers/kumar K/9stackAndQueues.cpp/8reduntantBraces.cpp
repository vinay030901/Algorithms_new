/*
Given a string A denoting an expression. It contains the following operators '+', '-', '*', '/'.

Chech whether A has redundant braces or not.

NOTE: A will be always a valid expression.



Problem Constraints
1 <= |A| <= 105



Input Format
The only argument given is string A.



Output Format
Return 1 if A has redundant braces, else return 0.



Example Input
Input 1:

 A = "((a+b))"
Input 2:

 A = "(a+(a+b))"
Input 3:

 A = "((a*b)+(c+d))"


Example Output
Output 1:

 1
Output 2:

 0
Output 3:

 0


Example Explanation
Explanation 1:

 ((a+b)) has redundant braces so answer will be 1.
Explanation 2:

 (a+(a+b)) doesn't have have any redundant braces so answer will be 0.
Explanation 3:

 ((a*b)+(c+d)) doesn't have have any redundant braces so answer will be 0.*/
#include <bits/stdc++.h>
using namespace std;
int braces(string A)
{
    int n = A.size();
    for (int i = 0; i < n - 2; i++)
    {
        if (A[i] == '(' && A[i + 1] == ')')
        {
            return 1;
        }
        if (A[i] == '(' && A[i + 2] == ')')
        {
            return 1;
        }
        if (A[i] == '(' && A[i + 1] == '(')
        {
            int j = 1 + 2;
            while (A[j] != ')')
            {
                j++;
            }
            if (A[j + 1] == ')')
                return 1;
        }
    }
    return 0;
}
int main()
{

    return 0;
}