#include<iostream>
using namespace std;

void InsertionSort(int *arr,int n) {
    // Sorting
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    // Printing
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

    InsertionSort(arr, n);

    return 0;
}