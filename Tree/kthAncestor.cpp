//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
Node* solve(Node *root, int& k, int node){
    //Base case
    if(root == NULL){
        return root;
    }
    
    // If root data and node value are equal
    if(root->data == node){
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);
    
    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k<=0){
            //lock the answer
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k<=0){
            //lock the answer
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k,node);
    if(ans == NULL || ans->data == node){
        return -1;
    }
    else{
        return ans->data;
    }
}
