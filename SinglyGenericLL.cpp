#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};
/////////////////////////////////////////////////////
template <class T>
class SinglyLL
{
public:
    struct node<T> *Head;
    int Count;

    SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteAtPos(int);
    void Display();
    int CountNode();
    void DeleteFirst();
    void DeleteLast();
};
/////////////////////////////////////////////////////////
template <class T>
SinglyLL<T>::SinglyLL()
{
    Head = NULL;
    Count = 0;
}
////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = No;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Count++;
}
/////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = No;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct node<T> *temp = Head;
        while (temp->next = NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;
}
////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::InsertAtPos(T No, int pos)
{
    if ((Head == NULL) || (pos > Count + 1) || (pos <= 0))
    {
        return;
    }

    if (pos == 1)
    {
        return InsertFirst(No);
    }
    else if (pos == (Count + 1))
    {
        return InsertLast(No);
    }
    else
    {
        struct node<T> *newn = NULL;
        struct node<T> *temp = Head;
        newn = new node<T>;

        if (newn == NULL)
        {
            return;
        }

        newn->next = NULL;
        newn->data = No;

        for (int i = 1; i <= (pos - 2); i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    Count++;
}
////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::DeleteAtPos(int pos)
{
    if ((Head == NULL) || (pos > Count) || (pos <= 0))
    {
        return;
    }

    if (pos == 1)
    {
        return DeleteFirst();
    }
    else if (pos == Count)
    {
        return DeleteLast();
    }
    else
    {
        struct node<T> *temp1 = Head, *temp2 = NULL;

        for (int i = 1; i < pos - 2; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;

        delete temp2;
    }
    Count--;
}
/////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::Display()
{
    cout << "elements from linked list are :" << endl;
    struct node<T> *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
/////////////////////////////////////////////////////////////////////
template <class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}
/////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct node<T> *temp = Head;
    if (Head == NULL)
    {
        return;
    }
    else
    {
        Head = Head->next;
        free(temp);
    }
    Count--;
}
////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::DeleteLast()
{
    if (Head == NULL)
    {
        return;
    }
    else if (Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct node<T> *temp = Head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete ((temp->next));
        temp->next = NULL;
    }
    Count--;
}
///////////////////////////////////////////////////////////////////////
int main()
{
    SinglyLL<int> obj1;
    SinglyLL<float> obj2;

    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertFirst(51);
    obj1.InsertFirst(101);

    obj1.InsertAtPos(77, 3);
    //obj1.DeleteFirst();
    //obj1.DeleteLast();
    obj1.DeleteAtPos(3);

    obj1.Display();
    cout << "number of nodes are :" << obj1.CountNode() << endl;

    obj2.InsertFirst(21.11);
    obj2.InsertFirst(11.11);
    obj2.InsertFirst(51.11);
    obj2.InsertFirst(101.11);

    obj2.InsertAtPos(77.89, 3);
    obj2.DeleteFirst();
    obj2.DeleteLast();
    obj2.DeleteAtPos(3);

    obj2.Display();
    cout << "number of nodes are :" << obj2.CountNode() << endl;

    return 0;
}

