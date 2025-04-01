#include<iostream>
#include<vector>
using namespace std;


int helper(vector<int> &v, int low, int high){

   int pivot = v[high];

   int i = -1;

   for(int j = low; j < high; j++){
      if(v[j] < pivot){
        i++;
        swap(v[i], v[j]);
      }
   }

   swap(v[++i], v[high]);

   return i;
}

void quickSort(vector<int> & v, int low, int high){
   if(low < high){

    int p = helper(v, low, high);

    quickSort(v, low, p - 1);
    quickSort(v, p + 1, high);

   }
   return;
}

int main(){

    vector<int> v = {4,1,2,5,6,7};

    quickSort(v, 0, v.size() - 1);

    for(auto x : v) cout<<x<<" ";
    cout<<endl;


    return 0;
}