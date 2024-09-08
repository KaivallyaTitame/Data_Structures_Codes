#include<stdio.h>
#include<stdlib.h>

struct nodeDL
{
    int data;
    struct nodeDL* prev;
    struct nodeDL* next;
};

typedef struct nodeDL NODE;
typedef struct nodeDL* PNODE;
typedef struct nodeDL** PPNODE;

void InsertFirst(PPNODE First,int No)
{
    PNODE newn = NULL;

    newn =(PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        (*First)->prev = newn;
        *First = newn;
    }
}


void InsertLast(PPNODE First,int No)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn =(PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->prev = NULL;
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
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}

void InsertAtPos(PPNODE First,int No,int Pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iLength = 0;

    iLength = Count(*First);
    
    newn=(PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;
    int i = 0;

    if((Pos < 1) || (Pos > iLength+1))
    {
        printf("Invalid position\n");
    }

    if(Pos == 1)
    {
        InsertFirst(First,No);
    }
    else if(Pos == iLength+1)
    {
        InsertLast(First,No);
    }
    else
    {
        temp = *First;
        for(i = 1;i < Pos - 1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}

void Display(PNODE First)
{
    while(First != NULL)
    {
        printf("%d\t",First->data);
        First = First->next;
    }
    printf("\n");
}

int Count(PNODE First)
{
    int iCount = 0;
    while(First != NULL)
    {
        iCount++;
        First = First->next;
    }
    return iCount;
}

void DeleteFirst(PPNODE First)
{
    if(*First == NULL)
    {
        printf("The LL is empty");
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        *First = (*First)->next;
        free((*First)->prev); 
        (*First)->prev = NULL;
    }
}

void DeleteLast(PPNODE First)
{
    PNODE temp = NULL;
    temp = *First;

    if(*First == NULL)
    {
        printf("The LL is empty");
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
        temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL; 
    }
}

void DeleteAtPos(PPNODE First,int Pos)
{
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;
    int iLength = 0;

    iLength = Count(*First);
    
    int i = 0;

    if((Pos < 1) || (Pos > iLength))
    {
        printf("Invalid position\n");
    }

    if(Pos == 1)
    {
        DeleteFirst(First);
    }
    else if(Pos == iLength+1)
    {
        DeleteLast(First);
    }
    else
    {
        temp1 = *First;
        for(i = 1;i < Pos - 1;i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp1->next->next;
        temp2->next->prev = temp1;
        free(temp2);
    }
}

int main()
{ 
    PNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head,101);
    InsertFirst(&Head,51);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);

    InsertLast(&Head,111);
    InsertLast(&Head,121);

    Display(Head);
    iRet = Count(Head);
    printf("Number of elements are : %d\n",iRet);

    DeleteFirst(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("Number of elements are : %d\n",iRet);

    DeleteLast(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("Number of elements are : %d\n",iRet);

    InsertAtPos(&Head,151,2);
    Display(Head);
    iRet = Count(Head);
    printf("Number of elements are : %d\n",iRet);

    DeleteAtPos(&Head,2);
    Display(Head);
    iRet = Count(Head);
    printf("Number of elements are : %d\n",iRet);
   
    return 0;
}