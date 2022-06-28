#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
	int i = low;
	int j = high;
	int pivot = arr[low];
	while (i < j) {
		while (pivot >= arr[i])
			i++;
		while (pivot < arr[j])
			j--;
		if (i < j)
			swap(arr[i], arr[j]);
	}
	swap(arr[low], arr[j]);
	return j;
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

int main()
{
    int n;
    cout << "Enter the size of Array: ";
    cin >> n;
    int *arr = new int[n];
    // Array input
    cout << "Enter elements of Array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);

    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
	return 0;
}
