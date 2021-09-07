#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // first create dp table to find length of shortest scs
        int n1 = str1.length();
        int n2 = str2.length();
        
        int dp[n1+1][n2+1];
        for(int i=0; i<=n1; i++){
            for(int j=0; j<=n2; j++){
                if(i == 0){
                    dp[i][j] = j;
                }
                else if(j == 0){
                    dp[i][j] = i;
                }
                else if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // next iterate from end of dp table to the beginning 
        // if both the characters from the string matches then they are surely in scs
        // if they dont then we must follow the minimum path required to reach this dest
        string s;
        int i = n1,j = n2;
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                s.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                s.push_back(str2[j-1]);
                j--;
            }
            else{
                s.push_back(str1[i-1]);
                i--;
            }
        }
        
        while(i > 0){
            s.push_back(str1[i-1]);
            i--;
        }
        while(j > 0){
            s.push_back(str2[j-1]);
            j--;
        }
        
        reverse(s.begin(),s.end());
        return s;
    }
};