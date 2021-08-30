#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.empty())
            return result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // initialize the pointer to the first second value in the array and
        // left and right to the begin and end of the right subarray
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int t = target - (nums[i] + nums[j]);
                
                int left = j+1; // next element after j
                int right = n-1; // last element
                
                while(left < right){
                    int sum = nums[left] + nums[right];
                    if(sum == t){
                        int current_left = nums[left];
                        int current_right = nums[right];
                        result.push_back({nums[i], nums[j], current_left, current_right});
                        
                        while(left < right && current_left == nums[left]) ++left; // removing duplicates of left
                        while(left < right && current_right == nums[right]) --right; // removing duplicates of right
                    }
                    
                    else if (sum < t){
                        left++;
                    }
                    else {
                        right--;
                    }
                }
                // removing duplicates of 'j'
                while(j+1 < n && nums[j] == nums[j+1]) ++j; 
                
                 // removing duplicates of 'i'
                while(i+1 < n && nums[i] == nums[i+1]) ++i;
            }
        }
        return result;
    }
};