#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long int ll;

int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n],b[n],score=0;

        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        for(int i=0;i<n;i++)
            score=max(score,(20*a[i]-10*b[i]));

        cout<<"\n";
        cout<<score<<endl;

    }
    return 0;
}
