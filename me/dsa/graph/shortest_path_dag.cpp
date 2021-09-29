// TODO:
// need to fix code...causes segmentation fault

#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

void topoSort(int x, vector<int>& vis, vector<pair<int,int>> adj[] ,stack<int> &s){
		vis[x] = 1;
		for(auto it: adj[x]){
			if(!vis[it.first]){
				topoSort(it.first, vis, adj, s);
			}
		}
	s.push(x);	
}

void findShortestPath(int src, int dest, vector<pair<int,int>> adj[], int n){
	stack<int> s;
	vector<int> vis(n+1, 0);
	
	for(int i=0; i<n; i++){
		if(!vis[i]){
			topoSort(i, vis, adj, s);
		}
	}
	
	vector<int> dist(n+1, 1e9);
	dist[src] = 0;
	
	while(!s.empty()){
		int node = s.top();
		s.pop();
		
		if(dist[node]!=INF){
			for(auto it: adj[node]){
				if(dist[node] + it.second < dist[it.first]){
					dist[it.first] = dist[node] + it.second;
				}
			}
		}
	}
	
	for(int i=0; i<n; i++){
		(dist[i] == 1e9) ? cout << "INF" : cout << dist[i] << " ";
	}
}

int main() {
	// your code goes here
	int n,m;
	cin >> n >> m; // enter the no. of nodes and the total no of edges
	vector<pair<int,int>> adj[n];
	
	// enter the edges as node-1 node-2 cost
	for(int i=0;i<m;i++){
		int u,v,cost;
		cin >> u >> v >> cost;
		adj[u].push_back({v, cost});
	}
	
	findShortestPath(0, n, adj, n);
}