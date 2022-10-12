/*
1. Assume you have an array of length 'n' initialized with all 0's and are given 'q' queries to update.
2. Each query is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
3. Return the modified array after all 'q' queries were executed.
Input Format
length = 5,
updates = 
1. Assume you have an array of length 'n' initialized with all 0's and are given 'q' queries to update.
2. Each query is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
3. Return the modified array after all 'q' queries were executed.
Input Format
length = 5,
updates = 
{
    {1,  3,  2},
    {2,  4,  3},
    {0,  2, -2}
}
Output Format
return {-2, 0, 3, 5, 3}
Explanation : 
Initial state:
{ 0, 0, 0, 0, 0 }
After applying operation [1, 3, 2]:
{ 0, 2, 2, 2, 0 }
After applying operation [2, 4, 3]:
{ 0, 2, 5, 5, 3 }
After applying operation [0, 2, -2]:
{-2, 0, 3, 5, 3 }
Output Format
return {-2, 0, 3, 5, 3}
Explanation : 
Initial state:
{ 0, 0, 0, 0, 0 }
After applying operation [1, 3, 2]:
{ 0, 2, 2, 2, 0 }
After applying operation [2, 4, 3]:
{ 0, 2, 5, 5, 3 }
After applying operation [0, 2, -2]:
{-2, 0, 3, 5, 3 }*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int length=5;
    vector<vector<int>>updates={
    {0,  3,  2},
    {2,  4,  3},
    {0,  2, -2}
};
    /*vector<vector<int>>updates={
    {0,  5,  2},
    {4,  7,  -1},
    {2,  8, 3},{0,9,1}
};*/
    int arr[length]={0};
    /* to update the array with certain values, it will take us about n*k complexity,
    we can do this in n+k comeplexity, with the help of prefix addition
    
    what we will do is, we will traverse over the update vector, and check the l and r,
    then we will make change in the array according to that value

    for example we have updates = 
    {
    {1,  3,  2},
    {2,  4,  3},
    {0,  2, -2}
    }
    so our array will be: {0,+2,0,0,-2} for (1,3,2)-> i=1 | j=4
    then: {0,+2,+3,0,-2} for (2,4,3)
    then: {-2, +2,+3,+2,-2}

    after that, we will do prefix sum over it:

    arr={-2, 0, 3, 5, 3}*/

    for(int i=0;i<updates.size();i++)
    {
        arr[updates[i][0]]+=updates[i][2];
        arr[updates[i][1]+1]-=updates[i][2];
    }

    int prefix[length]={0};
    prefix[0]=arr[0];
    for(int i=1; i < length; i++)
    prefix[i]=prefix[i - 1]+arr[i];

    for(int i=0; i < length; i++) cout<<prefix[i]<<" ";
}