/*find the missing and repeating number, giveb an unsorted array of size n, array of elements are in range 1-n
one number from the set is missing and one number occurs twice in array, find those numbers*/
#include<bits/stdc++.h>
using namespace std;
int returnRightMost(int n)
{
    return n & -n;
}
int main()
{
    /*the first method is easily the hashing one, where we will just observe the frequency of elements in the range and check for
    missing and repeating one
    
    the second approach is the summation approach where we will find the difference between sum of numbers and sum of array, and 
    difference between sum of squares of numbers and sum of array, using both equations we will find those numbers*/
    int arr[]={4,3,6,2,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int asumn=0,asums=0;
    for(int i=0;i<n;i++)
    {
        asumn+=arr[i];//sum of array
        asums+=arr[i]*arr[i];//sum of square of array
    }
    int sumn=(n*(n+1))/2;//sum of range
    int sums=(n*(n+1)*(2*n+1))/6;//sum of squares in the range
    int diff=sumn-asumn;//difference between those numbers
    int diff2=(sums-asums)/diff;//sum of missing and repeating numbers
    int miss=(diff+diff2)/2;//value of missing
    int repeat=diff2-miss;//value of repeating number
    cout<<"the repeating number is: "<<repeat<<" and the missing number is: "<<miss;

    /*we can also solve this question using xor approach, xor all the numbers in the range with numbers in array
    all the numbers will cancel out and we'll only get the xor of the missing and repeating and missing number
    int xi=0;
    for(int i=0;i<n;i++)
        xi=xi^arr[i];
    for(int i=1;i<=n;i++)
        xi=xi^i;
    cout<<"value of x is: "<<xi<<endl;
    int ind=returnRightMost(xi);
    cout<<"the index value is: "<<ind<<endl;
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        if((arr[i] & ind)==0)
            x^=arr[i];
        else
            y^=arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        if((i & ind)==0)
            x^=i;
        else
            y^=i;
    }
    int miss,repeat;
    for(int i=0;i<n;i++)
    {if(x==arr[i])
    {miss=y;
    repeat=x;}
    else if(y==arr[i])
    {miss=x;
    repeat=y;}}
    cout<<"missing number is: "<<miss<<" and repeating number is: "<<repeat;*/
}