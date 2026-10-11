class Solution {
public:
    bool isCycleDFS(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>> &prereq){
        vis[src] = true;
        recPath[src] = true;

        for(int i = 0; i < prereq.size(); i++){
            int u = prereq[i][0];
            int v = prereq[i][1];

            if(src == v){
                if(!vis[u]){
                    if(isCycleDFS(u, vis, recPath, prereq)){
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

    void topoSort(int src, vector<bool> &vis, stack<int> &s, vector<vector<int>> &prereq){
        vis[src] = true;

        for(int i = 0; i < prereq.size(); i++){
            int u = prereq[i][0];
            int v = prereq[i][1];

            if(src == v){
                if(!vis[u]){
                    topoSort(u, vis, s, prereq);
                }

            }
        }

        s.push(src);
    }

    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(isCycleDFS(i, vis, recPath, prereq)){
                    return ans;
                }
            }
        }

        // Topological Sorted Order - DAG(Directed Acyclic Graph)
        stack<int> s;
        vis.assign(n, false);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                topoSort(i, vis, s, prereq);
            }
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};