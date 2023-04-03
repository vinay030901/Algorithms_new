/*
    queue: queue is a linear data structure which follows first in first out principle.
    array: array is linear data structure in which elements are stored in contiguous manner.

    1. Create menu driver structure.
    2. Declare the array queue, max size, front and rear.
    3. Create function push,enter the value and push it into queue, condition- rear should be less than max-1,
    in main, if front is -1, then make it 0
    4. Create function deque, if the value is front is -1, no element is added, so queue underflow, we will print the value to be dequeued, if the value of front and rear is same, then we make front as -1 and later in main we will make rear as -1, otherwise we will increment the value of front
    5. create display function in which if front is -1, the queue is empty, otherwise we will print the element from front to rear
    6. create peek function in which if front is -1, the queue is empty, otherwise we will print the element at front
*/
#include <stdio.h>
#include <stdlib.h>
#define max 10
int enqueue(int queue[], int rear)
{
    if (rear == max - 1)
    {
        printf("Queue overflow\n");
        return rear;
    }
    int val;
    printf("Enter the value: ");
    scanf("%d", &val);
    queue[++rear] = val;
    return rear;
}
int dequeue(int queue[], int front, int rear)
{
    if (front == -1)
    {
        printf("Queue underflow");
        return front;
    }
    printf("Popped element is: %d", queue[front]);
    if (front == rear)
        front = -1;
    else
        front++;
    return front;
}
void display(int queue[], int front, int rear)
{
    if (front == -1)
    {
        printf("Queue is empty");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        print("%d ", queue[i]);
}
void peek(int queue[], int front)
{
    if (front == -1)
    {
        printf("Queue is empty");
        return;
    }
    printf("Peek element: %d", queue[front]);
}
int main()
{
    int queue[max], ch, front = -1, rear = -1;
    printf("\t\\Queue Data Structure");
    do
    {
        printf("\nMenu: \n1. push\n2. pop\n3. display\n4. top\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            rear = enqueue(queue, rear);
            if (front == -1)
                front = 0;
            break;
        case 2:
            front = dequeue(queue, front, rear);
            if (front == -1)
                rear = -1;
            break;
        case 3:
            display(queue, front, rear);
            break;
        case 4:
            peek(queue, front);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("invalid choice\n");
        }
    } while (1);
}