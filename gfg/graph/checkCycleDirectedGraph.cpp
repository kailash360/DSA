
class Solution
{
    public:
    bool cycleCheck(int x, vector<int>& vis, vector<int>& dfsVis, vector<int> adj[]){
        vis[x] = 1;
        dfsVis[x] = 1;
        for(auto it: adj[x]){
            if(!vis[it]){
                if(cycleCheck(it, vis, dfsVis, adj)) return true;
            }
            else if(dfsVis[it]){
                return true;
            }
        }
        dfsVis[x] = 0;
        return false;
    }
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	vector<int> vis(V+1, 0);
	   	vector<int> dfsVis(V+1, 0);
	   	
	   	for(int i=0; i<V; i++){
	   	    if(!vis[i]){
	   	        if(cycleCheck(i, vis, dfsVis, adj)) return true;
	   	    }
	   	}
	   	return false;
	}
};