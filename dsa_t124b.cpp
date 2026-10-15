#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int primMST(int v, vector<vector<pair<int, int>>> adj){
    vector<bool> inMST(v, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    int MSTCost = 0;

    while(!pq.empty()){
        int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(!inMST[u]){
            inMST[u] = true;
            MSTCost += wt;

            for(int i = 0; i < adj[u].size(); i++){
                int v = adj[u][i].first;
                int w = adj[u][i].second;
                if(!inMST[v])
                    pq.push({w, v});
            }
        }
    }

    return MSTCost;
}

int main(){
    int v = 4;

    vector<vector<pair<int, int>>> adj(v);

    adj[0].push_back({1, 10});
    adj[0].push_back({2, 15});
    adj[0].push_back({3, 30});

    adj[1].push_back({0, 10});
    adj[1].push_back({3, 40});

    adj[2].push_back({0, 15});
    adj[2].push_back({3, 50});

    adj[3].push_back({1, 40});
    adj[3].push_back({0, 30});
    adj[3].push_back({2, 50});

    cout << primMST(v, adj) << endl;

    return 0;
}

/*

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int primMST(int v, vector<vector<pair<int, int>>> adj){
    vector<bool> inMST(v, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    int MSTCost = 0;

    while(!pq.empty()){
        int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(!inMST[u]){
            inMST[u] = true;
            MSTCost += wt;

            for(auto e : adj[u]){
                pq.push({e.second, e.first});
            }
        }
    }

    return MSTCost;
}

int main(){
    int v = 4;

    vector<vector<pair<int, int>>> adj(v);

    adj[0].push_back({1, 10});
    adj[0].push_back({2, 15});
    adj[0].push_back({3, 30});

    adj[1].push_back({0, 10});
    adj[1].push_back({3, 40});

    adj[2].push_back({0, 15});
    adj[2].push_back({3, 50});

    adj[3].push_back({1, 40});
    adj[3].push_back({0, 30});
    adj[3].push_back({2, 50});

    cout << primMST(v, adj) << endl;

    return 0;
}

*/