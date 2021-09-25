class Solution {
public:
//     bool isSafe(vector<string> board, int row, int col, int n) {
//         // we need to check only in 3 directions -> because no queen has been placed in the right half of the table
//         int x = row;
//         int y = col;
//          // check if 'Q' in the top left diagonal
//         while(col >= 0 && row >= 0) {
//             if(board[row][col] == 'Q') return false;
//             row--;
//             col--;
//         }
//         row = x;
//         col = y;
//         // check if 'Q' in the row
//         while(col >= 0){
//             if(board[row][col] == 'Q') return false;
//             col--;
//         }
//         row = x;
//         col = y;
//         // check if 'Q' in the bottom left diagonal
//          while(col >= 0 && row < n) {
//             if(board[row][col] == 'Q') return false;
//             row++;
//             col--;
//         }
        
//         return true;
        
//     }
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal) {
        if(col == n){ 
            ans.push_back(board);
            return;
        }
        // for(int i=0; i<n; i++){
        //     cout << board[i] << endl;
        // }
        // cout << " --------" <<endl;
        for(int row=0; row<n; row++){
            
            if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1+col-row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1+col-row] = 1;
                solve(col+1, board, ans, n, leftRow, lowerDiagonal, upperDiagonal);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1+col-row] = 0;
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        vector<int> upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0), leftRow(n,0);
        string s(n,'.');
        for(int i=0;i<n;i++) board[i] = s;
        solve(0, board, ans, n, leftRow, lowerDiagonal, upperDiagonal);
        return ans;
    }
};