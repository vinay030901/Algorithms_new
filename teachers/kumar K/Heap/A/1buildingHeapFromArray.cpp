#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr, int i, int n)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (i != largest)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}
void buildHeap(vector<int> &arr, int n)
{
    int start = n / 2 - 1;
    for (int i = start; i >= 0; i--)
        heapify(arr, i, n);
}
int main()
{
    vector<int> arr = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = arr.size();
    buildHeap(arr, n);
    for (auto it : arr)
        cout << it << " ";
    return 0;
}