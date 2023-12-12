#include <bits/stdc++.h>
using namespace std;
// the simple logic here is that since the numbers are all less than n, then we will add n to every value, and then we check after dividing by n
// will give more than equal to 2, then that number appeared more than once.
int findDuplicate(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        arr[arr[i] % n] += n;
    }
    for (int i = 0; i < n; i++)
        if (arr[i] / n >= 2)
            return i;
    return 0;
}