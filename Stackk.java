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

class Stack // LIFO
{
    public node First;    
    public int iCount;

    public Stack()
    {
        System.out.println("Object of Stack gets created succesfully");

        First = null;
        iCount = 0;
    }

    public void Push(int No)    // InsertFirst
    {
        node newn = new node(No);

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


    public int Pop()    // DeleteFirst
    {
        int Value = 0;

        if(First == null)
        {
            System.out.println("Stack is empty");
            return -1;
        }
        else
        {
            Value = First.data;
            First = First.next;
        }
        iCount--;
        return Value;
    }

    public void Display()
    {
        System.out.println("Elements of stack are : ");

        node temp = First;

        while(temp != null)
        {
            System.out.println(temp.data);
            temp = temp.next;
        }
    }

    public int Count()
    {
        return iCount;
    }
}

class Stackk
{
    public static void main(String Arg[])
    {
        Stack obj = new Stack();
        int iRet = 0;

        obj.Push(10);
        obj.Push(20);
        obj.Push(30);
        obj.Push(40);

        obj.Display();

        iRet = obj.Pop();
        System.out.println("Poped element is : "+iRet);

        obj.Display();
    }
}