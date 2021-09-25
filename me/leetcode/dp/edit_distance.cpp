#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[501][501];
    int minimum(int x, int y, int z) { return min(min(x, y), z); }
    int solve(string& word1,string& word2, int i, int j) {
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i == 0)
            return dp[i][j] = j;
        if(j == 0)
            return dp[i][j] = i;
        if(word1[i-1] == word2[j-1])
            return dp[i][j] = solve(word1, word2, i-1, j-1);
        else{ // when the last characters are not same we have to take minimum of insert replace or remove -- we add 1 to denote that 1 operation was performed.
           return dp[i][j] = 1 + minimum(
                          dp[i-1][j]!=-1 ? dp[i-1][j] : solve(word1, word2, i-1, j),
                          dp[i][j-1]!=-1 ? dp[i][j-1] : solve(word1, word2, i, j-1),
                          dp[i-1][j-1]!=-1 ? dp[i-1][j-1] : solve(word1, word2, i-1, j-1)
                         );
        }
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        int n1 = word1.length();
        int n2 = word2.length();
        
        int ans = solve(word1, word2, n1, n2);
        return ans;
    }
};