#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<climits>
using namespace std;

vector<list<pair<long long int, long long int>>> graph;
void get_edge(int x, int y, int weight){
     graph[x].push_back(make_pair(y, weight));
     graph[y].push_back(make_pair(x, weight));
}

// void display(){
//     for(int i = 0; i < graph.size(); i++){
//         cout<<i<<" -> ";
//         for(auto x : graph[i]){
//             cout<<"("<<x.first<<","<<x.second<<")";
//         }
//         cout<<endl;
//     }
// }

// finder()

int finder(int n, int s){
    int ans = 0;
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> q;
    unordered_set<int>vis;
    vector<int> p(n + 1);
    unordered_map<int, int> m;
    for(int i = 1; i < n + 1; i++){
        m[i] = INT_MAX;
    }
    q.push(make_pair(0, s));
    while(!q.empty()){
        pair<int,int> cur = q.top();
        q.pop();
        if(vis.count(cur.second)){
          continue;
        } 
         ans += cur.first;
        vis.insert(cur.second);

        for(auto x : graph[cur.second]){
           
            if(!vis.count(x.first) && m[x.first] > x.second){
                q.push(make_pair(x.second, x.first));
                m[x.first] = x.second;
                p[x.first] = cur.second;
            }
        }
    }
    return ans;
}

int main(){
    int n, e, s;
    // vector<vector<int>> v = {
    //     {1,2,3},
    //     {1,3,4},
    //     {4,2,6},
    //     {5,2,2},
    //     {2,3,5},
    //     {3,5,7},
    // };
    // int n = 5;
    // int s = 1;
    vector<vector<int>> v(e, vector<int>(3));
    cin>>n>>e;
    for(int i = 0; i < e; i++){
        for(int j = 0; j < 3; j++){
            cin>>v[i][j];
        }
    }
    cin>>s;

   graph.resize(n+1, list<pair<long long int, long long int>>());
    // make graph
    for(int i = 0; i < v.size(); i++){
        get_edge(v[i][0], v[i][1], v[i][2]);
    }
    
    // finder()
    cout<<finder(n, s)<<endl;

    return 0;
}