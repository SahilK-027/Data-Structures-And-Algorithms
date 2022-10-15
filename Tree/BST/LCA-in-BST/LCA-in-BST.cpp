// TC O(N)
// Iterative
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        while(root!=NULL)
        {
            if(root->val < a->val && root->val < b->val){
                root = root->right;
            }
            else if(root->val > a->val && root->val > b->val){
               root = root->left;
            }
            else{
                // If root found break and come out
                break;
            }
        }
        return root;
    }
};



// Recursive
class Solution {
private:
    TreeNode* solve (TreeNode* root, TreeNode* a, TreeNode* b){
        if(root == NULL){
            return NULL;
        }
        if(root->val < a->val && root->val < b->val){
            return solve(root->right, a,b);
        }
        if(root->val > a->val && root->val > b->val){
            return solve(root->left, a,b);
        }
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};
