#include <vector>
#include <iostream>

using namespace std;

// Function to multiply two matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();
    
    // Initialize result matrix with zeros
    vector<vector<int>> result(rowsA, vector<int>(colsB, 0));
    
    // Perform matrix multiplication
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return result;
}

int main() {
    // Example matrices
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    vector<vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    
    vector<vector<int>> C = multiplyMatrices(A, B);
    
    // Print result
    for (const auto& row : C) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

