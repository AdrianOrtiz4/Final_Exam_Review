#include <iostream>
#include <vector>
int RecursivebinarySearch(std::vector<int> arr, int l, int r, int x);
 
int BinarySearch(std::vector<int> v, int To_Find);

int main(){
    // Binary Search Time complexity O(log n)
    // best case O(1)  worst cast O(log n)
    std::vector<int> sorted;
    for (int i = 0; i <= 100; i++){
        sorted.push_back(i);
    }
    std::cout << RecursivebinarySearch(sorted, 0, sorted.size() - 1, 1000);
}


int RecursivebinarySearch(std::vector<int> arr, int l, int r, int x){
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return  RecursivebinarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return  RecursivebinarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}
 
int BinarySearch(std::vector<int> v, int To_Find)
{
    int lo = 0, hi = v.size() - 1;
    int mid;
    // This below check covers all cases , so need to check
    // for mid=lo-(hi-lo)/2
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (v[mid] < To_Find) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    if (v[lo] == To_Find) {
        std::cout << "Found"
             << " At Index " << lo << std::endl;
    }
    else if (v[hi] == To_Find) {
        std::cout << "Found"
             << " At Index " << hi <<std:: endl;
    }
    else {
        std::cout << "Not Found" << std::endl;
    }
};