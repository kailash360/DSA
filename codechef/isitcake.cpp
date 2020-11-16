#include <iostream>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
     while(t--)
    {
        int n[10][10];
        int count=0;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
                cin>>n[i][j];
            
        }
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
                {
                    if(n[i][j]<=30)
                        count++;
                }
        }
        if(count>=60)
            cout<<"yes"<<endl;
        else
        {
            cout<<"no"<<endl;
        }
        
    }
    return 0;
}