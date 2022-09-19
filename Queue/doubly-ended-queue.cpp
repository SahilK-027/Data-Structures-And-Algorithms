#include <bits/stdc++.h>
using namespace std;
class DEqueue
{
private:
    DEqueue *next;
    int data;

public:
    void push_front(DEqueue *&head, DEqueue *&tail, int data)
    {
        DEqueue *n1 = new DEqueue;
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
    void push_back(DEqueue *&head, DEqueue *&tail, int data)
    {
        DEqueue *n1 = new DEqueue();
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
    void pop_front(DEqueue *&head, DEqueue *&tail)
    {
        if (head == NULL)
        {
            cout << "\nUnderFlow\n";
            return;
        }
        else
        {
            DEqueue *temp = head;
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
    void pop_back(DEqueue *&head, DEqueue *&tail)
    {
        if (head == NULL)
        {
            cout << "\nUnderFlow\n";
            return;
        }
        else
        {
            DEqueue *temp1 = head;
            DEqueue *temp2 = NULL;
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
    void front(DEqueue *&head)
    {
        if(head != NULL)
        cout << head->data << endl;
        else
        cout<<"\nEmpty DEqueue\n";
    }
    void rear(DEqueue *&tail)
    {
        if(tail != NULL)
        cout << tail->data << endl;
         else
        cout<<"\nEmpty DEqueue\n";
    }
};

int main()
{
    DEqueue *head = NULL;
    DEqueue *tail = NULL;
    DEqueue *q = new DEqueue();
    q->push_front(head, tail, 10);
    q->push_front(head, tail, 20);
    q->push_front(head, tail, 30);
    q->push_front(head, tail, 40);
    // q->front(head);
    // q->rear(tail);

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