#include<iostream>
#include<vector>
using namespace std;

class Stack{
public:

vector<int> s;


void push(int val){
 s.push_back(val);
 return;
}

void pop(){
 s.pop_back();
 return;
}

int top(){
 return s[s.size() - 1];
}

};

int main(){

 Stack s;

 s.push(1);
 s.push(2);
 s.push(3);

 cout<<s.top()<<endl;

 s.pop();

 cout<<s.top()<<endl;

    return 0;
}