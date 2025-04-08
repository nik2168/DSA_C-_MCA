#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v = {5, 2, 3, 2, 1};

    vector<int> freq(6, 0);


    // freq array
    for(int i  = 0; i < v.size(); i++){
           freq[v[i]]++;
    }

    // we are not sorting directly to maintain its stable sort nature 

    // stable sort - every ele in its og order even after sorting

    // commulative freq array
    for(int i = 1; i < freq.size(); i++){
        freq[i] += freq[i - 1];
    }

    vector<int> res(v.size());

    // taking ref of 
    for(int i = v.size() - 1; i >= 0; i--){
        res[--freq[v[i]]] = v[i];
    }


    for(auto x : res) cout<<x<<" ";

    return 0;
}