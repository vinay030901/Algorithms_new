/*given an unsorted array of intgers, find he length of longest consecuting elements sequence*/
#include<bits/stdc++.h>
using namespace std;
int longest(vector<int>vec,int n)
{
    set<int>hashset;
    for(int i=0;i<n;i++)
        hashset.insert(vec[i]);
    int maxStreak=0;
    for(int i=0;i<n;i++)
    {
        if(!(hashset.count(vec[i]-1)))
        {
            int count=1;
            int num=vec[i];
            while(hashset.count(num+1))
            {
                count+=1;
                num+=1;
            }
        maxStreak=max(maxStreak,count);
        }
    }
    return maxStreak;
}
int main()
{
    vector<int>vec{102,4,100,1,101,3,2};
    int n=vec.size();
    int ans=longest(vec,n);
    cout<<ans<<endl;
}