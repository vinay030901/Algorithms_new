/*given an array of size n, find the majority element. The majority element is the element that appears more than floor of n/2 times*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int cnt=0,ele;
    for(int i=0;i<n;i++)
    {
        if(cnt==0) 
            ele=arr[i];
        if(arr[i]==ele) 
            cnt++;
        else
            cnt--;
    }
    cout<<"majority element is: "<<ele<<endl;
}