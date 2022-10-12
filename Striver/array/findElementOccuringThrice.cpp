#include <bits/stdc++.h>
using namespace std;
int find(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = (high + low) / 2;
        if (mid % 2 == 1)
        {
            cout << "mid: " << mid << " val: " << arr[mid] << endl;
            if (arr[mid - 1] == arr[mid] && arr[mid] == arr[mid + 1])
                return arr[mid];
            else if (arr[mid] == arr[mid - 1])
                low = mid;
            else
                high = mid;
        }
        else
        {
            cout << "low: " << low << " mid: " << mid << " high: " << high << " val " << arr[mid] << endl;
            if (arr[mid] == arr[mid + 1])
                low = mid;
            else
                high = mid;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 1, 7, 7, 8, 8, 9, 9, 5, 5, 4, 4, 3, 3, 3, 0, 0};
    cout << find(arr) << endl;
}