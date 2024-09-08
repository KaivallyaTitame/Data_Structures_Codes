class node
{
    public int data;
    public node next;

    public node(int Value)
    {
        data = Value;
        next = null;
    }
}

class SinglyLL
{
    public node First;
    public int iCount;

    public SinglyLL()
    {
        System.out.println("Object of SinglyLL gets created succesfully");
        First = null;
        iCount = 0;
    }

    public void InsertFirst(int No)
    {
        node newn = null;

        newn = new node(No);

        if(First == null)
        {
            First = newn;
        }
        else
        {
            newn.next = First;
            First = newn;
        }
        iCount++;
    }

    public void InsertLast(int No)
    {
        node newn = null;
        node temp = null;

        newn = new node(No);

        if(First == null)
        {
            First = newn;
        }
        else
        {
            temp = First;

            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        iCount++;
    }

    public void Display()
    {
        System.out.println("Elements of the LinkedList are : ");

        node temp = First;

        while(temp != null)
        {
            System.out.print("| "+temp.data+" |-> ");
            temp = temp.next;
        }
        System.out.println("null");
    }

    public int Count()
    {
        return iCount;
    }

    public void DeleteFirst()
    {
        if(First == null)
        {
            System.out.println("LL is empty");
            return;
        }
        else
        {
            First = First.next;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        if(First == null)
        {
            System.out.println("LL is empty");
            return;
        }
        else if(First.next == null) // Single node
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

    public void InsertAtPos(int No, int iPos)
    {
        if((iPos < 1) || (iPos > iCount + 1))
        {
            System.out.println("Invalid Position");
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(No);
        }
        else if(iPos == iCount+1)
        {
            InsertLast(No);
        }
        else
        {
            node temp = First;
            int i = 0;
            
            node newn = new node(No);

            for(i = 1; i < iPos-1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;

            iCount++;
        }
    }

    public void DeleteAtPos(int iPos)
    {
        if((iPos < 1) || (iPos > iCount))
        {
            System.out.println("Invalid Position");
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
            
            for(i = 1; i < iPos-1; i++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;

            iCount--;
        }
    }
}

class SinglyL
{
    public static void main(String Arg[])
    {
        SinglyLL obj = new SinglyLL();    
        int iRet = 0;

        obj.InsertFirst(101);
        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.InsertLast(111);
        obj.InsertLast(121);       
        obj.InsertLast(151);

        obj.InsertAtPos(105,5);
        
        obj.Display();  
        iRet = obj.Count();

        System.out.println("Number of elements are : "+iRet); 

        obj.DeleteAtPos(5);
        
        obj.Display();  
        iRet = obj.Count();

        System.out.println("Number of elements are : "+iRet); 

    }
}