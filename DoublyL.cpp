#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyLL
{
    private:
    int iCount;
    PNODE First;

    public:
    DoublyLL();
    void Display();
    int Count();

    void InsertFirst(int No);
    void InsertLast(int No);
    void InsertAtPos(int No,int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

};

DoublyLL::DoublyLL()
{
    iCount = 0;
    First = NULL;
}

void DoublyLL::Display()
{
    PNODE temp = First;
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }
    cout<<endl;
}

int DoublyLL::Count()
{
    return iCount;
}

void DoublyLL::InsertFirst(int No)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if((First == NULL))
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iCount++;
}

void DoublyLL::InsertLast(int No)
{
    PNODE newn = NULL;
    PNODE temp = First;

    newn = new NODE;

    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if((First == NULL))
    {
        First = newn;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev =temp;
    }
    iCount++;
}

void DoublyLL::InsertAtPos(int No,int iPos)
{
    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == (iCount+1))
    {
        InsertLast(No);
    }
    else
    {
        PNODE newn = NULL;
        PNODE temp = First;
        int i = 0;

        newn = new NODE;

        newn->data = No;
        newn->prev = NULL;
        newn->next = NULL;

        for(i = 1; i < iPos-1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        
        iCount++;
    }
}

void DoublyLL::DeleteFirst()
{
    if(First == NULL)
    {
        cout<<"LL is empty";
        return;
    }
    else if(First->next== NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
    First = First->next;
    delete First->prev;
    First->prev = NULL;
    }
    iCount--;
}

void DoublyLL::DeleteLast()
{
    PNODE temp = First;
    if(First == NULL)
    {
        cout<<"LL is empty";
        return;
    }
    else if(First->next== NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    }
    iCount--;
}

void DoublyLL::DeleteAtPos(int iPos)
{
     if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp1 = First;
        PNODE temp2 = NULL;
        int i = 0;

        for(i = 1; i < iPos-1;i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp1->next->next;
        temp1->next->prev = temp1;
        delete temp2;
        iCount--;
    }
}

int main()
{
    DoublyLL DLobj;
    int iRet = 0;

    DLobj.InsertFirst(51);
    DLobj.InsertFirst(21);
    DLobj.InsertFirst(11);
    DLobj.InsertFirst(10);
    
    DLobj.InsertLast(100);
    DLobj.InsertLast(101);
    DLobj.InsertLast(111);
    DLobj.InsertLast(121);
    
    
    DLobj.Display();
    iRet = DLobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;


    DLobj.DeleteFirst();
    DLobj.Display();
    iRet = DLobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    DLobj.DeleteLast();
    DLobj.Display();
    iRet = DLobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;


    DLobj.InsertAtPos(161,5);
    DLobj.Display();
    iRet = DLobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    
    DLobj.DeleteAtPos(5);
    DLobj.Display();
    iRet = DLobj.Count();
    cout<<"Number of elements are : "<<iRet;

    return 0;
}