/*
Problem Description

You are given K sorted integer arrays in a form of 2D integer matrix A of size K X N.

You need to merge them into a single array and return it.



Problem Constraints
1 <= K, N <= 103

0 <= A[i][j] <= 108

A[i][j] <= A[i][j+1]



Input Format
First and only argument is an 2D integer matrix A.



Output Format
Return a integer array denoting the merged array you get after merging all the arrays in A.



Example Input
Input 1:

 A = [  [1, 2, 3]
        [2, 4, 6]
        [0, 9, 10]
     ]


Example Output
Output 1:

 [0, 1, 2, 2, 3, 4, 6, 9, 10]


Example Explanation
Explanation 1:

 You need to merge [1, 2, 3] , [2, 4, 6] and [0, 9, 10]  into a single array
 so the merged array will look like [0, 1, 2, 2, 3, 4, 6, 9, 10]*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> pp;
vector<int> Solution::solve(vector<vector<int> > &arr) {
    int n=arr.size();
    vector<int>ans;
    priority_queue<pp,vector<pp>,greater<pp>>mn;
    for(int i=0;i<n;i++)
    {
        mn.push({arr[i][0],{i,0}});
    }
    while(!mn.empty())
    {
        auto node=mn.top();
        mn.pop();
        ans.push_back(node.first);
        int i=node.second.first,j=node.second.second;
        if(j+1<arr[i].size())
        mn.push({arr[i][j+1],{i,j+1}});
    }
    return ans;
}




vector<int>merge(vector<int>&a1,vector<int>&a2)
{
    vector<int>ans;
    int i=0,j=0;
    while(i<a1.size() && j<a2.size())
    {
        if(a1[i]<a2[j])
        {
            ans.push_back(a1[i]);
            i++;
        }
        else{
            ans.push_back(a2[j]);
            j++;
        }
    }
    while(i<a1.size())
    {
        ans.push_back(a1[i++]);
    }
    while(j<a2.size())
    {
        ans.push_back(a2[j++]);
    }
    return ans;
}
vector<int> Solution::solve(vector<vector<int> > &arr) {
    int n=arr.size();
    while(arr.size()>1)
    {
        int i=0,j=arr.size()-1;
        while(i<j)
        {
            vector<int>first=arr[i],second=arr[j];
            arr[i]=merge(arr[i],arr[j]);
            arr.pop_back();
            i++;
            j--;
        }
    }
    return arr[0];
}

int main()
{

}