#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<string> st;
    bool solve(string x, int idx, vector<string>& wordDict,  vector<int>& mp) {
        int n = x.length();
        if(idx >= x.size())
            return true;
        if(mp[idx] != -1)
            return mp[idx];
        
        string sec;
        for(int i=idx; i<n; i++) {
            sec.push_back(x[i]);
            if(st.find(sec) != st.end()) {   
                if(solve(x, i+1, wordDict, mp)) {
                    return mp[idx] = true;
                }
            }
        }
        mp[idx] = 0;
        return mp[idx];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> mp(n, -1);
        for(int i=0; i<wordDict.size(); i++) {
            st.insert(wordDict[i]);
        }
        bool ans = solve(s, 0, wordDict, mp);
        return ans;
    }
};