#include<iostream>
#include<vector>
using namespace std;


int quickSortHelper(vector<vector<int>> & edges, int j, int n){
    int p = edges[n][2];
    int r = j;
    for(int i = j; i < n; i++){
           if(edges[i][2] < p){
            swap(edges[i], edges[r]);
            r++;
           }
    }
    swap(edges[r], edges[n]);
    return r;
}

void quicksort(vector<vector<int>> & edges, int i, int n){
    if(i > n) return;
    int p = quickSortHelper(edges, i, n);
    quicksort(edges, p + 1, n);
    quicksort(edges, i, p - 1);
}


// kruskals algorithm
//    vector<int> e = {0,1,2,3,4,5,6,7,8}; // edges
   vector<int> p = {0,1,2,3,4,5,6,7,8}; // parents
   vector<int> s = {1,1,1,1,1,1,1,1,1}; // size

int findUltimateParent(int r){
    if(p[r] == r) return r;
    return p[r] = findUltimateParent(p[r]);
}

bool unions(int a, int b){
        int x = findUltimateParent(a);
        int y = findUltimateParent(b);
        if(x == y) return true;
        if(s[x] > s[y]) p[y] = x;
        else p[x] = y;
        return false; 
}


int main(){
   vector<vector<int>> edges = {
    {1,2,20},
    {1,3,50},
    {1,4,70},
    {1,5,90},
    {2,3,30},
    {3,4,40},
    {4,5,60},
   };

   int ans = 0;
   int v = 7, edg = edges.size();

  quicksort(edges, 0, edges.size() - 1);

  for(auto x : edges){
    cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
  }

   for(int i = 0; i < edges.size(); i++){
     if(!unions(edges[i][0], edges[i][1]))
     ans += edges[i][2];
    }

    cout<<"Minimum edge weight is : "<<ans<<endl;

    return 0;
}
