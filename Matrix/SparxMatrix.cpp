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

    vector<vector<int>>sparx(4, vector<int>(k, 0));

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(v[i][j] != 0){
            sparx[i][0] = i;
            sparx[i][1] = j;
            sparx[i][2] = v[i][j];
            }
        }
    }

    sparx[3][0] = v.size();
    sparx[3][1] = v[0].size();
    sparx[3][2] = k;

    cout<<"Sparx Matrix is : "<<endl;

    for(int i = 0; i < sparx.size(); i++){
        for(int j = 0; j < sparx[i].size(); j++){
            cout<<sparx[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}

