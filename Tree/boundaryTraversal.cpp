#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void traverseLeft(TreeNode<int>* root,vector<int>& ans){
    // Empty tree
    if(root == NULL){
        return;
    }
    // Leaf node
    if(root->left == NULL && root->right == NULL){
        return;
    }
    // First store ans
    ans.push_back(root->data);
    
    //Recursive call
    if(root->left){
        traverseLeft(root->left,ans);
    }
    else{
        traverseLeft(root->right,ans);
    }
}
void traverseLeaf(TreeNode<int>* root,vector<int>& ans){
    // Empty tree
    if(root == NULL){
        return;
    }
    // Leaf node
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}
void traverseRight(TreeNode<int>* root,vector<int>& ans){
    // Empty tree
    if(root == NULL){
        return;
    }
    // Leaf node
    if(root->left == NULL && root->right == NULL){
        return;
    }
    // First go down
    if(root->right){
        traverseRight(root->right,ans);
    }
    else{
        traverseLeft(root->left,ans);
    }
    
    // while coming back store ans
    ans.push_back(root->data);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    // First store root data
    ans.push_back(root->data);
    
    // Traverse left part 
    traverseLeft(root->left,ans);
    
    // Traverse leaf nodes
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
    
    // Traverse right part
    traverseRight(root->right,ans);
    
    return ans;
}
