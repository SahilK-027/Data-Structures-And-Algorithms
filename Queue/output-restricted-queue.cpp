#include <bits/stdc++.h>
using namespace std;
class OpRestrictedQueue
{
private:
    OpRestrictedQueue *next;
    int data;

public:
    void push_front(OpRestrictedQueue *&head, OpRestrictedQueue *&tail, int data)
    {
        OpRestrictedQueue *n1 = new OpRestrictedQueue;
        n1->data = data;
        n1->next = NULL;
        if (head == NULL)
        {
            head = n1;
            tail = n1;
        }
        else
        {
            n1->next = head;
            head = n1;
        }
    }
    void push_back(OpRestrictedQueue *&head, OpRestrictedQueue *&tail, int data)
    {
        OpRestrictedQueue *n1 = new OpRestrictedQueue();
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
    void pop_front(OpRestrictedQueue *&head, OpRestrictedQueue *&tail)
    {
        if (head == NULL)
        {
            cout << "\nUnderFlow\n";
            return;
        }
        else
        {
            OpRestrictedQueue *temp = head;
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
    void front(OpRestrictedQueue *&head)
    {
        if(head != NULL)
        cout << head->data << endl;
        else
        cout<<"\nEmpty OpRestrictedQueue\n";
    }
    void rear(OpRestrictedQueue *&tail)
    {
        if(tail != NULL)
        cout << tail->data << endl;
         else
        cout<<"\nEmpty OpRestrictedQueue\n";
    }
};

int main()
{
    OpRestrictedQueue *head = NULL;
    OpRestrictedQueue *tail = NULL;
    OpRestrictedQueue *q = new OpRestrictedQueue();

    q->push_back(head, tail, 5);
    q->push_back(head, tail, 1);
    // q->front(head);
    // q->rear(tail);

    q->pop_front(head,tail);
    q->pop_front(head,tail);
    q->pop_front(head,tail);
    q->front(head);
    q->rear(tail);
}