#include <bits/stdc++.h>
using namespace std ;
class disjoint_set_size{
private:
    // size
    vector<int> size;
    // Parent
    vector<int> parent;
public:
    disjoint_set_size(int n){
        this->size.resize(n+1, 0);
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

    void unionBySize(int u, int v){
        int parent_u = this->findParent(u);
        int parent_v = this->findParent(v);
        if(parent_u == parent_v){
            return;
        }

        int size_u = this->size[parent_u];
        int size_v = this->size[parent_v];
        if(size_u < size_v){
            this->parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
        else{
            this->parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }
};
int main()
{
    disjoint_set_size g1(7);
    g1.unionBySize(1,2);
    g1.unionBySize(2,3);
    g1.unionBySize(4,5);
    g1.unionBySize(6,7);
    g1.unionBySize(5,6);
    if(g1.findParent(1) == g1.findParent(7)){
        cout<<"Same Compo"<<endl;
    }
    else{
        cout<<"Not Same Compo"<<endl;
    }

    g1.unionBySize(3,7);
    if(g1.findParent(1) == g1.findParent(7)){
        cout<<"Same Compo"<<endl;
    }
    else{
        cout<<"Not Same Compo"<<endl;
    }
    return 0;
}