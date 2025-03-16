#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> permutations;

void printArr(vector<int> & arr){

    for(auto x : arr){
        cout<<x<<" ";
    }

    cout<<endl;

    return;
}

void nextPermutation(int i, int n, vector<int> &nums)
{

    if (i >= n)
    {
        permutations.push_back(nums);
        return;
    }

    for (int j = i; j < n; j++)
    {
        swap(nums[i], nums[j]);
        printArr(nums);
        nextPermutation(i + 1, n, nums);
        swap(nums[i], nums[j]);
    }
}

int main()
{

    vector<int> nums = {1, 2, 3};

    nextPermutation(0, nums.size(), nums);

    // for(int i = 0; i < nums.size(); i++){
    //     cout<<nums[i]<<" ";
    // }
    // cout<<endl;

    // for (int i = 0; i < permutations.size(); i++)
    // {
    //     for (int j = 0; j < permutations[i].size(); j++)
    //     {
    //         cout << permutations[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}