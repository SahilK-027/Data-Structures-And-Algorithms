#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int src) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // Create adj_list
    unordered_map<int, list<pair<int, int>>> adj_list;
    for(auto i: vec){
        adj_list[i[0]].push_back(make_pair(i[1], i[2]));        
        adj_list[i[1]].push_back(make_pair(i[0], i[2]));
    }
    // Create distance array
    vector<int> dist(vertices, INT_MAX);
    dist[src] = 0;
    // Create set to store distance , node
    set<pair<int, int>>st;
    st.emplace(make_pair(0, src));
    // Algorith
    while(!st.empty()){
        // Remove top from set
        auto top = *(st.begin());
        int distance = top.first;        
        int node = top.second;
        // Reomove top from set
        st.erase(st.begin());
        // Traverse neighbours of top node
        for(auto neighbour: adj_list[node]){
            if(distance + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));
                // If record found update it
                if(record != st.end()){
                    st.erase(record);
                }
                dist[neighbour.first] = distance + neighbour.second;
                st.emplace(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}
