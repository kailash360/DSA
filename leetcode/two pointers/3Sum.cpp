#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end()); // sort the array in ascending order
        vector<vector<int>> res;
        // -4 -1 -1 0 1 2 
        for(int i=0;i<n-2;i++){
            if(i == 0 || (i>0 && nums[i]!=nums[i-1])){
            int num1 = nums[i];
            int t2 = -num1;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int n1 = nums[j];
                int n2 = nums[k];
                int sum = n1 + n2;
                if(sum < t2) {
                    j++;
                }
                else if(sum > t2) k--;
                else{
                    res.push_back({num1, n1, n2});
                    while(nums[j] == n1 && j<k) j++;
                    while(nums[k] == n2 && j<k) k--;
                }
            }
        }
            
        }
        return res;
    }
};