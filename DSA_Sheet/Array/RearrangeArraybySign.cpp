#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{

    int n = nums.size();

    int i = 0, j = 0;

    vector<int> res;

    bool flag = true;

    while (i < nums.size() || j < nums.size())
    {
        if (i < n && nums[i] >= 0 && flag == true)
        {
            res.push_back(nums[i++]);
            flag = false;
        }
        else if (j < n && nums[j] < 0 && flag == false)
        {
            res.push_back(nums[j++]);
            flag = true;
        }
        else
        {
            // reposition i and j to correct position
            while (i < n && !(nums[i] >= 0))
                i++;

            while (j < n && !(nums[j] < 0))
                j++;
        }
    }

    return res;
}

int main(){

    // vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> nums = {-1, 1};

    vector<int> res = rearrangeArray(nums);

    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }

    return 0;
}