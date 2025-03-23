#include<iostream>
#include<vector>
using namespace std;

int finder(vector<int> & v){

int res = 1;
int ele = v[0];

int temp = 1;

sort(v.begin(), v.end());

for(int i = 1; i < v.size(); i++){
     ele += 1;
        if (v[i] == ele)
    {
        temp++;
    }
     else if(v[i] == ele) continue;
     else{
        temp = 1;
        ele = v[i];
     }
     res = max(res, temp);
}

return res;

}

// 1,2,3,4,100,102,103

int main(){

    vector<int> v = {1, 4, 100, 3, 103, 2, 102, 104, 5, 6, 7, 101, 105};

    cout<<finder(v)<<endl;

    return 0;
}