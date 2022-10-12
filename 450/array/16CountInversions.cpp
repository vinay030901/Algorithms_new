/*inversion Count for an array indicates – how far (or close) the array is from being sorted. If the array is already sorted,
then the inversion count is 0, but if the array is sorted in the reverse order, the inversion count is the maximum.
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
Example:

Input: arr[] = {8, 4, 2, 1}
Output: 6

Explanation: Given array has six inversions:
(8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).


Input: arr[] = {3, 1, 2}
Output: 2

Explanation: Given array has two inversions:
(3, 1), (3, 2) */
#include <bits/stdc++.h>
using namespace std;
/*long long  merge(long long  arr[],long long  temp[],long long  l,long long  mid,long long  h)
{
    long long  i=l,j=mid,k=l,inv=0;
    while(i<=mid-1 && j<=h)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
            inv+=(mid-i);
        }
    }
    while(i<=mid-1)
    temp[k++]=arr[i++];
    while(j<=h)
    temp[k++]=arr[j++];
    for(long long  i=l;i<=h;i++)
    arr[i]=temp[i];
    return inv;

}
long long  mergeSort(long long  arr[],long long  temp[],long long  l,long long  h)
{
    long long  inv=0;
    if(l<h)
    {
        long long  mid=(l+h)/2;
        inv+=mergeSort(arr,temp,l,mid);
        inv+=mergeSort(arr,temp,mid+1,h);
        inv+=merge(arr,temp,l,mid,h);
    }
    return inv;
}*/
long long merge(long long arr[], long long p, long long q, long long r)
{

  // Create L ← A[p..q] and M ← A[q+1..r]
  long long n1 = q - p + 1;
  long long n2 = r - q;
  long long inv = 0;
  long long L[n1], M[n2];

  for (long long i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (long long j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Malong long ain current index of sub-arrays and main array
  long long i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2)
  {
    if (L[i] <= M[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = M[j];
      j++;
      inv += (n1 - i);
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = M[j];
    j++;
    k++;
  }
  return inv;
}

// Divide the array long long o two subarrays, sort them and merge them
long long mergeSort(long long arr[], long long l, long long r)
{
  long long inv = 0;
  if (l < r)
  {
    // m is the polong long  where the array is divided long long o two subarrays
    long long m = l + (r - l) / 2;

    inv += mergeSort(arr, l, m);
    inv += mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    inv += merge(arr, l, m, r);
  }
  return inv;
}

int main()
{
  // this process could be simply be done using the O(n^2) complexity
  // just traverse the array and check the number greater than it on the right side
  long long n = 4, count = 0;
  long long arr[] = {3,2,1,0};
  for (long long i = 0; i < n - 1; i++)
    for (long long j = i + 1; j < n; j++)
      if (arr[i] > arr[j])
        
        {
          count++;
          cout<<i<<" "<<j<<endl;}
  cout << "count of inversion using simple method: " << count << endl;

  // to this process in NLogN, we can use merge sort and count the number of changes of happening
  long long temp[n];
  cout << "count of inversion using enhanced merge sort: " << mergeSort(arr, 0, n - 1);
}