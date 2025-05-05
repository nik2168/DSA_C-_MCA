#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<int>> graph;
vector<vector<int>> matrix;

void getEdge(int a, int b, bool flag = false){
    graph[a].push_back(b);
    matrix[a][b] = 1;

    if(flag) {
        graph[b].push_back(a);
        matrix[b][a] = 1;
    }
}



void printGraph(){

    cout<<"Adjacency List : "<<endl;
    for(int i = 0; i < graph.size(); i++){
        cout<<i<<" ";
        for(auto x : graph[i]){
            cout<<"->"<<x<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"Adjacency Matrix : "<<endl;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    
    graph.resize(n, list<int> ());
    matrix.resize(n, vector<int> (n, 0));

    int e;
    cin>>e;

    while(e--){
      int m, n;
      cin>>m;
      cin>>n;

      getEdge(m, n);

    }

    printGraph();

    return 0;
}