#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bipartiteCheck(vector<int> adj[], int x, vector<int>& color) {
        
        if(color[x] == -1) color[x] = 1;
        
        for(auto it: adj[x]){
            if(color[it] == -1){
                color[it] = 1 - color[x];
                if(!bipartiteCheck(adj, it,color)){
                    return false;
                }
            }
            else if(color[it] == color[x]) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // bipartite graph
        
        vector<int> adj[n+1]; // graph to store the dislike between people
        for(int i=0; i<dislikes.size(); i++) {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        // check if graph is bipartite or not
        vector<int> color(n+1, -1);
        for(int i=0; i<n; i++) {
            if(color[i] == -1){
                if(!bipartiteCheck(adj, i, color)){
                    return false;
                }
            }
        }
        return true;
    }
};