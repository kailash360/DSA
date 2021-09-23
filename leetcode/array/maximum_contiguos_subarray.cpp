class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = nums[0];
        int max_sum_so_far = nums[0];
        for(int i=1; i<n; i++) {
            max_sum_so_far = max(max_sum_so_far + nums[i], nums[i]);
            max_sum = max(max_sum , max_sum_so_far);
        }
        return max_sum;
    }
};

// kadane's algorithm