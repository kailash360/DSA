// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	   int sum = 0;
	   for(int i=0; i<n; i++) sum += arr[i];
	   
	   int dp[n+1][sum+1];
	   
	   for(int i=0; i<=n; i++) dp[i][0] = 1; 
	   for(int i=1; i<=sum; i++) dp[0][i] = 0;
	   
	   // this loop figures out which subsets are possible between range of 0 and sum
	   for(int i=1; i<= n;i++){
	       for(int j=1; j<=sum; j++){
	           if(arr[i-1] > j){
	                dp[i][j] = dp[i-1][j];
	           }
	           else {
	               dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
	           }
	       }
	   }
	   
	   // this loop finds out the minimum sum partition
	   //  we know we need to minimize (sum - 2*s1)
	   int x = INT_MAX;
	   for(int j = sum/2; j>=0; j--){
	       if(dp[n][j] == 1){
	           x = sum - 2*j;
	           break;
	       }
	   }
	   
	   return x;
	}
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends