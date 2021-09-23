class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 1)
            return strs[0];
        int max_length = INT_MAX;
        string lPrefix;
        for(int i=1; i<n; i++) {
            string currPrefix = "";
            string s1 = strs[i];
            string s2 = strs[i-1];
            int k =0;
            
            while(s1[k] == s2[k]) {
                if(s1[k] == '\0' || s2[k] == '\0')
                    break;
                currPrefix.push_back(s1[k]);
                ++k;
            }
            if(currPrefix.length() < max_length){
                lPrefix = currPrefix;
                max_length = currPrefix.length();
            }
        }
        return lPrefix;
    }
};

// can be solved using Trie's with O(n) time -> checko out later