#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

// Graph BFS traversal:
// Travel to immidiale neighbors first
class Graph{
public:
    int V;
    list<int> *l;

    Graph(int V){
        this->V = V;
        l = new list<int>[V]; // arr = new int[size];
    }

    void addEdge(int v, int u){
        l[v].push_back(u);
        l[u].push_back(v);
    }

    //BFS Traversal
    void bfs(){ // TC = O(V+E), vertices plus edges
        queue<int> Q;
        vector<bool> vis(V, false);

        Q.push(0);
        vis[0] = true;

        while(Q.size() > 0){
            int u = Q.front();
            Q.pop();

            cout<<u<<" ";

            for(int v : l[u]){
                if(!vis[v]){
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }

        cout<<endl;
    }
};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.bfs();
    return 0;
}