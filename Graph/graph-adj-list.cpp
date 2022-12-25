#include <bits/stdc++.h>
#include<map>
using namespace std ;

class graph{
public:
    map<int, vector<int> > adj_list;
    void add_edge(int u, int v, bool isDirected){
        // Create edge
        adj_list[u].push_back(v);
        if(!isDirected){
            adj_list[v].push_back(u);
        }
    }

    void print_graph(){
        for(auto i: adj_list){
            cout<<i.first<<"-> ";
            for(auto j: i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    graph g;
    g.add_edge(0,1,0);
    g.add_edge(0,3,0);
    g.add_edge(1,3,0);
    g.add_edge(1,2,0);
    g.add_edge(2,3,0);
    g.add_edge(2,4,0);
    g.add_edge(3,4,0);
    g.print_graph();
    return 0;
}
