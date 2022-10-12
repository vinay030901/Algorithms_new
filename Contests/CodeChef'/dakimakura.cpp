#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int arr[]={9, 196, 225, 250 ,304, 310, 311, 452, 486, 515, 520, 557, 601, 610, 617, 618, 703, 799, 814, 845, 936 ,990};
    int n=22,k=6,x=250;
    for(int i=0,j=n-1;i<n/2;i++,j--)
        {
            swap(arr[i],arr[j]);
        }
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==x)
            continue;
            v.push_back({abs(arr[i]-x),arr[i]});
        }
        cout<<"the vector before sort is";
        for(auto i=v.begin();i!=v.end();i++)
                cout<<(i->second)<<" ";
        stable_sort(v.begin(),v.end());
        int num=v.size();
        for(int i=0;i<num-1;i++)
        {
            if(v[i].first==v[i+1].first)
                swap(v[i],v[i+1]);
        }
        cout<<"\nthe vector after sort is: ";
        for(auto i=v.begin();i!=v.end();i++)
                cout<<(i->second)<<" ";
        vector<int>vec(k);
        for(int i=0;i<k;i++)
        {
            vec[i]=v[i].second;
        }
        cout<<"\n";
        for(auto i=vec.begin();i!=vec.end();i++)
                cout<<*i<<" ";
}