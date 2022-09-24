#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void createTree(Node *&root)
{
    cout << "Enter data : ";
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return;
    }
    cout << endl
         << "Insert in left of " << data << endl;
    createTree(root->left);
    cout << endl
         << "Insert in right of " << data << endl;
    createTree(root->right);
}
void preorder(Node *root)
{
    if (root->data == -1)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    if (root->data == -1)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(Node *root)
{
    if (root->data == -1)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void leveOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // 1 level has completely traversed
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left->data != -1)
            {
                q.push(temp->left);
            }
            if (temp->right->data != -1)
            {
                q.push(temp->right);
            }
        }
    }
}
void buildFromLevelOrder(Node* &root)
{
    queue<Node *> q;
    cout<<endl<<"Enter data for root ";
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        
        cout<<endl<<"Enter left node for "<<temp->data;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        cout<<endl<<"Enter right node for "<<temp->data;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1){
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}
int main()
{
    //Tree data : 1 3 7 -1 -1 9 -1 -1 5 11 -1 -1 -1
    Node *root = NULL;
    createTree(root);
    cout << endl << "Tree created succesfully" << endl;

    cout<<endl;
    cout << "PREORDER: ";
    preorder(root);
    cout << endl;

    cout<<endl;
    cout << "INORDER: ";
    inorder(root);
    cout << endl;

    cout<<endl;
    cout << "POSTORDER: ";
    postorder(root);
    cout << endl;

    cout<<endl;
    cout << "LEVELORDER: "<<endl;
    leveOrderTraversal(root);
    cout << endl;
    return 0;
}
