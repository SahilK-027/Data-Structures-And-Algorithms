//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  private:
    pair<int,int> solve(Node *root){
        if(root == NULL){
            pair<int, int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> leftSum = solve(root->left);
        pair<int,int> rightSum = solve(root->right);
        
        pair<int, int> ans;
        //ans.first will contain the maxsum including current node
        ans.first = root->data + leftSum.second + rightSum.second;
        //ans.second will contain the massum excluding current node
        ans.second = max(leftSum.first, leftSum.second) 
                    + max(rightSum.first , rightSum.second);
        return ans;
    }
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        //This pair will contain 
        // first -> the sum obtained by including current nodes data ,
        // second -> the sum obtained by excluding current nodes data
        pair<int,int> ans = solve(root);
        
        return max(ans.first, ans.second);
    }
};
