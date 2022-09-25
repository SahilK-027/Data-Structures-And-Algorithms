/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

void diagonalTravel(Node * root, map<int,vector<int>>& mp, int lvl = 0){
    if(root == NULL){
        return;
    }
    
    diagonalTravel(root->right,mp,lvl);
    diagonalTravel(root->left,mp,lvl+1);
    mp[lvl].push_back(root->data);
}
vector<int> diagonal(Node *root)
{
    map<int,vector<int>> mp;
    vector<vector<int>> ans;
    vector<int> res;
    diagonalTravel(root,mp);
    for(auto i:mp){
        ans.push_back(i.second);
    }
    for(int i = 0 ; i< ans.size() ; i++){
        for(int j = ans[i].size()-1 ; j>=0;j--){
            res.push_back(ans[i][j]);
        }
    }
    return res;
}




// Approach 2
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


vector<int> diagonal(Node *root)
{
   vector<int> ans;
   if(root == NULL){
       return ans;
   }
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()){
       Node* temp = q.front();
       q.pop();
       while(temp != NULL){
           if(temp->left){
               q.push(temp->left);
           }
           ans.push_back(temp->data);
           temp = temp->right;
       }
   }
   return ans;
}
