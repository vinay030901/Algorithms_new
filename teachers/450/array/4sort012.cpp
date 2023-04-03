// sort an array of 0's, 1's and 2's
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // we will follow the dutch flag algorithm
    int arr[] = {2, 0, 1, 1, 2, 0, 2, 2, 0, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // we'll be having low, high and mid and we will swap accordingly
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        // if we have 0, then we'll swap them and increase the value of low, so that next 0 could be accommodated there
        if (arr[mid] == 0)
            swap(arr[low++], arr[mid++]);
        // if we get 1, then there's no need of swapping
        else if (arr[mid] == 1)
            mid++;
        // getting 2 will need swapping of high and mid, we will decrement high afterthat
        else if (arr[mid] == 2)
            swap(arr[mid], arr[high--]);
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}