/*
Given an n x n matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in
the given 2D array.
Example,

Input:k = 3 and array =
        10, 20, 30, 40
        15, 25, 35, 45
        24, 29, 37, 48
        32, 33, 39, 50
Output: 20
Explanation: The 3rd smallest element is 20

Input:k = 7 and array =
        10, 20, 30, 40
        15, 25, 35, 45
        24, 29, 37, 48
        32, 33, 39, 50
Output: 30

Explanation: The 7th smallest element is 30*/

#include <bits/stdc++.h>
using namespace std;
int CountLowerElements(vector<vector<int>> arr, int mid, int n)
{
        int cnt = 0;
        int i = n - 1, j = 0;
        while (i >= 0 && j < n)
        {
                if (arr[i][j] > mid)
                {
                        i--;
                }
                else
                {
                        cnt += (i + 1);
                        j++;
                }
        }
        return cnt;
}
int main()
{
        vector<vector<int>> arr ={{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }};
        /* {{10, 20, 30, 40},
                                   {15, 25, 35, 45},
                                   {24, 29, 37, 48},
                                   {32, 33, 39, 50}};*/
        int n = arr.size();
        int k = 3;
        /* we need to kth smallest element, one basic way is to put all the data in a matrix and sort it, then access the
           Kth element in that data structure- O(n^2LogN^2)

           Another method could be to use a priority queue and cap its size to k, then put all elements one by one,
           but both of these ways do not work on the fact that matrix is row column wise sorted.

           So we will use binary search algo for this question to get least complexity*/
        int low = arr[0][0], high = arr[n - 1][n - 1], ans;
        while (low <= high)
        {
                int mid = (low + high) / 2;
                int num = CountLowerElements(arr, mid, n); // we count the number of elements less than num
                if (num < k)                               // if our count is less than k, then we need to increase the value of low as we want a higher no
                {
                        low = mid + 1;
                }
                else if (num >= k) // if the count is greater than k, then we store the mid in our answer
                // this could be our answer and then we decrease the value of high, so that if we could get something
                // less than that number
                /*we didn't do num==k as for ex. our sorted matrix is:
                1 2 3 4 5 7 8 10 11
                and we want 5th largest element, in that case we would have given the answer=6[(1+11)/2]
                which isn't even in the matrix, so that's wrong*/
                {
                        ans = mid;
                        high = mid - 1;
                }
        }
        cout <<"answer using binary search: "<<ans<<endl;

        //using priority queue
        priority_queue<int>mn;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            mn.push(arr[i][j]);
            if(mn.size()>k)
            mn.pop();
        }
        cout<<"using priority queue: "<<mn.top();
}