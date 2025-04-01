#include<iostream>
#include<vector>
using namespace std;

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       int n = intervals.size();

       sort(intervals.begin(), intervals.end());

        if(n == 1) return intervals;
        
         vector<vector<int>> res;

         int i = 0;
         int j = 0;

         while(i < n && j < n){
            if(j < n - 1 && intervals[j][1] >= intervals[j + 1][0] ) j++;
            else {
                if (intervals[i][1] <= intervals[j][1]){
                    res.push_back({intervals[i][0], intervals[j][1]});
                }
                else{
                    res.push_back({intervals[i][0], intervals[i][1]});
                }
                i = j + 1;
                j ++;

            }
         }

         return res;

    }

int main(){

vector<vector<int>> intervals = {{1,4}, {2, 3}};

// vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15, 18}};

vector<vector<int>> res = merge(intervals);

for(int i = 0; i < res.size(); i++){
    cout<<"["<<res[i][0]<<", "<<res[i][1]<<"]"<<endl;
}

    return 0;
}