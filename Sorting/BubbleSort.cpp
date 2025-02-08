#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int arr[] = {2, 4, 1, 3, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arrSize; i++)
    {
        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }

    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// g++ -o program main.cpp
// ./program