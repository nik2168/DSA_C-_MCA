#include<iostream>
#include<vector>
using namespace std;

int main(){

vector<vector<int>> a = {{1,2}, {3,4}};
vector<vector<int>> b = {{5,6}, {7,8}};

vector<vector<int>>result(2, vector<int>(2, 0));

for(int i = 0; i < a.size(); i++){
    for(int j = 0; j < a.size(); j++){
        result[i][j] = a[i][j] + b[i][j];
    }
}

for(int i = 0; i < a.size(); i++){
    for(int j = 0; j < a.size(); j++){
        cout<<result[i][j]<<" ";
    }
    cout<<endl;
}

    return 0;
}

// output
// 6 8 
// 10 12 