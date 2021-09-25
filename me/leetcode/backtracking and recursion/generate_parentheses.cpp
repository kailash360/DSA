class Solution {
public:
    void solve(string temp, vector<string>& ans, int x, int y, int t) {
        // x -> left bracket count, y -> right bracket count
        if(temp.length() == t*2){
            ans.push_back(temp);
            return;
        }
        
        if(x < t) {
            string temp1 = temp;
            temp1.push_back('(');
            solve(temp1, ans, x+1, y, t);
        }
        if(y < x) {
            string temp1 = temp;
            temp1.push_back(')');
            solve(temp1, ans, x, y+1, t);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("", ans, 0, 0, n);
        return ans;
    }
};