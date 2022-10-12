#include <bits/stdc++.h>
using namespace std;
int findmin(string arr[], int n)
{
    int min=arr[0].length();
    for(int i=1;i<n;i++)
    {
        if(arr[i].length()<min)
            min=arr[i].length();
    }
    return min;
}
string longestCommonPrefix(string arr[],int n) {
    int min=findmin(arr,n);
    string res="";
    char current;
    for(int i=0;i<min;i++){
        current=arr[0][i];
        for(int j=1;j<n;j++)
        {
            if(current!=arr[j][i])
            {
                return res;
            }    
        }
        res.push_back(current);
    }
    return res;
}
int main()
{
    string arr[]={"geeksforgeeks","geek","geezer","geeker"};
    int n=sizeof(arr)/sizeof(arr[0]);
    string ans=longestCommonPrefix(arr,n);
    if(ans.length())
        {
            cout<<"longest common prefix: "<<ans<<endl;
        }
    else
        cout<<"no prefix"<<endl;
}