
/*
Structure of linked list is as
struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/
// function should insert the data to the front of the list
struct Node *insert(struct Node *head, int data) {
    Node* node = new Node(data);
    if(head == NULL){
        head = node;
        return head;
    }
    node->npx = head;
    head->npx = XOR(head->npx, node);
    head = node;
    return head;
}

vector<int> printList(struct Node *head) {
    vector<int> ans;
    Node* curr = head;
    Node* prev = NULL;
    while(curr){
        ans.push_back(curr->data);
        Node* next = XOR(prev,curr->npx);
        prev = curr;
        curr = next;
    }
    return ans;
}
