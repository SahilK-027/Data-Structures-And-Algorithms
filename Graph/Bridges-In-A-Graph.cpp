#include <bits/stdc++.h>
void dfs(int node, int parent, int& timer,vector<int>& disc, vector<int>& low, vector<vector<int>>& result, vector<bool>& visited, unordered_map<int, list<int>>&adj_list){
    visited[node] = true;
    disc[node] = low[node] = timer++;
    for(auto neighbour: adj_list[node]){
        if(neighbour == parent){
            continue;
        }
        if(!visited[neighbour]){
            dfs(neighbour, node, timer, disc, low, result, visited, adj_list);
            low[node] = min(low[node], low[neighbour]);
            // Check iof bridge
            if(low[neighbour]> disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else{
            // Back edgs
            low[node] = min(low[node], disc[neighbour]);
        }

    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Adj_list
    unordered_map<int, list<int>>adj_list;
    for(auto i: edges){
        adj_list[i[0]].push_back(i[1]);
        adj_list[i[1]].push_back(i[0]);
    }
    int timer =0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    vector<bool> visited(v,false);
    vector<vector<int>> result;
    // DFS
    for(int i = 0 ; i < v; i++){
        if(!visited[i]){
            dfs(i, parent, timer, disc, low, result, visited, adj_list);
        }
    }
    return result;
}
