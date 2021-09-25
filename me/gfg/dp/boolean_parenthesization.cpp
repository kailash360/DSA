#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int dp[201][201][2];
    int solve(string& s, int i, int j, char X) {
        // X determines whether we want to find out true or false counts;
        if(i > j)
            return 0;
        if(i == j && X == 'T')
            return dp[i][j][0] = (s[i] == 'T' ? 1 : 0);
        else if(i == j && X == 'F')
            return dp[i][j][1] = (s[i] == 'F' ? 1 : 0);
            
        if(X == 'T' && dp[i][j][0] != -1)
            return dp[i][j][0];
        if(X == 'F' && dp[i][j][1] != -1)
            return dp[i][j][1];
            
        int ans = 0;
        for(int k = i+1; k <= j-1; k+=2) {
            int lt = (dp[i][k-1][0] != -1 ? dp[i][k-1][0] : solve(s, i, k-1, 'T'));
            int rt = (dp[k+1][j][0] != -1 ? dp[k+1][j][0] : solve(s, k+1, j, 'T'));
            int lf = (dp[i][k-1][1] != -1 ? dp[i][k-1][1] : solve(s, i, k-1, 'F'));
            int rf = (dp[k+1][j][1] != -1 ? dp[k+1][j][1] : solve(s, k+1, j, 'F'));

            int temp;
            if(s[k] == '&' && X == 'T') {
                temp = lt*rt ;
            }
            if(s[k] == '&' && X == 'F') {
                temp = lt*rf + lf*rt + lf*rf;
            }
            if(s[k] == '|' && X == 'T') {
                temp = lt*rf + lf*rt + lt*rt;
            }
            if(s[k] == '|' && X == 'F') {
                temp = lf*rf;
            }
            if(s[k] == '^' && X == 'T') {
                temp = lt*rf + lf*rt;
            }
            if(s[k] == '^' && X == 'F') {
                temp = lf*rf + lt*rt;
            }
            ans = ans + temp;
        }
        if(X == 'T')
            return dp[i][j][0] = ans%1003;
        else if(X == 'F')
            return dp[i][j][1] = ans%1003;
    }
    int countWays(int N, string S){
        // code here
        memset(dp, -1, sizeof(dp));
        int ans = solve(S, 0, N-1, 'T');
        return ans;
    }
};