/*
    stack: stack is a linear data structure which follows last in first out principle.
    array: array is linear data structure in which elements are stored in contiguous manner.

    1. Create menu driver structure.
    2. Declare array, max and top.
    3. create the push function, if the size of top is max-1, then stack overflow otherwise we will input the value
    and store it in the stack.
    4. create the pop function, if the size of top is -1, then stack underflow otherwise we will print the value at top
    and decrement the top.
    5. create the display in which we will print the elements from top to 0, condition: top value should be greater than 0
    6. create the peek function in which will return the element at top, condition: top value should be greater than 0

*/
#include <stdio.h>
#include <stdlib.h>
#define max 10
int push(int stack[], int top)
{
    if (top == max - 1)
    {
        printf("\nstack overflow");
        return top;
    }
    int val;
    printf("\nEnter the value to be pushed: ");
    scanf("%d", &val);
    stack[++top] = val;
    return top;
}
int pop(int stack[], int top)
{
    if (top == -1)
    {
        printf("\nstack underflow");
        return top;
    }
    printf("\nPopped element is: %d", stack[top]);
    return --top;
}
void display(int stack[], int top)
{
    if (top == -1)
    {
        printf("\nNothing to display");
        return;
    }
    printf("\nstack elements: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
}
void peek(int stack[], int top)
{
    if (top == -1)
        printf("\nNothing to display");
    else
        printf("\nTop element: %d", stack[top]);
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
            top = push(stack, top);
            break;
        case 2:
            top = pop(stack, top);
            break;
        case 3:
            display(stack, top);
            break;
        case 4:
            peek(stack, top);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("invalid choice\n");
        }
    } while (1);
}