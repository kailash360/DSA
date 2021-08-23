class Solution {
public:
    bool isBipartiteCheck(int x, vector<int>& col, vector<vector<int>> graph){
        queue<int> q; // second paramter is for colors , lets take c1 = 1, c2 = -1
        q.push(x);
        // vis[x] = 1;
        col[x] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: graph[node]){
                if(!col[it]){
                    q.push(it);
                    col[it] = -col[node];
                }
                else if(col[node] == col[it]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        // vector<int> vis(V+1, 0);
        vector<int> col(V+1, 0);
        for(int i=0; i<V; i++){
            if(col[i] == 0 && !isBipartiteCheck(i, col, graph)) return false;
        }
        return true;
    }
};

// stack solution was leading to WA