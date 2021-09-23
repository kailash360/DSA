class Solution {
public:
    
    void solve(vector<vector<int>>& matrix, vector<int>& ans, int x, int y, int m, int n) {
        // x - 0 y - 0 m - size of x n - size of y
        if(x > m || y > n)
            return;
        // recursion to calculate the spiral matrix
        for(int i=x; i<=m; i++) {
            ans.push_back(matrix[x][i]);
        }
        for(int i=y+1; i<=n-1; i++) {
            ans.push_back(matrix[i][m]);
        }
        if(n != y){
            for(int i=m; i>=x; i--) {
                ans.push_back(matrix[n][i]);
            }
            
        }
        if(m != x){
            for(int i=n-1; i>=y+1; i--) {
                ans.push_back(matrix[i][y]);
            }
        }
        solve(matrix, ans, x+1,y+1,m-1,n-1);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int j = matrix[0].size(); //column size
        int k = matrix.size();
        solve(matrix, ans, 0, 0, j-1, k-1);
        return ans;
    }
};