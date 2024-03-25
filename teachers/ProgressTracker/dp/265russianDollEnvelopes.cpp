/*You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.



Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1


Constraints:

1 <= envelopes.length <= 105
envelopes[i].length == 2
1 <= wi, hi <= 10^5*/
#include <bits/stdc++.h>
using namespace std;
/*If you like this solution or find it useful, please upvote this post.

Prerequisite

Before moving on to the solution, you should know how can we find the length of Longest Increasing Subsequence unsing Binary Search. You can find the detailed explanation of the logic on the below link.


Longest Increasing Subsequence Using Binary Search

Why we need to sort?
In these types of problem when we are dealing with two dimensions, we need to reduce the problem from two-dimensional array into a one-dimensional array in order to improve time complexity.
"Sort first when things are undecided", sorting can make the data orderly, reduce the degree of confusion, and often help us to sort out our thinking. the same is true with this question. Now, after doing the correct sorting, we just need to find Longest Increasing Subsequence of that one dimensional array.
Now, you may be wondered what correct sorting actually is?
It is the sorting which we do to order to achieve the answer. Like, increasing, non-increasing sorting. Without any further discussion, let's dig into Intuition followed by algorithm.
Algorithm
We sort the array in increasing order of width. And if two widths are same, we need to sort height in decreasing order.
Now why we need to sort in decreasing order if two widths are same. By this practice, we're assuring that no width will get counted more than one time. Let's take an example
envelopes=[[3, 5], [6, 7], [7, 13], [6, 10], [8, 4], [7, 11]]
imageNow, if you see for a while,6 and 7 is counted twice while we're calculating the length of LIS, which will give the wrong ans. As question is asking, if any width/height are less than or equal, then, it is not possible to russian doll these envelopes.
Now, we know the problem. So, how can we tackle these conditions when two width are same, so that it won't affect our answer. We can simple reverse sort the height if two width are equal, to remove duplicacy.
Now, you may question, how reverse sorting the height would remove duplicacy? As the name itself says, Longest Increasing Subsequnce, the next coming height would be less than the previous one. Hence, forbidding it to increase length count.
imageIf you don't understand how LIS is calculated here, I strongly refer you to follow the prerequisite.
Now, we havesucessfully reduced the problem to LIS! All you need to apply classical LIS on heights, to calculate the ans. This would be the maximum number of envelopes can be russian doll.*/
int maxEnvelopes(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end(), [&](vector<int> &a, vector<int> &b)
         {
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0]; });
    vector<int> lis;
    lis.push_back(arr[0][1]);
    for (int i = 1; i < arr.size(); i++)
    {
        if (lis.back() < arr[i][1])
            lis.push_back(arr[i][1]);
        else
        {
            auto it = lower_bound(lis.begin(), lis.end(), arr[i][1]) - lis.begin();
            lis[it] = arr[i][1];
        }
    }
    return lis.size();
}
int main()
{
    // Your code here
    return 0;
}