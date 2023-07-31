#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &a1, vector<int> &a2)
    {
        int n1 = a1.size(), n2 = a2.size();
        if (n2 < n1)
            return findMedianSortedArrays(a2, a1);
        int l = 0, h = n1;
        while (l <= h)
        {
            int cut1 = (l + h) >> 1;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;
            int l1 = cut1 == 0 ? INT_MIN : a1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : a2[cut2 - 1];
            int r1 = cut1 == n1 ? INT_MAX : a1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : a2[cut2];
            if (l1 <= r2 && l2 <= r1)
            {
                if ((n1 + n2) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return max(l1, l2);
            }
            else if (l1 > r2)
                h = cut1 - 1;
            else
                l = cut1 + 1;
        }
        return 0.0;
    }
};