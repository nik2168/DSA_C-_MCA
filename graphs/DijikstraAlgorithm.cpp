#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <climits>
using namespace std;

vector<list<pair<int, int>>> graph;
void get_edge(int s, int d, int y)
{
    graph[s].push_back(make_pair(d, y));
    graph[y].push_back(make_pair(d, s));
}

void display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (auto x : graph[i])
        {
            cout << "(" << x.first << "," << x.second << ")";
        }
        cout << endl;
    }
}

// int finder(int n, int s, int d){
//     n = 300;
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
//     unordered_map<int, int> m;
//     vector<int> p(n);
//     unordered_set<int> vis;

//     for(int i = 0; i < n; i++){
//         m[i] = INT_MAX;
//     }
//     q.push(make_pair(0, s));
//     p[0] = 0;
//     m[0] = 0;

//     while(!q.empty()){
//         pair<double, int> cur = q.top();
//         q.pop();
//         if(vis.count(cur.second) == 1) continue;
//         vis.insert(cur.second);
//         for(auto x : graph[cur.second]){
//             int td = cur.first + x.first;
//            if(m[x.second] >  td){
//             m[x.second] = td;
//             p[x.second] = cur.second;
//             q.push(make_pair(td, x.second));
//            }
//         }
//     }
//     return m[d];
// }

int finder(int n, int src, int dst)
{

    unordered_map<int, double> m;                                                               // will store src & dist
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q; // will store dist & destination
    unordered_set<int> vis;                                                                     // visited nodes
    vector<int> par(n, 0);                                                                      // parent node;
    for (int i = 0; i < n; i++)
    {
        m[i] = INT_MAX;
    }
    q.push(make_pair(0, src));
    m[src] = 0;
    par[src] = 0;
    while (!q.empty())
    {
        pair<double, int> cur = q.top();
        q.pop();
        if (vis.count(cur.second) == 1)
            continue;
        vis.insert(cur.second);
        for (auto x : graph[cur.second])
        {
            cout << "yes" << endl;
            if (m[x.second] > (x.first + cur.first))
            {
                m[x.second] = (x.first + cur.first);
                q.push(make_pair((x.first + cur.first), x.second));
                par[x.second] = cur.second;
            }
        }
    }
    return m[dst];
}

int main()
{
    int n, e, s, d;
    cin >> n >> e >> s >> d;
    vector<vector<int>> v(e, vector<int>(e));
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> v[i][j];
        }
    }
    graph.resize(n, list<pair<int, int>>());
    for (int i = 0; i < e; i++)
    {
        get_edge(v[i][0], v[i][1], v[i][2]);
    }

    display();

    cout << finder(n, s, d);

    return 0;
}
