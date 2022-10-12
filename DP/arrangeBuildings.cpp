#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=6;
    // variables for previous stage
    int oldCountB=1,oldCountS=1;
    // variables for next stage
    int newCountB,newCountS;
    for(int i=2;i<=n;i++)
    {
        newCountB=oldCountS;
        newCountS=oldCountB+oldCountS;

        oldCountB=newCountB;
        oldCountS=newCountS;
    }
    cout<<newCountS*newCountS;
}
