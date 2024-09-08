Douclass node
{
    public int data;
    public node next;
    public node prev;

    public node(int Value)
    {
        data = Value;
        next = null;
        prev = null;
    }
}

class DoublyLL
{
    public node First;
    
    public int iCount;

    public DoublyLL()
    {
        System.out.println("Object of DoublyLL gets created sucessfully");
        First = null;
        iCount = 0;
    }

    public void InsertFirst(int No)
    {
        node newn = new node(No);

        if(First ==null)
        {
            First = newn;
        }
        else
        {
            newn.next = First;
            First.prev=newn;
            First = newn;
        }
        iCount++;
    }

    public void InsertLast(int No)
    {
        node newn = new node(No);

        if(First == null)
        {
            First = newn;
        }
        else
        {
            node temp = First;

            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
            newn.prev = temp;
        }
        iCount++;
    }

    public void InsertAtPos(int No,int Pos)
    {
        if(Pos < 1 || Pos > iCount+1)
        {
            System.out.println("Invalid Position : ");
            return;
        }

        if(Pos == 1)
        {
            InsertFirst(No);
        }
        else if(Pos == iCount+1)
        {
            InsertLast(No);
        }
        else
        {
        node newn = new node(No);

        newn.data = No;
        newn.next = null;
        newn.prev = null;

        node temp = First;

        int i = 0;
        for(i = 1; i < Pos-1;i++)
        {
            temp=temp.next;
        }
        newn.next = temp.next;
        newn.prev = temp;
        temp.next.prev = newn;
        temp.next = newn;
        iCount++;
        }
    }

    public void Display()
    {
        node temp = First;
        while(temp != null)
        {
            System.out.print("|"+temp.data+"|<=>");
            temp = temp.next;
        }
        System.out.println("NULL\n");
    }

    public int Count()
    {
        return iCount;
    }

    public void DeleteFirst()
    {
        node temp = First;
        if(First == null)
        {
            return;
        }
        else if(First.next == null)
        {
            First = null;
        } 
        else
        {
            First = First.next;
            First.prev = null;
        }  
        iCount--;     
    }

    public void DeleteLast()
    {
        if(First == null)
        {
            return;
        }
        if(First.next == null)
        {
            First = null;
        } 
        else
        {
            node temp = First;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
        } 
        iCount--;
    }

    public void DeleteAtPos(int Pos)
    {
        if(Pos < 1 || Pos > iCount+1)
        {
            System.out.println("Invalid Position : ");
            return;
        }

        if(Pos == 1)
        {
            DeleteFirst();
        }
        else if(Pos == iCount)
        {
            DeleteLast();
        }
        else
        {

        node temp = First;

        int i = 0;
        for(i = 1; i < Pos-1;i++)
        {
            temp=temp.next;
        }
        temp.next = temp.next.next;
        temp.next.prev = temp;

        iCount--;
        }
    }
}
class DoublyL
{
    public static void main(String Arg[])
    {
        DoublyLL obj = new DoublyLL();
        int iRet = 0;
        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        obj.InsertFirst(10);

        obj.InsertLast(101);
        obj.InsertLast(121);
        obj.InsertLast(151);

        obj.Display();
        iRet = obj.Count();
        System.out.print("Number of elements in the LL are : "+iRet+"\n");

        obj.DeleteFirst();
        obj.Display();
        iRet = obj.Count();
        System.out.print("Number of elements in the LL are : "+iRet+"\n");

        obj.DeleteLast();
        obj.Display();
        iRet = obj.Count();
        System.out.print("Number of elements in the LL are : "+iRet+"\n");

        obj.InsertAtPos(160,2);
        obj.Display();
        iRet = obj.Count();
        System.out.print("Number of elements in the LL are : "+iRet+"\n");

        obj.DeleteAtPos(2);
        obj.Display();
        iRet = obj.Count();
        System.out.print("Number of elements in the LL are : "+iRet+"\n");
    }
}