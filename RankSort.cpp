#include<iostream>
using namespace std;

void RankSort(int *arr, int n) {
    int *rank = new int[n];
    // Initilizing rank array to 0
    for(int i = 0; i < n; i++) {
        rank[i] = 0;
    }
    // Ranking the elements
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(arr[i] > arr[j]) {
                rank[i]++;
            } else {
                rank[j]++;
            }
        }
    }
    // Copying from arr to sortedArray according to rank
    int *sortedArray = new int[n];
    for(int i = 0; i < n; i++) {
        sortedArray[rank[i]-1] = arr[i];
    }
    // Printing sorted Array
    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++) {
        cout << sortedArray[i] << " ";
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

    RankSort(arr, n);

    return 0;
}