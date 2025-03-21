#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


int main(){

  unordered_set<int> s;
s.insert(3);
s.insert(1);
  cout<<s.count(5);



    return 0;
}