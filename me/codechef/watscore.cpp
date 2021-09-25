#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,p,s;
        cin >> n;
        int maximum[9]={0};
        for(int i=0;i<n;i++)
        {
            cin >> p >> s;
            if(p!=9 || p!=10 || p!=11)
                maximum[p] = max(maximum[p],s);
        }

        int sum=0;
        for(int i=1;i<=8;i++)
            sum+=maximum[i];

        cout << sum << endl;
    }
    return 0;
}