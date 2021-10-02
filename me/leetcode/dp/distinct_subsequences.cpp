#include <bits/stdc++.h>
using namespace std;

// --> Pass string as a pointer and not as a copy. Copying a string and then passing it takes extra time which will lead to TLE.
// --> Alogwith returning dp[idx][matching] modify it too. So that we don't have to do the same task again later on.
class Solution {
public:
    // TODO:
    // need to optimize 
    // memoized approach
    int dp[1001][1001];
    int solve(string &x, string &y, int idx, int matching){
        // int ans = 0;
        if(dp[idx][matching] != -1)
            return dp[idx][matching];
        if(matching == y.length())
            return 1;
        if(idx >= x.length() && matching == y.length())
            return 1;
        if(idx >= x.length() && matching != y.length())
            return 0;
        
        if(x[idx] == y[matching]){
            dp[idx][matching] = solve(x,y,idx+1,matching+1)+solve(x,y,idx+1,matching);
        }
        else{
            dp[idx][matching] = solve(x,y,idx+1,matching);
        }
        return dp[idx][matching];
    }
        
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(s,t,0,0);
        return ans;
    }
};