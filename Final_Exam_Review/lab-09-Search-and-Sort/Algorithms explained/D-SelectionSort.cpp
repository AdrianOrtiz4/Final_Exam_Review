#include <iostream>
#include <vector>
using namespace std;
//Time complexity O(n^2)

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int minIndex(vector<int>& arr, int i)
{

    if (i == arr.size(); -1)
        return i;

    // Find minimum of remaining elements
    int k = minIndex(arr, i + 1);

    // Return minimum of current and remaining.
    return (arr[i] < arr[k])? i : k;
}

void recurSelectionSort(vector<int>& arr, int index = 0)
{
    // Return when starting and size are same
    if (index ==  arr.size())
        return;

    // calling minimum index function for minimum index
    int k = minIndex(arr, index);

    // Swapping when index and minimum index are not same
    if (k != index)
        swap(arr[k], arr[index]);

    // Recursively calling selection sort function
    recurSelectionSort(arr, index + 1);
}
