/*
linkedlist:linkedlist is a linear data structure and it consists of nodes where each  node contains a datafield and reference to the next element.
push:
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int val;
    struct Node *next;
} Node;
Node *push(Node *rear)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("no memory allocated");
        return rear;
    }
    int val;
    printf("Enter the value: ");
    scanf("%d", &val);
    p->val = val;
    if (rear == NULL)
    {
        rear = p;
    }
    else
    {
        rear->next = p;
        rear = p;
    }
    rear->next = NULL;
    return rear;
}
Node *pop(Node *front)
{
    if (front == NULL)
    {
        printf("Stack underflow\n");
        return front;
    }
    Node *p = front;
    printf("The popped element is: %d\n", p->val);
    front = front->next;
    free(p);
    return front;
}
void display(Node *front)
{
    if (front == NULL)
        printf("stack is empty\n");
    else
    {
        printf("Stack elements: ");
        Node *temp = front;
        while (temp)
        {
            printf("%d ", temp->val);
            temp = temp->next;
        }
    }
}
void peek(Node *front)
{
    if (front == NULL)
        printf("stack is empty\n");
    else
        printf("Peek element: %d", front->val);
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
            rear = push(rear);
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