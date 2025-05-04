#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> & v){
    for(auto x : v) cout<<x<<" ";
    cout<<endl;
}

int main(){

    vector<int> v = {4,1,3,2,5};

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



    printArray(v);

    cout<<124/10 % 10;
    

    return 0;
}