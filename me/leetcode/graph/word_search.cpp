#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m;
    int n;
    string s;
    bool dfs(int loc, int i, int j, vector<vector<char>>& board) {
        if(i >= m || j >= n || i < 0 || j < 0 || board[i][j] == '1')
            return false;
        if(loc == s.size() -1)
            return true;
        char ch = board[i][j];
        
        board[i][j] = '1';
        bool x = false;
        if(i+1 < m && board[i+1][j] == s[loc+1])
            x = x || dfs(loc+1, i+1, j, board);
        if(j+1 < n && board[i][j+1] == s[loc+1])
            x = x || dfs(loc+1 , i, j+1, board);
        if(i-1 >= 0 &&board[i-1][j] == s[loc+1])
            x = x || dfs(loc+1, i-1, j, board);
        if(j-1 >= 0 && board[i][j-1] == s[loc+1])
            x = x || dfs(loc+1, i, j-1, board);
        
        board[i][j] = ch;
        
        return x;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        s = word;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == word[0] && dfs(0, i,j, board)){
                    return true;        
                }
            }
        }
        return false;
    }
};

// dfs