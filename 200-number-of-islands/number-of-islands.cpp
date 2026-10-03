class Solution {
public:
    void helper(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid, int m, int n){
        if(i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || grid[i][j] != '1'){
            return;
        }
        vis[i][j] = true;

        helper(i-1, j, vis, grid, m, n);
        helper(i, j+1, vis, grid, m, n);
        helper(i+1, j, vis, grid, m, n);
        helper(i, j-1, vis, grid, m, n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    helper(i, j, vis, grid, m, n);
                    islands++;
                }
            }
        }

        return islands;
    }
};