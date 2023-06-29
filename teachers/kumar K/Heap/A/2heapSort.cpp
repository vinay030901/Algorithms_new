/*Complexity Analysis of Heap Sort
Time Complexity: O(N log N)
Auxiliary Space: O(1)

Important points about Heap Sort:
Heap sort is an in-place algorithm.
Its typical implementation is not stable but can be made stable (See this)
Typically 2-3 times slower than well-implemented QuickSort.  The reason for slowness is a lack of locality of reference.
Advantages of Heap Sort:
Efficiency –  The time required to perform Heap sort increases logarithmically while other algorithms may grow exponentially slower as the number of items to sort increases. This sorting algorithm is very efficient.
Memory Usage – Memory usage is minimal because apart from what is necessary to hold the initial list of items to be sorted, it needs no additional memory space to work
Simplicity –  It is simpler to understand than other equally efficient sorting algorithms because it does not use advanced computer science concepts such as recursion.
Disadvantages of Heap Sort:
Costly: Heap sort is costly.
Unstable: Heap sort is unstable. It might rearrange the relative order.
Efficient: Heap Sort is not very efficient when working with highly complex data.
Frequently Asked Questions Related to Heap Sort
Q1. What are the two phases of Heap Sort?

The heap sort algorithm consists of two phases. In the first phase, the array is converted into a max heap. And in the second phase, the highest element is removed (i.e., the one at the tree root) and the remaining elements are used to create a new max heap.

Q2. Why Heap Sort is not stable?

The heap sort algorithm is not a stable algorithm. This algorithm is not stable because the operations that are performed in a heap can change the relative ordering of the equivalent keys.

Q3. Is Heap Sort an example of the “Divide and Conquer” algorithm?

Heap sort is NOT at all a Divide and Conquer algorithm. It uses a heap data structure to efficiently sort its element and not a “divide and conquer approach” to sort the elements.

Q4. Which sorting algorithm is better – Heap sort or Merge Sort?

The answer lies in the comparison of their time complexity and space requirements. The Merge sort is slightly faster than the Heap sort. But on the other hand merge sort takes extra memory. Depending on the requirement, one should choose which one to use.

Q5. Why is Heap sort better than Selection sort?

Heap sort is similar to selection sort, but with a better way to get the maximum element. It takes advantage of the heap data structure to get the maximum element in constant time */
#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr, int i, int n)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[largest] < arr[l])
        largest = l;
    if (r < n && arr[largest] < arr[r])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}
void heapSort(vector<int> &arr, int n)
{
    // first of all we need to create the heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, i, n);

    // now we need to take the first element of the heap, then again make it heap, so max element will be taken again and again
    // and then array is converted into heap
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}
int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapSort(arr, arr.size());
    for (auto it : arr)
        cout << it << " ";
    return 0;
}