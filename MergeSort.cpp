#include<iostream>
using namespace std;

void Merge(int *arr, int l, int m, int r) {
    // Creating temporary arrays
    int *leftArray = new int[m-l+1];
    int *rightArray = new int[r-m]; 
    
    // Copying elements to temporary arrays
    for (int i = 0; i < m-l+1; i++) {
        leftArray[i] = arr[l+i]; 
    }
    for (int i = 0; i < r-m; i++) {
        rightArray[i] = arr[m+1+i]; 
    }

    // Merging
    int l_idx = 0, r_idx = 0, idx = l;
    while(l_idx < m-l+1 && r_idx < r-m) {
        if(leftArray[l_idx] <= rightArray[r_idx]) {
            arr[idx] = leftArray[l_idx];
            l_idx++;
        } else {
            arr[idx] = rightArray[r_idx];
            r_idx++;
        }
        idx++;
    }
    // Copying remaining elements
    while(l_idx < m-l+1) {
        arr[idx] = leftArray[l_idx];
        idx++;
        l_idx++;
    }
    while(r_idx < r-m) {
        arr[idx] = rightArray[r_idx];
        idx++;
        r_idx++;
    }
}

void MergeSort(int *arr, int l, int r) {
    if(l >= r) {
        return;
    }
    int m = l + (r - l)/2;
    MergeSort(arr, l, m);
    MergeSort(arr, m+1, r);
    Merge(arr, l, m, r);
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

    MergeSort(arr, 0, n-1);

    // Printing answer
    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}