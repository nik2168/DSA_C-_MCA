#include<iostream>
#include<vector>
using namespace std;

// int arr[] = {5, 9, 2, 1, 4, 8, 3};

void helper(int arr[], int i, int mid, int n){
   
    int n1 = mid - i; // 3
    int n2 = n - mid; // 3

    vector<int>v1;
    vector<int> v2;

    for(int j = i; j < n1; j++){
        v1.push_back(arr[j]);
    }

    for(int j = n2; j <= n; j++){
        v2.push_back(arr[j]);
    }


    cout<<n1<<" "<<n2<<endl;

    for(int j = 0; j < v1.size(); j++){
        cout<<v1[j]<<" ";
    }

    cout<<endl;

    for(int j = 0; j < v2.size(); j++){
        cout<<v2[j]<<" ";
    }

    cout<<endl;

    // merge both array

    int l = 0, j = 0, k = i;

    while(l < v1.size() && j < v2.size()){
        if(v1[l] < v2[j])   arr[k] = v1[l++];
        else arr[k] = v2[j++];
        k++;
    }

    while(l < v1.size())     arr[k++] = v1[l++]; 
    while(j < v2.size())     arr[k++] = v2[j++]; 
}

void mergeSort(int arr[], int i, int n){

    int mid = i + (n - i)/2;
    
    mergeSort(arr, 0, mid);
    mergeSort(arr, mid, n);
    
    helper(arr, i, mid, n);

    return; 
}

int main(){

    int arr[] = {5, 9, 2, 1, 4, 8, 3};

    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}