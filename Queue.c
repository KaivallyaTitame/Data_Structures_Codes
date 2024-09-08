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

void EnQueue(PPNODE First,int No)
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
        while(temp->next != NULL)
        {
          temp = temp->next;
        }
        temp->next = newn;
    }
}

void Display(PNODE First)
{
    printf("Elements of Queue are : ");
    while(First != NULL)
    {
        printf("%d\t",First->data);
        First = First->next;
    }
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

int DeQueue(PPNODE First)
{
    int Value = 0;
    PNODE temp = NULL;
    if(*First == NULL)
    {
       printf("Unable to remove element as queue is empty\n");
       return -1;
    }
    else
    {
        temp = *First;
        Value = (*First)->data;
        *First = (*First)->next;
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
        printf("1 : Insert new element in Queue\n");
        printf("2 : Remove the element from Queue\n");
        printf("3 : Display the element form Queue\n");
        printf("4 : Count number of elements in Queue\n");
        printf("5 : Exit\n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
               printf("Enter the element that you want to insert : \n");
               scanf("%d",&iNo);
               EnQueue(&Head,iNo);
            break;

            case 2:
                iNo = DeQueue(&Head);
                if(iNo != -1)
                {
                    printf("Removed element from Queue is : %d\n",iNo);
                }
            break;

            case 3:
                Display(Head);
            break;

            case 4:
                iNo = Count(Head);
                printf("Number of elements in the Queue are : %d",iNo);
            break;

            case 5:
               printf("Thank you for using our application\n");
            break;
        }
    }

    
    return 0;
}