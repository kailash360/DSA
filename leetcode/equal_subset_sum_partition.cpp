class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum += nums[i]; // calculate the sum of all elements
        if(sum % 2 != 0) return false;
        sum = sum / 2; // this will be the value of a subset
        int dp[n+1][sum+1];
        // base case for dp is when no elements -> true
        // when some elements -> false
        for(int i=1; i<=sum; i++) dp[0][i] = 0; // if sum > 0 but no elements -> not poss
        for(int i=0; i<=n; i++) dp[i][0] = 1; // if sum = 0 but multiple elements -> possible (not choosing any element will give sum = 0)
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                 if(j < nums[i-1])
                     dp[i][j] = dp[i-1][j];
                else{
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
};