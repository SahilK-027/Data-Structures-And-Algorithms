#include <bits/stdc++.h>
using namespace std;
class IpRestrictedQueue
{
private:
    IpRestrictedQueue *next;
    int data;

public:

    void push_back(IpRestrictedQueue *&head, IpRestrictedQueue *&tail, int data)
    {
        IpRestrictedQueue *n1 = new IpRestrictedQueue();
        n1->data = data;
        n1->next = NULL;
        if (head == NULL)
        {
            head = n1;
            tail = n1;
        }
        else
        {
            tail->next = n1;
            tail = n1;
        }
    }
    void pop_front(IpRestrictedQueue *&head, IpRestrictedQueue *&tail)
    {
        if (head == NULL)
        {
            cout << "\nUnderFlow\n";
            return;
        }
        else
        {
            IpRestrictedQueue *temp = head;
            if(temp->next){
                head = temp->next;
            }
            else{
                head = NULL;
                tail = NULL;
            }
            delete temp;
        }
    }
    void pop_back(IpRestrictedQueue *&head, IpRestrictedQueue *&tail)
    {
        if (head == NULL)
        {
            cout << "\nUnderFlow\n";
            return;
        }
        else
        {
            IpRestrictedQueue *temp1 = head;
            IpRestrictedQueue *temp2 = NULL;
            while (temp1->next != NULL)
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            if (temp2)
            {
                tail = temp2;
                temp2->next = NULL;
                delete temp1;
            }
            else
            {
                tail = NULL;
                head = NULL;
                delete temp1;
            }
        }
    }
    void front(IpRestrictedQueue *&head)
    {
        if(head != NULL)
        cout << head->data << endl;
        else
        cout<<"\nEmpty IpRestrictedQueue\n";
    }
    void rear(IpRestrictedQueue *&tail)
    {
        if(tail != NULL)
        cout << tail->data << endl;
         else
        cout<<"\nEmpty IpRestrictedQueue\n";
    }
};

int main()
{
    IpRestrictedQueue *head = NULL;
    IpRestrictedQueue *tail = NULL;
    IpRestrictedQueue *q = new IpRestrictedQueue();

    q->push_back(head, tail, 5);
    q->push_back(head, tail, 1);
    // q->front(head);
    // q->rear(tail);

    q->pop_back(head, tail);
    q->pop_back(head, tail);
    q->pop_back(head, tail);
    // q->front(head);
    // q->rear(tail);

    q->pop_front(head,tail);
    q->pop_front(head,tail);
    q->pop_front(head,tail);
    q->front(head);
    q->rear(tail);
}