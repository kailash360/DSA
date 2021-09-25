#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,x;
		cin >> n;
		int odd = 0,even=0;
		for(int i=0;i<n;i++){
			cin >> x;
			if(x%2 == 0) even++;
			else odd++;
		}
		
		if(odd%2 == 1){
			cout << "2"<<endl;
		}
		else
			cout << "1"<<endl;
	}
	
	return 0;
}