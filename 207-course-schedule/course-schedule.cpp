class Solution {
public:
    bool isCycle(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>> &edges){
        vis[src] = true;
        recPath[src] = true;

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            if(src == v){
                if(!vis[u]){
                    if(isCycle(u, vis, recPath, edges)){
                        return true;
                    }
                }else if(recPath[u]){
                    return true;
                }
            }
        }

        recPath[src] = false;

        return false;
    }

    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(isCycle(i, vis, recPath, edges)){
                    return false;
                }
            }
        }

        return true;
    }
};