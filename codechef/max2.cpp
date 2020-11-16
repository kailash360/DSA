#include <iostream>
using namespace std;
int main()
{
     int n=0;
     cin>>n;
     char x[n];
     cin>>x;
     int count=0;
     for(int i=n-1;i>=0;i--)
     {
         if(x[i]=='1')
            break;
        else
        {
            count++;
        }
        
     }
     cout<<count<<endl;
     return 0;
    
}