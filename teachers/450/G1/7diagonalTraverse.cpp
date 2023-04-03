#include <bits/stdc++.h>
using namespace std;
vector<int>findDiagonalOrder(vector<vector<int> >arr)
{
    int n=arr.size()-1,m=arr[0].size()-1;
        int i=0,j=0,f=0;
        vector<int>ans;
        while(i<=n && j<=m && i>=0 && j>=0)
        {
            if(f==0)
            {
                while(j<m && i>0)
                {
                    ans.push_back(arr[i][j]);
                    i--;
                    j++;
                }
                ans.push_back(arr[i][j]);
                f=1;
                if(j==m) i+=1;
                else j+=1;
            }
            else
            {
                while(i<n && j>0)
                {
                    ans.push_back(arr[i][j]);
                    i++;
                    j--;
                }
                ans.push_back(arr[i][j]);
                f=0;
                if(i==n) j+=1;
                else i+=1;
            }
        }
        return ans;
}
int main()
{
    vector<vector<int>>v={{1,2,3},{4,5,6},{7,8,9}};
    vector<int>ans=findDiagonalOrder(v);

    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
}