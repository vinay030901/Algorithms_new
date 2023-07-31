#include <bits/stdc++.h>
using namespace std;
void sortColors(vector<int> &arr)
{
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
            swap(arr[mid++], arr[low++]);
        else if (arr[mid] == 2)
            swap(arr[mid], arr[high--]);
        else
            mid++;
    }
}
int main()
{
}