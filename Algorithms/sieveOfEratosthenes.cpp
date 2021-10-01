//Sieve-of-eratosthenes
#include<iostream>
using namespace std;

void primeSieve(int n){

    //initialising a large array with all element as 0
    int prime[1000]={0};

    //traversing the sieve from 2 and marking if the
    //element is prime or not
    for(int i=2;i<=n;i++){
        //if curr ele is unmarked
        if(prime[i]==0){
            //marking all its multiple as non-prime
            //we start from i*i as any multiple less than this
            //would already been marked as non-prime earlier
            //ex: for 4 -> multiples 4x2, 4x3 marked already by 2 and 3 respectively
            for(int j=i*i;j<=n;j+=i){
                prime[j]=1;
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            cout<<i<<" ";
        }
    }
}

int main(){

    //finding prime numbers upto n
    int n;
    cin>>n;

    primeSieve(n);

    return 0;
}