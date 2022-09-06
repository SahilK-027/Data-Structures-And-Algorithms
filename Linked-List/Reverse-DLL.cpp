#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next,*prev;
};
void insertAtStart(Node *&start, int data)
{
   Node *n1 = new Node;
   n1->data = data;
   n1->next = start;
   n1->prev = NULL;
   start = n1;
}
void reverseDLL(Node* &head){
    Node* current = head;
    Node* prev = current->prev;
    Node* next = current->next;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        current->prev =next;
        prev = current;
        current = next;
    }
    head = prev;
}
void displayList(Node *start)
{
    if (start == NULL)
    {
        cout << "\nUnderFlow\n";
        return;
    }
    Node *temp;
    temp = start;
    while (temp->next != NULL)
    {
        cout << temp->data << " <=> ";
        temp = temp->next;
    }
    cout << temp->data;
}
int main()
{
    Node* start = NULL;
    insertAtStart(start, 10);
    insertAtStart(start, 20);
    insertAtStart(start, 30);
    insertAtStart(start, 40);
    cout<<"BEFORE: ";
    displayList(start);
    reverseDLL(start);
    cout<<endl;
    cout<<"AFTER: ";
    displayList(start);
    cout<<endl;
    return 0;
}
