#include<iostream>
#include<vector>
using namespace std;


int counter = 0;

void printArr(vector<int> & v){
    if(v.size() <=0) cout<<"empty"<<endl;
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
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
