#include <iostream>
#include <vector>
#include <set>
using namespace std;

// using recursion;

void print(int i, int n, int target, int sum, vector<int> &temp, vector<int> &nums, set<vector<int>> &subseq)
{

    if (i >= n || sum >= target && temp.size() >= 4)
    {

        if (sum == target && temp.size() == 4)
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

int main()
{

    vector<int> nums = {-493, -482, -482, -456, -427, -405, -392, -385, -351, -269, -259, -251, -235, -235, -202, -201, -194, -189, -187, -186, -180, -177, -175, -156, -150, -147, -140, -122, -112, -112, -105, -98, -49, -38, -35, -34, -18, 20, 52, 53, 57, 76, 124, 126, 128, 132, 142, 147, 157, 180, 207, 227, 274, 296, 311, 334, 336, 337, 339, 349, 354, 363, 372, 378, 383, 413, 431, 471, 474, 481, 492};
    // vector<int> nums = {1, 0, -1, 0, -2, 2};
    // vector<int> nums = {1,2,3,4,5,6,7,8,9};

    vector<vector<int>> output;
    set<vector<int>> subseq;

    sort(nums.begin(), nums.end());

    int target = 0;
    vector<int> temp;

    // print(0, nums.size(), target, 0, temp, nums, subseq);

    int n = nums.size();

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
            int low = j + 1, high = n - 1;
            while (low < high)
            {
                if (nums[low] + nums[high] < newTarget)
                {
                    low++;
                }
                else if (nums[low] + nums[high] > newTarget)
                {
                    high--;
                }
                else
                {
                    output.push_back({nums[i], nums[j], nums[low], nums[high]});
                    int tempIndex1 = low, tempIndex2 = high;
                    while (low < high && nums[low] == nums[tempIndex1])
                        low++;
                    while (low < high && nums[high] == nums[tempIndex2])
                        high--;
                }
            }
            while (j + 1 < n && nums[j] == nums[j + 1])
                j++;
        }
        while (i + 1 < n && nums[i] == nums[i + 1])
            i++;
    }

    // for (auto vec : subseq)
    // {
    //     output.push_back(vec);
    // }

    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}