#include<iostream>
#include<vector>
using namespace std;

// int arr[] = {5, 9, 2, 1, 4, 8, 3};

int counter = 0;

void printArr(vector<int> & v){
    if(v.size() <=0) cout<<"empty"<<endl;
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    nt merge(vector<int>& arr, int l,int m, int r) {
         vector<int>temp;
         int count = 0;
         int left = l;
         int right = m+1;
          while(left<=m && right <= r){
              if(arr[left] <= arr[right]){
                  temp.push_back(arr[left]);
                  left++;
              }
              else{
                  temp.push_back( arr[right]);
                  right++;
                  count+= m-left+1;
              }
          }
          while(left<=m){
            temp.push_back(arr[left]);
            left++;  
          }
          while(right<=r){
            temp.push_back( arr[right]);
            right++;  
          }
          for(int i =l ; i<=r; i++){
              arr[i] = temp[i-l];
          }
          return count;
     }
int mergeSort(vector<int>& arr, int l, int r) {
        if(l>=r) return 0;
        int m = (l+r)/2;
        int first= mergeSort(arr, l , m);
        int second = mergeSort(arr , m+1, r);
        int final =  merge(arr, l , m , r);
        return first+second+final;
    }
     
class Solution {
  public:
    // Function to count inversions in the array.
    
    int inversionCount(vector<int> &arr) {
    return mergeSort(arr,0,arr.size()-1);
    }
};
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp arrays
    vector<int> L(n1), R(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int z = 0, v = 0;

    while(z < n1 && v < n2){
        if(L[z] < R[v]){
            z++;
        }
        else{
            counter += (n1-z);
            v++;
        }
    }

    // Merge temp arrays back
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int i, int n){

    if(i >= n) return;

    int mid = i + (n - i)/2;
    
    mergeSort(arr, i, mid);
    mergeSort(arr, mid + 1, n);
    
    merge(arr, i, mid, n);
    for(int x = 0; x < 5; x++) cout<<arr[x]<<" ";
    cout<<endl;

    return; 
}

int main(){

    // int arr[] = {2, 3, 4, 5, 6};
    int arr[] = {2, 4, 1, 3, 5};
    // int arr[] = {5, 9, 2, 1, 4, 8, 3};

    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    cout<<"Counter : "<<counter<<endl;

    return 0;
}

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

class Solution
{
public:
    // Function to count inversions in the array.

    int inversionCount(vector<int> &arr)
    {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};