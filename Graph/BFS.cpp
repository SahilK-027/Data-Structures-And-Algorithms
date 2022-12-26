#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    // Step 1: Create adj list (Want answer in ascending order)
    unordered_map<int, set<int>> adj_list;
    for(auto i: edges){
        adj_list[i.first].insert(i.second);
        adj_list[i.second].insert(i.first);
    }
    
    // Step 2: Create BFS traversal vector
    vector<int> BFS_V;
    unordered_map<int, bool> visited;
    for(int i = 0 ; i < vertex; i++){
        if(!visited[i]){
           queue<int> q;
           q.push(i);
           visited[i] = true;
           while(!q.empty())
           {
                int node = q.front();
                q.pop();
                BFS_V.push_back(node);
                for(auto i: adj_list[node])
                {
                    if(!visited[i])
                    {
                         q.push(i);  
                        visited[i] = true;
                    }
                }
            }
        } 
    }
    return BFS_V;
}
