#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& ans) {
        int n = candidates.size();
        if(target == 0) ans.push_back(temp);
       
        for(int i=idx; i<n; i++) {
            if(i>idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            temp.push_back(candidates[i]);
            solve(i+1, candidates, target - candidates[i], temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, candidates, target, temp, ans);
        return ans;
    }
};