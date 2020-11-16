#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;;
        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                char ch;
                cin >> ch;
                if(ch == '0' || j==i)
                    continue;
                if(abs(j-i)<=k)
                    adj[i].push_back(j);
            }
        }

        vector<int> dis(n,-1);
        dis[0]=0;
        queue<int> q;
        q.push(0);

        while(!q.empty())
        {
            int k = q.front();
            q.pop();
            for(auto i:adj[k]){
                if(dis[i]!=-1){
                    continue;
                }
                dis[i] = dis[k] + 1;
                q.push(i);
            }
        }
        cout << dis[n-1] << endl;
    }
    return 0;
}