class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort array of 0's 1's and 2's without any sorting algorithm
        int n = nums.size();
        // dutch flag - optimal
        int low = 0;
        int mid = 0;
        int high = n-1;
        while(mid <= high){
            if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        
    }
};