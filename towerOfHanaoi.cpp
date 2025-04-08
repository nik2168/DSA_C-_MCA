#include<iostream>
using namespace std;

void helper(int n, int a, int b, int c){
    if(n < 0) return;

    helper(n - 1, a, c, b);
    cout<<"Move a Disc from "<<a<<" to "<<c<<endl;
    helper(n - 1, b, a, c);

}

int main(){

   int n = 2;
   int a = 1, b = 2, c = 3;

    helper(n, a, b, c);

    return 0;
}

// output
// Move a Disc from 1 to 3
// Move a Disc from 1 to 2
// Move a Disc from 3 to 2
// Move a Disc from 1 to 3
// Move a Disc from 2 to 1
// Move a Disc from 2 to 3
// Move a Disc from 1 to 3