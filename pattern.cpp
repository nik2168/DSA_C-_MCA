#include<iostream>
#include<vector>
using namespace std;

// // Function to return precedence of operators
// int prec(char c)
// {
//     if (c == '^')
//         return 3;
//     else if (c == '/' || c == '*')
//         return 2;
//     else if (c == '+' || c == '-')
//         return 1;
//     else
//         return -1;
// }

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
        prec('^');
    }

    

    // cout<<char(65);

    return 0;
}