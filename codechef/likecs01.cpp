#include <iostream>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
        int n,m,k,l,r;
        cin>>n>>m>>k>>l>>r;
        int mx=0,y=0;
        for(int i=0;i<n;i++)
        {
            int c,p;
            cin>>c>>p;
            if((c-m)>=(k+1))
                c-=m;
            else if((c+m)<=(k-1))
                c+=m;
            else
                c=k;

            if(y==0 && c>=l && c<=r)
            {
                mx=p;
                y=1;
                continue;
            }
            if(c>=l && c<=r && mx>p)
                mx=p;

        }
        if(mx==0)
            cout<<-1<<"\n";
        else
            cout<<mx<<"\n";

    }
    return 0;
}
