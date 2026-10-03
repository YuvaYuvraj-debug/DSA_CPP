#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
public:
    int V;
    list<int> *l;

    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void connect(int v, int u){
        l[v].push_back(u);
        l[u].push_back(v);
    }

    void DFSHelper(int u, vector<bool> &vis){
        cout<< u << " ";
        vis[u] = true;

        for(int v : l[u]){
            if(!vis[v]){
                DFSHelper(v, vis);
            }
        }
    }

    void dfs(){
        int src = 0;
        vector<bool> vis(V, false);

        /*
        // for disconnected graph

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                DFSHelper(src, vis);
            }
        }
            
        */
        
        DFSHelper(src, vis);
    }
};

int main(){
    Graph g(5);

    g.connect(0,1);
    g.connect(1,2);
    g.connect(1,3);
    g.connect(2,4);

    g.dfs();
    return 0;
}