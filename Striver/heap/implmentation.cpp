#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr, int n, int i)
{
    int left = 2 * i + 1, right = 2 * i + 2;
    int mx = i;
    if (left < n && arr[left] > arr[mx])
        mx = left;
    if (right < n && arr[right] > arr[mx])
        mx = right;
    if (mx != i)
    {
        swap(arr[mx], arr[i]);
        heapify(arr, n, mx);
    }
}
void buildHeap(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}
void insert(vector<int> &arr, int k)
{
    arr.push_back(k);
    int i = arr.size() - 1;
    while (i > 0)
    {
        if (arr[i] > arr[(i - 1) / 2])
        {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
        else
            break;
    }
}
void pop(vector<int>&arr)
{
    swap(arr[0],arr[arr.size() - 1]);
    arr.pop_back();
    int i=0,n=arr.size();
    while(i<n/2)
    {
        
    }
}
int main()
{

    vector<int> arr = {3, 9, 4, 5, 1, 10, 2, 13};
    buildHeap(arr, arr.size());
    for (auto it : arr)
        cout << it << " ";
    cout<<"\n";
    insert(arr, 11);
    for (auto it : arr)
        cout << it << " ";
    pop(arr);
}