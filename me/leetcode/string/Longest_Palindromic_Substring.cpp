class Solution {
public:
    int expandAroundCenter(string s,int L,int R){
        while(L >= 0 && R < s.length() && s[L] == s[R]){
            L--;
            R++;
        }
        return R-L-1;
    }
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.length();
        int left = 0,right=0;
        for(int i=0;i<n;i++){
            // expanding odd case
            int even = expandAroundCenter(s,i,i);
            int odd = expandAroundCenter(s,i,i+1);
            int len = max(odd,even);
            if(len > (right-left)){
                left = i - (len - 1) / 2;
                right = i + len / 2;
            }
        }
        
        return s.substr(left , right-left+1);
    }
};