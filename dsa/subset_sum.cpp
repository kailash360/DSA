// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int solve(int idx, int N, vector<int>& arr, int sum, vector<int>& subsetSums){
        if(idx == N){
            subsetSums.push_back(sum);
            return -1;
        }
        // pick element
        solve(idx+1, N, arr, sum + arr[idx], subsetSums);
        
        // dont pick
        solve(idx+1, N, arr, sum, subsetSums);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> subsetSums;
        solve(0, N, arr, 0, subsetSums);
        sort(subsetSums.begin(),subsetSums.end());
        return subsetSums;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends