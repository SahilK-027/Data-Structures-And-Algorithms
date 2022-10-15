class Solution {
private:
    TreeNode* solve(vector<int>& pre, int mini,int maxi, int& i){
        if(i >= pre.size()){
            return NULL;
        }
        if(pre[i]<mini || pre[i]>maxi){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[i++]);
        root->left = solve(pre,mini,root->val,i);
        root->right = solve(pre,root->val,maxi,i);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int i = 0;
        return solve(pre, mini, maxi,i);
    }
};
