#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Initially the distance will be infinity
    int infinity = int(1e9);
    // Vector to store the distance
    vector<int> distance(n+1, infinity);
    // let distance of source be 0.
    distance[src] = 0;

    // N-1 checks
    for(int i = 1; i <= n; i++){
        // Traverse all nodes
        for(int j = 0 ; j < m ; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(distance[u] != int(1e9) 
            && 
                distance[u] + wt < distance[v]
                ){
                    distance[v] = distance[u] + wt;
            }
        }
    }
    // Final check for negative cycle
    bool flag = false;
    // Traverse all nodes
    for(int j = 0 ; j < m ; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(distance[u] != int(1e9) 
            && 
            distance[u] + wt < distance[v]
        ){
                flag = true; 
        }
    }
    if(!flag){
        return distance[dest];
    }
    else{
        return -1;
    }
}
