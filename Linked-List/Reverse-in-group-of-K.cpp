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

int getlength(Node *next)
{
    int length = 0;
    Node *temp = next;
    while (temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

Node *reverseKGroup(Node *head, int k)
{
    // 1. Base case
    if (head == NULL || k == 1)
    {
        return head;
    }

    // 2. We will reverse first k nodes
    int cnt = 0;
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while (curr != NULL && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    // 3. First we will find length of remaining list and if length of remaining list is greater than or equal to k then only we will reverse further part
    int length = getlength(next);

    // 4. We will ask recursion to reverse next k nodes and return new head
    Node *newHead = next;
    if (next != NULL && length >= k)
    {
        newHead = reverseKGroup(next, k);
    }

    // 5. Attach newhead to linked list which we have reversed
    head->next = newHead;

    // 6. Return prev
    return prev;
}

int main()
{
    Node *start = NULL;
    insertAtStart(start, 6);
    insertAtStart(start, 5);
    insertAtStart(start, 4);
    insertAtStart(start, 3);
    insertAtStart(start, 2);
    insertAtStart(start, 1);
    displayList(start);
    int k = 3;
    Node* newlist = reverseKGroup(start, k);
    displayList(newlist);
    return 0;
}
