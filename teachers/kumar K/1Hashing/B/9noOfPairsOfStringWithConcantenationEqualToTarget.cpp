/*Given an array of digit strings nums and a digit string target, return the number of pairs of indices (i, j) (where i != j) such that the concatenation of nums[i] + nums[j] equals target.

Example 1:

Input: nums = ["777","7","77","77"], target = "7777"
Output: 4
Explanation: Valid pairs are:
- (0, 1): "777" + "7"
- (1, 0): "7" + "777"
- (2, 3): "77" + "77"
- (3, 2): "77" + "77"
Example 2:

Input: nums = ["123","4","12","34"], target = "1234"
Output: 2
Explanation: Valid pairs are:
- (0, 1): "123" + "4"
- (2, 3): "12" + "34"
Example 3:

Input: nums = ["1","1","1"], target = "11"
Output: 6
Explanation: Valid pairs are:
- (0, 1): "1" + "1"
- (1, 0): "1" + "1"
- (0, 2): "1" + "1"
- (2, 0): "1" + "1"
- (1, 2): "1" + "1"
- (2, 1): "1" + "1"*/
/*
Intuition - Optimized Permutation and Combination Approach
Here, rather than concatenating all the given strings, we break the target string into substrings and find whether these 2 strings are present in the pool of strings given to us in the nums vector.
Approach
Since we know that we're going to perform searching in nums, we create another unordered_map which contains these given strings as well as their frequencies in nums.
Now, for every pair of substrins we can create using the target, we firstly check whether both of them exists in the pool of strings given to us. If yes, we perform the steps below.
If the 2 substrings not equal, we find the number of occurences of both of these substrings, multiply their occurences and thereafter add the result to an ans variable.
If the 2 substrings are equal, we'd do the same, rather we'll subtract 1 from either of the frequencies and thereafter add the result in the ans variable.
Explanation
The optimized approach is based on Permutation and Combination.
Imagine N number of things are to be paired with M number of things. The total number of ways in which you can do that is N x M. More specifically, it's (N1){N\choose 1}(1N) x (M1){M\choose 1}(1M).
Similarly, if you have N number of things and you want to pair them with one another, you can do that in N x (N - 1) ways. More specifically, it's (N1){N\choose 1}( 1N) x (N−11){N - 1\choose 1}(1N−1) (Since 1 N is already chosen).(Here, (NR){N\choose R}(RN) means superscript N, C, subscript R, which means the number of ways of choosing R different things out of N things)

Complexity
Time complexity: O(n)
Space complexity: O(n)O*/
#include<bits/stdc++.h>
using namespace std;
int numOfPairs(vector<string>& arr, string target) {
    unordered_map<string,int>mp;
    for(auto it:arr)
    mp[it]++;
    int ans=0;
    for(int i=1;i<target.size();i++)
    {
        string s1=target.substr(0,i),s2=target.substr(i);
        if(mp.find(s1)!=mp.end() && mp.find(s2)!=mp.end())
        {
            if(s1!=s2)
            ans+=(mp[s1]*mp[s2]);
            else ans+=(mp[s1]*(mp[s2]-1));
        }
    }
    return ans;
}
int main()
{

}