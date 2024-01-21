#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &arr, int target)
{
    int l = 0, h = arr.size() * arr[0].size() - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        int val = arr[mid / arr[0].size()][mid % arr[0].size()];
        if (val == target)
            return true;
        else if (val > target)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}
int main()
{
    // Your code here
    return 0;
}