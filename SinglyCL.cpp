#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyCL
{
   private:
   PNODE First;
   PNODE Last;
   int iCount;

   public:
   SinglyCL();

   void Display();
   int Count();

   void InsertFirst(int No);
   void InsertLast(int No);
   void InsertAtPos(int No,int iPos);

   void DeleteFirst();
   void DeleteLast();
   void DeleteAtPos(int iPos);
};

SinglyCL::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

void SinglyCL::InsertFirst(int No)
{
   PNODE newn = NULL;

   newn = new NODE;

   newn->data = No;
   newn->next = NULL;

   if(First == NULL && Last == NULL)
   {
    First = newn;
    Last = newn;
   }
   else
   {
    newn->next = First;
    First = newn;
   }
   Last->next = First;
   iCount++;
}

void SinglyCL::InsertLast(int No)
{
    PNODE newn = NULL;

    newn= new NODE;

    newn->data = No;
    newn->next = NULL;

    
   if(First == NULL&& Last == NULL)
   {
    First = newn;
    Last = newn;
   }
   else
   {
    Last->next = newn;
    Last = newn;
   }
   Last->next = First;
   iCount++;
}

void SinglyCL::InsertAtPos(int No,int iPos)
{
    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid position";
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        PNODE newn = NULL;

        newn = new NODE;
        newn->data = No;
        newn->next = NULL;

        PNODE temp = First;
        int i = 0;
        for(i = 1;i < iPos-1;i++)
        {
            temp = temp->next;
        }
        newn->next=temp->next;
        temp ->next = newn;

        iCount++;
    }
}

void SinglyCL::Display()
{
    PNODE temp = First;
   if((First == NULL)&&(Last == NULL))
   {
     cout<<"LinkedList is empty"<<endl;
   }

   do
   {
    cout<<"|"<<temp->data<<"|<=>";
    temp = temp -> next;
   }while(temp != First);
   cout<<endl;
}

int SinglyCL::Count()
{ 
    return iCount;
}

void SinglyCL::DeleteFirst()
{
    if(First == NULL&& Last == NULL)
    {
        cout<<"The LL is emplty";
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        PNODE temp = First;
        First = First->next;
        Last->next = First;
        delete temp;
    }
    iCount--;
}

void SinglyCL::DeleteLast()
{
    if(First == NULL&& Last == NULL)
    {
        cout<<"The LL is emplty";
        return;
    }
    else if(First == Last)
    {
       delete First;
       First == NULL;
       Last == NULL;
    }
    else
    {
        PNODE temp = First;
        while(temp->next != Last)
        {
            temp = temp->next;
        }
        delete Last;
        Last = temp;
        Last->next = First;
    }
    iCount--;
}

void SinglyCL::DeleteAtPos(int iPos)
{
     if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid position";
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount + 1)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp1 = First;
        PNODE temp2 = NULL;
        int i = 0;
        for(i = 1;i < iPos-1;i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
}

int main()
{
    SinglyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertFirst(10);
    
    obj.InsertLast(100);
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    
    
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;


    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;


    obj.InsertAtPos(161,5);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    
    obj.DeleteAtPos(5);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet;

    return 0;
}