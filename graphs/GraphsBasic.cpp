#include<iostream>
#include<list>
using namespace std;

vector<list<int>> graph;

void addEdge(int a, int b, bool flag = false){
   graph[a].push_back(b);
   if(flag) graph[b].push_back(a);
}

void printGraph(){

    for(int i = 0; i < graph.size(); i++){
        cout<<i<<" : ";
        for(int j : graph[i]){
            cout<<j<<"->";
        }
        cout<<"NULL"<<endl;
    }
}


int main(){

    int n;
    cin>>n;

    graph.resize(n, list<int>());

    while(n--){
     int val1, val2;
     cin>>val1;
     cin>>val2;

     addEdge(val1, val2);
    }

    printGraph();

    return 0;
}