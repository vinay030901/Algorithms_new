/*
We are given a row-wise sorted matrix of size r*c, we need to find the median of the matrix given. It is assumed that r*c is always odd.
Examples:

Input : 1 3 5
        2 6 9
        3 6 9
Output : Median is 5
If we put all the values in a sorted
array A[] = 1 2 3 3 5 6 6 9 9)

Input: 1 3 4
       2 5 6
       7 8 9
Output: Median is 5*/
#include <bits/stdc++.h>
using namespace std;
int countSmallerElements(vector<int> &arr, int mid)
{
    int l = 0, h = arr.size() - 1;
    while (l <= h)
    {
        int md = (l + h) >> 1;
        if (arr[md] <= mid)
            l = md + 1;
        else
            h = md - 1;
    }
    return l;
}
int main()
{
    /* to find the median in a sorted matrix, the brute force approach is simply to put all the elements in a
    data structure and then sort those elements, then we can easily access the median*/
    int n = 3, m = 3;
    vector<vector<int>> arr = {{3, 30, 38},
                               {36, 43, 60},
                               {40, 51, 69}};
    multiset<int> ms;
    // so we put all the elements in a multiset, since set is sorted by default, we an easily access the median by using the
    // iterator
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ms.insert(arr[i][j]);
    int med = n * m / 2 + 1;
    auto itr = ms.begin();
    advance(itr, med - 1);
    cout << *itr;

    /*our next method is using binary search
    first we find the low and high, low is 0 and high is the highest value that could be used, for gfg it is 2000
    so, we wil count the number of elements on the left, and then change the value of low and high accordingly
    and wherever low end, we will have our answer.

    Now we need to know how to cound the numbers lesser than equal to our element, for this we will use binary search,
    we will find the first index which is greater than equal to our element*/
    int low = 0, high = 2000;
    while (low <= high)
    {
        int mid = (low + high) >> 1, cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += countSmallerElements(arr[i], mid); // function to count smaller elements than our mid
        if (cnt <= (n * m) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "\nmedian using binary search: " << low;
}