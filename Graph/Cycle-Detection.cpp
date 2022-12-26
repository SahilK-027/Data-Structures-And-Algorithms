#include<bits/stdc++.h>
bool isCyclicBFS(int i, unordered_map<int, set<int>>&adj_lst, unordered_map<int, bool>& visited, unordered_map<int, int>& nodeToParent){
    queue<int>q;
    q.push(i);
    nodeToParent[i] = -1;
    visited[i] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i: adj_lst[node]){
            if(visited[i] == true && nodeToParent[node] != i){
                return true;
            }
            else if(!visited[i]){
                visited[i] = true;
                nodeToParent[i] = node;
                q.push(i);
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Create Adjacency list
    unordered_map<int, set<int>>adj_lst;
    for(int i = 0 ; i < edges.size(); i++){
        adj_lst[edges[i][0]].emplace(edges[i][1]);
        adj_lst[edges[i][1]].emplace(edges[i][0]);
    }
    
    // BFS
    unordered_map<int, bool>visited;
    unordered_map<int, int>nodeToParent;
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            if(isCyclicBFS(i, adj_lst, visited, nodeToParent)){
                 return "Cycle Present";
            }
        }
    }
    return "Cycle Not Present";
}
