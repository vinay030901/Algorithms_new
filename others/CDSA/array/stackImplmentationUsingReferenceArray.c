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
void push(char *stack, char c, int *top)
{
    if (*top == max - 1)
    {
        printf("\nStack overflow");
        return;
    }
    stack[++(*top)] = c;
}
int pop(char *stack, int *top)
{
    if (*top == -1)
    {
        printf("\nStack underflow");
        return;
    }
    return stack[(*top)--];
}
void display(char *stack, int *top)
{
    if (*top == -1)
    {
        printf("\nStack underflow");
        return;
    }
    for (int i = *top; i >= 0; i--)
        printf("%d ", stack[i]);
}
void peek(char *stack, int *top)
{
    if (*top == -1)
    {
        printf("\nStack underflow");
        return;
    }
    printf("top element: %d ", stack[*top]);
}
int pred(char x)
{
    if (x == '^')
        return 5;
    if (x == '/' || x == '*')
        return 4;
    return 3;
}
int main()
{
    char infix[max] = {}, postfix[max], stack[max];
    int top = -1, i = 0, j = 0;
    printf("Enter the infix expression: ");
    gets(infix);
    push(stack, '(', &top);
    while (infix[i] != '.')
    {
        char ch = infix[i];
        if (ch == '(')
            push(stack, ch, &top);
        else if (ch == '-' || ch == '+' || ch == '*' || ch == '/')
        {
            while (pred(ch) <= pred(stack[top]))
                ch = pop(stack, &top);
            postfix[j] = ch;
            j++;
            push(stack, ch, &top);
        }
        else if (ch == ')')
        {
                }
    }
}