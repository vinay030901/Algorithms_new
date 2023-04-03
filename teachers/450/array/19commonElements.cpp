// we need to find the common elements from three sorted arrays
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // we will not talk about the brute force here
    // one approach we can use is take another array of size of sum of all three arrays and put those elements in it and then
    // use a map to count the element who appeared 3 or 6 etc times
    int a1[] = {1, 5, 10, 20, 40, 80};
    int a2[] = {6, 7, 20, 80, 100};
    int a3[] = {3, 4, 15, 20, 30, 70, 80, 100};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    int n2 = sizeof(a2) / sizeof(a2[0]);
    int n3 = sizeof(a3) / sizeof(a3[0]);
    cout << "Using three pointer approach: ";
    // we can also use three pointer way for traversing the array here
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2 && k < n3)
    {
        if (a1[i] == a2[j] && a2[j] == a3[k])
        {
            cout << a1[i] << " ";
            i++;
            j++;
            k++;
        }
        else if (a1[i] <= a2[j] && a1[i] <= a3[k])
            i++;
        else if (a2[j] <= a1[i] && a2[j] <= a3[k])
            j++;
        else
            k++;
    }
}