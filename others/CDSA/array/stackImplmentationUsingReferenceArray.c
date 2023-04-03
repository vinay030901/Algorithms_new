/*
    stack: stack is a linear data structure which follows last in first out principle.
    array: array is linear data structure in which elements are stored in contiguous manner.

    1. Create menu driver structure.
    2. Declare array, max and top.
    3. create the push function, send the array and top using reference.if top==max-1, then stack overflow, otherwise increment the value of top
    4. create the pop function, if the size of top is -1, then stack underflow otherwise we will print the value at top
    and decrement the top.
    5. create the display in which we will print the elements from top to 0, condition: top value should be greater than 0
    6. create the peek function in which will return the element at top, condition: top value should be greater than 0

*/
#include <stdio.h>
#include <stdlib.h>
#define max 10
void push(int *stack, int *top)
{
    if (*top == max - 1)
    {
        printf("\nStack overflow");
        return;
    }
    int val;
    printf("\nEnter the value: ");
    scanf("%d", &val);
    stack[++(*top)] = val;
}
void pop(int *stack, int *top)
{
    if (*top == -1)
    {
        printf("\nStack underflow");
        return;
    }
    printf("The popped element is %d", stack[(*top)--]);
}
void display(int *stack, int *top)
{
    if (*top == -1)
    {
        printf("\nStack underflow");
        return;
    }
    for (int i = *top; i >= 0; i--)
        printf("%d ", stack[i]);
}
void peek(int *stack, int *top)
{
    if (*top == -1)
    {
        printf("\nStack underflow");
        return;
    }
    printf("top element: %d ", stack[*top]);
}
int main()
{
    int stack[max], ch, top = -1;
    printf("\t\tStack Data Structure");
    do
    {
        printf("\nMenu: \n1. push\n2. pop\n3. display\n4. top\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push(&stack[0], &top);
            break;
        case 2:
            pop(&stack[0], &top);
            break;
        case 3:
            display(&stack[0], &top);
            break;
        case 4:
            peek(&stack[0], &top);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("invalid choice\n");
        }
    } while (1);
}