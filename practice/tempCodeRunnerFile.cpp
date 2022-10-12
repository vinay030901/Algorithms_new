#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int knapSack(int w, int wt[], int val[], int n) 
    { 
       int t[n+1][w+1]={0};
       for(int i=0;i<n+1;i++)
       {
           for(int j=0;j<w+1;j++)
           {
               if(i==0||j==0)
                t[i][j]=0;
               else if(wt[i-1]<=j)
                {
                    t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
                }
                else
                    t[i][j]=t[i-1][j];
            cout<<"i = "<<i<<" and j = "<<j<<" val[i-1]= "<<val[i-1]<<" wt[i-1]= "<<wt[i-1]<<endl;
            for(int k=0;k<n+1;k++)
            {
                for(int l=0;l< w+1; l++)
                cout<<t[k][l]<<" ";
                cout<<endl;
            }
             cout<<endl;   
           }
       }
       return t[n][w];
    }
int main()
{
    int val[] = { 1,2,3};
    int wt[] = {4,5,1};
    int W = 4;
    int n = sizeof(val) / sizeof(val[0]);
     
    cout << knapSack(W, wt, val, n);
     
    return 0;

}