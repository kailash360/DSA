#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end()); // sort intervals based on the starting indexes
        
        int left = intervals[0][0];
        int right = intervals[0][1];
        
        vector<vector<int>> x;
        
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] > right) {
                x.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
            else {
                if(intervals[i][1] <=right) {
                    // do nothing
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