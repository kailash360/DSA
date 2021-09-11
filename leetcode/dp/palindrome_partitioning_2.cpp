#include <bits/stdc++.h>
using namespace std;

/* bruh */
class Solution {
public:
    int dp[2001][2001];
    
    bool isPalindrome(int i, int j, string& s){
        while(i <= j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int solve(int i, int j, string& s){
        if(i >= j || isPalindrome(i,j,s))
            return dp[i][j] = 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        // find the minimum number of cuts from each portion in between i and j markers.
        dp[i][j] = INT_MAX;
        for(int k = i; k < j; k++) {
            if(!isPalindrome(i,k,s)) 
                continue;
            dp[i][j] = min(((dp[i][k] != -1? dp[i][k] : solve(i,k,s)) + (dp[k+1][j] != -1? dp[k+1][j] :solve(k+1,j,s)) + 1), dp[i][j]);
        }
        return dp[i][j];
    }
    
    int minCut(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.length();
        int ans = solve(0,n-1,s);
        return ans;
    }
};