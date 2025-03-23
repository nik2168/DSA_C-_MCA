#include<iostream>
#include<vector>
using namespace std;

// rotate the matrix by 90 degree ...

    void rotate(vector<vector<int>>& matrix) {

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i; j < matrix[i].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            int x = 0;
            int y = matrix[i].size() - 1;

            while(x < y){
                swap(matrix[i][x++], matrix[i][y--]);
            }
        }

        return;
    }

int main(){

    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

    rotate(matrix);

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}