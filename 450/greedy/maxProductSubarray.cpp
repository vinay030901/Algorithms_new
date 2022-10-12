#include<bits/stdc++.h>
using namespace std;
int maxProduct(int arr[], int n) {
	    if(n==1)
	    return arr[0];
	    int curr=1,mx=0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]==0)
	            {curr=1;
                continue;}  
	        curr*=arr[i];
            cout<<"curr value is: "<<curr<<endl;
	        mx=max(mx,curr);
	    }
	    return mx;
	}
int main()
{
    int arr[]={8, -2, -2, 0, 8, 0, -6, -8, -6, -1};
    int n=10;
    cout<<maxProduct(arr,n);
}