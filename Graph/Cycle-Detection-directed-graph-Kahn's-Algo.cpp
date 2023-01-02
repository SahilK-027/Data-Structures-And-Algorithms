#include<unordered_map>
#include<list>
#include<queue>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Create adjacency list
    unordered_map<int, list<int>>adj_list;
    for(auto i: edges){
        adj_list[i.first - 1].push_back(i.second - 1);
    }
    
    // Step 1: Find indegree of all nodes
    vector<int>indegree(n);
    for(auto i: adj_list){
        for(auto j: i.second){
            indegree[j]++;
        }
    }
    // Step 2: Push element with 0 ingree in queue
    queue<int>q;
    for(int i = 0; i < indegree.size() ;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    // Step 3: Do BFS
    vector<int>ans;
    while(!q.empty()){
        // Remove and store front
        int front = q.front();
        q.pop();
        ans.push_back(front);
        // Find all neightbours of front
        for(auto neighbour: adj_list[front]){
            // As front have been removed update their indegree
            indegree[neighbour] -= 1;
            // Push the neighbours with indegree 0 in queue
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    if(ans.size() == n){
        return 0;
    }
    return 1;
}
