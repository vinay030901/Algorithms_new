#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2, 3, -1, 4, 6, -3, 7, -5};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];
    cout << "prefix of array: ";
    for (int i = 0; i < n; i++)
        cout << prefix[i] << " ";

    /* so using prefix sum array we can find the sum of zero index to Ith index
    prefix[i] = sum[0,i]
    so we can find the sum from 'l' to 'r' in constant time.
    ex l=1 and r=5
    sum[1,5]=prefix[5] - prefix[0(1-1)]

    sum(i,j) = prefix[j] - prefix[i-1]*/

    // now we can also create the prefix count array, the prefix count array could be created for a specific index

    // for example, we have an array and we want to count the number of zeroes till a position
    int a[] = {0, 1, 1, 0, 0, 1, 1, 0};
    n = sizeof(a) / sizeof(a[0]);
    int c = 0;
    int prefixCount[n];
    if (a[0] == 0)
        prefixCount[0] = 1;
    else
        prefixCount[0] = 0;
    for (int i = 1; i < n; i++)
        if (a[i] == 0)
            prefixCount[i] = 1 + prefixCount[i - 1];
        else
            prefixCount[i] = prefixCount[i - 1];
    cout << "\nprefix count of array: ";
    for (int i = 0; i < n; i++)
        cout << prefixCount[i] << " ";

    /* so we need countOf0(i,j) =
    count of 0(2,6) = prefixCount(6)-prefixCount(1)
                            |           |
                            j           i-1*/
}