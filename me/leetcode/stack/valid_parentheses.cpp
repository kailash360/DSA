class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
              st.push(s[i]);   
            }
            else if(st.empty())
                return false; // this is important to prevent run time error due to popping from empty stack...
            else if(s[i] == ')' && st.top() == '(')
                st.pop();
            else if(s[i] == '}' && st.top() == '{') 
                st.pop();
            else if(s[i] == ']' && st.top() == '[')
                st.pop();
            else 
                st.push(s[i]);
        }
        if(st.empty()) return true;
        return false;
    }
};