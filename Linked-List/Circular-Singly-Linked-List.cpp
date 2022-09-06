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
    if (start == NULL)
    {
        start = n1;
        n1->next = start;
        return;
    }
    n1->next = start;
    Node *temp = start;
    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = n1;
    start = n1;
}
void insertAtEnd(Node *&start, int data)
{
    if (start == NULL)
    {
        insertAtStart(start, data);
        return;
    }
    Node *n1 = new Node;
    n1->data = data;
    Node *temp = start;
    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = n1;
    n1->next = start;
}
void deleteFirstNode(Node *&start)
{
    if (start == NULL)
    {
        cout << "\nUnderflow\n";
        return;
    }
    Node *temp = start;
    while (temp->next != start)
    {
        temp = temp->next;
    }
    if (temp == start)
    {
        start = NULL;
        delete temp;
        return;
    }
    Node *temp2;
    temp2 = start;
    temp->next = temp2->next;
    start = temp2->next;
    delete temp2;
}
void deleteLastNode(Node *&start)
{
    if (start == NULL)
    {
        cout << "\nUnderflow\n";
        return;
    }
    Node *temp = start;
    Node *temp2 =NULL;
    while(temp->next != start)
    {
        temp2 =temp;
        temp = temp->next;
    }
    if (!temp2)
    {
        deleteFirstNode(start);
        return;
    }
    temp2->next = start;
    delete temp;
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
    while (temp->next != start)
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
    cout << "Program for Circular Singly linked list"
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
