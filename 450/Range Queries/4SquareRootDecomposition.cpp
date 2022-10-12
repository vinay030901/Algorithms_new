/*
You are given a list of N numbers and Q queries.Each query is specified by two numbers i and j.The answer to
each query is the minimum number between the range between i and j(including i and j).The query are specified using 0 based indexing.

Expected complexity : O(Q * logN)

Sample Input
4
2 4 3 1
4
1 2
1 3
2 2
0 1
Sample Output
3
1
3
2

so basically, this question will be solved in O(n*q) complexity by brute force but we can solve it in q*log(n) using the
square root decomposition*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2, 3, -1, 9, 6, -2, 10, 4, 12, -1, 5, 7, 16, -4, 8, 2};

    vector<vector<int>> update = {{1, 14}, {10, 15}, {0, 7}, {3, 10}, {15, 18}};
    int n = sizeof(arr) / sizeof(arr[0]);

    /* so we will do preprocessing for this process
    we will make a square root array: its size would be size of square root of it, if its size is 16, the sqrt array size is 4
    is size is 18, then sqrt size is 5 which is equal to ceil(sqrt(18)).

    above array size is 16, then our sqrt array size is 4 now*/
    float f = sqrt(n);
    int q = (int)ceil(sqrt(n));
    vector<int> sqrt(q, INT_MAX);
    vector<int>sum(q, 0);
    /* now in first index of sqrt, we will put the minimum of root n values, then in second index, we will put the other root

    so for 16, we will have sqrt={min(0,1,2,3), min(4,5,6,7), min(8,9,10,11), min(12,13,14,15))

    so sqrt is ={-1, -2, -1, -4};

    so how to do this, we will traverse the array and put the minimum in (index/(sqrt(n))) index values

  index      sqrt index
    0-> 0/4 =    0
    1-> 1/4 =    0
    2-> 2/4 =    0
    ...

    9-> 9/4 =    2
    15-> 15/4=   3*/

    for (int i = 0; i < n; i++)
        sqrt[i / q] = min(arr[i], sqrt[i / q]);

    for (int i = 0; i < n; i++)
        sum[i / q] += arr[i];

    cout<<"sqrt array: ";
    for(int i=0;i<q; i++) cout<<sqrt[i]<<" ";
    cout<<endl;

    cout<<"sum array: ";
    for(int i=0;i<q; i++) cout<<sum[i]<<" ";
    cout<<endl;

    /* now to compare the element and to find the minimum, we can use a simple trick, if we need to check from position
    'l' to 'r', and if l/sqrt(n) == 0 and l+sqrt(n)-1 is less than equal to r, then instead of traversing the whole array,
    we will check the sqrt of that position and directly jump to the latter part*/

    for (int i = 0; i < update.size(); i++)
    {
        int l = update[i][0], r = update[i][1], mn = INT_MAX;
        for (int j = l; j <= r; j++)
        {
            if (j % q == 0 && (j + q - 1) <= r)
            {
                mn = min(mn, sqrt[j / q]);
                j += q;
            }
            else
            {
                mn = min(mn, arr[j]);
            }
        }
        cout << mn << "\n";
    }

    vector<vector<int>>change={{6,13},{8,-3}};

    for(int i=0; i<change.size(); i++)
    {
        int ind=change[i][0],val=change[i][1];
        arr[ind]+=val;
        sqrt[ind/q]+=val;
    }
    cout<<"the array after update is: ";
    for(int i=0;i<n; i++) cout<<arr[i]<<" ";
}
