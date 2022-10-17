// APPROACH 1:
// USING INORDER TRAVERSAL
#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void inorder(TreeNode<int> *root, vector<int>& in){
    if(root == NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
vector<int> mergeTwoSortedArrays(vector<int> in1, vector<int> in2){
    vector<int> ans(in1.size()+in2.size());
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < in1.size() && j<in2.size()){
        if(in1[i] <= in2[j]){
            ans[k++] = in1[i++];
        }
        else if(in1[i] > in2[j]){
            ans[k++] = in2[j++];
        }
    }
    while(i < in1.size()){
        ans[k++] = in1[i++];
    }
    while(j < in2.size()){
        ans[k++] = in2[j++];
    }
    return ans;
}
TreeNode<int> * constructBst(vector<int>& in, int s, int e){
    if(s > e){
        return NULL;
    }
    int m = s + (e - s) / 2;
    TreeNode<int> * root = new TreeNode<int> (in[m]);
    root -> left = constructBst(in, s, m-1);
    root -> right = constructBst(in, m+1, e);    
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int> in1;
    vector<int> in2;
    inorder(root1, in1);
    inorder(root2, in2);
    
    vector<int> in3 = mergeTwoSortedArrays(in1,in2);
    
    int s = 0;
    int e = in3.size()-1;
    TreeNode<int> *ansRoot = constructBst(in3,s,e);
    return ansRoot;    
}
