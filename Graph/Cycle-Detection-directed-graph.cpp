#include<bits/stdc++.h>
bool DFScycle(int i, unordered_map<int, vector<int>>& adj_list, vector<bool>& visi, vector<bool>&dfs_visi){
    visi[i] = true;
    dfs_visi[i] = true;
    for(auto node : adj_list[i]){
        if(!visi[node]){
           bool cycleDetected = DFScycle(node, adj_list, visi, dfs_visi);
            if(cycleDetected) return true;
        }
        else{
            if(dfs_visi[node] == true){
                return true;
            }
        }
    }
    dfs_visi[i] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    // Craeting Adj list
    unordered_map<int, vector<int>>adj_list;
    for(auto i: edges){
        adj_list[i.first].push_back(i.second);
    }
    // DFS CALLS
    vector<bool>visi(n, false);
    vector<bool>dfs_visi(n, false);
    for(int i = 1 ; i < n ; i++){
        if(!visi[i]){
            if(DFScycle(i, adj_list, visi, dfs_visi)){
                return true;
            }
        }
    }
    return false;
}
