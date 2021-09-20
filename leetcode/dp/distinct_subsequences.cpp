class Solution {
public:
    // need to optimize
    // memoized approach
    int dp[1001][1001];
    int solve(string x, string y, int idx, int matching){
        int ans = 0;
        if(dp[idx][matching] != -1)
            return dp[idx][matching];
        if(matching == y.length())
            return 1;
        if(idx >= x.length() && matching == y.length())
            return 1;
        if(idx >= x.length() && matching != y.length())
            return 0;
        
        if(x[idx] == y[matching]){
            ans = ans + (dp[idx+1][matching+1]!=-1 ? dp[idx+1][matching+1] : solve(x, y, idx+1, matching + 1)) + (dp[idx+1][matching]!=-1 ? dp[idx+1][matching] :solve(x, y, idx+1, matching));
        }
        else {
            ans = ans + (dp[idx+1][matching]!=-1 ? dp[idx+1][matching] :solve(x, y, idx+1, matching));
        }
        return dp[idx][matching] = ans;
    }
        
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(s,t,0,0);
        return ans;
    }
};