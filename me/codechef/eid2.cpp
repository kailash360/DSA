#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
       int a[3],c[3];
       cin>>a[0]>>a[1]>>a[2]>>c[0]>>c[1]>>c[2];
        pair<int, int> pairt[3]; 
  
     
    for (int i = 0; i < 3; i++)  
    { 
        pairt[i].first = a[i]; 
        pairt[i].second = c[i]; 
    } 
  
    
    sort(pairt, pairt + 3); 
      
    
    for (int i = 0; i < 3; i++)  
    { 
        a[i] = pairt[i].first; 
        c[i] = pairt[i].second; 
    }

    int flag=0;
    for(int i=0;i<2;i++)
    {
        if((a[i]<a[i+1] && c[i]<c[i+1] || a[i]==a[i+1] && c[i]==c[i+1]))
            continue;
        else 
            {
                flag=1;
                break;
            }
    }
    if(flag==1)
        cout<<"NOT FAIR"<<endl;
    else
    {
        cout<<"FAIR"<<endl;
    }
    
    }
    return 0;
}
    