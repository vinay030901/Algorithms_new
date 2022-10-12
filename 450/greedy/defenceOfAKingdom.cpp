#include <bits/stdc++.h>
using namespace std;
int main()
{
    int w,h,t;
    cin>>w>>h>>t;
    vector<int>height,width;                       
    height.push_back(0);
    width.push_back(0);
    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        width.push_back(a);
        height.push_back(b);
    }
    height.push_back(h+1);
    width.push_back(w+1);
    sort(height.begin(), height.end());
    sort(width.begin(), width.end());
    int mxh=INT_MIN,mxw=INT_MIN;
    for(int i=0;i<width.size()-1;i++){
        mxw=max(width[i+1]-width[i]-1,mxw);
        mxh=max(height[i+1]-height[i]-1,mxh);
    }
    cout<<mxh*mxw;
}