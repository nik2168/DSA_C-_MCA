#include<iostream>
#include<string>
using namespace std;

int main() {

string s = "Nik";
int count = 0;

for(int i = 0; i < s.size(); i++){
    count++;
}

cout<<"length of string : "<<count<<endl;

    return 0;
}

// output
// length of string : 3