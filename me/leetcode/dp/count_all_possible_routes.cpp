#include <bits/stdc++.h>
using namespace std;

// so basically whats happening is that im trying to go from start -> some location and if thats possible im trying to go one
// recursive depth more to check if thats possible....
// if I reach finish and fuel is is still 0 or greater I add 1 to the ans.
// Take care I cannot return 1 because I can go from start -> some location -> start -> some location -> finish...so I set ans = 1 at [*]
class Solution {
public:
    int dp[101][201];
    int solve(vector<int>& locations, int start, int finish, int fuel) {
        long long int ans = 0;
        if(fuel >= 0 && start == finish) {
            ans = 1; // [*]
        }
        if(fuel < 0 || start >= locations.size())
            return 0;
        
        if(dp[start][fuel] != -1)
            return dp[start][fuel];
        
        for(int i=0; i< locations.size(); i++) {
            if(i == start)
                continue;
            ans += solve(locations, i, finish, fuel - abs(locations[i] - locations[start])) % 1000000007;
        }
        return dp[start][fuel] = ans%1000000007;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(locations, start, finish, fuel);
        return ans;
    }
};