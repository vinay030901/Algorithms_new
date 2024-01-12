#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &arr, int target)
{
    int i = 0, j = arr[0].size() - 1;
    while (i < arr.size() && j >= 0)
    {
        if (arr[i][j] == target)
            return true;
        if (arr[i][j] > target)
            j--;
        else
            i++;
    }
    return false;
}
int main() {
    // Your code here
    return 0;
}