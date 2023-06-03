#include <stdio.h>
#include <stdlib.h>
typedef struct singlelinked
{
    int data;
    struct singlelinked *next;
} sl;
void splitlinked(sl **L1, sl **Q1, sl **T1, sl **I1)
{
    sl *P = NULL;
    int ch;
    if (*L1 == NULL)
    {
        printf("Empty");
    }
    else
    {
        printf("Enter the data where you want to split: ");
        scanf("%d", &ch);
        if (*L1 == NULL)
        {
            printf("Empty");
        }
        if ((*L1)->data == ch) // deletion of First Node
        {
            *Q1 = *L1;
            *T1 = (*L1)->next;
        }
        else
        {
            P = (*L1)->next;
            while (P->data != ch && P->next != NULL)
            {
                P = P->next;
            }
            if (P->data == ch && P->next != NULL)
            {
                *Q1 = *L1;
                *I1 = P;
                *T1 = P->next;
            }
            else if (P->next == NULL && P->data == ch)
            {
                *Q1 = P;
                *T1 = P->next;
            }
        }
    }
}
void firstlinked(sl *Q, sl *I)
{
    if (Q == NULL)
    {
        printf("empty");
    }
    else
    {
        while (Q != I)
        {
            printf("%d ", Q->data);
            Q = Q->next;
        }
        printf("%d ", Q->data);
    }
}
void secondlinked(sl *T)
{
    if (T == NULL)
    {
        printf("empty");
    }
    else
    {
        while (T != NULL)
        {
            printf("%d ", T->data);
            T = T->next;
        }
    }
}
int main()
{
    sl *L = NULL, *R = NULL, *P = NULL, *Q = NULL, *I = NULL, *T = NULL;
    int ch;
    while (1)
    {
        P = (sl *)malloc(sizeof(sl));
        if (P != NULL)
        {
            printf("Enter the value: ");
            scanf("%d", &P->data);
            if (L == NULL && R == NULL)
            {
                L = R = P;
            }
            else
            {
                R->next = P;
                R = P;
            }
            R->next = NULL;
        }
        printf("Do you want to continue(0/1): ");
        scanf("%d", &ch);
        if (ch != 1)
            break;
    }
    splitlinked(&L, &Q, &T, &I);
    printf("First linked list: ");
    firstlinked(Q, I);
    printf("\nsecond linked list: ");
    secondlinked(T);
}