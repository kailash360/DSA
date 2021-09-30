class Solution {
public:
    int curr = 0;
    void dfs(int i, int j , vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >=grid.size() || j >= grid[0].size())
            return;
        if(grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        curr = curr+1;
        dfs(i+1, j , grid);
        dfs(i, j+1 , grid);
        dfs(i-1, j , grid);
        dfs(i, j-1 , grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    dfs(i, j, grid);
                    ans = max(ans, curr);
                    curr = 0;
                }
            }
        }

        return ans;
    }
};