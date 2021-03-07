class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        const int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1));
        for(int L = n-1 ; L>=0 ; L--){
            for(int R=L ; R<n ; R++){
                for(int i=L ; i<=R; i++){
                    dp[L][R] = max(dp[L][R] , 
                                  (nums[i]*(L?nums[L-1]:1)*(R==n-1?1:nums[R+1]))
                                   + (L<=i-1?dp[L][i-1]:0) + (i+1<=R?dp[i+1][R]:0)
                                  );
                }
            }
        }
        return dp[0][n-1];
    }
};