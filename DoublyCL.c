//Doubly Circular

#include<stdio.h>
#include<stdlib.h>

struct nodeDC
{
    int data;
    struct nodeDC* prev;
    struct nodeDC* next;
};

typedef struct nodeDC NODE;
typedef struct nodeDC* PNODE;
typedef struct nodeDC** PPNODE;

void InsertFirst(PPNODE First,PPNODE Last,int No)
{
    PNODE newn = NULL;

    newn=(PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if(*First == NULL &&  *Last == NULL)
    {
        *First = newn;
        *Last = newn;
    }
    else
    {
        newn->next = *First;
        (*First)->prev = newn;
        *First = newn;
    }
    (*Last)->next = *First;
    (*First)->prev = *Last;
}

void InsertLast(PPNODE First,PPNODE Last,int No)
{
    PNODE newn = NULL;

    newn=(PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if(*First == NULL && *Last == NULL)
    {
        *First = newn;
        *Last = newn;
    }
    else
    {
       (*Last)->next = newn;
       newn->prev = *Last;
       *Last = newn; 
    }
    (*Last)->next = *First;
    (*First)->prev = *Last;
}

void InsertAtPos(PPNODE First,PPNODE Last,int No,int Pos)
{
    int i = 0;
    PNODE newn = NULL;
    PNODE temp = *First;
    int iLength = 0;

    iLength = Count(*First,*Last);

    newn=(PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if(Pos < 1 || Pos > iLength+1)
    {
        printf("Invalid position\n");
        return;
    }

    if(Pos == 1)
    {
       InsertFirst(First,Last,No);
    }
    else if(Pos == iLength+1)
    {
        InsertLast(First,Last, No);
    }
    else
    {
        for(i = 1;i < Pos -1; i++)
        {
           temp = temp->next;
        }
           newn->next = temp->next;
           temp->next->prev = newn;

           temp->next = newn;
           newn->prev = temp;
    }
}

void Display(PNODE First,PNODE Last)
{
    if (First == NULL && Last == NULL) 
    {
        printf("LL is empty");
        return;
    }
    PNODE temp = First;
    
    do
    {
      printf("%d\t",temp->data);
      temp = temp->next;   
    }while(temp != First);
    printf("\n");
}

int Count(PNODE First,PNODE Last)
{ 
    int iCount = 0;
    if (First == NULL) 
    {
        printf("LL is empty");
        return 0;
    }
    PNODE temp = First;
    
    do
    {
      iCount++;
      temp = temp->next;   
    }while(temp != First);
    return iCount;
}

void DeleteFirst(PPNODE First,PPNODE Last)
{
    if (First == NULL && Last == NULL) 
    {
        printf("LL is empty");
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
       *First=(*First)->next;
       free((*Last)->next);
       (*Last)->next = *First;
       (*First)->prev = *Last;
    }
}

void DeleteLast(PPNODE First,PPNODE Last)
{
    if (First == NULL && Last == NULL) 
    {
        printf("LL is empty");
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
       *Last = (*Last)->prev;
       free((*First)->prev);

       (*Last)->next = *First;
       (*First)->prev = *Last;
    }
}

void DeleteAtPos(PPNODE First,PPNODE Last,int Pos)
{
    int i = 0;
    PNODE temp = *First;
    int iLength = 0;

    iLength = Count(*First,*Last);
    
    if(Pos < 1 || Pos > iLength+1)
    {
        printf("Invalid position\n");
        return 0;
    }

    if(Pos == 1)
    {
       DeleteFirst( First, Last);
    }
    else if(Pos == iLength)
    {
        DeleteLast( First, Last);
    }
    else
    {
        for(i = 1;i < Pos -1; i++)
        {
           temp = temp->next;
        }
           temp->next = temp->next->next;
           free(temp->next->prev);
           temp->next->prev = temp;
    }
}

int main()
{
    PNODE Head = NULL;
    PNODE Tail = NULL;
    int iRet = 0;

    InsertFirst(&Head,&Tail,101);
    InsertFirst(&Head,&Tail,51);
    InsertFirst(&Head,&Tail,21);
    InsertFirst(&Head,&Tail,11);

    InsertLast(&Head,&Tail,111);
    InsertLast(&Head,&Tail,121);

    Display(Head,Tail);
    iRet = Count(Head,Tail);
    printf("Number of elements are : %d\n",iRet);

    DeleteFirst(&Head,&Tail);
    Display(Head,Tail);
    iRet = Count(Head,Tail);
    printf("Number of elements are : %d\n",iRet);

    DeleteLast(&Head,&Tail);
    Display(Head,Tail);
    iRet = Count(Head,Tail);
    printf("Number of elements are : %d\n",iRet);

    InsertAtPos(&Head,&Tail,151,2);
    Display(Head,Tail);
    iRet = Count(Head,Tail);
    printf("Number of elements are : %d\n",iRet);

    DeleteAtPos(&Head,&Tail,2);
    Display(Head,Tail);
    iRet = Count(Head,Tail);
    printf("Number of elements are : %d\n",iRet);
    return 0;
}