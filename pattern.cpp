#include<iostream>
#include<vector>
using namespace std;

int main(){

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < (8-i); j++){
           cout<<" "; 
        }
        for(int j = 0; j < (2 * i) - 1; j++){
            cout<<char(j+65);
        }
        cout<<endl;
    }
    for(int i = 6; i > 0; i--){
        for(int j = 0; j < (8-i); j++){
           cout<<" "; 
        }
        for(int j = 0; j < (2 * i) - 1; j++){
            cout<<char(j+65);
        }
        cout<<endl;
    }

    // cout<<char(65);

    return 0;
}