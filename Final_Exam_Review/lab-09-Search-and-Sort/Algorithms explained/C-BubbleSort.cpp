#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr);
std::vector<int> nums = {3,8,7,9,5,1,2,4};
int main(){
    for(int num :nums){
        std::cout << num << " ";
    }
     std::cout << "\n";
    bubbleSort(nums);
    
      for(int num :nums){
        std::cout << num  << " ";
    }
    return -1;
}


void bubbleSort(std::vector<int>& arr){
    for(int i = 0; i < arr.size() - 1; i++){
        for(int j = 0; j < arr.size()-i-1;j++){
            if(arr[j] > arr[j + 1]){
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// temp = a;
//     a = b;
//     b = temp;

















// void bubbleSort(std::vector<int>& arr) {
//     int n = arr.size();

//     for (int i = 0; i < n-1; i++) {
//         for (int j = 0; j < n-i-1; j++) {
//             if (arr[j] > arr[j+1]) {
//                 // Swap elements
//                 std::swap(arr[j] ,arr[j+1]);
    
//             }
//         }
//     }
// }
void RecursivebubbleSort(std::vector<int>& arr, int n) {
    // Base case: return if array is empty or has only one element
    if (n <= 1) {
        return;
    }

    // One pass through the array
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1]) {
            // Swap elements
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }

    // Recursively sort the remaining (n-1) elements
    RecursivebubbleSort(arr, n-1);
}