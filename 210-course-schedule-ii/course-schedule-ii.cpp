class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);

        for(const auto& edge : prereq){
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> res;
        res.reserve(n);

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for(int v : adj[curr]){

                if(--indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        return res.size() == n ? res : vector<int>();
    }
};