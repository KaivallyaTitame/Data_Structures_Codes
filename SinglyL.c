#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE First, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        *First = newn;
    }
}   // O(1)

void InsertLast(PPNODE First, int No)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        temp = *First;

        while(temp->next != NULL)
        {
            temp = temp ->next;
        }
        temp -> next = newn;
    }
}   // O(N)

void Display(PNODE First)
{
    while(First != NULL)
    {
        printf("| %d |->",First->data);
        First = First -> next;
    }
    printf("NULL\n");
} // O(N)

int Count(PNODE First)
{
    int iCnt = 0;

    while(First != NULL)
    {
        iCnt++;
        First = First -> next;
    }
    return iCnt;
} // O(N)

void DeleteFirst(PPNODE First)
{
    PNODE temp = NULL;

    if(*First == NULL)    // Case 1
    {
        printf("Unable to delete as LL is empty\n");
        return;
    }
    else if((*First) -> next == NULL) // Case 2
    {
        free(*First);
        *First = NULL;
    }
    else    // Case 3
    {
        temp = *First;
        *First = (*First) -> next;
        free(temp);
    }
}

void DeleteLast(PPNODE First)
{
    PNODE temp = NULL;

    if(*First == NULL)    // Case 1
    {
        printf("Unable to delete as LL is empty\n");
        return;
    }
    else if((*First) -> next == NULL) // Case 2
    {
        free(*First);
        *First = NULL;
    }
    else    // Case 3
    {
        temp = *First;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAtPos(PPNODE First, int No, int iPos)
{
    int iLength = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;
    int i = 0;

    iLength = Count(*First);

    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(First,No);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(First,No);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = No;
        newn->next = NULL;

        temp = *First;

        for(i = 1; i < iPos-1; i++)
        {
	        temp = temp->next;
        }

        newn->next = temp -> next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE First, int iPos)
{
    int iLength = 0;
    int i = 0;

    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    iLength = Count(*First);

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(First);
    }
    else if(iPos == iLength)
    {
        DeleteLast(First);
    }
    else
    {
        temp1 = *First;

        for(i = 1; i < iPos -1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1 -> next;

        temp1->next = temp2 -> next;
        free(temp2);
    }
}

int main()
{
    PNODE Head = NULL;
    int iRet = 0;
    
    InsertFirst(&Head, 51);
    InsertFirst(&Head, 21);
    InsertFirst(&Head, 11);

    InsertLast(&Head, 101);
    InsertLast(&Head, 111);
    InsertLast(&Head, 121);
    InsertLast(&Head, 151);
    
    InsertAtPos(&Head,105,5);
    
    Display(Head);
    iRet = Count(Head);
    printf("Number of elements are : %d\n",iRet);

    DeleteAtPos(&Head, 5);

    Display(Head);
    iRet = Count(Head);
    printf("Number of elements are : %d\n",iRet);

    return 0;
}
