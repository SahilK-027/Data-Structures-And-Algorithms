#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void insertAtStart(Node *&start, int data)
{
    Node *n1 = new Node;
    n1->data = data;
    n1->next = start;
    start = n1;
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
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data<<endl;
}
void reverseLL(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return; // Checking for Empty or single node LL
    }
    // Using 3 ptr approach
    Node *current = head;
    Node *previous = NULL;
    Node *next = current->next;
    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}
void reverseLL2(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return; // Checking for Empty or single node LL
    }
    //Recursion will reverse list from head->next
    reverseLL2(head->next);

    //Our job is to reverse first Node
    head->next->next = head;
    head->next = NULL;
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
    reverseLL(start);
    cout<<"AFTER: ";
    displayList(start);
    return 0;
}
