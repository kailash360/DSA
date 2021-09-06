const int MOD = 1e9+7;
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<int> dp(target+1);
        dp[0] = 1;
        for(int i=1;i<=d;i++){
            vector<int> dp2(target+1);
            for(int j=1;j<=target;j++){
                for(int k=1;k<=f;k++){
                    if(k <= j)
                        dp2[j] = (dp2[j]+ dp[j-k])%MOD;
                }
            }
            dp = dp2;
        }
        return dp[target];
    }
};