#include <iostream>
using namespace std;

// Bubble sort function
void BUBBLE_SORT(int arr[],int size) {

    for (int i = 0;i < size - 1;i++) {
        bool swapped = false; // Flag used to modify the bubble sort to end early if sorted
        for (int j = 0;j < size - i - 1;j++) {
            // Check if previous element is greater than current element, if so, then swap till correct place
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

// Driver code
int main() {

    int arr[] = {2,4,8,12,15,18,21,25,27,29};
    int size = sizeof(arr) / sizeof(arr[0]);
    BUBBLE_SORT(arr,size);
    for (int i = 0;i < size;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}