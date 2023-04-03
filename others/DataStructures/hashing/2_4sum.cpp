/*given an array of integers and a target, and there are elements a,b,c,d, in the array suchj that the 
a+b+c+d=target. Find all the unique quadruplets in the array*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr{4,3,3,4,4,2,1,2,1,1};
    int target=9;
    sort(arr.begin(), arr.end());
    int n=arr.size();
    int left,right;
    vector<vector<int> >ans;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int s=target-(arr[i]+arr[j]);
            left=j+1;
            right=n-1;
            while(left<right){
                int twosum=arr[left]+arr[right];
                if(twosum<s) left++;
                else if(twosum>s) right--;
                else if(twosum==s)
                    {
                        vector<int>quad(4,0);
                        quad[0]=arr[i];
                        quad[1]=arr[j];
                        quad[2]=arr[left];
                        quad[3]=arr[right];
                        ans.push_back(quad);
                while(left<right && arr[left]==quad[2])
                    {++left;}
                while(left<right && arr[right]==quad[3]){
                    --right;
                }
                }
            while(j+1<n && arr[j]==arr[j+1]){
                ++j;
            }
            }
            while(i+1<n && arr[i]==arr[i+1]){
                ++i;
            }
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][3]<<endl;
    }
}