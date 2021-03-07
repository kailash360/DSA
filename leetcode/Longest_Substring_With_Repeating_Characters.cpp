class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> lastIndex(256 , -1);
        int len = 0;
        int upd = 0;
        for(int i=0;i<n;i++){
            upd = max(upd , lastIndex[s[i]]+1);
            len = max(len , i - upd + 1);
            lastIndex[s[i]] = i;
        }
        return len;
    }
};