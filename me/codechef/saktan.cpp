#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
  int a;
  cin >> a;
  while (a--) 
  {
    ll r = 0, c = 0, x = 0, y = 0, w = 0, z = 0, n, m, q;
    cin >> n >> m >> q;
    ll row[n] = {0};
    ll col[m] = {0};
    while (q--) 
    {
        cin >> r >> c;
        row[r-1]++;
        col[c-1]++;
    }

    for (int i = 0; i<n; i++) 
    {
        if (row[i] % 2 == 0) 
          y++;
        else 
          x++;
    }
    for(int i=0; i<m; i++)
    {
        if (col[i] % 2 == 0) 
          z++;
        else 
          w++;
    }

    ll sol=(w*y)+(z*x);
    cout << sol << endl;
  }
  return 0;
}