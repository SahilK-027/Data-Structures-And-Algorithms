#include <bits/stdc++.h> 
void dfs(int i, vector<int>& visited, unordered_map<int, vector<int>>& adj_list, stack<int>& st){
    // Complete the dfs traversal
    visited[i] = true;
    for(auto node: adj_list[i]){
        if(!visited[node]){
            dfs(node, visited, adj_list, st);
        }
    }
    // Just before returning push the element on the stack
    st.push(i);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Create adjacency matrix
    unordered_map<int, vector<int>>adj_list;
    for(auto i: edges){
        adj_list[i[0]].push_back(i[1]);
    }
    // Get required extra memory.
    vector<int>visited(v, 0);    
    stack<int>st;
    for(int i = 0 ; i < v ; i++){
        if(!visited[i]){
            dfs(i, visited, adj_list, st);
        }
    }
    // Store answer int vector form stack
    vector<int>ans;
    while(!st.empty()){
        int temp = st.top();
        st.pop();
        ans.push_back(temp);
        
    }
    return ans;
}
