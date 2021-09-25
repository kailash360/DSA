#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin >> arr[i];
        
        if(n<=k)
        {
            ll x = k/n;
            ll y = k%n;
            // cout<<n/2<<endl;
            if(x%3==1)
            {
                ll temp = 0;
                for(ll i=0;i<n/2;i++)
                {
                    temp = arr[i];
                    arr[i] = arr[i]^arr[n-i-1];
                    arr[n-i-1] = temp;
                }
            }
            else if(x%3==2)
            {
                ll temp = 0;
                for(ll i=0;i<n/2;i++)
                {
                    temp = arr[n-i-1];
                    arr[n-i-1] = arr[i]^arr[n-i-1];
                    arr[i] = temp;
                }
            }
            else
            {
                if(n%2==1)   
                    arr[n/2]=0;
            }
            for(ll i=0;i<y;i++)
            {
                ll a = i%n;
                ll b = n - (i%n) - 1;
                ll c = arr[a]^arr[b];
                arr[i%n]=c;
            }
            if(n%2==1)
                arr[n/2]=0;
        }
        else
        {
            for(ll i=0;i<k;i++)
            {
                ll a = i%n;
                ll b = n - (i%n) - 1;
                ll c = arr[a]^arr[b];
                arr[i%n]=c;
            }
        }
        
        for(ll i=0;i<n;i++)
            cout<<arr[i]<<" ";
        
        cout<<endl;
    }
    return 0;
}