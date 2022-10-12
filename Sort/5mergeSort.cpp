#include <iostream>
using namespace std;
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
void merge(int arr[], int l, int mid, int r)
{
    int ln = mid - l + 1, rn = r - mid, i, j, k;
    int L[ln], R[rn];
    for (i = 0; i < ln; i++)
        L[i] = arr[l + i];
    for (j = 0; j < rn; j++)
        R[j] = arr[mid + j + 1];
    i = 0;
    j = 0;
    k = l;
    while (i < ln && j < rn)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < ln)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < rn)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}
int main()
{
    int arr[] = {64, 25, 12, 22, 11, 33};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}