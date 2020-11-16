#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        long int  c;
        cin>>c;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            c=c-a[i];
        }
        if(c<0)
        {
            cout<<"No"<<endl;
        }
        else 
        {
            cout<<"Yes"<<endl;
        }
    }

}