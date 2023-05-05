#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int val;
    struct node *next, *prev;
} Node;
Node *enqueue(Node *rear)
{
    Node *p = (Node *)malloc(sizeof(Node));
    int x;
    printf("Enter the value: ");
    scanf("%d", &x);
    p->val = x;
    if (rear == NULL)
    {
        rear = p;
        rear->prev = NULL;
    }
    else
    {
        rear->next = p;
        p->prev = rear;
        rear = p;
    }
    rear->next = NULL;
    return rear;
}
Node *dequeue(Node *front, Node *rear)
{
    if (front == NULL)
    {
        printf("linkedlist is empty\n");
        return;
    }
    int x;
    printf("enter the value to delete: ");
    scanf("%d", &x);
    if (front->val == x)
    { // it means the front value is to be deleted
      // so we will simple forward the front pointer and free the memory
    }
}
void main()
{
    int ch;
    Node *front = NULL, *rear = NULL;
    do
    {
        printf("\nMenu: \n1. enqueue\n2. dequeue\n3. display\n4. peek\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            rear = enqueue(rear);
            if (front == NULL)
                front = rear;
            break;
        case 2:
            front = pop(front);
            if (front == NULL)
                rear = NULL;
            break;
        case 3:
            display(front);
            break;
        case 4:
            peek(front);
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    } while (ch != 5);
}