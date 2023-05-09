#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void insert(vector<int>& arr, int n, int key)
{
    // base case
    if (n == 0 || arr[n-1] <= key) {
        arr[n] = key;
        return;
    }

    // recursively move larger elements one position to the right
    insert(arr, n-1, key);
    arr[n] = arr[n-1];
}

void recursiveInsertionSort(vector<int>& arr, int n)
{
    // base case
    if (n <= 1)
        return;

    // sort first n-1 elements recursively
    recursiveInsertionSort(arr, n-1);

    // insert last element at its correct position
    int key = arr[n-1];
    insert(arr, n-1, key);
}


int main() {
    // Example usage
    vector<int> arr = {5, 2, 8, 4, 1};

    // Call insertion sort function
    insertionSort(arr);

    // Print sorted vector
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
