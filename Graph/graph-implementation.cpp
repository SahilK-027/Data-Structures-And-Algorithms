#include <bits/stdc++.h>
using namespace std;
class Graph
{
private:
    int V_no;
    int **Adj_mtrx;
    int E_no;

public:
    Graph(int V_no, int E_no)
    {
        this->V_no = V_no;
        this->E_no = E_no;
        this->Adj_mtrx = new int *[V_no];
        for (int i = 0; i < V_no; i++)
        {
            this->Adj_mtrx[i] = new int[V_no];
        }
        for (int i = 0; i < V_no; i++)
        {
            for (int j = 0; j < V_no; j++)
            {
                this->Adj_mtrx[i][j] = 0;
            }
        }
    }
    void insert(Graph *G)
    {
        cout << "\nYou are going to Create New Graph\n";

        int v_i, v_j, wt;
        for (int i = 0; i < G->E_no; i++)
        {
            cout << "\nEnter the number of vertices which has an edge: ";
            cin >> v_i >> v_j;
            cout << "Enter the weight of edge: ";
            cin >> wt;
            int x = v_i - 1;
            int y = v_j - 1;
            G->Adj_mtrx[x][y] = wt;
            G->Adj_mtrx[y][x] = wt;
        }
        cout << "\nYour Graph Has Been Created You Can Display Adjacency Matrix\n";
    }
    void display(Graph *G)
    {
        cout << "\nAdjacecy Matrix:=>";
        cout << "\n";
        for (int i = 0; i < G->V_no; i++)
        {
            for (int j = 0; j < G->V_no; j++)
            {
                if (Adj_mtrx[i][j] == 0)
                {
                    cout << G->Adj_mtrx[i][j] << "   ";
                }
                else
                {
                    cout << G->Adj_mtrx[i][j] << "  ";
                }
            }
            cout << "\n";
        }
    }
    void BFS(Graph *G)
    {
        int i,j;
        queue<int> q;
        int vno;
        int *status;
        cout<<"BFS Traversal: ";
        status = new int[G->V_no];
        for(int i = 0 ; i< G->V_no;i++){
            status[i] = 1;
        }
        q.push(1); // Stating node in graph
        status[0] = 2; // Updated status of first node
        while(!q.empty()){
            vno = q.front();
            q.pop();
            cout<<vno<<" ";
            status[vno-1]=3;
            for(int j = 0 ; j<G->V_no ; j++){
                if(G->Adj_mtrx[vno-1][j] != 0 && status[j] == 1){
                    q.push(j+1);
                    status[j] =2;
                }
            }
        }
    }
};


int main()
{
    Graph *G = new Graph(5, 8);
    G->insert(G);
    G->display(G);
    G->BFS(G);
    return 0;
}
