#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
class info{
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};
info solve(TreeNode<int>* root, int &maxSize){
    // BASE CASE
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }
    // GO IN 
    info leftAns = solve(root->left, maxSize);
    info rightAns = solve(root->right, maxSize);
    
    // Processing
    info currNode;
    // Find size and add 1 for root
    currNode.size = leftAns.size + rightAns.size + 1;
    currNode.maxi = max(root->data, rightAns.maxi);
    currNode.mini = min(root->data, leftAns.mini);
    if(leftAns.isBST && 
       rightAns.isBST &&
       root->data > leftAns.maxi &&
       root->data < rightAns.mini
      ){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }
    if(currNode.isBST){
        maxSize = max(maxSize, currNode.size);
    }
    return currNode;
}
int largestBST(TreeNode<int>* root) 
{
    int maxSize = 0;
    solve(root, maxSize);
    return maxSize;
}
