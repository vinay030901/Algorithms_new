/*Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.



Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23


Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isvalid(int mid, vector<int> &arr, int ho)
    {
        long long ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            ans += (arr[i] / mid);
            if (arr[i] % mid != 0)
                ans++;
        }
        return ans <= ho;
    }
    int minEatingSpeed(vector<int> &arr, int ho)
    {
        int l = 1, h = 1e9;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (isvalid(mid, arr, ho))
                h = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};
class Solution
{
public:
    int minEatingSpeed2(vector<int> &piles, int h)
    {
        cout.tie(0);
        cin.tie(0);
        ios_base::sync_with_stdio(0);

        long maxSpeed = *max_element(piles.begin(), piles.end()), minSpeed = 1;

        while (minSpeed <= maxSpeed)
        {
            long mid = (maxSpeed + minSpeed) / 2, hoursNeeded = 0;
            for (const auto &pile : piles)
            {
                hoursNeeded += (pile + mid - 1) / mid; // hours needed is the sum of time it takes to finish each
                // pile at speed mid
            }
            if (hoursNeeded > h)
            { // too slow
                minSpeed = mid + 1;
            }
            else
            {
                maxSpeed = mid - 1;
            }
        }
        return minSpeed;
    }
};
int main()
{
    // Your code here
    return 0;
}