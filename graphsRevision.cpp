#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<unordered_set>
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


void bfs(){
    queue<int> q;
    unordered_set<int> s;
    
    q.push(0);
    s.insert(0);

    cout<<endl;
    cout<<"BFS : "<<endl;

    while(!q.empty()){
        int ele = q.front();
        cout<<ele<<" ";
        q.pop();
        s.insert(ele);
        
        for(auto x : graph[ele]){
           if(s.find(x) == s.end()) {
            q.push(x);
            s.insert(x);
           }
        }

    }
    cout<<endl;
}

void dfs(){
    stack<int> q;
    unordered_set<int> s;

    q.push(0);
    s.insert(0);

    cout << endl;
    cout << "DFS : " << endl;

    while (!q.empty())
    {
        int ele = q.top();
        cout << ele << " ";
        q.pop();
        s.insert(ele);

        for (auto x : graph[ele])
        {
            if (s.find(x) == s.end())
            {
                q.push(x);
                s.insert(x);
            }
        }
    }
    cout<<endl;
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

    bfs();
    dfs();

    return 0;
}

// input
// 3
// 3
// 0 1
// 0 2
// 1 2

// output
// Adjacency List : 
// 0 ->1 ->2 
// 1 ->2 
// 2 

// Adjacency Matrix : 
// 0 1 1 
// 0 0 1 
// 0 0 0 

// BFS : 
// 0 1 2 

// DFS : 
// 0 2 1 % 