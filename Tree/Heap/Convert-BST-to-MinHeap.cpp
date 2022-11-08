#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
void inorder(BinaryTreeNode* root,vector<int>& arr ){
    if(root == NULL){
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
void buildTree(BinaryTreeNode*& root, vector<int>& arr, int& s)
{
    if(root == NULL){
        return;
    }
    root->data = arr[s++];
    buildTree(root->left, arr, s);
    buildTree(root->right, arr, s);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
    // Store BST TO inorder
	vector<int> arr;
    inorder(root, arr);
    int s = 0;
    // Build tree from inorder
    buildTree(root, arr, s);
    return root;
}
