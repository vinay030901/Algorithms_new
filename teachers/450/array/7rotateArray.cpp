#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2, 3, 4, 1, 5, 23, 12, 2};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    k = n - k;
    // we can rotate any array using the stl function easily

    // one way could be initialise a new array and push all the elements from k and then put other elements

    int arr1[n], j = 0;
    for (int i = k; i < n; i++, j++)
        arr1[j] = arr[i];
    for (int i = 0; i < k; i++)
        arr1
            [j + i] = arr[i];
    cout << "using external array: ";
    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";

    // we can also use deque, here we can pop up the elements from last and push them in front.
    deque<int> deq;
    k = 2;
    int arr2[n];
    for (int i = 0; i < n; i++)
        deq.push_back(arr[i]);
    for (int i = 0; i < k; i++)
    {
        int x = deq.back();
        deq.push_front(x);
        deq.pop_back();
    }
    cout << "\nusing deque: ";
    for (int i = 0; i < n; i++)
    {
        arr2[i] = deq.front();
        deq.pop_front();
    }
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";

    // but the fastest way to do it using rotate stl
    rotate(arr, arr + k, arr + n);
    cout << "\nUsing STL rotate: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}