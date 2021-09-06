#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> mp;
        
        for(int num : nums){
            sum += num;
            if(sum == k)
                ans++;
            if(mp.find(sum - k) != mp.end()){
                ans += mp[sum-k];
            }
            mp[sum]++;
        }
        
        return ans;
    }
};