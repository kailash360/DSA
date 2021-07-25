#include <bits/stdc++.h>
using namespace std;

long long subarrayXor(int arr[], int n, int m)
{
    int xorSum = 0;
    int count = 0;
    unordered_map<int,int> freq;
    
    for(int i=0;i<n;i++){
    	xorSum = xorSum ^ arr[i];
    	if(xorSum == m) count++;
    	if(freq.find(xorSum ^ m) != freq.end()){
    		count += freq[xorSum^m];
    	}
    	freq[xorSum] += 1;
    }
 
    return count;
}
 
int main()
{
    int arr[] = { 4, 2, 2, 6, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 6;
 
    cout << "Number of subarrays having given XOR is "
         << subarrayXor(arr, n, m);
    return 0;
}