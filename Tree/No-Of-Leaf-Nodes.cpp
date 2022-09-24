/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/
void solve(BinaryTreeNode<int> *root, int& cnt){
    if(root == NULL){
        return;
    }
    // Check for leaf node
    if(root->left == NULL && root->right == NULL){
        cnt++;
    }
    // Otherwise send left and right subtree to recursion and recursion will give ans
    solve(root->left,cnt);
    solve(root->right,cnt);
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int cnt = 0;
    solve(root,cnt);
    return cnt;
}
