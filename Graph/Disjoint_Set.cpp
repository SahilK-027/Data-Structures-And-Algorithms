#include <bits/stdc++.h>
using namespace std ;
class disjoint_set_rank{
private:
    // Rank
    vector<int> rank;
    // Parent
    vector<int> parent;
public:
    disjoint_set_rank(int n){
        this->rank.resize(n+1, 0);
        this->parent.resize(n+1);
        for(int i = 0 ; i < this->parent.size(); i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(this->parent[node] == node){
            return node;
        }

        return this->parent[node] = findParent(this->parent[node]);
    }

    void unionByRank(int u, int v){
        int parent_u = this->findParent(u);
        int parent_v = this->findParent(v);
        if(parent_u == parent_v){
            return;
        }

        int rank_u = this->rank[parent_u];
        int rank_v = this->rank[parent_v];
        if(rank_u < rank_v){
            this->parent[parent_u] = parent_v;
        }
        else if(rank_u > rank_v){
            this->parent[parent_v] = parent_u;
        }
        else{
            this->parent[v] = parent_u;
            rank[parent_v]++;
        }
    }
};
int main()
{
    disjoint_set_rank g1(7);
    g1.unionByRank(1,2);
    g1.unionByRank(2,3);
    g1.unionByRank(4,5);
    g1.unionByRank(6,7);
    g1.unionByRank(5,6);
    if(g1.findParent(1) == g1.findParent(7)){
        cout<<"Same Compo"<<endl;
    }
    else{
        cout<<"Not Same Compo"<<endl;
    }

    g1.unionByRank(3,7);
    if(g1.findParent(1) == g1.findParent(7)){
        cout<<"Same Compo"<<endl;
    }
    else{
        cout<<"Not Same Compo"<<endl;
    }
    return 0;
}