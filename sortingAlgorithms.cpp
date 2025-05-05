#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &v)
{
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

// 4 1 3 2 5
void mergeHelper(int l, int h, int mid, vector<int> &v)
{
    vector<int> v1(mid - l + 1);
    vector<int> v2(h - mid);

    for (int i = 0; i < v1.size(); i++)
    {
        v1[i] = v[l + i];
    }

    for (int i = 0; i < v2.size(); i++)
    {
        v2[i] = v[mid + i + 1];
    }

    printArray(v1);
    printArray(v2);
    int i = 0;
    int j = 0;
    int k = l;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] > v2[j])
            v[k++] = v2[j++];
        else
            v[k++] = v1[i++];
    }

    while (i < v1.size())
        v[k++] = v1[i++];

    while (j < v2.size())
        v[k++] = v2[j++];
}

void mergeSort(int i, int j, vector<int> &v)
{
    if (i >= j)
        return;

    int mid = i + (j - i) / 2;

    mergeSort(i, mid, v);
    mergeSort(mid + 1, j, v);

    mergeHelper(i, j, mid, v);
}

int quickHelper(int l, int h, vector<int> & v){
    int pivot = v[h];

    int i = l - 1;
    
    for(int j = l; j < h; j++){
       if(v[j] < pivot){
        swap(v[j], v[++i]);
       }
    }

    swap(v[++i], v[h]);

    return i;
}

    void
    quickSort(int i, int j, vector<int> &v)
{
    if(i >= j) return;

    int p = quickHelper(i, j, v);

    quickSort(i, p - 1, v);
    quickSort(p + 1, j, v);
}

int main()
{

    vector<int> v = {4, 1, 5, 2, 3};

    // quickSort(0, v.size() - 1, v);

    // mergeSort(0, v.size() - 1, v);

    // bubble sort -> compare two and push the largest ele at the end on each iteration
    // for(int i = 0; i < v.size() - 1; i++){
    //         bool flag = false;
    //     for(int j = i + 1; j < v.size(); j++){
    //       if(v[i] > v[j]) {
    //         swap(v[i], v[j]);
    //         flag = true;
    //       }
    //     }
    //     if(!flag) break;
    // }

    // selection sort -> find the smallest element and swap it with the first on each iterations
    // for(int i = 0; i < v.size(); i++){
    //     int minIdx = i;
    //     for(int j = i + 1; j < v.size(); j++){
    //         if(v[j] < v[minIdx]) minIdx =  j;
    //     }
    //     swap(v[minIdx], v[i]);
    // }

    // insertition sort -> put each element in the sorted part of the array starting with size 1
    // for(int i = 1; i < v.size(); i++){
    //       int cur = v[i];
    //       int pre = i - 1;

    //       while( pre >= 0 && v[pre] > cur ){
    //         v[pre + 1] = v[pre];
    //         pre--;
    //       }

    //       v[pre + 1] = cur;
    // }

    // Bubble Sort: Best: O(n), Average: O(n²), Worst: O(n²)
// Selection Sort: Best: O(n²), Average: O(n²), Worst: O(n²)
// Insertion Sort: Best: O(n), Average: O(n²), Worst: O(n²)
// Merge Sort: Best: O(n log n), Average: O(n log n), Worst: O(n log n)
// Quick Sort: Best: O(n log n), Average: O(n log n), Worst: O(n²)
// Heap Sort: Best: O(n log n), Average: O(n log n), Worst: O(n log n)
// Radix Sort: Best: O(nk), Average: O(nk), Worst: O(nk)
// n = number of elements, k = number of digits in the radix sort
    printArray(v);

    return 0;
}