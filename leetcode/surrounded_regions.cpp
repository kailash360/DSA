class Solution {
public:
    int X[4] = {0,0,1,-1};
    int Y[4] = {1,-1,0,0};
    void markInvalid(int x, int y, vector<vector<char>>& board){
        // mark all the islands invalid which are on the border...we will not traverse them
        board[x][y] = 'I';
        
         for(int k=0; k<4; k++){
            int newX = x + X[k];
            int newY = y + Y[k];
            if(newX>=0 && newY>=0 && newX<board.size() && newY<board[0].size() && board[newX][newY] == 'O'){
                markInvalid(newX, newY, board);
            }
        }
        
        
    }
    void dfs(int x, int y, vector<vector<char>>& board){
        board[x][y] = 'X';
        
        for(int k=0; k<4; k++){
            int newX = x + X[k];
            int newY = y + Y[k];
            if(newX>=0 && newY>=0 && newX<board.size() && newY<board[0].size() && board[newX][newY] == 'O'){
                dfs(newX, newY, board);
            }
        }
        
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(); //row length
        int n = board[0].size();// column length
        // for the top border and bottom border
        for(int i=0; i<m; i++)
        {
            if(board[i][0]=='O')
                markInvalid(i,0, board);

            if(board[i][n-1]=='O')
                markInvalid(i,n-1, board);
        }
        // for the left border and right border
        for(int j=0; j<n; j++)
        {
            if(board[0][j]=='O')
                markInvalid(0,j, board);

            if(board[m-1][j]=='O')
                markInvalid(m-1,j, board);
        }
   
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O'){
                    dfs(i,j,board);
                }
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'I') { 
                    board[i][j] = 'O';
                };
            }
        }
    }
};