/**
 * @file binary_insertion_sort.cpp
 * @brief Implementation of binary insertion sort algorithm and self-test cases.
 */
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


/**
 * @brief Performs binary search to find the correct index for insertion in the sorted array.
 *
 * @param arr The array in which the element needs to be inserted.
 * @param lo The lower index bound for the binary search (inclusive).
 * @param hi The upper index bound for the binary search (exclusive).
 * @param ele The element to be inserted.
 * @return The index where 'ele' should be inserted in the sorted subarray.
 */

int binary_search(vector<int> &arr, int lo, int hi, int ele){
    while (lo + 1 < hi){
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] > ele){
            hi = mid;
        }
        else{
            lo = mid;
        }
    }
    return hi;
}

/**
 * @brief Binary Insertion Sort algorithm to sort the array in ascending order.
 *
 * @param n The size of the array.
 * @param arr The array to be sorted.
 */
void insertionSort(int n, vector<int> &arr){
    for(int i = 1; i < n; i++){
        int j = i;
        int ele = arr[j];
        int lo = -1; // invalid
        int hi = j; // valid
        int correct_index = binary_search(arr, lo, hi, ele);
        
        while (j > correct_index) {
            arr[j] = arr[j - 1];
            j--;
        }
        
        arr[correct_index] = ele;
    }
}

/**
 * @brief Function to display the elements of the array.
 *
 * @param arr The array to be displayed.
 */
void display(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 * @brief Self-test cases for binary insertion sort algorithm.
 */
void testBinaryInsertionSort() {
    // Test case 1
    vector<int> arr1 = {12, 11, 13, 5, 6};
    insertionSort(arr1.size(), arr1);
    assert(arr1 == vector<int>({5, 6, 11, 12, 13}));

    // Test case 2
    vector<int> arr2 = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(arr2.size(), arr2);
    assert(arr2 == vector<int>({11, 12, 22, 25, 34, 64, 90}));

    // Test case 3: Array already sorted
    vector<int> arr3 = {1, 2, 3, 4, 5};
    insertionSort(arr3.size(), arr3);
    assert(arr3 == vector<int>({1, 2, 3, 4, 5}));

    // Test case 4: Array in reverse order
    vector<int> arr4 = {5, 4, 3, 2, 1};
    insertionSort(arr4.size(), arr4);
    assert(arr4 == vector<int>({1, 2, 3, 4, 5}));

    // Test case 5: Array with duplicate elements
    vector<int> arr5 = {5, 2, 1, 4, 2, 3, 1, 4, 3, 5};
    insertionSort(arr5.size(), arr5);
    assert(arr5 == vector<int>({1, 1, 2, 2, 3, 3, 4, 4, 5, 5}));
}

/**
 * @brief Main function to run self-test cases for binary insertion sort.
 *
 * @return Integer indicating success (0).
 */
int main() {
    // Run the self-test cases
    testBinaryInsertionSort();

    cout << "All test cases passed successfully!" << endl;

    return 0;
}
