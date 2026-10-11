class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int originalCol, int color){
        if(r < 0 || c < 0 || r >= image.size() || c >= image[0].size()){
            return;
        }
        if(image[r][c] != originalCol || image[r][c] == color){
            return;
        }

        image[r][c] = color;

        dfs(image, r-1, c, originalCol, color);
        dfs(image, r, c+1, originalCol, color);
        dfs(image, r+1, c, originalCol, color);
        dfs(image, r, c-1, originalCol, color);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int r, int c, int color) {
        dfs(image, r, c, image[r][c], color);

        return image;
    }
};