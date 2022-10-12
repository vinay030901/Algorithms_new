#include <bits/stdc++.h>
using namespace std;
int main()
{
    // we need to find the duplicate number .
    // we can use brute force approach for this and use every number to check if it has come again -O(n^2)
    // another approach could be to use map for this and calculate the frequency but it will take extra space

    // the elements are less than num
    int arr[] = {0, 1, 6, 2, 3, 6, 3};
    int num = 7;
    int n = sizeof(arr) / sizeof(arr[0]);

    /* using map, we can calculate the frequency of every number and whenever the value reaches, we will print the
    value and then keep moving, if that value reaches three, then we will not print it*/
    map<int,int>mp;
    cout<<"using map: ";
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
        if(mp[arr[i]]==2)
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // we will try to do this in constant space.
    // we will traverse the array and we will add the value of n and at the index value of array
    // the logic is that all the value are less than n, so whenever we add n to it, it will give answer of / n as 1
    // but when we add it twice, the answer changes to 2
    // so every repeated element will have a value 2

    // this could only be used for finding only single duplicate number
    for (int i = 0; i < n; i++)
    {
        arr[arr[i]] += num;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] / (num) >= 2)
            cout << i << " ";
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
}