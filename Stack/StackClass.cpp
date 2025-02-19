#include<iostream>
#include<vector>
using namespace std;

class Stack{
public:

vector<int> s;
int size;

Stack(int size){
    this->size = size;
}

void push(int val){
    if(s.size() >= size){
        cout<<"Overflow"<<endl;
        return;
    }
 s.push_back(val);
 return;
}

void pop(){
    if(s.size() == 0){
        cout<<"Underflow"<<endl;
        return;
    }
 s.pop_back();
 return;
}

int top(){
 return s[s.size() - 1];
}

};

int main(){

    int n;
    cin>>n;


 Stack s(4);

for(int i = 0; i < n; i--){
    int val;
    cin>>val;
    s.pushBack(val);
}

 cout<<s.top()<<endl;

 s.pop();

 cout<<s.top()<<endl;

    return 0;
}

// output 
// Overflow 3 3