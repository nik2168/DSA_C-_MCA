#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int arr[] = {2, 4, 1, 3, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arrSize; i++)
    {
        bool isSwap = false; // optimize buuble sort

        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[i] > arr[j]) // just check the adjecent ele and swap if one is smaller then other
            {
                swap(arr[i], arr[j]);
                isSwap = true;
            }
        }

        if (!isSwap)  break;

    }

    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// g++ -o program main.cpp
// ./program

// output
// 1 2 3 4 5