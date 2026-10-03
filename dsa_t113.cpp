#include<iostream>
#include<vector>
#include<list>
#include<queue>
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

    bool isCycleHelper(int src, vector<bool> &vis){
        queue<pair<int, int>> q; // store the source vertex ans parent(here it is previous) vertex

        q.push({src, -1});

        vis[src] = true;

        while(!q.empty()){
            int source = q.front().first;
            int par = q.front().second;
            q.pop();

            for(int v : l[source]){
                if(!vis[v]){
                    vis[v] = true;
                    q.push({v, source});
                }else if(par != v){
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(){
        vector<bool> vis(V, false);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(isCycleHelper(i, vis)){
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