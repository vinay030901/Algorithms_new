#include<iostream>
using namespace std;
void minLengthSubarray(int arr[],int n)
{
    int s,e,i;
    for(s=0;s<n-1;s++)
    {
        if(arr[s+1]<arr[s])
            break;
    }
    for(e=n-1;e>=0;e--)
    {
        if(arr[e-1]>arr[e])
            break;
    }
    int min=arr[s];
    int max=arr[s];
    for(i=s+1;i<=e;i++)
    {
        if(arr[i]>max)
            max=arr[i];
        if(arr[i]<min)
            min=arr[i];
    }
    for(i=n-1;i>e;i--)
    {
        if(arr[i]<max)
        {
            e=i;
            break;
        }
    }
    for(i=0;i<s;i++)
    {
        if(arr[i]>min)
        {
            s=i;
            break;
        }
    }
    cout<<s<<"    "<<e;
}
int main()
{
    int arr[]={455};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl;
    minLengthSubarray(arr,n);
}