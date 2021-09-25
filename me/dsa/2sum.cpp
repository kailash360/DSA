/* time complexity for searching in an hash table is O(1) */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> search_table; // hash table
        vector<int> solution;
        for(int i=0;i<nums.size();i++){
            int num1 = target - nums[i];
            if(search_table.find(num1) != search_table.end()){
                solution.push_back(search_table[num1]);
                solution.push_back(i);
            }
            search_table[nums[i]] = i;
        }
        return solution;
    }
};