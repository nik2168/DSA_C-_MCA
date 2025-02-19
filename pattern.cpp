#include<iostream>
#include<vector>
using namespace std;

int main(){

    int i = 4;
    int j = 4;
    int n = 8;

    while(i >= 0 && j < 8){
        // cout<<i<<" "<<j<<endl;
        for(int k = 0; k < n; k++){
    
            if(i == 1 && j == n - 1){
                cout<<"* ";
            }
            else if(k == i || k == j){
                cout<<"*";
            }
            else {
                cout<<" ";
            }
        }
        cout<<endl;
        i--;
        j++;
    }

    return 0;
}