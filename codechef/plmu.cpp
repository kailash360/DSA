#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,x,t=0,z=0;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> x;
            if(x==2)
                t++;
            if(x==0)
                z++;
        }
        
        int ans = t*(t-1)/2  +  z*(z-1)/2;
        
        cout << ans << endl;
    }
    return 0;
}