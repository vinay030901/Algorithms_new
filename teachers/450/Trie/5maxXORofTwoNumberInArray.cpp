/*
The first line of the input contains an integer, 'T,’ denoting the number of test cases.

The first line of each test case contains two space-separated integers, 'N' and ‘M’ denoting the number of elements in the first and second array.

The second line of each test case contains 'N' space-separated integers denoting the elements of the array first array.

The last line of each test case contains 'M' space-separated integers denoting the elements of the array second array.
Output Format:
For each test case, print a single integer - the maximum possible xor among all possible pairs.

Print the output of each test case in a separate line.
Note :
You do not need to input or print anything, and it has already been taken care of. Just implement the given function.
Constraints:
1 <=  T  <= 5
1 <=  N, M <= 1000
0 <=  arr1[i], arr2[i]  <= 10 ^ 9

Where 'T' denotes the number of test cases, 'N', ‘M’ denotes the number of elements in the first array and second array, ‘arr1[i]', and ‘arr2[i]’ denotes the 'i-th' element of the first array and second array.

Time limit: 1 sec
Sample Input 1:
1
7 7
6 6 0 6 8 5 6
1 7 1 7 8 0 2
Sample Output 1:
15
Explanation of sample input 1:
First testcase:
Possible pairs are (6, 7), (6, 8), (6, 2), (8, 7), (8, 8), (6, 2). And 8 xor 7 will give the maximum result i.e. 15
Sample Input 2:
1
3 3
25 10 2
8 5 3
Sample Output 2:
28
Explanation of sample input 2:
First test case:
28 is the maximum possible xor given by pair = (25, 5). It is the maximum possible xor among all possible pairs. */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    
}