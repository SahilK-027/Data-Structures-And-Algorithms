#include <bits/stdc++.h>
bool comparator(vector<int>& a, vector<int>& b){
  return a[2] < b[2];
}

void makeSet(vector<int>& par, vector<int>& rank, int n){
  for(int i = 0 ; i < n ; i++){
    par[i] = i;
  }
}
int findParent(vector<int>& par, int node){
  // Reached final parent in the hierarchy
  if(par[node] == node){
    return node;
  }
  // Find parent and path compression
  par[node] = findParent(par, par[node]);
  return par[node];
}
void unionSet(int u, int v, vector<int>& par, vector<int>& rank){
  u = findParent(par, u);
  v = findParent(par, v);

  if(rank[u] < rank[v]){
    par[u] = v;
  }
  else if(rank[u] > rank[v]){
    par[v] = u;
  }
  else{
    par[v] = u;
    rank[u]++;
  }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  sort(edges.begin(), edges.end(), comparator);
  vector<int> parent(n);
  vector<int> rank(n, 0);
  makeSet(parent, rank, n);

  int ans = 0;
  for(int i = 0 ; i< edges.size(); i++){
    int u = findParent(parent, edges[i][0]);
    int v = findParent(parent, edges[i][1]);
    int wt = edges[i][2];
    if(u != v){
      ans += wt;
      unionSet(u, v, parent, rank);
    }
  }
  return ans;
}
