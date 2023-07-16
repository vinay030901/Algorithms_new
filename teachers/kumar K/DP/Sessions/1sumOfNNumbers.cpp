/*You are given an array and you have to find the sum of element from index 1 to given index
 */
#include <bits/stdc++.h>
using namespace std;

// but this technique is taking O(N) time and we will be given q queries, so for each query we will need to run a for loop and this
// is not efficient
void findSum(vector<int> &arr, int i)
{
    int sum = 0;
    for (int j = 0; j <= i; j++)
        sum += arr[j];
    cout << sum;
}

//
int main()
{

    return 0;
}