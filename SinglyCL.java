class node
{
    public int data;
    public node next;
    node(int Value)
    {
        data = Value;
        next = null;
    }
}

class SinglyCLL
{
    public node First;
    public node Last;
    public int iCount;
    SinglyCLL()
    {
        First = null;
        Last = null;
        iCount = 0;
    }

    void InsertFirst(int No)
    {
        node newn = new node(No);

        if(First == null)
        {
            First = newn;
            Last = newn;
            Last.next = First;
        }
        else
        {
            newn.next = First;
            First = newn;
            Last.next = First;
        }
        iCount++;
    }

    void InsertLast(int No)
    {
        node newn = new node(No);

        if(First == null)
        {
            First = newn;
            Last = newn;
            Last.next = First;
        }
        else
        {
            Last.next = newn;
            Last = newn;
            Last.next = First;
        }
        iCount++;
    }

    void InsertAtPos(int No,int iPos)
    {
       if(iPos < 1 || iPos > iCount + 1)
       {
        System.out.println("Invalid position");
        return;
       }

       if(iPos == 1)
       {
        InsertFirst(No);
       }
       else if(iPos == (iCount + 1))
       {
        InsertLast(No);
       }
       else
       {
         node newn = new node(No);
         node temp = First;
         int i = 0;
         for(i = 1;i < iPos - 1;i++)
         {
            temp = temp.next;
         }
         newn.next = temp.next;
         temp.next = newn;
         iCount++;
       }
    }

    void Display()
    {
        if(First == null)
        {
            System.out.println("LL is empty");
            return;
        }
        node temp = First;
        do
        {
            System.out.print("|"+temp.data+"|<->");
            temp = temp.next;
        }while(temp != First);
        System.out.println();
    }

    int Count()
    {
        return iCount;
    }

    void DeleteFirst()
    {
        if(First == null)
        {
            System.out.println("LL is empty.");
            return;
        }
        else if(First == Last)
        {
            First = null;
            Last = null;
        }
        else
        {
            First = First.next;
            Last.next = First;
        }
        iCount--;
    }

    void DeleteLast()
    {
        if(First == null)
        {
            System.out.println("LL is empty");
            return;
        }

        if(First == Last)
        {
            First = null;
            Last = null;
        }

        node temp = First;
        do{
                temp = temp.next;
          }while(temp.next.next != First);
        temp.next = First;
        Last = temp;
        Last.next = First;
        iCount--;
    }

    void DeleteAtPos(int iPos)
    {
       if(iPos < 1 || iPos > iCount)
       {
        System.out.println("Invalid position");
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
         node temp = First;
         int i = 0;
         for(i = 1;i < iPos - 1;i++)
         {
            temp = temp.next;
         }
         temp.next = temp.next.next;
         Last.next = First;
         iCount--;
       }
    }
}

class SinglyCL
{
    public static void main(String Arg[])
    {
        int iRet = 0;
        SinglyCLL cobj = new SinglyCLL();

        cobj.InsertFirst(51);
        cobj.InsertFirst(21);
        cobj.InsertFirst(11);
        cobj.InsertFirst(10);

        cobj.InsertLast(161);
        cobj.InsertLast(151);
        cobj.InsertLast(121);
        cobj.InsertLast(101);

        cobj.Display();
        iRet = cobj.Count();
        System.out.println("Number of elements in LL are : "+iRet);

        cobj.DeleteFirst();
        cobj.Display();
        iRet = cobj.Count();
        System.out.println("Number of elemenst are : "+iRet);

        cobj.DeleteLast();
        cobj.Display();
        iRet = cobj.Count();
        System.out.println("Number of elemenst are : "+iRet);

        cobj.InsertAtPos(105,5);
        cobj.Display();
        iRet = cobj.Count();
        System.out.println("Number of elemenst are : "+iRet);

        cobj.DeleteAtPos(5);
        cobj.Display();
        iRet = cobj.Count();
        System.out.println("Number of elemenst are : "+iRet);
    }
}