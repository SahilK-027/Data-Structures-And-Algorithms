/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false

class Solution
{
    private:
    pair<bool , int> isSumTreeFast(Node* root){
        if(root == NULL){
            //  empty tree  
            pair<bool,int> p = make_pair(true, 0);
            return p;
        }
        if((root->left == NULL && root->right ==NULL)){
            // leaf node
            pair<bool,int> p = make_pair(true, root->data);
            return p;
        }
        // solve left and right subtree
        pair<bool, int> left = isSumTreeFast(root->left);
        pair<bool, int> right = isSumTreeFast(root->right);
        
        
        bool left_tree = left.first;
        bool right_tree = right.first;
        bool sum = left.second + right.second == root->data;
        
        pair<bool, int>ans;
        
        // Check for subtree
        if(left_tree, right_tree, sum){
            ans.first = true;
            ans.second = left.second + right.second+ root->data;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    public:
    bool isSumTree(Node* root)
    {
         pair<bool,int>ans;
         ans = isSumTreeFast(root);
         return ans.first;
    }
};
