#include <bits/stdc++.h>
using namespace std;

// DSU class definition
class DSU {

    private :

        vector<int> parent;
        vector<int> rank;
    
    public :

        // Initialize all vectors
        DSU(int n) {

            parent.resize(n);
            for (int i = 0;i < n;i++) {
                parent[i] = i;
            }
            rank.resize(n);
            fill(rank.begin(),rank.end(),0);
        }

        // Find parent node of given node
        int FIND(int a) {

            if (a == parent[a]) {
                return a;
            }else {
                return parent[a] = FIND(parent[a]);
            }
        }

        // Union the nodes in order to have a common parent and show connection
        void UNION(int a,int b) {

            a = FIND(a);
            b = FIND(b);
            if (a == b) {
                return;
            }
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
            if (rank[a] > rank[b]) {
                parent[b] = a;
            }else {
                parent[a] = b;
            }
        }
};

// Driver code
int main() {

    DSU D = DSU(10);
    return 0;
}