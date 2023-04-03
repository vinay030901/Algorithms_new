#include <bits/stdc++.h>
using namespace std;
struct job{
    int profit,id,dead;
};
void comparison(job a,job b) {
    return a.profit> b.profit;
}
pair<int,int>jobSequence(job arr[],int n)
{
    sort(arr,arr+n,comparison);
    int maxi=0;
    for(int i=0;i<n;i++)
    maxi=max(maxi,arr[i].dead);
    vector<int>slot(maxi+1,-1);
    int maxprofit=0,jobs=0;
    for(int i=0;i<maxi;i++) {
        for(int j=arr[i].dead;j>0;j--)
        {
            if(slot[j]==-1)
            {
                jobs++;
                maxprofit+=arr[i].profit;
                slot[j]=arr[i].id;
            }
        }
    }
    return make_pair(jobs,maxprofit);
}
int main()
{
    
}