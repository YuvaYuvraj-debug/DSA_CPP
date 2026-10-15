#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<climits>
using namespace std;

class Edge {
public:
    int V;
    int wt;

    Edge(int V, int wt) {
        this->V = V;
        this->wt = wt;
    } 
};

void dijkstra(int src, vector<vector<Edge>>& g, int V) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // priority_queue<int> pq; // max-heap
    // priority_queue<int, vector<int>, greater<int>> pq; // min-heap

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // <dist[u], u>
    pq.push({0, src});

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for(const Edge& e : g[u]){ // Edge relaxation step
            if(dist[e.V] > dist[u] + e.wt) {
                dist[e.V] = dist[u] + e.wt;
                pq.push({dist[e.V], e.V});
            }
        }
    }

    for(int i = 0; i < V; i++) {
        cout << dist[i] << " ";
    }

}

int main() {
    int V = 6;
    vector<vector<Edge>> g(V);

    // adjacency list:
    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(2, 1));
    g[1].push_back(Edge(3, 7));

    g[2].push_back(Edge(4, 3));

    g[3].push_back(Edge(5, 1));

    g[4].push_back(Edge(3, 2));
    g[4].push_back(Edge(5, 5));
    
    dijkstra(0, g, V);

    return 0;
}