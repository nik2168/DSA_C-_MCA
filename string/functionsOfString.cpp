#include<iostream>
#include<vector>
using namespace std;


class String{

    vector<char> c;

    public:

    void pushBack(char val){
        c.push_back(val);
    }

    void pop_back(){
        c.pop_back();
    }

    void concat(string str){
        for(auto x : str){
           c.push_back(x);
        }
    }

    String substr(int st, int end){
         String res;
         for(int i = st; i <= end; i++){
            res.pushBack(c[i]);
         }

         return res;
    }

    void print(){
        for(int i = 0; i < c.size(); i++){
            cout<<c[i];
        }
        cout<<endl;
    }

    int sizeOfStirng(){
        return c.size();
    }

};

int main() {

String s;

s.pushBack('N');
s.pushBack('i');
s.pushBack('k');

s.concat("hil");

cout<<"Size : "<<s.sizeOfStirng()<<endl;
String res = s.substr(1, 3);
cout<<"Substring : ";
res.print();
s.print();

    return 0;
}


// output
// Size : 6
// Substring : ikh
// Nikhil