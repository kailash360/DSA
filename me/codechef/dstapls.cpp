#include <iostream>
using namespace std;
typedef long long int ll;

int main()
{

    int t=0;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        if((n/k)%k==0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
