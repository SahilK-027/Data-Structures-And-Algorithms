#include <bits/stdc++.h>
using namespace std ;
class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode*right;
    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right =NULL;
    }
};


void inorder(TreeNode *root)
{
    if (root->data == -1)
    {
        return;
    }
    if(root->left)
    inorder(root->left);
    cout << root->data << " ";
    if(root->right)
    inorder(root->right);
}
TreeNode* insertIntoBST(TreeNode*& root,int data){
    // Base case
    if(root == NULL){
        root = new TreeNode(data);
        return root;
    }
    // Data greater than root
    if(data > root->data){
        root->right = insertIntoBST(root->right,data);
    }
    else{
        // Data smaller than root
        root->left = insertIntoBST(root->left,data);
    }
    return root;
}
void takeData(TreeNode*& root){
    int data;
    cin>>data;
    while(data != -1){
        insertIntoBST(root,data);
        cin>>data;
    }
}
int main()
{
    TreeNode* root = NULL;
    cout<<"Enter data to build BST: ";
    takeData(root);
    cout<<"TREE Inorder: ";
    inorder(root);
    return 0;
}