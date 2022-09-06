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
void insertAtEnd(Node *&start, int data)
{
    Node *n1 = new Node;
    n1->data = data;
    n1->next =NULL;
    if(start == NULL){
        insertAtStart(start,data);
    }
    else{
        Node *temp;
        temp = start;
        while(temp->next != NULL){
            temp = temp -> next;
        }
        temp -> next = n1;
    }
}
void deleteFirstNode(Node *&start)
{
    if(start == NULL){
        cout<<"\nUnderflow\n";
        return;
    }
    Node *temp;
    temp = start;
    start = temp->next;
    if(start!=NULL){
        temp->next->prev = start;
    }
    delete temp;

}
void deleteLastNode(Node *&start)
{
    if(start == NULL){
        cout<<"\nUnderflow\n";
        return;
    }
    Node *t1, *t2;
    t1 = start;
    t2 = NULL;
    while(t1->next != NULL){
        t2 = t1;
        t1 = t1->next;
    }
    if(t2){
        t2->next =NULL;
        delete t1;
    }
    else{
        deleteFirstNode(start);
    }
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
    Node *start = NULL;
    int data;
    int flag = 1;
    int ch;
    cout << "Program for Doubly linked list"
         << "\n";
    cout << "MENU: "
         << "\n";
    while (flag)
    {
        cout << "\n1. Insert At Start\n2. Insert At End\n3. Delete First Node\n4. Delete Last Node\n5. Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            insertAtStart(start, data);
            cout << endl;
            displayList(start);
            cout << endl;
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            insertAtEnd(start, data);
            cout << endl;
            displayList(start);
            cout << endl;
            break;
        case 3:
            deleteFirstNode(start);
            cout << endl;
            displayList(start);
            cout << endl;
            break;
        case 4:
            deleteLastNode(start);
            cout << endl;
            displayList(start);
            cout << endl;
            break;
        case 5:
            flag = 0;
            break;
        default:
            cout << "Wrong choice re-enter" << endl;
            break;
        }
    }
    return 0;
}
