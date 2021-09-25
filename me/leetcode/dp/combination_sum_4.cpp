#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001];
    int solve(vector<int>& nums, int target) {
        
        if(target < 0) return 0;
        
        if(dp[target] != -1) return dp[target];
        
        
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            ans = ans + solve(nums, target - nums[i]);      
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        dp[0] = 1;
        int ans = solve(nums, target);
        return ans;
    }
};