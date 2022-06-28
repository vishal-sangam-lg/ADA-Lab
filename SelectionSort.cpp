#include<iostream>
using namespace std;

void SelectionSort(int *arr, int n) {
    // Sorting
    for(int i = 0; i < n-1; i++) {
        int min_idx = i;
        for(int j = i+1; j < n; j++) {
            if(arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
    // Printing Array
    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of Array: ";
    cin >> n;
    int *arr = new int[n];
    // Array input
    cout << "Enter elements of Array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SelectionSort(arr, n);

    return 0;
}