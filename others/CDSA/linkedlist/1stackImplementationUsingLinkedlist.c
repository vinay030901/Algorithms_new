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
Node *push(Node *top)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("not enough memory\n");
        return top;
    }
    int val;
    printf("Enter the value: ");
    scanf("%d", &val);
    p->val = val;
    p->next = top;
    top = p;
    return top;
}
Node *pop(Node *top)
{
    if (top == NULL)
    {
        printf("Stack underflow\n");
        return top;
    }
    Node *p = top;
    printf("the popped element is: %d\n", p->val);
    top = top->next;
    free(p);
    return top;
}
void display(Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    Node *temp = top;
    while (temp)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}
void peek(Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("peek element: %d\n", top->val);
}
void main()
{
    int ch;
    Node *top = NULL;
    do
    {
        printf("\nMenu: \n1. push\n2. pop\n3. display\n4. top\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            top = push(top);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            display(top);
            break;
        case 4:
            peek(top);
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    } while (ch != 5);
}