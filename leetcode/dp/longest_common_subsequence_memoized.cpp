// memoized approach for the longest common subsequence problem
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1000][1000];
    int solve(string& x,string& y,int n1,int n2){
        if(n1 == 0 || n2 == 0)
            return 0;
        if(dp[n1][n2] != -1)
            return dp[n1][n2];
        if(x[n1-1] == y[n2-1])
            return dp[n1][n2] = 1+solve(x,y,n1-1,n2-1);
        else
            return dp[n1][n2] = max(solve(x,y,n1-1,n2), solve(x,y,n1,n2-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        int n1 = text1.length();
        int n2 = text2.length();
        int ans = solve(text1, text2, n1, n2);
        return ans;
    }
};