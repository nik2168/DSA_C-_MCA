#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v = {3,6,7,8,2,10,5};

    int search;
    cout<<"Enter a element to search in array : ";
    cin>>search;
    
    bool flag = false;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == search) flag = true;
    }

    if(flag) cout<<"Element is present in the array !";
    else cout<<"Element is not present in the array !";

    return 0;
}

// output
// Enter a element to search in array : 3
// Element is present in the array !% 