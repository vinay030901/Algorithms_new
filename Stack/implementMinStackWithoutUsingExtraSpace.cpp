#include<bits/stdc++.h>
using namespace std;
stack<int>s;
int me;
void push(int a)
{
    if(s.size()==0) 
    {
        s.push(a);
        me=a;
    }
    else
    {
        if(a>-me)
        {
            s.push(a);
        }
        else
        {
            s.push(2*a-me);
            me=a;
        }
    }
}
void pop()
{
    if(s.size()==0)
    return;
    if(s.top()>=me)
    s.pop();
    else
    {
        me=2*me-s.top();
        s.pop();
    }
}
int top()
{
    if(s.size()==0) return -1;
    else
    {
        if(s.top()>=me)
        return s.top();
        else
        return me;
    }
}
int getmin()
{
    if(s.size()==0) return -1;
    else return me;
    
}
int main()
{

}