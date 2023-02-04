#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Creat Adj_list
    unordered_map<int, list<pair<int, int>>>adj_list;
    for(int i = 0 ; i < g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int weight = g[i].second;
        adj_list[u].push_back(make_pair(v,weight));
        adj_list[v].push_back(make_pair(u,weight));
    }

    // Create required data structures
    vector<int>dist(n+1, INT_MAX);
    dist[1] = 0;
    vector<bool>visited(n+1,false);
    vector<int> parent(n+1, -1);

    // Algo
    for(int i = 1 ; i <= n; i++){
        int mini = INT_MAX;
        int u;
        // Step 1:  Find min distance node
        for(int node = 1 ; node <= n; node++){
            if(!visited[node] && dist[node] < mini){
                mini = dist[node];
                u = node;
            }
        }
        // step 2: Mark that node as visited
        visited[u] = true;
        // Step 3: Check its neighbours
        for(auto adj: adj_list[u]){
            int v = adj.first;
            int wt = adj.second;
            if(!visited[v] && wt < dist[v]){
                parent[v] = u;
                dist[v] = wt;
            }
        }
    }

    vector<pair<pair<int, int>, int>>ans;
    for(int i = 2; i <= n ;i++){
        ans.push_back(make_pair(make_pair(parent[i], i), dist[i]));
    }
    return ans;
}
