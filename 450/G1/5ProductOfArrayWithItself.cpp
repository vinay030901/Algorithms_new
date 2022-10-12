/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]*/

#include <bits/stdc++.h>
using namespace std;
vector<int>productWithoutItself1(vector<int>& arr)
{
    vector<int>ans;
    for(int i=0;i<arr.size();i++)
    {
        int a=1;
        for(int j=0;j<arr.size();j++)
        {
            if(j==i) continue;
            else a*=arr[j];
        }
        ans.push_back(a);
    }
    return ans;
}
vector<int>productWithoutItself2(vector<int>& arr)
{
    // if number is zero is two, then whole answer array will have answer as zero
    // if it has one zero, then that zero index will have the value of the multiplication of whole array and rest is zero
    int cntz=0,n=arr.size();
    for(int i=0;i<n;i++) cntz++;
    if(cntz==1){
        int mul=1,ind;
        for(int i=0;i<arr.size();i++)
            if(arr[i]==0)   ind=i;
            else mul*= arr[i];
        vector<int>ans(n,0);
        ans[ind]=mul;
        return ans;
        }
    else if(cntz==2)
    {
        vector<int>ans(n,0);
        return ans;
    }
    int mul=1;
    vector<int>ans;
    for(int i=0;i<arr.size();i++)
        mul*= arr[i];
    for(int i=0;i<n; i++)
    ans.push_back(mul/arr[i]);
    return ans;
}
vector<int>productWithoutItself3(vector<int>arr)
{
    int n=arr.size();
    vector<int>ans(n,1);
    int left=1,right=1;
    for(int i=0;i<n;i++)
    {
        ans[i]*=left;
        ans[n-i-1]*=right;

        left*=arr[i];
        right*= arr[n-i-1];
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int>arr={1,2,3,4};
    // the most basic approach which comes into mind is to check for every element are multiply all other elements
    // but this approach is polynomial time(n^2)
    cout<<"using n^2 appraoch: ";
    vector<int>ans1=productWithoutItself1(arr);
    for(int i=0;i<ans1.size();i++)
    cout<<ans1[i]<<" ";

    // another could be to use the division operator, we can first find the multiplication of all the numbers
    // then we will traverse the array and divide the total multiplied value with the array values
    // but it divides the array and this shouldn't be used in this question

    cout<<"\nusing division appraoch: ";
    vector<int>ans2=productWithoutItself2(arr);
    for(int i=0;i<ans2.size();i++)
    cout<<ans2[i]<<" ";

    // another apporoach which is best is using two pointer, we will traverse from start and end, keep track of the 
    // two variables, which will be multiplied and then its value is given to array

    cout<<"\nusing two pointer appraoch: ";
    vector<int>ans3=productWithoutItself3(arr);
    for(int i=0;i<ans3.size();i++)
    cout<<ans3[i]<<" ";
}