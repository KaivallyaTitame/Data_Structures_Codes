//Stack Insert First Delete First

//Queue Insert Last Delete First

#include<stdio.h>
#include<stdlib.h>

struct nodeQE
{
    int data;
    struct nodeQE* next;
};

typedef struct nodeQE NODE;
typedef struct  nodeQE* PNODE;
typedef struct nodeQE** PPNODE;

void Push(PPNODE First,int No)
{
    PNODE newn = NULL;

    newn =(PNODE)malloc(sizeof(NODE));
    newn->data  =No;
    newn->next = NULL;

    PNODE temp = *First;
    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
       newn->next = *First;
       *First = newn;
    }
}

void Display(PNODE First)
{
    printf("Elements of Stack are : \n");
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

int Pop(PPNODE First)
{
    int Value = 0;
    PNODE temp = NULL;
    if(*First == NULL)
    {
       printf("Unable to remove element as queue is empty\n");
       return -1;
    }
    else if((*First)->next==NULL)
    {
        Value = (*First)->data;
    }
    else
    {
        PNODE temp = *First;
        Value = temp->data;
        *First =(*First)->next;
        free(temp);
    }
    return Value;
}

int main()
{
    PNODE Head = 0;
    int iChoice = 0;
    int iNo = 0;

    printf("------------Implementation of Queue------------\n");
    while(iChoice != 5)
    {
        printf("Please select you chioce : \n");
        printf("1 : Push new element in Stack\n");
        printf("2 : Pop the element from Stack\n");
        printf("3 : Display the element form Stack\n");
        printf("4 : Count number of elements in Stack\n");
        printf("5 : Exit\n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
               printf("Enter the element that you want to push : \n");
               scanf("%d",&iNo);
               Push(&Head,iNo);
            break;

            case 2:
                iNo = Pop(&Head);
                if(iNo != -1)
                {
                    printf("Poped element from the Stack is : %d\n",iNo);
                }
            break;

            case 3:
                Display(Head);
            break;

            case 4:
                iNo = Count(Head);
                printf("Number of elements in the Stack are : %d\n",iNo);
            break;

            case 5:
               printf("Thank you for using our application\n");
            break;
        }
    }

    
    return 0;
}