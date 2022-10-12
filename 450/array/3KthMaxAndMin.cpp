#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int k;
    k = *a;
    *a = *b;
    *b = k;
}
// Standard partition process of QuickSort().
// It considers the last element as pivot and
// oves all smaller element to left of it
// and greater elements to right
int partition(int *arr, int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int randomPartition(int *arr, int l, int r)
{
    int n = r - l + 1;
    int pivot = (rand() % 100 + 1) % n;
    swap(arr[l + pivot], arr[r]);
    return partition(arr, l, r);
}

// This function returns k'th smallest
// element in arr[l..r] using
// QuickSort based method. ASSUMPTION:
// ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int *arr, int l,
                int r, int k)
{

    // If k is smaller than number
    // of elements in array
    if (k > 0 && k <= r - l + 1)
    {

        // Partition the array around last
        // element and get position of pivot
        // element in sorted array
        int pos = randomPartition(arr, l, r);

        // If position is same as k
        if (pos - l == k - 1)
        {
            return arr[pos];
        }

        // If position is more, recur
        // for left subarray
        if (pos - l > k - 1)
        {
            return kthSmallest(arr, l, pos - 1, k);
        }

        // Else recur for right subarray
        return kthSmallest(arr, pos + 1, r,
                           k - pos + l - 1);
    }

    // If k is more than number of
    // elements in array
    return INT_MAX;
}
void quickSort(int arr[], int low, int high)
{
    if (low <= high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    vector<int> arr = {3, 4, 2, 1, 5, 7, 10, -1, 67, 223, 6};
    int n = arr.size();
    int k = 5;
    // first method is to sort and find the max and min using it, time= O(NlogN)
    // but we can do it in lesser complexity using heaps, that is O(NlogK)
    // for Kth Max
    priority_queue<int, vector<int>, greater<int>> mn;
    priority_queue<int> mx;
    for (int i = 0; i < n; i++)
    {
        mn.push(arr[i]);
        if (mn.size() > k)
            mn.pop();
        // Min heap will remove the smaller element which will come at the top and we'll be remained with the max elements
        // same is the case with the max heap where greater element will be popped and we get smaller element
        mx.push(arr[i]);
        if (mx.size() > k)
            mx.pop();
    }
    cout << "Kth largest element is: " << mn.top() << endl;
    cout << "Kth minimum element is: " << mx.top() << endl;

    // we can also do this using set
    // all elements must be distinct
    set<int> s(arr.begin(), arr.end());
    auto itr = s.begin();
    advance(itr, k - 1);
    cout << "kth minimum using set it: " << *itr << endl;

    // we can also do this using quick select algorithm
    int a[] = {3, 4, 2, 1, 5, 7, 10, -1, 67, 223, 6};
    cout << kthSmallest(a, 0, n - 1, k);

    cout << "\nsorted array: ";
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}