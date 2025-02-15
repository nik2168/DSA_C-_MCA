#include <iostream>
#include <vector>
using namespace std;

// Insertion sort
// Insertion sort is a simple sorting algorithm that works by iterating over the array one element at a time, inserting each element into its proper position in the sorted portion of the array. It is an in-place sorting algorithm, meaning that it only requires a single additional memory space to perform the sort. It is also a comparison-based sorting algorithm, meaning that it uses comparisons to determine the order of the elements.

int main()
{

    int arr[] = {5, 2, 8, 3, 1, 6, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < n; i++)
    {
        int take = arr[i];  // will take one element at a time
        int j = i - 1;

        for (; j >= 0; j--)
        {
            if (arr[j] < take)
            {
                break;
            }
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = take; // will put the element in its right position
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// output 1 2 3 4 5 6 8 