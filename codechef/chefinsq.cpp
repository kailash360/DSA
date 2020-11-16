#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;


ll combination(ll n, ll k) 
{ 
    ll C[n + 1][k + 1]; 
    ll i, j; 

    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, k); j++) 
        { 

            if (j == 0 || j == i) 
                C[i][j] = 1; 

            else
                C[i][j] = C[i - 1][j - 1] + 
                          C[i - 1][j]; 
        } 
    } 
  
    return C[n][k]; 
} 

int main()
{
    ll t=0;
    cin >> t;
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        if(k==0)
            {cout<<0<<endl;break;}
        ll ar[n];
        for(ll i=0;i<n;i++)
            cin >> ar[i];
        
        sort(ar,ar+n);
        
        ll c1=1;
        ll c2=0;
        for(ll i=0;i<k-1;i++)
        {
            if(ar[i]==ar[k-1])
                c1++;
        }
        for(ll i=k;i<n;i++)
        {
            if(ar[k-1]==ar[i])
                c2++;
        }
        
        ll c3=c1+c2;
        cout<<combination(c3,c1)<<endl;
        
    
    }
    return 0;
}