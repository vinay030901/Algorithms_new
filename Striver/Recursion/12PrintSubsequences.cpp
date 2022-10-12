#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
void print(vector<int>v)
{
    for(int i = 0; i < v.size();i++) cout << v[i] << " ";
    cout<<"\n";
}
void printSubsequences(int arr[],int ind,int n,vector<int>&v)
{
    // so here we used the approach that we either take the element or leave it, to do this we will use a vector, and push the element 
    // into it first, then we call the function with increased value of index, so when we reach the value of n or we can say end
    // we print the vector
    // then we return back and pop the element from the vector, again increase index and print
    if(ind>=n){
        print(v);
        return;
    }
    v.push_back(arr[ind]);
    printSubsequences(arr,ind+1,n,v);
    v.pop_back();
    printSubsequences(arr,ind+1,n,v);
}
int main()
{
    int arr[]= {1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    printSubsequences(arr,0,n,v);
}