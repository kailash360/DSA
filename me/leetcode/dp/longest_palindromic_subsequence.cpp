#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s_ = s;
        reverse(s_.begin(), s_.end());
        // now s and s_ are reverse of each other and the longest common subsequence of both are actually the longest palindromic subsequence
        
        int x = s.length();
	    int y = s_.length();
	    
	    int dp[x+1][y+1];
	    for(int i=0; i<=x; i++) dp[i][0] = 0;
	    for(int j=0; j<=y; j++) dp[0][j] = 0;
	    
	    for(int i=1; i<=x; i++){
	        for(int j=1; j<=y; j++){
	            if(s[i-1] == s_[j-1])
	                dp[i][j] = 1 + dp[i-1][j-1];
	            else
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	        }
	    }
        
        return dp[x][y];
    }
};