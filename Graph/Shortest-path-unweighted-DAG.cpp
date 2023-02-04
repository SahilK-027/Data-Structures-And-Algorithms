#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int> > > adj_list;
    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj_list[u].push_back(p);
    }
    void printList()
    {
        for (auto i : adj_list)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "[" << j.first << "," << j.second << "], ";
            }
            cout << endl;
        }
    }
    void DFS(int i, vector<bool> &visited, stack<int> &st, unordered_map<int, list<pair<int, int> > > &adj_list)
    {
        visited[i] = true;
        for (auto node : adj_list[i])
        {
            if (!visited[node.first])
            {
                DFS(node.first, visited, st, adj_list);
            }
        }
        st.push(i);
    }

    void topological_sort(int no_nodes, vector<bool> &visited, stack<int> &st)
    {
        for (int i = 0; i < no_nodes; i++)
        {
            if (!visited[i])
            {
                DFS(i, visited, st, adj_list);
            }
        }
    }

    void getShortestPath(int src, vector<int> &dist, stack<int> &st)
    {
        while (!st.empty())
        {
            int top = st.top();
            st.pop();

            if (dist[top] != INT_MAX)
            {
                for (auto neighbour : adj_list[top])
                {
                    if (dist[top] + neighbour.second < dist[neighbour.first])
                    {
                        dist[neighbour.first] = dist[top] + neighbour.second;
                    }
                }
            }
        }
    }
};
int main()
{
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    // g.printList();
    int no_nodes = 6;
    vector<bool> visited(no_nodes, false);
    stack<int> st;
    g.topological_sort(no_nodes, visited, st);

    int src = 1;
    vector<int> dist(no_nodes, INT_MAX);
    dist[src] = 0;
    g.getShortestPath(src, dist, st);

    for (auto i : dist)
    {
        cout << i << " ";
    }
    return 0;
}
