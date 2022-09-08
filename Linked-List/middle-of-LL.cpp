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
    cout << temp->data << endl;
}


int middle_of_ll(Node* start){
    Node* fast = start;
    Node* slow = start;
    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow ->next;
    }
    return slow->data;
}


int main()
{
    Node *start = NULL;
    insertAtStart(start, 5);
    insertAtStart(start, 4);
    insertAtStart(start, 3);
    insertAtStart(start, 2);
    insertAtStart(start, 1);
    displayList(start);
    cout<< middle_of_ll(start)<<endl;
    return 0;
}
