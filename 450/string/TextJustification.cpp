#include <bits/stdc++.h>
using namespace std;
void textJustification(vector<string>nums,int k)
{
    vector<int>arr;
    for(int i=0;i<nums.size();i++)
    arr.push_back(nums[i].length());

    int n=arr.size();
    vector<string>ans;
    int sp=0;
    for(int i=0;i<n;)
    {
        sp+=arr[i];
        if(sp<k)
        {
            sp+=1;
            i++;
        }
        else
        {
            
        }
    }
}
int main()
{
    vector<string>v={"This", "is", "an", "example", "of", "text", "justification."};
    int k=16;
    textJustification(v,k);
}