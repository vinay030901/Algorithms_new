#include <bits/stdc++.h>
using namespace std;
bool compare(int mps1[], int mps2[])
{
    for (int i = 0; i < 256; i++)
        if (mps1[i] != mps2[i])
            return false;
    return true;
}
vector<int> findAnagrams(string s2, string s1)
{
    int m = s1.length();
    int n = s2.length();
    vector<int> ans;
    int mps1[256] = {0}, mps2[256] = {0};
    if (m > n)
        return ans;
    int i = 0;
    for (i = 0; i < m; i++)
    {
        mps1[s1[i]]++;
        mps2[s2[i]]++;
    }
    for (i = m; i < n; i++)
    {
        if (compare(mps1, mps2))
            ans.push_back(i - m);
        mps2[s2[i]]++;
        mps2[s2[i - m]]--;
    }
    if (compare(mps1, mps2))
        ans.push_back(i - m);
    return ans;
}
int main()
{
}