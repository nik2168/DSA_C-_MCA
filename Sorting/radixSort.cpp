#include<iostream>
#include<vector>
using namespace std;


void countSort(vector<int> & v, int n, int pos){

    vector<int> freq(10, 0);

    for(int i = 0; i < v.size(); i++){
        freq[(v[i] / pos) % 10]++;
    }

    for(int i = 1; i < freq.size(); i++){
        freq[i] += freq[i - 1];
    }

    vector<int> ans(v.size());

    for(int i = v.size() - 1; i >= 0; i--){
        ans[--freq[(v[i] / pos) %10]] = v[i];
    }

    for(int i = 0; i < v.size(); i++){
        v[i] = ans[i];
    }
}

void radixSort(vector<int> & v, int n){

    int maxEle = INT_MIN;

    for(auto x : v) maxEle = max(maxEle, x);

    for(int pos = 1; maxEle/pos > 0; pos *= 10){
        countSort(v, n, pos);
    }

}


int main(){

    vector<int> v = {4,1,56,734,84};

    radixSort(v, v.size());

    for(auto x : v) cout<<x<<" ";

    return 0;
}

// output
// 1 4 56 84 734 %