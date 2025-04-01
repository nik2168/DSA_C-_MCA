#include<iostream>
#include<vector>
#include<set>
using namespace std;


// using recursion;

void print(int i, int n, int target, int sum, vector<int> &temp, vector<int> & nums, set<vector<int>> & subseq){

    if(i >= n || sum >= target && temp.size() >= 3) {

        if(sum == target && temp.size() == 3)
        subseq.insert(temp);
        return;
    }

    temp.push_back(nums[i]);
    sum += nums[i];
    print(i + 1, n, target, sum, temp, nums, subseq);
    
    sum -= nums[i];
    temp.pop_back();
    print(i + 1, n, target, sum, temp, nums, subseq); 
     
}

int main(){

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // vector<int> nums = {1,2,3,4,5,6,7,8,9};


    vector<vector<int>> output;
    set<vector<int>>subseq;
    vector<int> temp;

    sort(nums.begin(), nums.end());

    int target = 0;

    // print(0, nums.size(), target, 0, temp, nums, subseq);

    for (int i = 0; i < nums.size(); i++)
    {

        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k)
        {

            int sum = nums[i] + nums[j] + nums[k];

            if (sum == 0)
            {
                subseq.insert({nums[i], nums[j++], nums[k--]});
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }

    for(auto vec : subseq){
     output.push_back(vec);  
    }

    for(int i = 0; i < output.size(); i++){
        for(int j = 0; j < output[i].size(); j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}