
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        
        for(int i=1; i<=n; i++){
            int x = INT_MIN;
            for(int j=0; j<i; j++){
                x = max(x, price[j] + dp[i-j-1]);
            }
            dp[i] = x;
        }
        
        return dp[n];
    }
};
