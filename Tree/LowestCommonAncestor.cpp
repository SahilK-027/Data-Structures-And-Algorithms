class Solution {
private:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
		// Empty tree
        if(root == NULL){
            return root;
        }
		
		// Common Ansestor foiund
        if(root == p || root == q){
            return root;
        }
		
		// Solve recursively left and right subtree
        TreeNode* leftTreeAns = solve(root->left, p,q);
        TreeNode* rightTreeAns = solve(root->right, p,q);
        
		// If both answers are NULL means NO solution
        if(leftTreeAns == NULL && rightTreeAns == NULL){
            return NULL;
        }
		
		// if one of the ans is found then return that answer
        else if(leftTreeAns != NULL && rightTreeAns == NULL){
            return leftTreeAns;
        }
        else if(leftTreeAns == NULL && rightTreeAns != NULL){
            return rightTreeAns;
        }
		
		// Both answers are found at left and right of particular root so return that root as answer
        else{
            return root;
        }    
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        TreeNode* ans = solve(root, p, q);
        return ans;
    }
};
