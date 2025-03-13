#include <iostream>
#include <vector>
using namespace std;

// We need to find the subarray which has the largest sum.

int maxSubArray(vector<int> &nums)
{
    int minSum = INT_MAX;

    int sum = 0;

    int maxSum = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {

        sum += nums[i];

        maxSum = max(sum, maxSum);
        if (minSum != INT_MAX && (sum - minSum) > sum)
            maxSum = max(maxSum, (sum - minSum));
        if (minSum > sum)
        {
            minSum = sum;
        }
    }

    return maxSum;
}

int main()
{

    // vector<int> nums = {5, 4, -1, 7, 8};
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int res = maxSubArray(nums);

    cout << "Max Sum : " << res << endl;

    return 0;
}