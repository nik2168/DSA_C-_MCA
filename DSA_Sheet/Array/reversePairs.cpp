#include <iostream>
#include <vector>
using namespace std;

int counter;
void merge(vector<int> &arr, int l, int m, int r)
{
    vector<int> temp;
    int left = l;
    int right = m + 1;

    while (left <= m && right <= r)
    {

        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= m)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= r)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i - l];
    }

    return;
}

void countPairs(vector<int> &arr, int s, int mid, int e)
{
    int right = mid + 1;
    for (int i = s; i <= mid; i++)
    {
cout << arr[i] << " " << arr[right] << endl;

        while (right <= e && arr[i] > (long long)2 * arr[right])
            right++;
        counter += (right - (mid + 1));
    }
}


void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r){
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    countPairs(arr, l, m, r);
    merge(arr, l, m, r);
    }
}

int main()
{

    counter = 0;
    // vector<int> arr = {5, 4, 3, 2, 1};
    vector<int> arr = {2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647};

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Count : " << counter <<endl;

        return 0;
}