class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> mp;
        
        for(int num:nums) {
            mp[num]++;
        }
        for(auto it: mp) {
            int x = it.first;
            int target = k + x;
            // search target in map if not found insert nums[i] in map
            if(k > 0){ 
                if(mp.count(target)){
                    count++;
                }
            }
            else{
                if(mp[x] > 1) {
                    count++;
                }
        }
       
        }
         return count;
    }
};