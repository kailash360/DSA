class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        unordered_set<int> s;
        
        for(int num: nums){
            s.insert(num);
        }
        
        int res = 0;
        
        for(int num: nums){
            if(!s.count(num-1)){
                int current_num = num;
                int current_length = 1;
                while(s.count(current_num+1)){
                    current_length++;
                    current_num++;
                }
                res = max(current_length, res);
            }
        }
        
        return res; // O(3n)
    }
};