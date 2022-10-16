/*
GO WITH THE LEVEL ORDER AND THEN RETURN THE FIRST VALUE IN LAST LEVEL
*/
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int val = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp != NULL){
                val = temp->val;
                // We want the leftmost root so we will push right first then left
                if(temp->right){
                    q.push(temp->right);
                }
                if(temp->left){
                    q.push(temp->left);
                }
            }
            else{
                // One level is complete
                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
        return val;
    }
};
