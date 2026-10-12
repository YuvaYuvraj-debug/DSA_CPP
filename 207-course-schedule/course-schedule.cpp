class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);

        for(auto edge : edges){
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            count++;

            for(int v : adj[curr]){
                indegree[v]--;

                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        return count == n;
    }
};