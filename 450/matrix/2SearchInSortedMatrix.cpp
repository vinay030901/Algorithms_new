/*
Given a matrix of size n x m, where every row and column is sorted in increasing order, and a number x. Find whether element x is present in the matrix or not.

Example 1:

Input:
n = 3, m = 3, x = 62
matrix[][] = {{ 3, 30, 38},
              {36, 43, 60},
              {40, 51, 69}}
Output: 0
Explanation:
62 is not present in the matrix, 
so output is 0.
Example 2:

Input:
n = 1, m = 6, x = 55
matrix[][] = {{18, 21, 27, 38, 55, 67}}
Output: 1
Explanation: 55 is present in the matrix.*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 3, m = 3, x = 30;
    int arr[n][m] = {{ 3, 30, 38},
              {36, 43, 60},
              {40, 51, 69}};
    /*we can easily search in a matrix in O(n^2) time, but since it is row-wise column-wise sorted, 
    we need to make use of it instead of just traversing through the whole matrix. 

    One method is we will start from end of row 1 and check for the number, if the number is greater than a[i][j],
    we will move down and if the number is smaller, then we will move left, we will do this until we come out of the matrix,
    or we complete a given amount of comparisons*/
    int i=0,j=m-1,f=1;
    while(i<n && j<m)
    {
        if(arr[i][j]==x)
        {
            cout<<x<<" found i= "<<i<<" j= "<<j<<endl;
            f=0;
            break;
        }
        if(arr[i][j]<x)
        i++;
        else    j--;
    } 
    if(f==1)
    cout<<x<<" not found\n"; 

    /*another optimal way is to use binary search, here we can call every elements of matrix as a number,
    for ex. a[0][0] is 0, then a[0][1] is 1 till the length of row, then in new row, the number continues,
    so in a 4*4 matrix,we have number from 0 to 15, so low is 0 and high is 1

    then we will use binary search and for example (0+15)/2=7, so to access 7, 
    i=7/4=1, j=7%4=3, therefore number is a[1][3], if the number we want to find is greater than number at 
    a[1][3], low=mid+1, that is low=8, in such a way we woll find the number*/
    int low=0,high=m*n-1,fb=1;
    while(low<=high)
    {
        int mid=(low + high)/2;
        if(arr[mid/m][mid%m]==x)
        {
            cout<<x<<" found using binary search"<<endl;
            fb=0;
            break;
        }
        else if(arr[mid/m][mid%m]>x) high=mid-1;
        else low=mid+1;
    }
    if(fb==1) cout<<x<<" not found using binary search";
}