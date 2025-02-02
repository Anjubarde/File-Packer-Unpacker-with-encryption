/*
    Generic Doubly Circular LinkedList
*/

#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template<class T>
class DoublyCL
{
    public:
        struct node<T> * head;
        struct node<T> * tail;
        int iCount;

        DoublyCL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();

};

        template<class T>
        DoublyCL<T>::DoublyCL()
        {
            head = NULL;
            tail = NULL;
            iCount = 0;
        }

        template<class T>
        void DoublyCL<T>::InsertFirst(T no)
        {
            struct node<T> * newn = new node<T>;
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(head == NULL)
            {
                head = newn;
                tail = newn;
            }
            else
            {
                newn->next = head;
                head->prev = newn;
                head = newn;
                tail->next = head;
                head->prev = tail;
            }
            iCount++;
        }

        template<class T>
        void DoublyCL<T>::InsertLast(T no)
        {
            struct node<T> * newn = new node<T>;
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;
        

            if(head == NULL)
            {
                head = newn;
                tail = newn;
            }
            else
            {
                tail->next = newn;                                          
                newn->prev = tail;
                tail = newn;
                tail->next = head;
                head->prev = tail;
            }
            iCount++;
        }
        
        template<class T>
        void DoublyCL<T>::InsertAtPos(T no, int ipos)
        {
           if(ipos < 1 || ipos > iCount + 1)
           {
                cout<<"Invalid Position"<< endl;
                return;
           }

           if(ipos == 1)
           {
                InsertFirst(no);
           }
           else if(ipos == iCount + 1)
           {
                InsertLast(no);
           }
           else
           {
                struct node<T> * newn = new node<T>;
                newn->data = no;
                struct node<T> * temp = head;

                for(int i = 1; i < ipos - 1; i++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                newn->prev = temp;
                temp->next->prev = newn;
                temp->next = newn;

                iCount++;
           }
        }
        
        template<class T>
        void DoublyCL<T>::DeleteFirst()
        {
            if(head == NULL)
            {
                cout<<"List is empty"<< endl;
                return;
            }
            if(head == tail)
            {
                delete head;
                head = NULL;
                tail = NULL;
            }
            else
            {
                head = head->next;
                delete head->prev;
                head->prev = tail;
                tail->next = head;
            }
            iCount--;
        }

        template<class T>
        void DoublyCL<T>::DeleteLast()
        {
            if(head == NULL)
            {
                cout<<"LinkedList is empty"<<endl;
                return;
            }
            if(head == tail)
            {
                delete head;
                head = NULL;
                tail = NULL;
            }
            else
            {
                tail = tail->prev;
                delete tail->next;
                tail->next = head;
                head->prev = tail;
            }
            iCount--;
        }

        template<class T>
        void DoublyCL<T>::DeleteAtPos(int ipos)
        {
            if(ipos < 1 || ipos > iCount)
            {
                cout<<"Invalid position"<<endl;
                return;
            }
            if(ipos == 1)
            {
                DeleteFirst();
            }
            else if(ipos == iCount)
            {
                DeleteLast();
            }
            else
            {
                struct node<T> * temp = head;

                for(int i = 1; i<ipos; i++)
                {
                    temp = temp->next;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;

                iCount--;
            }
        }

        template<class T>
        void DoublyCL<T>::Display()
        {
            if(head == NULL)
            {
                cout<<"LinkedList is empty"<<endl;
                return;
            }

            struct node<T> * temp = head;
            do
            {
                cout<<temp->data<< " ";
                temp = temp->next;
            } while(temp != head);
            
            cout << endl;
        }

        template<class T>
        int DoublyCL<T>::Count()
        {
            return iCount;
        }

int main()
{
    DoublyCL <int>obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    
    obj.InsertAtPos(75,4);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();
    
    obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";
    
    return 0;
}