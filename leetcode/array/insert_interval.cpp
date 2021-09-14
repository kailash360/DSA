#include <bits/stdc++.h>
using namespace std;

/* lots of edge cases

ex:
1. [[1,5]]
   [2,7]

2. [[1,5]]
   [2,7]

3. []
   [5,7]
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> x;
        if(intervals.size() == 0){
            x.push_back(newInterval);
            return x;
        }
        int target = newInterval[0];
        int lower_index;
        for(int i=0 ;i<intervals.size(); i++) {
            if(target < intervals[i][0]){
                intervals.insert(intervals.begin()+i, newInterval);
                break;
            }
            if (i==intervals.size()-1 && target >= intervals[i][0]) { // to solve edge case
                intervals.push_back(newInterval);
                break;
            }
        }
        int left = intervals[0][0];
        int right = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] > right){
                x.push_back({left,right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
            else{
                if(intervals[i][1] <= right){
                    //do nothing
                }
                else{
                    right = intervals[i][1];
                }
            }
        }
        
        x.push_back({left,right});
        return x;
    }
};