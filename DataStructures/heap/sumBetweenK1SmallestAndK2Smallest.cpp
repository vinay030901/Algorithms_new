#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long arr[] ={2,4,5,6,6,6,7,10,10,10};
    long long n=10,k1=2,k2=5,f=0;
    long long sum=0;
    unordered_map<long long,long long>m;
    for(long long i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
    long long p=m.size();
    if(k2>p)
    {
        k2=p;
        f=1;
        cout<<"k2 value changed and f is "<<f<<endl;
    }
    priority_queue<long long>maxh;
    priority_queue<long long>maxh1;
        for(auto i=m.begin();i!=m.end();i++)
        {
            maxh.push(i->first);
            if(maxh.size()>k1)
                maxh.pop();
        }
        long long small=maxh.top();
        cout<<"small value is: "<<small<<endl;
        for(auto i=m.begin();i!=m.end();i++)
        {
            maxh1.push(i->first);
            if(maxh1.size()>k2)
                maxh1.pop();
        }
        long long large=maxh1.top();
        cout<<"large value is: "<<large<<endl;
        if(f==1)
            {large+=1;
            cout<<"large value now is: "<<large<<endl;}
        for(long long i=0;i<n;i++)
            if(arr[i]>small && arr[i]<large)
            {
                cout<<sum<<"+"<<arr[i]<<endl;
                sum+=arr[i];}
        cout<<sum<<endl;
}