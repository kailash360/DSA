// Yet to figure out the error in this code....
#include <bits/stdc++.h>
using namespace std;

class Solution{

  public:
    int dp[1000][1000];
    int solve(int arr[], int s1, int s2, int n) {
        if(n == 0)
            return abs(s1-s2);
        
        if(dp[n][s1] != -1) return dp[n][s1];
        
        int x = solve(arr, s1+arr[n-1], s2, n-1);
        int y = solve(arr, s1, s2+arr[n-1], n-1);
        return dp[n][s1] = min(x,y);
        // return dp[n][s1] = min(dp[n-1][x] , dp[n-1][s1]);
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    memset(dp, -1 , sizeof(dp));
	    int sum = 0;
	    for(int i=0; i<n; i++) sum += arr[i]; // calculate the sum of the elements of the array
	    int s1 = 0;
	    int s2 = 0;
	    int ans = solve(arr, s1, s2, n);
	    return ans;
	} 
};