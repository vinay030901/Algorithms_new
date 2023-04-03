/*write an algo that searches for a value in an m*n matrix. properties of this matrix are ---
Integers in each row are sorted
the first integer of each row is greater than last integer of previous column*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>>arr{{1},{3}};
    int x=30,f=0;
    int row=arr.size();
    int col=arr[0].size();
    int high=row*col-1;
    int low=0;
    while(low<=high) {
        int mid=low+(high-low)/2;
        if(arr[mid/4][mid%4]==x)
        {
            f=1;
            cout<<"true";
            break;
        }
        if(arr[mid/4][mid%4]<x)
            low=mid+1;
        else
            high=mid-1;
    }
    if(f==0)
        cout<<"false";
}