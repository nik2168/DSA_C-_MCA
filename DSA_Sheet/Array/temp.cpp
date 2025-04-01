#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int solve(int *A, int n1, int B)
{


 int s = 0;
 int res = 0;

 unordered_map<int, int> m;

for(int i = 0; i < n1; i++){
  s ^= A[i];
  if(s == B) res++;

  int check = B ^ s;

  if(m.find(check) != m.end()) res += m[check];

   m[s]++;
}

cout<<endl;

return res;

}

int main(){

  int A[] = {4,2,2,6,4};
  int B = 6;

  int n = sizeof(A)/sizeof(A[0]);

cout<<solve(A, n, B)<<endl;
 
  return 0;
}