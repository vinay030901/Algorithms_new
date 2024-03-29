/*The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.



Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"


Constraints:

1 <= n <= 9
1 <= k <= n!*/
#include <bits/stdc++.h>
using namespace std;
/*This problem is recursive like dynamic programming.
Kth Permutation sequence can be formed by choosing the 1st digit and then the rest of the digits one by one.
Visually:
1 + (permutations of rest of digits)
2 + (permutations of ...)
so on...

For N=3,
we have the permutations:
1|2,3
1|3,2
2|1,3
2|3,1
3|1,2
3|2,1

I put a bar "|" to separate first digit from the rest of digits.
There are a total of N! = 3! = 6 perms. Each 1st digit is "attached" to (n-1)! =2! = 2 permutations formed by rest of digits.
Thus , to choose 1st digit, simply calculate (k-1) / (n-1)! and use it to index into an array of digits 1,2,3,
Once 1st digit is chosen, we choose 2nd and so on recursively.

We remove 1st digit from the array of digits , so the remaining are the "rest of digits".
There are 2 ways to remove:

pull the chosen digit from its current place to the right place in the permutation and shift rest of digits accordingly. (this is the in-place method chosen in my code so left part is partially formed permuation and right part is the candidates)
mark the chosen digit as "used" so you don't use it again. (need an array of booleans to track)
Notice the candidates always remain sorted regardless of which digit is removed. This is an important property to solve the problem recursively.*/
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> numbers;
        for (int i = 1; i < n; i++)
        {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans = "";
        k = k - 1;
        while (true)
        {
            ans = ans + to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);
            if (numbers.size() == 0)
                break;
            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};
int main()
{
    // Your code here
    return 0;
}