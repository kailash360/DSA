// Greedy
#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int dep[], int n){
    int plat_curr = 1;
    int max_plat = 1;
    sort(arr, arr+n);
    sort(dep, dep+n);
    int i=1, j=0;
    
    while(i<n && j<n){
        if(arr[i] <= dep[j]){
            plat_curr++;
            i++;
        }
        else if(arr[i] > dep[j]){
            plat_curr--;
            j++;
        }
        max_plat = max(plat_curr, max_plat);
    }
    return max_plat;
}

int main(){
    int arr[] = {};
    int dep[] = {};
    int n = 0;
    int ans = solve(arr,dep,n);
    cout << ans;
    return 0;
}