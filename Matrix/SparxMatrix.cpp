// g++ -o test code.cpp
// ./test

#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<vector<int>>v(3, vector<int>(3, 0));

        int k = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin>>v[i][j];
            if(v[i][j] > 0) k++;
        }
    }

    vector<vector<int>>sparx(k + 1, vector<int>(3, 0));

    int t = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(v[i][j] != 0){
            sparx[t][0] = i;
            sparx[t][1] = j;
            sparx[t][2] = v[i][j];
            t++;
            }
        }
    }

    sparx[t][0] = v.size();
    sparx[t][1] = v[0].size();
    sparx[t][2] = k;

    cout<<"Sparx Matrix is : "<<endl;

    for(int i = 0; i < sparx.size(); i++){
        for(int j = 0; j < sparx[i].size(); j++){
            cout<<sparx[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}

// output
// 0 1 3
// 0 0 2
// 0 3 0

// Sparx Matrix is : 
// 0 1 1 
// 0 2 3 
// 1 2 2 
// 2 1 3 
// 3 3 4 