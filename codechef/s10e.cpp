#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int arr[n+5];
		arr[0]=arr[1]=arr[2]=arr[3]=arr[4]=arr[5]=-1;
        for(int i=5;i<n+5;i++)
            cin >> arr[i];
		int c=0;
		for(int i=5;i<n+5;i++)
		{
			int count=0;
			for(int j=i-5;j<i;j++)
			{
				if(arr[j]>arr[i] || arr[j]==-1 )
				{
					count++;
				}
			}
			if(count==5)
				c++;
		}
		cout<<c<<endl;
	}
	return 0;
}
