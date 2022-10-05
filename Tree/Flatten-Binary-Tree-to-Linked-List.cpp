//APPROACH 1: BRUTE FORCE
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// CREATING AN SEPARATE ARRAY OF PREORDER AND THEN CREATING LL
// TC: O(N)
// SC : O(N)
class Solution {
void preorder(TreeNode* root,vector<TreeNode*>& ans){
        // Base case
        if(root == NULL){
            return;
        }
        // Preorder Traversal = ROOT - LEFT - RIGHT
        ans.push_back(root);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> ans;
        preorder(root,ans);
        TreeNode*temp = root;
        for(int i = 1 ; i<ans.size() ;i++){
            temp->right = ans[i];
            temp->left = NULL;
            temp = temp->right;
        }
    }
};




//APPROACH 2: RECURSIVE APPROACH
// TC : O(N)
// SC : O(height)

class Solution {
TreeNode* solve(TreeNode* root){
    // Base Case
    if(root == NULL){
        return NULL;
    }
    
    
    // RECURSION WILL SOLVE LEFT SUBTREE AND WILL CREATE LL OUT OF IT
    TreeNode* leftLL = solve(root->left);
    // RECURSION WILL SOLVE RIGHT SUBTREE AND WILL CREATE LL OUT OF IT
    TreeNode* rightLL = solve(root->right);
    
    
    // OURJOB
    // Make root left NULL
    root->left = NULL;
    // If left linked list exists
    if(leftLL){
        // attach it to root->right
        root->right = leftLL;
        // Find last node in left LL
        TreeNode* temp = leftLL;
        while(temp->right){
             temp = temp->right;
        }
        // Attach right Linked list to last node in leftLL
        temp->right = rightLL;
    }
    
    else{
        // Means left linked list doesn't exists so attach root->right to rightLL
        root->right = rightLL;
    }
    return root;
}
public:
    void flatten(TreeNode* root) {
        root = solve(root);
    }
};




// Approach 3: Using morris traversal
// TC : O(N)
// SC : O(1)
class Solution {
private:
    TreeNode* findPredecessor(TreeNode* curr){
        TreeNode* predecessor = curr->left;
        while(predecessor->right != NULL){
            predecessor = predecessor->right;
        }
        return predecessor;
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left != NULL){
                // left part exists
                TreeNode* predecessor = findPredecessor(curr);
                // Make link of predecessor with right part of tree
                predecessor->right = curr->right;    
                // Attach root->right to left
                curr->right = curr->left;
                // Make root left NULL
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
