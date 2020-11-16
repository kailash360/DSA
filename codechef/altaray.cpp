#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll arr[n];
        
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        
        ll dp[n]={0};
        dp[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            if((arr[i]^arr[i+1])<0)
                dp[i] = dp[i+1] + 1;
            else
                dp[i] = 1;
        }
        
        for(int i=0;i<n;i++)
            cout << dp[i] << " ";
            
        cout << endl;
    }
    return 0;
}

