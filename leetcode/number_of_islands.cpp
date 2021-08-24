class Solution {
public:
    
    void dfs(int x, int y, vector<vector<char>>& grid){
        if(x >= grid.size() || y >= grid[0].size() || x < 0 || y < 0)
            return;
        if(grid[x][y] != '1') 
            return;
        
        grid[x][y] = '2';
        
        dfs(x+1, y, grid);
        dfs(x-1, y, grid);
        dfs(x, y+1, grid);
        dfs(x, y-1, grid);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();   
        int ans = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    ++ans;
                }
            }
        }
        return ans;
    }
};