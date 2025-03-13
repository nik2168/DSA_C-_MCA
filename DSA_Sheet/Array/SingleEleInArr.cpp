#include<iostream>
#include<vector>
using namespace std;


    int singleNumber(vector<int>& nums) {
         

         int res = 0;

         for(auto x : nums){
            res ^= x;
         }

         return res;
         
    }

int main() {

    vector<int> nums = {1,1,2,2,3};

    cout<<singleNumber(nums);

    return 0;
}