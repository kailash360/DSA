class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else{
                if(!st.empty() && s[st.top()] == '('){
                    st.pop();
                    int last=-1;
                    if(!st.empty()){
                        last = st.top();
                    }
                    ans = max(ans, i-last);
                }
                else{
                        st.push(i);
                    }
            }
        }
        return ans;
    }
};