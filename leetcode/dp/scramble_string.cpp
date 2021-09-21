#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string,bool> m;
    bool solve(string s1, string s2) {
        int n1 = s1.length(); // length of string s1 (same as length of s2)
        
        if(s1.compare(s2) == 0) // check if s1 and s2 are lexicographically equal here
            return true;
        if(n1 <= 1) // if not equal and length of s1 is 1 or less then false
            return false;
        
        string temp = s1;
        temp.push_back(' ');
        temp.append(s2);
        
        if(m.find(temp) != m.end())
            return m[temp];
        
        bool flag = false;
        for(int i=1; i<n1; i++) {
            if(
            (solve(s1.substr(0,i), s2.substr(0,i)) && solve(s1.substr(i,n1-i), s2.substr(i,n1-i))) || (solve(s1.substr(0,i), s2.substr(n1-i,i)) && solve(s1.substr(i,n1-i), s2.substr(0,n1-i)))
            ){
                flag = true; // this is the basis of the problem acc to statement whether we have to replace x and y or not ....this forms the recursion tree
                break;
            }
        }
        
        return m[temp] = flag;
    }
    bool isScramble(string s1, string s2) {
        int n1 = s1.length(); // length of string s1
        int n2 = s2.length(); // length of string s2
        
        if(n1 != n2)
            return false;
        return solve(s1,s2);
    }
};