#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printArray(const vector<string>& arr) {
    for (const auto &s : arr)
        cout << s << " ";
    cout << "\n";
}

void merge(vector<string>& arr, int low, int mid, int high) {
    cout << "Merging: low = " << low << ", mid = " << mid << ", high = " << high << "\n";
    int i = low, j = mid + 1;
    vector<string> temp;
    
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= high) {
        temp.push_back(arr[j]);
        j++;
    }
    
    // Copy the merged elements back to original array
    for (int k = low; k <= high; k++) {
        arr[k] = temp[k - low];
    }
    
    cout << "After merge: ";
    printArray(arr);
}

void mergeSort(vector<string>& arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        cout << "\nSplitting: low = " << low << ", mid = " << mid << ", high = " << high << "\n";
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    vector<string> arr = {"Cat", "Bit", "Hat", "Mat", "Rat", "Bat", "Hot", "Bot", "Sit"};
    
    cout << "Original Array: ";
    printArray(arr);
    
    mergeSort(arr, 0, arr.size() - 1);
    
    cout << "\nSorted Array: ";
    printArray(arr);
    
    // Complexity Analysis:
    cout << "\nTime Complexity: O(n log n)\n";
    cout << "Space Complexity: O(n) due to temporary arrays used in merging.\n";
    
    return 0;
}
