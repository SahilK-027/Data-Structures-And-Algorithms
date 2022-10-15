// APPROACH 1: INORDER TRAVERSAL FOPR BST IS SORTED
class Solution {
private:
    void inorder(TreeNode* root,vector<int>& v){
        if(root == NULL){
            return ;
        }
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right ,v);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        if(v.size() == 1){
            return true;
        }
        int prev = 0;
        for(int curr = 1; curr<v.size();curr++){
            if(v[curr] <= v[prev]){
                return false;
            }
            prev++;
        }
        return true;
    }
};

// APPROACH 2: 
/*
As we know in BST each node value in left part is less than root->val and in right part is greater than root->val
So, we can calculate range for each node and then we'll check if the node is in range or not
if(inrange) => return true;
else        => return false;


Range for root = (-∞, +∞)
Range for left of root = (-∞ , root->val);
Range for right of root = (root->val , +∞)
*/
class Solution {
private:
    bool solve(TreeNode* root , int n_infinity, int p_infinity){
        if(root == NULL){
            return true;
        }
        
        if(n_infinity < root->val && root->val < p_infinity){
            bool leftAns = solve(root->left , n_infinity , root->val);
            bool rightAns = solve(root->right , root->val , p_infinity);
            return leftAns && rightAns;
        }
        else{
            return false;
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root, INT_MIN, INT_MAX);
    }
};
