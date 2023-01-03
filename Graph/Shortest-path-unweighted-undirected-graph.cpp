#include<unordered_map>
#include<list>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	// Create adjacency list
    unordered_map<int, list<int>>adj_list;
    for(auto i: edges){
        adj_list[i.first].push_back(i.second);
        adj_list[i.second].push_back(i.first);
    }
    // Bfs traversal
    // Keep track of parent
    vector<int>parent(n+1, -1);
    unordered_map<int, bool> visited;
    queue<int>q;
    q.push(s);
    visited[s] = true;
    // BFS logic
    while(!q.empty()){
        int par = q.front();
        visited[par] = true;
        q.pop();
        for(auto i: adj_list[par]){
            if(!visited[i]){
                parent[i] = par;
                visited[i] = true;
                q.push(i);
            }
        }
    }
    // Create answer
    vector<int> ans; 
    // As parent of source is -1
    while(t != -1){
        ans.push_back(t);
        t = parent[t];
    }
    // We are traveling from destination to source
    reverse(ans.begin(), ans.end());
	return ans;
}
