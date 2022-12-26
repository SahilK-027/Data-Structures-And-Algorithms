// Recursion
void DFS(int node, unordered_map<int, set<int>> & adj_list, unordered_map<int, bool>& visited, vector<int>& DFS_V){
    DFS_V.push_back(node);
    visited[node]= true;
    
    // Call for all connected node
    for(auto i: adj_list[node]){
        if(!visited[i]){
            DFS(i, adj_list, visited, DFS_V);
        }
    }
}

vector<vector<int>> depthFirstSearch(int v, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    // Step 1: Create adj list (Want answer in ascending order)
    unordered_map<int, set<int>> adj_list;
    for(int i = 0 ; i < edges.size(); i++){
        int u = edges[i][0];        
        int v = edges[i][1];
        adj_list[u].insert(v);        
        adj_list[v].insert(u);
    }
    
    unordered_map<int, bool> visited;
    for(int i = 0 ; i < v; i++){
        if(!visited[i]){
            vector<int> DFS_V;
            DFS(i,adj_list,visited, DFS_V);
            ans.push_back(DFS_V);
        }
    }
    return ans;
}
