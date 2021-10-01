#include <iostream>
using namespace std;

// Binary search function
int BINARY_SEARCH(int arr[],int size,int num) {

    int low = 0;
    int high = size - 1;
    while (high >= low) {
        // Calculating the new mid element after every iteration
        int mid = (low + high) / 2;
        if (arr[mid] == num) {
            // Found element
            return mid;
        }else if (num > arr[mid]) {
            // Choose right array
            low = mid + 1;
        }else {
            // Choose left array
            high = mid - 1;
        }
    }
    return -1;
}

// Driver code
int main() {

    int arr[] = {2,4,8,12,15,18,21,25,27,29};
    int num = 18;
    int size = sizeof(arr) / sizeof(*arr);
    cout << BINARY_SEARCH(arr,size,num);
    return 0;
}