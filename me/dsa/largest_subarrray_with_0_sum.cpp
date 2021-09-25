#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n){
    unordered_map<int,int> search_table;
    int x = 0;
    int max_len = 0;
    for(int i=0;i<n;i++) {
        x = x + arr[i];

        if(arr[i] == 0 && max_len == 0){
            max_len = 1;
        }
        if(x == 0){
            max_len = i+1;
        }
        if(search_table.find(x) != search_table.end()){
            max_len = max(max_len, i - search_table[x]);
        }
        else{
            search_table[x] = i;
        }
    } // prefix sum hash table with (sum) -> (index) pairs

    return max_len;
}

// Driver Code
int main()
{
    int arr[] = { 15, -2, 2, -8, 1, 7, 10, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of the longest 0 sum subarray is "
         << maxLen(arr, n);
 
    return 0;
}