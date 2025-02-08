# Comprehensive Guide to Sorting Algorithms in C++

## 1. Bubble Sort

### Step-by-Step Explanation
1. **Outer Loop**: Iterates n-1 times (where n is array length)
2. **Inner Loop**: Compares adjacent elements
3. **Swapping**: If left element > right element, swap them
4. **Optimization**: Early termination if no swaps needed
5. **Completion**: Largest element "bubbles up" in each iteration

```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        // Last i elements are already in place
        for (int j = 0; j < n-i-1; j++) {
            // Compare adjacent elements
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        // If no swapping occurred, array is sorted
        if (!swapped) break;
    }
}


Time & Space Analysis
Time Complexity: O(n²) worst/average, O(n) best
Space Complexity: O(1)
Stability: Stable
In-Place: Yes

2. Selection Sort
### Step-by-Step Explanation
1. **Divide**: Split the array into sorted and unsorted regions.
2. **Find Minimum**: Locate the smallest element in the unsorted region.
3. **Swap**: Place the minimum element at the beginning of the unsorted region.
4. **Update Boundary**: Move the sorted/unsorted boundary to the right.
5. **Repeat**: Continue until the entire array is sorted.

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        // Find minimum element in unsorted array
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap found minimum with first element
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}


Time & Space Analysis
Time Complexity: O(n²) all cases
Space Complexity: O(1)
Stability: Not stable
In-Place: Yes

3. Insertion Sort

### Step-by-Step Explanation

1. **Start**: Begin with second element
2. **Key Selection**: Pick current element as key
3. **Comparison**: Compare key with previous elements
4. **Shifting**: Shift greater elements right
5. **Insertion**: Place key in correct position

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements greater than key
        // to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


Time & Space Analysis
Time Complexity: O(n²) worst/average, O(n) best
Space Complexity: O(1)
Stability: Stable
In-Place: Yes

4. Merge Sort
### Step-by-Step Explanation

1. **Divide**: Split array into two halves
2. **Recursion**: Sort both halves recursively
3. **Merge**: Combine sorted halves
4. **Compare**: Pick smaller elements first
5. **Copy**: Transfer merged elements back

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temp arrays
    vector<int> L(n1), R(n2);
    
    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
        
    // Merge temp arrays back
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


Time & Space Analysis
Time Complexity: O(n log n) all cases
Space Complexity: O(n)
Stability: Stable
In-Place: No

5. Quick Sort

1. **Pivot Selection**: Choose pivot element
2. **Partitioning**: Arrange elements around pivot
3. **Recursion**: Sort sub-arrays independently
4. **Combine**: No explicit combination needed
5. **Optimization**: Various pivot selection strategies

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


Time & Space Analysis
Time Complexity: O(n log n) average, O(n²) worst
Space Complexity: O(log n)
Stability: Not stable
In-Place: Yes

6. Heap Sort
### Step-by-Step Explanation

1. **Build Heap**: Create max heap from array
2. **Extract Max**: Remove root element
3. **Restructure**: Maintain heap property
4. **Repeat**: Continue until heap is empty
5. **In-Place**: Store sorted elements at end

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
        
    if (right < n && arr[right] > arr[largest])
        largest = right;
        
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
        
    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


Time & Space Analysis
Time Complexity: O(n log n) all cases
Space Complexity: O(1)
Stability: Not stable
In-Place: Yes
Usage Example

#include <iostream>
using namespace std;

// Helper function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    // Choose any sorting algorithm
    heapSort(arr, n);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}


Algorithm Selection Guide
==========================

Use Bubble Sort when:

*   Array is nearly sorted
*   Simplicity is preferred
*   Space is a constraint

Use Selection Sort when:

*   Array size is small
*   Memory writes are expensive

Use Insertion Sort when:

*   Array is nearly sorted
*   Online sorting needed
*   Small dataset

Use Merge Sort when:

*   Stable sorting required
*   O(n log n) guaranteed
*   External sorting

Use Quick Sort when:

*   Average case performance critical
*   In-place sorting needed
*   Cache performance important

Use Heap Sort when:

*   O(n log n) worst-case needed
*   Space is a constraint
*   Partial sorting needed

