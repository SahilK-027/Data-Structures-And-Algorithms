/*
struct Node{
  int data;
  Node* left, right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        map<int, int> mp;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int horizontal_distance = temp.second;
            
            if(mp.find(horizontal_distance) == mp.end()){
                mp[horizontal_distance] = frontNode->data;
            }
            if(frontNode -> left){
                q.push(make_pair(frontNode -> left,horizontal_distance-1));
            }
            if(frontNode -> right){
                q.push(make_pair(frontNode -> right,horizontal_distance+1));
            }
        }
        
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
