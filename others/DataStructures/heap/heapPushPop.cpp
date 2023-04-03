#include<iostream>
using namespace std;
# define max 1000
int heapSize=0;
int heap[max];
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void heapify(int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<heapSize && heap[l]>heap[largest])
        largest=l;
    if(r<heapSize && heap[r]>heap[largest])
        largest=r;
    if(largest!=i)
    {
        swap(heap[largest],heap[i]);
        heapify(largest);
    }
}
void heap_push(int val)
{
    if(heapSize>=max)
    {
        cout<<"overflow";
        return;
    }

    heap[heapSize]=val;
    int curr = heapSize;
    while(curr>0 && heap[curr]<heap[curr/2])
    {
        swap(&heap[curr],&heap[(curr-1)/2]);
        curr=(curr-1)/2;
    }
    heapSize+=1;
    for(int i=heapSize/2-1;i>=0;i--)
        heapify(i);
}
int heap_pop()
{
    int curr=0;
    int popped=heap[0];
    swap(heap[0],heap[heapSize-1]);
    heapSize-=1;
    for(int i=heapSize/2-1;i>=0;i--)
        heapify(i);
    return popped;
}
void showHeap()
{
    for(int i=heapSize/2-1;i>=0;i--)
        heapify(i);
    cout<<"heap:  ";
    for(int i=0;i<heapSize;i++)
        cout<<heap[i]<<"  ";
    
}
int main()
{
    int arr[]={45, 67, 12, 34, 56, 84, 10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int choice,element;
    while(true)
    {
        cout<<"\n1-push\n2-pop\n3-print\n4-exit\n";
        cout<<"enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"enter element";
            cin>>element;
            heap_push(element);
            break;
        case 2:
            cout<<"popped: "<<heap_pop()<<"\n";
            break;
        case 3:
            showHeap();
            break;
        case 4:
            return 0;
        default:
            return 0;
            break;
        }
    }
}