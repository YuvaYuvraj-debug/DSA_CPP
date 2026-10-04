class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshCount = 0;
        queue<pair<int, int>> q;
        
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    freshCount++;
                }else if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        int minutes = 0;
        while(!q.empty() && freshCount != 0){
            int sz = q.size(); 
            minutes++;

            for(int k = 0; k < sz; k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if(i-1 >= 0 && grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    freshCount--;
                    q.push({i-1, j});
                }

                if(i+1 < m && grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    freshCount--;
                    q.push({i+1, j});
                }

                if(j-1 >= 0 && grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    freshCount--;
                    q.push({i, j-1});
                }

                if(j+1 < n && grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    freshCount--;
                    q.push({i, j+1});
                }
            }
        }

        return freshCount == 0? minutes : -1;
    }
};