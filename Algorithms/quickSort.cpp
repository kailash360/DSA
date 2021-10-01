//Quick Sort
#include<iostream>
using namespace std;

//In quick sort, we first select a pivot element
//we place pivot at its correct position such that all elements
//to left of pivot are smaller than it and to the right are all 
//greater than pivot.

//basic function to swap 
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


int partition(int arr[], int l, int r){

    //initially taking last element as pivot
    int pivot = arr[r];
    int i=l-1;
    
    
    for(int j=l; j<r; j++){
        if(arr[j]<pivot){
                i++;
                swap(arr, i, j);
        }
    }
    //placing pivot at its right position
    swap(arr, i+1, r);
    return i+1;
}

void quickSort(int arr[], int l, int r){

    if(l<r){
        //calculating right position of pivot
        int pi = partition(arr, l, r);
        //sorting both parts separately
        //both on either side of pivot
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}

int main(){

    int arr[]={3,4,1,5,2};
    quickSort(arr, 0, 4);

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    //1 2 3 4 5

    return 0;

}