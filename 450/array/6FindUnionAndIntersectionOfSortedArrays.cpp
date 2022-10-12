#include <bits/stdc++.h>
using namespace std;
bool binary_search(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return true;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
int main()
{
    int arr1[] = {1, 4, 7, 8, 34, 45, 67};
    int arr2[]={1, 2, 4, 13, 34, 45, 56, 60};

    // we have the stl function for both union and intersection, so in this case the question is easy
    // but we need to device the algorithm for it

    // for union
    // one easy method could be to put all the elements in a set and that will remove the repeating elements

    // we can use a merge sort like algorithm for this case
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    int i = 0, j = 0, k = 0;
    vector<int> ans, intersection;
    while (i < m && j < n)
    {
        if (arr1[i] == arr2[j]) // if both are same, we will just put the element only once and increment both i and j
        {
            ans.push_back(arr1[i]);
            intersection.push_back(arr1[i]); // if element are same, we will push the element in intersection
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j]) // now we are putting arr1 element if it is less, we can put any element of the array
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else
        {
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while (i < m) // checking for the remaining larger elements
    {
        ans.push_back(arr1[i]);
        i++;
    }
    while (j < n) // checking for the remaining larger elements in arr2
    {
        ans.push_back(arr2[j]);
        j++;
    }
    cout << "Union: ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "  ";
    cout << endl;
    cout << "Intersection: ";
    for (int i = 0; i < intersection.size(); i++)
        cout << intersection[i] << "  ";

    // if the size of one of the array is very small then we can do find common element just be using binary search
    // just travese every element and search for it in arr1
    vector<int> binIntersection;
    for (int i = 0; i < n; i++)
    {
        if (binary_search(arr1, m, arr2[i]))
            binIntersection.push_back(arr2[i]);
    }
    cout << "\nIntersection using binary search: ";
    for (int i = 0; i < binIntersection.size(); i++)
        cout << binIntersection[i] << "  ";
}