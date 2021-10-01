//Count Sort
#include<iostream>
#include<algorithm>
using namespace std;

void countSort(int arr[], int n){

    //find the max element
    int k=arr[0];
    for(int i=0;i<n;i++){
        k=max(k, arr[i]);
    }
    //store count of each element
    int count[10]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    //store cumulative count
    for(int i=1;i<=k;i++){
        count[i]+=count[i-1];
    }

    int output[n];
    //find index of element of original array in count array
    //and add it in output array
    for(int i=n-1;i>=0;i--){
        output[--count[arr[i]]]=arr[i];
    }
    //updating original array
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

int main(){

    int arr[]={3,4,1,5,2};
    countSort(arr, 5);

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    //1 2 3 4 5

    return 0;

}