#include<iostream>
#include<vector>
using namespace std;



int merge(vector<int> &arr, int l, int m, int r)
{
    vector<int> temp;
    int count = 0;
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
            count += m - left + 1;
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
    return count;
}
int mergeSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return 0;
    int m = (l + r) / 2;
    int first = mergeSort(arr, l, m);
    int second = mergeSort(arr, m + 1, r);
    int final = merge(arr, l, m, r);
    return first + second + final;
}


int main(){

    vector<int> arr = {5,2,1,7,8};

    cout<<"Count : "<<mergeSort(arr, 0, arr.size() - 1);

    return 0;
}