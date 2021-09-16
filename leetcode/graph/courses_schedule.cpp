#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // prerequisites -> [[ai,bi] ...]
        // u have to take bi first before u can take ai
        // this can indicate a direct edge from bi -> ai
        // there cant be any loops and it will form a DAG
        vector<int> g[numCourses];
        vector<int> indegree(numCourses, 0);
       
        for(int i=0; i<prerequisites.size(); i++) {
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        // now if the topo sort of this graph is possible return true else return false.
        queue<int> q;
	    for(int i=0; i<numCourses; i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
        
        vector<int> topo;
        int count = 0;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
            count++;
	        topo.push_back(node);
	        for(auto it: g[node]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
        
        if(count == numCourses)
            return true;
        else
            return false;
    }
};