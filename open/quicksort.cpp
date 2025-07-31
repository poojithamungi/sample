#include <iostream>
#include <vector>

using namespace std;

// Function to partition the array
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choosing the last element as pivot
    int i = low - 1;         // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);  // Swap smaller element to the left
        }
    }
    swap(arr[i + 1], arr[high]);  // Move pivot to correct position
    return i + 1;
}

// Recursive quicksort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partition index

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {8, 4, 1, 3, 9, 5, 2, 7, 6};

    cout << "Before sorting: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "After quick sort: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
