# Tree Traversals

![alt](https://cs-people.bu.edu/tvashwin/cs112_spring09/lab06_files/tree_example.png)

**1. Inorder Traversal**

Algorithm Inorder(root):

* Step 1: Traverse the left subtree, i.e., call Inorder(left->subtree)
* Step 2: Visit the root.
* Step 3: Traverse the right subtree, i.e., call Inorder(right->subtree)
```cpp
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


class Solution {
private: 
    vector<int> solve(TreeNode* root , vector<int> &ans){
        if(root == NULL){
            return ans;
        }
        /*Inorder-> left - root - ans*/
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
        return ans;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        return solve(root, ans);
    }
};
```

**2. Preorder Traversal**

* Step 1: Visit the root.
* Step 2: Traverse the left subtree, i.e., call Preorder(left->subtree)
* Step 3: Traverse the right subtree, i.e., call Inorder(right->subtree)
```cpp
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
class Solution {
private:
    void solve(TreeNode* root,vector<int>& ans){
        // Base case
        if(root == NULL){
            return;
        }
        // Preorder Traversal = ROOT - LEFT - RIGHT
        ans.push_back(root->val);
        solve(root->left,ans);
        solve(root->right,ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};
```

**3. Postorder Traversal**

* Step 1: Traverse the left subtree, i.e., call Preorder(left->subtree)
* Step 2: Traverse the right subtree, i.e., call Inorder(right->subtree)
* Step 3: Visit the root.
```cpp
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
class Solution {
private:
    void solve(TreeNode* root,vector<int>& ans){
        // Base case
        if(root == NULL){
            return;
        }
        // Preorder Traversal = LEFT - RIGHT - ROOT
        solve(root->left,ans);
        solve(root->right,ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};
```

**4. Level order traversal**

The algorithm is just like BFS. The algorithm works in this way - Before moving on to the nodes at the next depth level, algorithm begins at the root of the tree and explores every node there. To keep track of the child nodes that were discovered but haven't been fully explored, additional memory, typically a queue, is required.
```cpp
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL ){
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp != NULL)
            {
                v.push_back(temp->val);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            else
            {
                // 1 level has completely traversed
                ans.push_back(v);
                v.clear();
                if (!q.empty())
                {
                    // Queue still has elements in next level
                    q.push(NULL);
                }
            }
        }
        return ans;
    }
};
```
