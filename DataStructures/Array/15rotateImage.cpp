/*rotate an array by 90 degrees
one approach could be to make a new array and copy the element in that with some changes but it will take quadratic and space
so instead we will just transpose the array the matrix and then reverse the elements in it*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>>arr{{1,2,3},{4,5,6},{7,8,9}};
    int n=arr.size();
    //transpose the vector
    for(int i=0;i<n;i++)
    for(int j=0;j<i;j++)
    {
        swap(arr[i][j],arr[j][i]);
    }
    for(int i=0;i<n;i++)
        reverse(arr[i].begin(),arr[i].end());
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}