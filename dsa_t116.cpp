#include<iostream>
#include<vector>
#include<list>
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
    }

    bool isCycleHelper(int src, vector<bool> &vis, vector<bool> &recPath){
        vis[src] = true;
        recPath[src] = true;

        list<int> neigbours = l[src];

        for(int v : neigbours){
            if(!vis[v]){
                if(isCycleHelper(v, vis, recPath)){
                    return true;
                }
            }else if(recPath[v]){
                return true;
            }
        }
        recPath[src] = false;

        return false;
    }

    bool isCycle(){
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(isCycleHelper(i, vis, recPath)){
                    return true;
                }
            }
        }

        return false;
    }
};

int main(){
    Graph g(4);

    g.connect(0, 2);
    g.connect(1, 0);
    g.connect(2, 3);
    g.connect(3, 0);
    
    cout<<g.isCycle()<<endl;
    return 0;
}