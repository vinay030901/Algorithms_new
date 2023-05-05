#include <stdio.h>
typedef struct Node
{
    int val;
    struct Node *next;
} Node;

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