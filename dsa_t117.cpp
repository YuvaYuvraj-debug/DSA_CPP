#include<iostream>
#include<list>
#include<vector>
#include<stack>
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

    void dfs(int curr, vector<bool> &vis, stack<int> &s){ // TC = O(V+E)
        vis[curr] = true;

        list<int> neigbours = l[curr];

        for(int v : neigbours){
            if(!vis[v]){
                dfs(v, vis, s);
            }
        }

        s.push(curr);
    }

    void topoSort(){
        vector<bool> vis(V, false);
        stack<int> s;

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, s);
            }
        }

        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
};

int main(){
    Graph g(6);

    g.connect(2, 3);
    g.connect(3, 1);
    g.connect(4, 1);
    g.connect(4, 0);
    g.connect(5, 0);
    g.connect(5, 2);

    g.topoSort();
    return 0;
}