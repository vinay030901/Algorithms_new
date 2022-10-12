#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=6;
    // variables for previous stage
    int oldCountZ=1,oldCountO=1;
    // variables for next stage
    int newCountZ,newCountO;
    for(int i=2;i<=n;i++)
    {
        newCountZ=oldCountO;
        newCountO=oldCountZ+oldCountO;

        oldCountZ=newCountZ;
        oldCountO=newCountO;
    }
    cout<<newCountO;
}
