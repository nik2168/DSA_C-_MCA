#include<iostream>
#include<vector>
using namespace std;
 
int main(){

    int arr[] = {4, 9, 2, 1, 3};

    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < n; i++){

        int min_idx = i;  // just assume first as the smallest ele

        for(int j = i + 1; j < n; j++){
          if(arr[min_idx] > arr[j]) min_idx = j;  // if first smallest is greator then someone update it
        }
        
        swap(arr[i], arr[min_idx]); // make sure the smallest in the array comest int he sorted portion
    }

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}

// output 1 2 3 4 9