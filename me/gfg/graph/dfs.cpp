#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    void dfs(int node, vector<int>& visited, vector<int> adj[], vector<int>& dfsStore){
        dfsStore.push_back(node);
        visited[node] = 1;
        for(auto it: adj[node]){
            if(!visited[it])
                dfs(it, visited, adj, dfsStore);
        }
    }
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int> dfsStore;
	    vector<int> visited(V+1, 0);
	    
	    for(int i=0; i<V; i++){
	        if(!visited[i]){
	            dfs(i, visited, adj, dfsStore);
	        }
	    }
	    return dfsStore;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
} 
// stack solution was leading to WA