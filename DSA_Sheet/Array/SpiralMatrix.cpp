#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{

    vector<int> spiral;

    int top = 0, btm = matrix.size() - 1, right = matrix[0].size() - 1, left = 0;

    int itr = 0;
    char mov = 'r';
    while(itr < matrix.size() * matrix[0].size()){
        
        if(mov == 'r'){

        for(int i = left; i <= right; i++){
            spiral.push_back(matrix[top][i]);
            itr++;
        }
        top++;
        mov = 'b';
        }
        else if(mov == 'b'){
            for (int i = top; i <= btm; i++)
            {
                spiral.push_back(matrix[i][right]);
                itr++;
            }
            right--;
            mov = 'l';
        }
        else if(mov == 'l'){
            for (int i = right; i >= left; i--)
            {
                spiral.push_back(matrix[btm][i]);
                itr++;
            }
            btm--;
            mov = 't';
        }
        else{
            for (int i = btm; i >= top; i--)
            {
                spiral.push_back(matrix[i][left]);
                itr++;
            }
            left++;
            mov = 'r';
        }
    }

    return spiral;
}

int main(){

    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}, {17,18,19,20}, {21,22,23,24}};

    vector<int> res = spiralOrder(matrix);

    for(int i = 0; i < res.size(); i++){
         cout<<res[i]<<" ";
    }

        return 0;
}