#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
public:
    int V;
    list<int> *l;

    Graph(int V){
        this->V =  V;
        l = new list<int>[V];
    }

    void connect(int v, int u){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool isCycleHelper(int src, vector<bool>& vis, int par){
        vis[src] = true;
        list<int> neighbour = l[src];

        for(int v : neighbour){
            if(!vis[v]){
                if(isCycleHelper(v, vis, src)){
                    return true;
                }
            }else if(par != v){
                return true;
            }
        }

        return false;
    }

    bool isCycle(){
        vector<bool> vis(V, false);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(isCycleHelper(i, vis, -1)){
                    return true;
                }
            }
        }

        return false;
    }
};

int main(){
    Graph g(5);

    g.connect(0, 1);
    g.connect(0, 2);
    g.connect(0, 3);
    g.connect(1, 2);
    g.connect(3, 4);

    cout<<g.isCycle()<<endl;
    return 0;
}