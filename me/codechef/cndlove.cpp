#include <iostream>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
        int n=0;
        cin>>n;
        int r=0;
        int sum=0;
        for(int i=0;i<n;i++)
            {
                cin>>r;
                sum+=r;
            }
        if(sum%2==0)
            cout<<"NO"<<endl;
        else 
            cout<<"YES"<<endl;
    }
    return 0;
}