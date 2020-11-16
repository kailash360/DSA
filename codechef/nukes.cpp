#include <iostream>
using namespace std;
int main()
{
	long long int A=0,N=0,K=0;
	cin>>A>>N>>K;
	int reactor[K];
	for(int i=0;i<K;i++)
	{
		reactor[i]=A%(N+1);
		A/=(N+1);
	}
	
	for(int i=0;i<K;i++)
	{
		cout<<reactor[i]<<"\t";
	}
	cout<<"\n";
	return 0;
}