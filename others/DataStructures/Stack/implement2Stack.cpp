#include<bits/stdc++.h>
using namespace std;
#define n 10
void push1(int *arr,int &top1,int top2,int ele)
{
    if(top1<top2-1)
    {
        arr[++top1]=ele;
        return;
    }
    cout<<"stack overflow\n";
}
void push2(int *arr,int top1,int &top2,int ele)
{
    if(top1<top2-1)
    {
        arr[--top2]=ele;
        return;
    }
    cout<<"stack overflow\n";
}
void pop1(int *arr,int &top1)
{
    if(top1<0)
    {
        cout<<"stack1 underflow\n";
        return;
    }
    cout<<"popped element is: "<<arr[top1]<<endl;
    top1--;
}
void pop2(int *arr,int &top2)
{
    if(top2>=n)
    {
        cout<<"stack2 underflow\n";
        return;
    }
    cout<<"popped element is: "<<arr[top2]<<endl;
    top2++;
}
void display1(int *arr,int top1)
{
    cout<<"stack 1: ";
    for(int i=0;i<=top1;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
void display2(int *arr,int top2)
{
    cout<<"stack 2: ";
    for(int i=top2;i<
    n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int arr[n];
    int top1=-1,top2=n;
    pop1(arr,top1);
    pop2(arr,top2);
    push1(arr,top1,top2,4);
    push1(arr,top1,top2,5);
    push1(arr,top1,top2,6);
    push1(arr,top1,top2,7);
    push1(arr,top1,top2,12);
    push1(arr,top1,top2,13);
    display1(arr,top1);
    push2(arr,top1,top2,8);
    push2(arr,top1,top2,9);
    push2(arr,top1,top2,10);
    push2(arr,top1,top2,11);
    push2(arr,top1,top2,14);
    push2(arr,top1,top2,15);
    display2(arr,top2);
    pop1(arr,top1);
    pop1(arr,top1);
    pop2(arr,top2);
    pop2(arr,top2);
    display1(arr,top1);
    display2(arr,top2);
}